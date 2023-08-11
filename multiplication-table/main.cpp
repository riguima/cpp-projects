#include <iostream>


void ask(){
    std::string answer;
    while(true){
        std::cout << "\nDeseja continuar? [y/n]: ";
        std::cin >> answer;
        if(std::tolower(answer[0]) == 'y'){
            break;
        }else if(std::tolower(answer[0]) == 'n'){
            std::exit(0);
        }else{
            std::cout << "\nOpção inválida, digite apenas y ou n";
        }
    }
}


void show_table(){
    int number;
    while(true){
        std::system("clear");
        std::cout << "Digite um número para ver sua tabuada: ";
        std::cin >> number;
        std::cout << '\n';
        for(int c=0; c<=10; c++){
            std::cout << number << " x " << c << " = " << number * c << '\n';
        }
        ask();
    }
}


int main(){
    show_table();
    return 0;
}
