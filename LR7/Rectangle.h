#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h, double x = 0.0, double y = 0.0);

    double getArea() const override;
    double getWidth() const;
    double getHeight() const;

    // Переопределяем метод получения центра (центр прямоугольника)
    std::pair<double, double> getCenter() const override;
    void printInfo() const override;
};

#endif // RECTANGLE_H

