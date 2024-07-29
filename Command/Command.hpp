#pragma once

#include <iostream>
#include <queue>
#include <stack>

// 抽象命令类
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// 接收者
class Receiver {
public:
    void action() {
        std::cout << "Receiver::action()" << std::endl;
    }
};

// 调用者
class Invoker {
public:
    Invoker(Command *command)
            : m_command(command) {}

    void executeCommand() {
        m_command->execute();
    }

private:
    Command *m_command;
};

// 具体命令类
class ConcreteCommand : public Command {
public:
    ConcreteCommand(Receiver receiver)
            : m_receiver(receiver) {}

    void execute() override {
        m_receiver.action();
    }

private:
    Receiver m_receiver;
};