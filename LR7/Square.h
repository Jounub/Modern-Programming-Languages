#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square(double side, double x = 0.0, double y = 0.0);
    void setSide(double side);
    double getSide() const;
    void printInfo() const override;
};

#endif // SQUARE_H

