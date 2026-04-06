#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h, double x, double y)
    : Figure(x, y), width(w), height(h) {
    if (w <= 0 || h <= 0) {
        std::cerr << "Error: Rectangle sides must be positive!" << std::endl;
        width = height = 1.0;
    }
}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

std::pair<double, double> Rectangle::getCenter() const {
    // Центр прямоугольника - это сохраненные координаты
    return { centerX, centerY };
}

void Rectangle::printInfo() const {
    std::cout << "Rectangle: width=" << width
        << ", height=" << height
        << ", center=(" << centerX << ", " << centerY << ")"
        << ", area=" << getArea();
}
