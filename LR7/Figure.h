#ifndef FIGURE_H
#define FIGURE_H

#include <utility> // для std::pair

class Figure {
protected:
    double centerX;
    double centerY;

public:
    Figure(double x = 0.0, double y = 0.0);
    virtual ~Figure() = default;

    // Чисто виртуальные методы
    virtual double getArea() const = 0;

    // Виртуальные методы с реализацией по умолчанию
    virtual std::pair<double, double> getCenter() const;
    virtual void setCenter(double x, double y);
    virtual void move(double dx, double dy);

    // Чисто виртуальный метод для получения информации о фигуре
    virtual void printInfo() const = 0;
};

#endif // FIGURE_H

