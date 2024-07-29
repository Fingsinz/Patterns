#include <iostream>
#include <memory>
#include <unordered_map>

class Shape {
public:
    Shape(int x = 0, int y = 0)
            : m_x(x)
            , m_y(y) {}

    virtual ~Shape() = default;
    virtual void draw() = 0;

protected:
    int m_x;
    int m_y;
};

class Circle : public Shape {
public:
    Circle(int x = 0, int y = 0)
            : Shape(x, y) {}

    void draw() override {
        std::cout << "CIRCLE";
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int x = 0, int y = 0)
            : Shape(x, y) {}

    void draw() override {
        std::cout << "RECTANGLE";
    }
};

class Triangle : public Shape {
public:
    Triangle(int x = 0, int y = 0)
            : Shape(x, y) {}

    void draw() override {
        std::cout << "TRIANGLE";
    }
};

class ShapeFactory {
public:
    Shape* getShape(std::string type, int x, int y) {
        if (m_shapes.find(type) == m_shapes.end()) {
            if (type == "CIRCLE") {
                m_shapes[type] = std::make_unique<Circle>();
            } else if (type == "RECTANGLE") {
                m_shapes[type] = std::make_unique<Rectangle>();
            } else if (type == "TRIANGLE") {
                m_shapes[type] = std::make_unique<Triangle>();
            }

            m_shapes[type]->draw();
            std::cout << " drawn at (" << x << ", " << y << ")" << std::endl;
        } else {
            m_shapes[type]->draw();
            std::cout << " shared at (" << x << ", " << y << ")" << std::endl;
        }
        return m_shapes[type].get();
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Shape>> m_shapes;
};

int main() {
    std::string type;
    int x, y;

    ShapeFactory shapeFactory;
    while (std::cin >> type >> x >> y) {
        shapeFactory.getShape(type, x, y);
    }

    return 0;
}