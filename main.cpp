#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>



void print_array(std::array<int , 251> array ,int size) {

    for(int i = 0; i < size; i++) {
        std::cout << array[i] <<"\t";
    }
    std::cout << "\n";

}

void play_game() {


    std::array<int , 251> guesses;
    int count = 0;
   // int guesses[250];
    int guess_count = 0;

    int random = rand() % 251;
    //std::cout << random<<std::endl;
    std::cout << "Guess a number: \n";
    while(true) {
        int guess;
        std::cin >> guess;
       guesses[count++] = guess;
       // guesses.push_back(guess);
        if(guess == random) {
            std::cout << "You win!\n";
            break ;
        } else if (guess < random) {
            std::cout << "Too low\n";
        } else if (guess > random) {
            std::cout << "Too high\n";
        }
    }


    print_array(guesses , count);

}


int main() {


    srand(time(NULL));
    int choice;


    do{
        std::cout << "0. Quit" <<std::endl << "1. Play Game\n";
        std::cin >> choice;

     switch (choice) {
         case 0:
             std::cout << "Thanks for nothing\n";
             break;
         case 1:
             std::cout << "yoo let's play\n";
             play_game();
             break;
     }
    } while(choice != 0);







    return 0;
}