// "Copyright [2024] <Jason Ossai>"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "pentaflake.hpp"

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: Penta L N" << std::endl;
        return 1;
    }

    double L = std::stod(argv[1]);
    int N = std::stoi(argv[2]);

    sf::RenderWindow window(sf::VideoMode(2 * L, 2 * L), "Pentaflake");

    Pentaflake pentaflake(L, N);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(pentaflake);
        window.display();
    }

    return 0;
}
