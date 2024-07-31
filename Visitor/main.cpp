/*
 * Author: Fingsinz
 * Date: 2024.07.31
 *
 * 访问者模式：在不改变对象结构的前提下，对对象中的元素进行新的操作。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1098
 */

#include <iostream>
#include <memory>
#include <vector>

class CircleLand;
class RectangleLand;

// 抽象访问者
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(CircleLand *element) = 0;
    virtual void visit(RectangleLand *element) = 0;
};

// 抽象元素：土地
class Land {
public:
    virtual ~Land() = default;
    virtual void accept(Visitor *visitor) = 0;
};

// 具体元素：圆形土地
class CircleLand : public Land {
public:
    CircleLand(double radius = 0)
            : m_radius(radius) {}

    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }

    double getRadius() const {
        return m_radius;
    }

private:
    double m_radius;
};

// 具体元素：矩形土地
class RectangleLand : public Land {
public:
    RectangleLand(int width, int height)
            : m_width(width)
            , m_height(height) {}

    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }

    int getWidth() const {
        return m_width;
    }

    int getHeight() const {
        return m_height;
    }

private:
    int m_width;
    int m_height;
};

// 具体访问者：计算面积
class AreaVisitor : public Visitor {
public:
    void visit(CircleLand *element) override {
        double area = element->getRadius() * element->getRadius() * 3.14;
        std::cout << area << std::endl;
    }

    void visit(RectangleLand *element) override {
        int area = element->getHeight() * element->getWidth();
        std::cout << area << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::unique_ptr<Visitor> visitor(new AreaVisitor());
    std::unique_ptr<Land> land;

    while (n--) {
        std::string type;
        std::cin >> type;

        if (type == "Circle") {
            double r;
            std::cin >> r;
            land.reset(new CircleLand(r));
        } else if (type == "Rectangle") {
            int w, h;
            std::cin >> w >> h;
            land.reset(new RectangleLand(w, h));
        }

        land->accept(visitor.get());
    }

    return 0;
}