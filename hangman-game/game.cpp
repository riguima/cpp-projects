#include "game.h"
#include <iostream>
#include <cstring>

using namespace std;


Game::Game(string word, string tip){
    this->word = word;
    this->tip = tip;
    for(auto it=this->word.begin(); it!=this->word.end(); it++){
        *it = tolower(*it);
        char letter = (*it == ' ')? ' ': '-';
        this->secret.push_back(letter);
    }
}


void Game::run(){
    while(this->chances != 0){
        system("clear");
        cout << "Chances: " << this->chances << endl;
        cout << "A dica é: " << this->tip << endl;
        for(auto it=this->choose_letters.begin(); it!=choose_letters.end(); it++){
            string delimiter = (it == this->choose_letters.end() - 1)? "": " - ";
            cout << *it << delimiter;
        }
        cout << endl;
        for(auto it=this->secret.begin(); it!=this->secret.end(); it++){
            cout << *it;
        }
        cout << "\nDigite uma palavra ou uma letra: ";
        getline(cin, this->choose);
        if(
            this->choose.length() == 1 &&
            this->choose_letters.find(this->choose[0]) == string::npos
        ){
            this->choose_letters.push_back(this->choose[0]);
        }
        if(
            (this->choose.length() == 1 &&
            this->word.find(this->choose[0]) == string::npos) ||
            (this->choose.length() > 1 && this->choose != this->word)
        ){
            --this->chances;
            continue;
        }else{
            size_t index = this->word.find(this->choose[0]);
            while(index != string::npos){
                this->secret[index] = this->choose[0];
                index = this->word.find(this->choose[0], index + 1);
            }
        }
        if(this->secret == this->word || this->choose == this->word){
            cout << "Parabens, a palavra era " << this->word << endl;
            exit(0);
        }
    }
    cout << "Você perdeu, a palavra era " << this->word << endl;
}
