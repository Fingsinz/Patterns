#include <iostream>
#include <memory>

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class Receiver {
public:
    void action(std::string msg) {
        std::cout << msg << " is ready!" << std::endl;
    }
};

class Invoker {
public:
    void setCommand(std::unique_ptr<Command> command) {
        m_command = std::move(command);
    }

    void executeCommand() {
        m_command->execute();
    }

private:
    std::unique_ptr<Command> m_command;
};

class OrderCommand : public Command {
public:
    OrderCommand(std::string dringName, Receiver *receiver)
            : m_receiver(receiver)
            , m_dringName(dringName) {}

    void execute() override {
        m_receiver->action(m_dringName);
    }

private:
    std::string m_dringName;
    Receiver *m_receiver;
};

int main() {
    int n;
    std::cin >> n;

    std::unique_ptr<Receiver> receiver = std::make_unique<Receiver>();

    while (n--) {
        std::string name;
        std::cin >> name;

        std::unique_ptr<Command> orderCommand = std::make_unique<OrderCommand>(name, receiver.get());

        Invoker invoker;
        invoker.setCommand(std::move(orderCommand));
        invoker.executeCommand();
    }
    return 0;
}