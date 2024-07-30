#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 状态模式：将对象每个状态的行为封装在一个具体类中，使得对象可以在运行时动态改变。
 */

#include <iostream>

// 抽象状态类
class State {
public:
    virtual ~State() = default;
    virtual void handle() = 0;
};

// 具体状态 A
class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "状态A下的操作\n";
    }
};

// 具体状态 B
class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "状态B下的操作\n";
    }
};

class Context {
public:
    void setState(State *state) {
        currentState = state;
    }

    void request() {
        currentState->handle();
    }

private:
    State *currentState;
};