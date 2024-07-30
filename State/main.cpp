/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 状态模式：将对象每个状态的行为封装在一个具体类中，使得对象可以在运行时动态改变。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1097
 */

#include <iostream>
#include <memory>

class State {
public:
    virtual ~State() = default;
    virtual void operation() = 0;
};

class LightOn : public State {
public:
    void operation() override {
        std::cout << "Light is ON\n";
    }
};

class LightOff : public State {
public:
    void operation() override {
        std::cout << "Light is OFF\n";
    }
};

class LightBlink : public State {
public:
    void operation() override {
        std::cout << "Light is Blinking\n";
    }
};

class Light {
public:
    void setState(State *state) {
        m_state.reset(state);
    }

    void exec() {
        m_state->operation();
    }

private:
    std::unique_ptr<State> m_state;
};

int main() {
    int n;
    std::cin >> n;

    Light light;

    while (n--) {
        std::string op;
        std::cin >> op;

        State *state = nullptr;

        if (op == "ON") {
            state = new LightOn();
        } else if (op == "OFF") {
            state = new LightOff();
        } else if (op == "BLINK") {
            state = new LightBlink();
        }

        light.setState(state);
        light.exec();
    }

    return 0;
}