#include <iostream>
#include <memory>
#include <vector>
#include "Rectangle.h"
#include "Square.h"

int main() {
    std::cout << "Demonstration of class work" << std::endl;
    std::cout << std::endl;

    // 1. Работа с прямоугольником с указанием центра
    std::cout << "1. Rectangle with center:" << std::endl;
    Rectangle rect(5.0, 3.0, 2.0, 3.0);
    rect.printInfo();
    std::cout << std::endl;
    std::cout << std::endl;

    // 2. Работа с квадратом с указанием центра
    std::cout << "2. Square with center:" << std::endl;
    Square square(4.0, 10.0, 5.0);
    square.printInfo();
    std::cout << std::endl;
    std::cout << std::endl;

    // 3. Демонстрация перемещения фигуры
    std::cout << "3. Moving figures:" << std::endl;
    std::cout << "   Before moving:" << std::endl;
    std::cout << "   ";
    rect.printInfo();
    std::cout << std::endl;

    rect.move(3.0, -1.0);
    std::cout << "   After moving by (3, -1):" << std::endl;
    std::cout << "   ";
    rect.printInfo();
    std::cout << std::endl << std::endl;

    // 4. Демонстрация установки нового центра
    std::cout << "4. Setting new center:" << std::endl;
    std::cout << "   Before: ";
    square.printInfo();
    std::cout << std::endl;

    square.setCenter(0.0, 0.0);
    std::cout << "   After setting center to (0, 0): ";
    square.printInfo();
    std::cout << std::endl << std::endl;

    // 5. Полиморфизм с выводом информации
    std::cout << "5. Polymorphism with info output:" << std::endl;
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Rectangle>(7.0, 4.0, 1.0, 1.0));
    figures.push_back(std::make_unique<Square>(5.0, 3.0, 3.0));
    figures.push_back(std::make_unique<Rectangle>(2.5, 8.0, -2.0, 4.0));
    figures.push_back(std::make_unique<Square>(3.0, 5.0, -1.0));

    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "   Figure " << i + 1 << ": ";
        figures[i]->printInfo();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 6. Получение центра фигуры
    std::cout << "6. Getting figure centers:" << std::endl;
    Rectangle rect2(8.0, 6.0, 4.0, 7.0);
    auto center = rect2.getCenter();
    std::cout << "   Rectangle center: (" << center.first << ", "
        << center.second << ")" << std::endl;

    Square square2(5.0, -3.0, 2.0);
    center = square2.getCenter();
    std::cout << "   Square center: (" << center.first << ", "
        << center.second << ")" << std::endl;
    std::cout << std::endl;

    // 7. Перемещение всех фигур в векторе
    std::cout << "7. Moving all figures in vector:" << std::endl;
    std::vector<std::unique_ptr<Figure>> movableFigures;
    movableFigures.push_back(std::make_unique<Rectangle>(4.0, 3.0, 0.0, 0.0));
    movableFigures.push_back(std::make_unique<Square>(2.0, 1.0, 1.0));

    std::cout << "   Before moving:" << std::endl;
    for (const auto& fig : movableFigures) {
        std::cout << "   ";
        fig->printInfo();
        std::cout << std::endl;
    }

    // Перемещаем все фигуры
    for (auto& fig : movableFigures) {
        fig->move(2.0, 2.0);
    }

    std::cout << "   After moving by (2, 2):" << std::endl;
    for (const auto& fig : movableFigures) {
        std::cout << "   ";
        fig->printInfo();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 8. Демонстрация обработки ошибок
    std::cout << "8. Error handling demonstration:" << std::endl;
    Rectangle invalidRect(-5.0, 3.0, 0.0, 0.0);
    invalidRect.printInfo();
    std::cout << std::endl;

    Square invalidSquare(-4.0, 0.0, 0.0);
    invalidSquare.printInfo();
    std::cout << std::endl;

    return 0;
}
