#include <iostream>
#include <memory>
#include <unordered_map>

// 抽象享元类
class Shape {
public:
    Shape(int x = 0, int y = 0)
            : m_x(x)
            , m_y(y) {}

    virtual ~Shape() = default;
    virtual void draw(std::string externalState) = 0;
    virtual void setXY(int x, int y) {
        m_x = x, m_y = y;
    }

protected:
    int m_x;
    int m_y;
};

// 具体享元类
class Circle : public Shape {
public:
    Circle(int x = 0, int y = 0)
            : Shape(x, y) {}

    void draw(std::string externalState) override {
        std::cout << "CIRCLE " << externalState << " at (" << m_x << ", " << m_y << ")" << std::endl;
    }
};

// 具体享元类
class Rectangle : public Shape {
public:
    Rectangle(int x = 0, int y = 0)
            : Shape(x, y) {}

    void draw(std::string externalState) override {
        std::cout << "RECTANGLE " << externalState << " at (" << m_x << ", " << m_y << ")" << std::endl;
    }
};

// 具体享元类
class Triangle : public Shape {
public:
    Triangle(int x = 0, int y = 0)
            : Shape(x, y) {}

    void draw(std::string externalState) override {
        std::cout << "TRIANGLE " << externalState << " at (" << m_x << ", " << m_y << ")" << std::endl;
    }
};

// 享元工厂类，管理享元
class ShapeFactory {
public:
    Shape* getShape(std::string type, int x, int y) {
        if (m_shapes.find(type) == m_shapes.end()) {
            // 如果不存在该图形，则新建一个，放入管理

            if (type == "CIRCLE") {
                m_shapes[type] = std::make_unique<Circle>(x, y);
            } else if (type == "RECTANGLE") {
                m_shapes[type] = std::make_unique<Rectangle>(x, y);
            } else if (type == "TRIANGLE") {
                m_shapes[type] = std::make_unique<Triangle>(x, y);
            }

            m_shapes[type]->draw("drawn"); // 外部信息为绘画一个
        } else {
            // 如果存在该图形，共享该图形，修改参数

            m_shapes[type]->setXY(x, y);    // 设置新的 x、y
            m_shapes[type]->draw("shared"); // 外部信息为共享一个
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