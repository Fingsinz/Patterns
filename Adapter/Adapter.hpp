#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.24
 *
 * 适配器模式：将一个类的接口转换成客户希望的另一个接口，充当两个不同接口的桥梁，让不兼容的类一起工作。
 */

#include <iostream>

// 目标接口
class Target {
public:
    virtual void request() = 0;
};

// 被适配者
class Adaptee {
public:
    void specificRequest() {
        std::cout << "specificRequest" << std::endl;
    }
};

// 适配器类
class Adapter : public Target {
public:
    Adapter(Adaptee *adaptee) {
        m_adaptee = adaptee;
    }
    void request() override {
        m_adaptee->specificRequest();
    }

private:
    Adaptee *m_adaptee;
};