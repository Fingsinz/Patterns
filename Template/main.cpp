/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 模板方法模式：定义一个算法骨架，将一些步骤的实现延迟到子类。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1087
 */

#include <iostream>
#include <memory>

// 咖啡模板类
class Coffee {
public:
    virtual ~Coffee() = default;

    void make() {
        show();
        grind();
        brew();
        addCondiments();
        std::cout << std::endl;
    }

protected:
    virtual void show() = 0;

    virtual void grind() {
        std::cout << "Grinding coffee beans\n";
    }

    virtual void brew() {
        std::cout << "Brewing coffee\n";
    }

    virtual void addCondiments() {
        std::cout << "Adding condiments\n";
    }
};

// 美式咖啡类
class Americano : public Coffee {
protected:
    void show() override {
        std::cout << "Making American Coffee:\n";
    }
};

// 拿铁类
class Latte : public Coffee {
protected:
    void show() override {
        std::cout << "Making Latte:\n";
    }

    void addCondiments() override {
        std::cout << "Adding milk\n";
        std::cout << "Adding condiments\n";
    }
};

int main() {
    int type;
    while (std::cin >> type) {
        std::unique_ptr<Coffee> coffee;

        if (type == 1) {
            coffee = std::make_unique<Americano>();
        } else if (type == 2) {
            coffee = std::make_unique<Latte>();
        }

        coffee->make();
    }

    return 0;
}