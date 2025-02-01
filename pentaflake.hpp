// "Copyright [2024] <Jason Ossai>"
#ifndef PENTAFLAKE_HPP
#define PENTAFLAKE_HPP

#include <cmath>
#include <SFML/Graphics.hpp>

class Pentaflake : public sf::Drawable {
private:
    float L;  // length of one side of the base pentagon
    int N;    // depth of recursion
    void drawPentaflake(sf::RenderTarget& target, sf::Vector2f center,
        float size, int depth, double theta) const;

public:
    Pentaflake(float l, int n);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
