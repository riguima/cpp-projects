#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

int main(){
    string word, tip;
    cout << "Digite a palavra: ";
    getline(cin, word);
    cout << "Digite a dica: ";
    getline(cin, tip);
    Game game(word, tip);
    game.run();
    return 0;
}
