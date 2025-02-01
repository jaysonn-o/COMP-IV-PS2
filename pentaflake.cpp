// "Copyright [2024] <Jason Ossai>"
#include "pentaflake.hpp"

const double PI = 3.141592653589793;
const double rd = 180 / PI;
const double angleOffset = 72.0;  // For a pentagon, 72 degrees between vertices

Pentaflake::Pentaflake(float l, int n) : L(l), N(n) {}

void Pentaflake::drawPentaflake(sf::RenderTarget& target, sf::Vector2f center, float size, int depth, double theta) const {
    if (depth <= 0) {
        // Draw a pentagon
        sf::ConvexShape pentagon(5);
        for (int i = 0; i < 5; ++i) {
            float angle = (angleOffset * i + theta * rd) * PI / 180.0;
            pentagon.setPoint(i, sf::Vector2f(size * cos(angle), size * sin(angle)));
        }
        pentagon.setOrigin(size, size);
        pentagon.setFillColor(sf::Color::White);
        pentagon.setPosition(center);
        pentagon.rotate(theta * rd);
        target.draw(pentagon);
    }
    else {
        drawPentaflake(target, center, size / 3.0, depth - 1, theta);

        for (int i = 0; i < 5; ++i) {
            double newTheta = (angleOffset * i) * PI / 180.0;
            sf::Vector2f newCenter = center + sf::Vector2f(size * 2 / 3 * cos(newTheta), size * 2 / 3 * sin(newTheta));
            drawPentaflake(target, newCenter, size / 3.0, depth - 1, theta);
        }
    }
}

void Pentaflake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Vector2f center(target.getSize().x / 2, target.getSize().y / 2);
    drawPentaflake(target, center, L, N, 0);
}
