#include "game.hpp"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <signal.h>

/* If SIGINT is caught during different color text,
the text color is returned to normal. */
void sigHandler(int signum){
    std::cout << "\033[0m";
    exit(signum);
}

// Runs the program
int main(){
    system("clear");
    signal(SIGINT, sigHandler);
    //Create Game object
    Game *game = new Game();
	//Run the game
    game->run();
    delete game;
    return 0;
}
