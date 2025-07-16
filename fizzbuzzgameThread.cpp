#include "fizzbuzzgameThread.h"
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>



namespace fizzbuzzgameThread
{

FizzBuzzGame::FizzBuzzGame(const std::vector<std::string>& names,    //Objeto constructor
                           const std::map<int, std::string>& rules,
                           int limit): names(names), rules(rules), count_limit(limit), current_number(1), current_turn(0) {} 
    void FizzBuzzGame::say(int index) {

        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]() {
                return index == current_turn || current_number > count_limit;
            });

            if (current_number > count_limit) break;

            std::string output;
            for (const auto& rule : rules) {
                if (current_number % rule.first == 0) {
                    output += rule.second;
                }
            }

            if (output.empty()) output = std::to_string(current_number);

            std::cout << names[index] << " dice " << output << std::endl;

            current_number++;
            current_turn = (current_turn + 1) % names.size();

            lock.unlock();
            cv.notify_all();
        }
    }

    void FizzBuzzGame::start() {
        std::vector<std::thread> threads;
        for (int i = 0; i < names.size(); ++i) {
            threads.emplace_back(&FizzBuzzGame::say, this, i);
        }

        for (auto& t : threads) {
            t.join();
        }
    }
}

