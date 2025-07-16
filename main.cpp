#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>
#include "juegoFizzbuzz.h"
#include "juegoCustomfizzbuzz.h"

int main() {
    int option;
    std::cout << "Elija un modo de Juego:\n1. Juego FizzBuzz\n2. Juego Fizzbuzz personalizado\nOpción: ";
    std::cin >> option;

    if (option == 1)
        juegoFizzbuzz::fixed_game();
    else
        juegoCustomfizzbuzz::custom_game();
    return 0;
}
