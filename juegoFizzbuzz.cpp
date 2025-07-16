#include "juegoFizzbuzz.h"
#include "fizzbuzzgameThread.h"
#include <iostream>
#include <vector>
#include <map>

namespace juegoFizzbuzz
{
    // Versión 1: juego fijo con nombres y reglas predeterminadas
    void fixed_game() {
        std::vector<std::string> names = {"Abdul", "Bart", "Claudia", "Divya"};
        std::map<int, std::string> rules = {
            {3, "fizz"},
            {5, "buzz"}
        };
        fizzbuzzgameThread::FizzBuzzGame hilo(names, rules, 30);
        hilo.start();
    }
}