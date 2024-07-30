#pragma once

/*
Author: Fingsinz
Date: 2024.07.30

中介者模式：行为型设计模式，通过一个中介对象来封装一组对象之间的交互。
*/

#include <iostream>
#include <vector>

class Colleague;

// 抽象中介者
class Mediator {
public:
    virtual ~Mediator() {}
    virtual void Register(Colleague *colleague) = 0;
    virtual void Send(std::string const &message, Colleague *colleague) = 0;
};

// 具体中介者
class ConcreteMediator : public Mediator {
public:
    void Register(Colleague *colleague) override {
        m_colleagues.push_back(colleague);
    }

    void Send(std::string const &message, Colleague *colleague) override {
        for (auto const &c : m_colleagues) {
            if (c != colleague) {
                c->receive(message);
            }
        }
    }

private:
    std::vector<Colleague *> m_colleagues;
};

// 抽象同事
class Colleague {
public:
    virtual ~Colleague() {}
    virtual void send(std::string const &message) = 0;
    virtual void receive(std::string const &message) = 0;

protected:
    Mediator *m_mediator;
};

// 具体同事A
class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator *mediator) {
        m_mediator = mediator;
    }

    void send(std::string const &message) override {
        m_mediator->Send(message, this);
    }

    void receive(std::string const &message) override {
        std::cout << "ColleagueA received: " << message << std::endl;
    }
};

// 具体同事B
class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator *mediator) {
        m_mediator = mediator;
    }

    void send(std::string const &message) override {
        m_mediator->Send(message, this);
    }

    void receive(std::string const &message) override {
        std::cout << "ColleagueB received: " << message << std::endl;
    }
};