// ============================================================

// Lab: More Details about Classes

// Course: Object-Oriented Programming (C++)

// Level: 2nd Year Engineering

// ============================================================

#include <iostream>

#include <string>

#include <cmath>

// ============================================================

// CLASS DEFINITIONS

// ============================================================

class Point {

private:

    double x;

    double y;

public:

    // TODO 1: Constructor with member initializer list

    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x

    double getX() const { return x; }

    // TODO 3: const getter for y

    double getY() const { return y; }

    // TODO 4: const display()

    void display() const {

        std::cout << "(" << x << ", " << y << ")";

    }

    // TODO 5: Rectangle is friend class

    friend class Rectangle;

};


class Rectangle {

private:

    Point topLeft;

    Point bottomRight;

public:

    // TODO 6: constructor with member initializer list

    Rectangle(double x1, double y1, double x2, double y2)

        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7: const getWidth() — direct private access via friendship

    double getWidth() const {

        return std::abs(bottomRight.x - topLeft.x);

    }

    // TODO 8: const getHeight() — direct private access via friendship

    double getHeight() const {

        return std::abs(bottomRight.y - topLeft.y);

    }

    // TODO 9: const getArea()

    double getArea() const {

        return getWidth() * getHeight();

    }

    // TODO 10: const display()

    void display() const {

        std::cout << "Rectangle [ topLeft=";

        topLeft.display();

        std::cout << ", bottomRight=";

        bottomRight.display();

        std::cout << ", width="  << getWidth()
<< ", height=" << getHeight()
<< ", area="   << getArea()
<< " ]" << std::endl;

    }

    // TODO 11: isSameSize is friend function

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);

};


// TODO 12: isSameSize — uses direct private member access + epsilon comparison

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {

    double w1 = std::abs(r1.bottomRight.x - r1.topLeft.x);

    double h1 = std::abs(r1.bottomRight.y - r1.topLeft.y);

    double w2 = std::abs(r2.bottomRight.x - r2.topLeft.x);

    double h2 = std::abs(r2.bottomRight.y - r2.topLeft.y);

    return std::abs(w1 - w2) < 1e-9 &&

           std::abs(h1 - h2) < 1e-9;

}


class ConstDemo {

private:

    int value;

public:

    // TODO 13: constructor with member initializer list

    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()

    int getValue() const { return value; }

    // TODO 15: NON-const doubleValue()

    void doubleValue() { value *= 2; }

    // TODO 16: const constGetDouble()

    int constGetDouble() const { return value * 2; }

};


// ============================================================

// MAIN

// ============================================================

int main() {

    // TODO 17: Point demo

    std::cout << "=== Point ===" << std::endl;

    Point p(3.0, 4.0);

    p.display();

    std::cout << std::endl;

    // TODO 18: Rectangle demo

    std::cout << "\n=== Rectangle ===" << std::endl;

    Rectangle r1(0.0, 6.0, 4.0, 0.0);  // 4 x 6

    Rectangle r2(1.0, 3.0, 5.0, 0.0);  // 4 x 3

    Rectangle r3(2.0, 5.0, 6.0, 2.0);  // 4 x 3

    r1.display();

    r2.display();

    r3.display();

    // TODO 19: isSameSize demo

    std::cout << "\n=== isSameSize ===" << std::endl;

    std::cout << "r1 vs r2: " << (isSameSize(r1, r2) ? "same" : "different") << std::endl;

    std::cout << "r2 vs r3: " << (isSameSize(r2, r3) ? "same" : "different") << std::endl;

    // TODO 20: ConstDemo non-const object

    std::cout << "\n=== ConstDemo (non-const object) ===" << std::endl;

    ConstDemo cd(5);

    std::cout << "value       = " << cd.getValue()       << std::endl;

    std::cout << "constDouble = " << cd.constGetDouble() << std::endl;

    cd.doubleValue();

    std::cout << "after doubleValue
 
