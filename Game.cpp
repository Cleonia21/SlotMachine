//
// Created by Cleonia on 15.09.2022.
//

#include "Game.hpp"

Game::Game() {}

Game::~Game() {
    SDL_DestroyRenderer( render );
	SDL_DestroyWindow( window );
    IMG_Quit();
	SDL_Quit();
}

void Game::init() {
    //Initialize SDL
    if (SDL_Init( SDL_INIT_VIDEO ) < 0)
        throw std::runtime_error("SDL could not init! SDL Error: " + std::string(SDL_GetError()));

    //Set texture filtering to linear
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

    //Create window
    window = SDL_CreateWindow( "Slot Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == nullptr )
        throw std::runtime_error("Window could not be created! SDL Error: " + std::string(SDL_GetError()));

    //Create render for window
    render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( render == nullptr )
        throw std::runtime_error("Renderer could not be created! SDL Error: " + std::string(SDL_GetError()));
    //Initialize renderer color
    SDL_SetRenderDrawColor( render, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
        throw std::runtime_error("SDL_image could not init! SDL_image Error: " + std::string(IMG_GetError()));

    initViewports();
}

void Game::startGame() {
    //Loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Prepare buttons
    ButtonsInterface buttons(render, buttonsViewport);
    buttons.init();

    //Prepare drum
    Drum drum(render, drumViewport);
    drum.init();

    //Create the array for states
    auto **stateInterface = new StateInterface *[4];
    stateInterface[0] = new WaitingState(&buttons.getStart(), &drum);
    stateInterface[1] = new RotationState(&buttons.getEnd(), &drum);
    stateInterface[2] = new StopState(nullptr, &drum);
    stateInterface[3] = new WinState(&buttons.getStart(), &drum);

    int state = 0;
    Uint32 timer = SDL_GetTicks();
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            buttons.handleEvent(&e);
        }
        //Frame delay
        if (timer + 10 > SDL_GetTicks())
            std::this_thread::sleep_for(std::chrono::milliseconds(timer + 10 - SDL_GetTicks()));
        timer = SDL_GetTicks();

        clearScreen();

        buttons.render();

        //State Transition
        state = stateInterface[state]->getState();
        //Execute a specific state
        stateInterface[state]->render();

        updateScreen();
    }

    for (int i = 0; i < 4; i++)
        delete stateInterface[i];
    delete [] stateInterface;
}

void Game::initViewports() {
    buttonsViewport = {
            SCREEN_WIDTH / 5 * 4,
            0,
            SCREEN_WIDTH / 5,
            SCREEN_HEIGHT
    };
    int remainingW = SCREEN_WIDTH / 5 * 4;
    int remainingH = SCREEN_HEIGHT;
    drumViewport = {
            remainingW / 10,
            remainingH / 10,
            remainingW / 10 * 8,
            remainingH / 10 * 8
    };
}

void Game::clearScreen() {
    SDL_RenderClear(render);
}

void Game::updateScreen() {
    SDL_RenderPresent(render);
}
