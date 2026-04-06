#include "Figure.h"
#include <iostream>

Figure::Figure(double x, double y) : centerX(x), centerY(y) {}

std::pair<double, double> Figure::getCenter() const {
    return { centerX, centerY };
}

void Figure::setCenter(double x, double y) {
    centerX = x;
    centerY = y;
}

void Figure::move(double dx, double dy) {
    centerX += dx;
    centerY += dy;
}
