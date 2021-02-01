#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

//need to creat best_score file at first
void print_vector(std::vector<int> vector) {

    for(int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] <<"\t";
    }
    std::cout << "\n";

}

void play_game() {


    std::vector<int> guesses;
   // int guesses[250];
    int count = 0;

    int random = rand() % 251;
    std::cout << random<<std::endl;
    std::cout << "Guess a number:\n ";
    while(true) {
        int guess;
        std::cin >> guess;

        count++;

        guesses.push_back(guess);
        if(guess == random) {
            std::cout << "You win!\n";
            break ;
        } else if (guess < random) {
            std::cout << "Too low\n";
        } else if (guess > random) {
            std::cout << "Too high\n";
        }
    }

    std::ifstream input("best_score.txt");

  if(!(input.is_open())){
    std::cout << "meeeh\n";
    return;
  }


    int best_score;
    input >> best_score;

    std::ofstream output("best_score");
  if(!(output.is_open())){
    std::cout << "meeeh\n";
    return;
  }
    if(count < best_score) {
        output << count;
    } else {
      output << best_score;
    }


    print_vector(guesses);

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