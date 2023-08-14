#include "pong.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Pong::Pong(){
    this->window.create(
        sf::VideoMode(1280, 720),
        "Pong::Remix",
        sf::Style::Fullscreen | sf::Style::Titlebar | sf::Style::Close
    );
    this->window.setFramerateLimit(60);

    this->ball_initial_position = sf::Vector2f(
        this->window.getSize().x / 2, this->window.getSize().y / 2
    );

    this->font.loadFromFile("pong_font.ttf");

    float players_y(
        this->window.getSize().y / 2.f -
        this->player_1.getGlobalBounds().height / 2.f
    );

    this->player_1.setSize(this->PLAYERS_SIZE);
    this->player_1.setFillColor(this->MAIN_COLOR);
    this->player_1.setPosition(sf::Vector2f(30.f, players_y));

    this->player_2.setSize(this->PLAYERS_SIZE);
    this->player_2.setFillColor(this->MAIN_COLOR);
    this->player_2.setPosition(
        sf::Vector2f(
            this->window.getSize().x -
            this->player_2.getGlobalBounds().width - 30,
            players_y
        )
    );

    this->score_player_1_text.setFont(this->font);
    this->score_player_1_text.setString(std::to_string(this->score_player_1));
    this->score_player_1_text.setCharacterSize(30);
    this->score_player_1_text.setPosition(
        sf::Vector2f(
            this->score_player_1_text.getGlobalBounds().width * 2,
            this->score_player_1_text.getGlobalBounds().height
        )
    );

    this->score_player_2_text.setFont(this->font);
    this->score_player_2_text.setString(std::to_string(this->score_player_2));
    this->score_player_2_text.setCharacterSize(30);
    this->score_player_2_text.setPosition(
        sf::Vector2f(
            this->window.getSize().x -
            this->score_player_2_text.getGlobalBounds().width * 3,
            this->score_player_2_text.getGlobalBounds().height
        )
    );

    this->paused_text.setFont(this->font);
    this->paused_text.setString("Aperte qualquer tecla para começar");
    this->paused_text.setCharacterSize(50);
    this->paused_text.setPosition(
        sf::Vector2f(
            this->window.getSize().x / 2.f -
            this->paused_text.getGlobalBounds().width / 2.f,
            this->window.getSize().y / 2.f -
            this->paused_text.getGlobalBounds().height / 2.f
        )
    );

    this->ball.setSize(this->BALL_SIZE);
    this->ball.setPosition(this->ball_initial_position);
}


void Pong::run(){
    while(this->window.isOpen()){
        this->events();
        this->draw();
        if(this->ball.getPosition().x > this->window.getSize().x){
            this->score_player_1_text.setString(
                std::to_string(++this->score_player_1)
            );
        }else if(this->ball.getPosition().x < 0){
            this->score_player_2_text.setString(
                std::to_string(++this->score_player_2)
            );
        }else if(
            this->ball.getPosition().y > this->window.getSize().y ||
            this->ball.getPosition().y < 50
        ){
            this->ball_velocity_y = -this->ball_velocity_y;
        }else if(
            this->ball.getGlobalBounds().intersects(
                this->player_1.getGlobalBounds()
            ) ||
            this->ball.getGlobalBounds().intersects(
                this->player_2.getGlobalBounds()
            )
        ){
            this->ball_velocity_x += 2.f;
            this->ball_velocity_y += 2.f;
            this->ball_velocity_x = -this->ball_velocity_x;
        }
        if(
            this->ball.getPosition().x > this->window.getSize().x ||
            this->ball.getPosition().x < 0
        ){
            this->ball.setPosition(this->ball_initial_position);
            this->ball_velocity_x = 5.f;
            this->ball_velocity_y = 5.f;
        }
        this->ball.move(this->ball_velocity_x, this->ball_velocity_y);
    }
}


void Pong::draw(){
    this->window.clear(sf::Color::Black);
    if(!this->paused){
        this->window.draw(this->score_player_1_text);
        this->window.draw(this->score_player_2_text);
        this->window.draw(this->player_1);
        this->window.draw(this->player_2);
        this->window.draw(this->ball);
    }else{
        this->window.draw(this->paused_text);
    }
    this->window.display();
}


void Pong::events(){
    sf::Event event;
    while(this->window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::KeyPressed:
                if(this->paused){
                    this->paused = false;
                    break;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)){
                    this->player_1.move(0.f, -this->PLAYERS_VELOCITY);
                    if(this->player_1.getPosition().y < 50){
                        this->player_1.move(0.f, this->PLAYERS_VELOCITY);
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)){
                    this->player_1.move(0.f, this->PLAYERS_VELOCITY);
                    if(
                        this->player_1.getPosition().y >
                        this->window.getSize().y -
                        this->player_1.getGlobalBounds().height
                    ){
                        this->player_1.move(0.f, -this->PLAYERS_VELOCITY);
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)){
                    this->player_2.move(0.f, -this->PLAYERS_VELOCITY);
                    if(this->player_2.getPosition().y < 50){
                        this->player_2.move(0.f, this->PLAYERS_VELOCITY);
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)){
                    this->player_2.move(0.f, this->PLAYERS_VELOCITY);
                    if(
                        this->player_2.getPosition().y >
                        this->window.getSize().y -
                        this->player_2.getGlobalBounds().height
                    ){
                        this->player_2.move(0.f, -this->PLAYERS_VELOCITY);
                    }
                }
                break;
            default:
                break;
        }
    }
}
