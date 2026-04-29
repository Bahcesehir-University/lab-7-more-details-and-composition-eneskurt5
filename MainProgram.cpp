// ============================================================

// Lab: More Details about Classes

// Course: Object-Oriented Programming (C++)

// Level: 2nd Year Engineering

// Duration: 60 minutes

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

    // TODO 5: declare Rectangle as friend class

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

    // TODO 7: const getWidth()

    double getWidth() const {

        return std::abs(bottomRight.x - topLeft.x);  // friend access

    }

    // TODO 8: const getHeight()

    double getHeight() const {

        return std::abs(bottomRight.y - topLeft.y);  // friend access

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
<< " ]";

    }

    // TODO 11: declare isSameSize as friend function

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);

};


// TODO 12: implement isSameSize

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {

    // friend access lets us reach private members directly,

    // but calling const member functions is perfectly fine too.

    return (r1.getWidth()  == r2.getWidth()) &&

           (r1.getHeight() == r2.getHeight());

}


class ConstDemo {

private:

    int value;

public:

    // TODO 13: constructor with member initializer list

    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()

    int getValue() const { return value; }

    // TODO 15: NON-const doubleValue() — multiplies value by 2

    void doubleValue() { value *= 2; }

    // TODO 16: const constGetDouble() — returns value * 2 without modifying

    int constGetDouble() const { return value * 2; }

};


// ============================================================

// MAIN

// ============================================================

int main() {

    // TODO 17: Point demo

    std::cout << "=== Point ===\n";

    Point p(3.0, 4.0);

    p.display();

    std::cout << "\n";

    // TODO 18: Rectangle demo

    std::cout << "\n=== Rectangle ===\n";

    Rectangle r1(0.0, 6.0, 4.0, 0.0);   // 4 x 6

    Rectangle r2(1.0, 3.0, 5.0, 0.0);   // 4 x 3

    Rectangle r3(2.0, 5.0, 6.0, 2.0);   // 4 x 3  (same size as r2)

    r1.display(); std::cout << "\n";

    r2.display(); std::cout << "\n";

    r3.display(); std::cout << "\n";

    // TODO 19: isSameSize demo

    std::cout << "\n=== isSameSize ===\n";

    std::cout << "r1 vs r2: " << (isSameSize(r1, r2) ? "same" : "different") << "\n";

    std::cout << "r2 vs r3: " << (isSameSize(r2, r3) ? "same" : "different") << "\n";

    // TODO 20: ConstDemo — non-const object (can call all methods)

    std::cout << "\n=== ConstDemo (non-const object) ===\n";

    ConstDemo cd(5);

    std::cout << "value        = " << cd.getValue()       << "\n";

    std::cout << "constDouble  = " << cd.constGetDouble() << "\n";

    cd.doubleValue();

    std::cout << "after doubleValue(), value = " << cd.getValue() << "\n";

    // TODO 21: ConstDemo — const object (can only call const methods)

    std::cout << "\n=== ConstDemo (const object) ===\n";

    const ConstDemo ccd(7);

    std::cout << "value        = " << ccd.getValue()       << "\n";

    std::cout << "constDouble  = " << ccd.constGetDouble() << "\n";

    // ccd.doubleValue();  // ❌ compile error — non-const method on const object

    return 0;

}
 
