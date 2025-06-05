#include <iostream>

// Rectangle class
class Rectangle {
protected:
    int width, height;

public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getArea() { return width * height; }
};

// Square class extending the Rectangle class
class Square : public Rectangle {
public:
    void setWidth(int w) override {
        width = w;
        height = w; // makes it a square
    }

    void setHeight(int h) override {
        height = h;
        width = h; // makes it a square
    }
};

// Function to print the area of the given rectangle object
void printArea(Rectangle& r) {
    r.setWidth(5);
    r.setHeight(10);
    std::cout << "Area: " << r.getArea() << std::endl; // Expected: 50 but Actual: 100
}

int main() {
    // Replacing object of Rectangle class with Square class
    Square s;
    printArea(s);
    return 0;
}
