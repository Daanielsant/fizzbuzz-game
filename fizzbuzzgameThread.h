#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>

namespace fizzbuzzgameThread
{
    class FizzBuzzGame{

        private:

            void say(int index);
            std::vector<std::string> names;
            std::map<int, std::string> rules;
            int count_limit;
            int current_number;
            int current_turn;

            std::mutex mtx;
            std::condition_variable cv;

        public:
            FizzBuzzGame(const std::vector<std::string>& names, const std::map<int, std::string>& rules, int limit);

            void start();  
    };
}