#include "juegoCustomfizzbuzz.h"
#include "fizzbuzzgameThread.h"
#include <iostream>
#include <vector>
#include <map>

namespace juegoCustomfizzbuzz
{
    // Versión 2: juego con entrada personalizada
    void custom_game() {
        int num_players, num_rules, limit;

        std::cout << "Ingrese el número de jugadores: ";
        std::cin >> num_players;
        std::vector<std::string> names(num_players);
        for (int i = 0; i < num_players; ++i) {
            std::cout << "Nombre del jugador " << i + 1 << ": ";
            std::cin >> names[i];
        }

        std::cout << "Ingrese el número de reglas: ";
        std::cin >> num_rules;
        std::map<int, std::string> rules;
        for (int i = 0; i < num_rules; ++i) {
            int divisor;
            std::string word;
            std::cout << "Regla " << i + 1 << " - Divisor: ";
            std::cin >> divisor;
            std::cout << "Palabra que dice según divisor: ";
            std::cin >> word;
            rules[divisor] = word;
        }

        std::cout << "¿Hasta que número debe contar?";
        std::cin >> limit;

        fizzbuzzgameThread::FizzBuzzGame hilo(names, rules, limit);
        hilo.start();
    }
}