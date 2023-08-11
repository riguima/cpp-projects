#pragma once
#include <string>

using namespace std;

class Game{
    string word;
    string tip;
    string secret;
    string choose_letters;
    string choose;
    int chances = 5;

    public:
        Game(string word, string tip);
        void run();
};
