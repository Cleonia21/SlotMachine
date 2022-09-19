//
// Created by Cleonia on 13.09.2022.
//

#include <iostream>

#include "Game.hpp"

int main(  ) {
    Game game;

    try {
        game.init();
    } catch (const char *msg) {
        std::cout << msg << std::endl;
        return 1;
    }

    try {
        game.startGame();
    } catch (const char *msg) {
        std::cout << msg << std::endl;
        return 1;
    }

	return 0;
}
