#pragma once
#include <SFML/Graphics.hpp>

class Pong{
    private:
        sf::RenderWindow window;
        sf::RectangleShape player_1;
        sf::RectangleShape player_2;
        sf::RectangleShape ball;
        bool paused = true;
        float ball_velocity_x = 5.f;
        float ball_velocity_y = 5.f;
        const sf::Vector2f PLAYERS_SIZE = sf::Vector2f(20.f, 100.f);
        const sf::Vector2f BALL_SIZE = sf::Vector2f(15.f, 15.f);
        sf::Vector2f ball_initial_position;
        const sf::Color MAIN_COLOR = sf::Color::White;
        const float PLAYERS_VELOCITY = 30.f;
        sf::Font font;
        int score_player_1 = 0;
        int score_player_2 = 0;
        sf::Text score_player_1_text;
        sf::Text score_player_2_text;
        sf::Text paused_text;
    protected:
        void events();
        void draw();
    public:
        Pong();
        void run();
};
