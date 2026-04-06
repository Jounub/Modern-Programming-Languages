#include "Square.h"
#include <iostream>

Square::Square(double side, double x, double y) : Rectangle(side, side, x, y) {}

void Square::setSide(double side) {
    if (side <= 0) {
        std::cerr << "Error: Square side must be positive!" << std::endl;
        return;
    }
    width = height = side;
}

double Square::getSide() const {
    return width;
}

void Square::printInfo() const {
    std::cout << "Square: side=" << width
        << ", center=(" << centerX << ", " << centerY << ")"
        << ", area=" << getArea();
}
