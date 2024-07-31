/*
 * Author: Fingsinz
 * Date: 2024.07.31
 *
 * 责任链模式：允许构建一个对象链，请求从链的一端进入，沿着链上的对象依次处理，直至链上某个对象能够处理该请求。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1100
 */

#include <iostream>
#include <memory>

// 抽象处理者
class Handler {
public:
    virtual void handleRequest(std::string name, int days) = 0;
    virtual void setNextHandler(Handler *next) = 0;

protected:
    Handler *m_nextHandler = nullptr;
};

// 具体处理者：主管
class Supervisor : public Handler {
public:
    void handleRequest(std::string name, int days) override {
        if (canHandle(days)) {
            std::cout << name << " Approved by Supervisor.\n";
        } else if (m_nextHandler != nullptr) {
            m_nextHandler->handleRequest(name, days);
        } else {
            std::cout << name << " Denied by Supervisor.\n";
        }
    }

    void setNextHandler(Handler *next) override {
        m_nextHandler = next;
    }

private:
    bool canHandle(int days) {
        return days <= 3;
    }
};

// 具体处理者：经理
class Manager : public Handler {
public:
    void handleRequest(std::string name, int days) override {
        if (canHandle(days)) {
            std::cout << name << " Approved by Manager.\n";
        } else if (m_nextHandler != nullptr) {
            m_nextHandler->handleRequest(name, days);
        } else {
            std::cout << name << " Denied by Manager.\n";
        }
    }

    void setNextHandler(Handler *next) override {
        m_nextHandler = next;
    }

private:
    bool canHandle(int days) {
        return days <= 7;
    }
};

// 具体处理者：董事
class Director : public Handler {
public:
    void handleRequest(std::string name, int days) override {
        if (canHandle(days)) {
            std::cout << name << " Approved by Director.\n";
        } else if (m_nextHandler != nullptr) {
            m_nextHandler->handleRequest(name, days);
        } else {
            std::cout << name << " Denied by Director.\n";
        }
    }

    void setNextHandler(Handler *next) override {
        m_nextHandler = next;
    }

private:
    bool canHandle(int days) {
        return days <= 10;
    }
};

int main() {
    int n;
    std::cin >> n;

    // 创建责任链
    std::unique_ptr<Handler> supervisor(new Supervisor()), manager(new Manager()), director(new Director());
    supervisor->setNextHandler(manager.get());
    manager->setNextHandler(director.get());

    while (n--) {
        std::string name;
        int days;
        std::cin >> name >> days;

        supervisor->handleRequest(name, days);
    }

    return 0;
}