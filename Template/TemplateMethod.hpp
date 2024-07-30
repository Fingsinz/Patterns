#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 模板方法模式：定义一个算法骨架，将一些步骤的实现延迟到子类。
 */

#include <iostream>

// 模板类
class AbstractClass {
public:
    virtual ~AbstractClass() = default;
    void templateMethod() {
        step1();
        step2();
        step3();
    }

protected:
    virtual void step1() = 0; // 可能是抽象方法
    virtual void step2() {}   // 也可能是具体方法，提供默认实现
    virtual void step3() {}
};

// 具体类
class ConcreteClass : public AbstractClass {
protected:
    void step1() override {
        std::cout << "Step 1\n";
    }

    void step2() override {
        std::cout << "Step 2\n";
    }

    void step3() override {
        std::cout << "Step 3\n";
    }
};