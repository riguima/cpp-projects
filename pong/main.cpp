#include "pong.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


int main(){
    std::shared_ptr<Pong> pong = std::make_shared<Pong>();
    pong->run();
    return 0;
}
