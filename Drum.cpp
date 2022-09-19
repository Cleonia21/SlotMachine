//
// Created by Cleonia on 16.09.2022.
//

#include "Drum.hpp"

Drum::Drum(SDL_Renderer* render, SDL_Rect &_viewport)
{
    gameRender = render;
    viewport = _viewport;

    lineNum = 3;
    elemNum = 5;

    velocity = nullptr;
    symbols = nullptr;
}

Drum::~Drum()
{
    delete[] symbols;
    delete[] velocity;
}

void Drum::init() {
    //Allocating memory for an array of elements
    symbols = new DrumSymbol[elemNum * lineNum];

    //Calculating the Height and Width of an Element
    int elemW = viewport.w / 3;
    elemH = viewport.h / 3;

    //Loading Images into Texture Objects
    std::string indices[] = {"1", "2", "3", "4"};
    for (int i = 0; i < 4; i++) {
        texture[i].init(gameRender);
        texture[i].loadFromFile("img/Symbol" + indices[i] + ".png", elemW, elemH);
    }

    //Initializing an object to get random numbers
    std::random_device sd{};
    std::mt19937 engine {sd()};
    std::uniform_int_distribution random{0, 3};

    //Creation of symbols
    int symbolPosX = viewport.x;
    for (int i = 0; i < lineNum; i++) {
        int symbolPosY = viewport.y;
        for (int j = 0; j < elemNum; j++) {
            DrumSymbol *beforeSymbol;
            if (j == 0)
                beforeSymbol = &symbols[i * elemNum + elemNum - 1];
            else
                beforeSymbol = &symbols[i * elemNum + j - 1];

            int rnd = random(engine);
            symbols[i * elemNum + j].init(&texture[rnd], symbolPosX, symbolPosY, viewport,
                                          beforeSymbol, rnd);
            symbolPosY += elemH;
        }
        symbolPosX += elemW;
    }

    //Allocating memory for an array of speeds
    velocity = new VelocityParam [lineNum];
    velocityInit();
}

void Drum::acceleration() {
    //Increase in speed
    velocityChange(1);
    //Move elements
    move();
}

bool Drum::deceleration() {
    //Deceleration speed
    velocityChange(-1);
    //Move elements
    move();

    int stopLineNum = 0;
    for (int i = 0; i < lineNum; i++) {
        //If the line is edge aligned, then stop the line
        if (velocity[i].positionController % elemH == 0 && velocity[i].velocity == 1) {
            velocity[i].velocity = 0;
        }
        //Increase the counter of stopped lines
        if (velocity[i].velocity == 0) {
            stopLineNum++;
        }
    }
    //If all lines are stopped
    if (stopLineNum == lineNum) {
        //Reinitialize the speed for the next game
        velocityInit();
        //Calculates score
        calculateScore();
        //All lines are stopped
        return true;
    }
    //Lines not stopped
    return false;
}

void Drum::renderScore() {
    render();

    //Draw a red line in the middle of the screen
    int y = viewport.y + viewport.h / 2 - 5;
    SDL_SetRenderDrawColor( gameRender, 0xFF, 0x00, 0x00, 0xFF );
    for (int i = 0; i < 10; i++) {
        SDL_RenderDrawLine( gameRender, viewport.x, y + i, viewport.x + viewport.w, y + i);
    }
    SDL_SetRenderDrawColor( gameRender, 0xFF, 0xFF, 0xFF, 0xFF );

    //Creating and rendering end game textures
    Texture textTexture(gameRender);
    Texture numsTexture(gameRender);
    textTexture.loadFromFile("img/ScoreText.png", viewport.w / 2, viewport.h / 8);
    numsTexture.loadFromFile("img/nums.png", viewport.w / 2, viewport.h / 8);

    textTexture.render(0, 0);
    SDL_Rect num = {
            numsTexture.getWidth() / 10 * score,
            0,
            numsTexture.getWidth() / 10,
            viewport.h / 8
    };
    numsTexture.render(textTexture.getWidth(), 0, &num);
}

void Drum::render() {
    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < elemNum; j++) {
            symbols[i * elemNum + j].render();
        }
    }
}

void Drum::move() {
    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < elemNum; j++) {
            symbols[i * elemNum + j].alignment();
        }
    }

    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < elemNum; j++) {
            symbols[i * elemNum + j].move(int(velocity[i].velocity));
        }
    }
}

void Drum::calculateScore() {
    //calculateScore calculates points based on the number of identical elements in a row
    int types[lineNum];
    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < elemNum; j++) {
            if (symbols[i * elemNum + j].getPosY() == viewport.y + elemH)
                types[i] = symbols[i * elemNum + j].getType();
        }
    }

    score = 1;
    int tmpScore = 1;
    for (int i = 0; i < lineNum - 1; i++) {
        if (types[i] == types[i + 1]) {
            tmpScore++;
        }
        else {
            if (score < tmpScore)
                score = tmpScore;
            tmpScore = 1;
        }
    }
    if (score < tmpScore)
        score = tmpScore;
}

void Drum::velocityInit() {
    std::random_device sd{};
    std::mt19937 engine {sd()};

    std::uniform_real_distribution<float> stepRnd{0.1, 0.5};
    std::uniform_real_distribution<float> maxRnd{10, 25};
    for (int i = 0; i < lineNum; i++) {
        velocity[i].velocity = 1;
        velocity[i].velocityStep = stepRnd(engine);
        velocity[i].velocityMax = maxRnd(engine);
        velocity[i].positionController = 0;
    }
}

void Drum::velocityChange(float direction) {
    for (int i = 0; i < lineNum; i++) {
        if (velocity[i].velocity == 0)
            continue;
        velocity[i].velocity += velocity[i].velocityStep * direction;
        if (velocity[i].velocity > velocity[i].velocityMax)
            velocity[i].velocity = velocity[i].velocityMax;
        if (velocity[i].velocity < 1)
            velocity[i].velocity = 1;
        velocity[i].positionController += uint(velocity[i].velocity);
    }
}
