/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 中介者模式：行为型设计模式，通过一个中介对象来封装一组对象之间的交互。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1094
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

class Colleague;

// 抽象中介者
class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void registerColleague(Colleague *colleague) = 0;
    virtual void removeColleague(Colleague *colleague) = 0;
    virtual void send(std::string const &message, Colleague *colleague) = 0;
};

// 抽象同事
class Colleague {
public:
    Colleague(std::string name = "", Mediator *mediator = nullptr)
            : m_name(name)
            , m_mediator(mediator) {}
    virtual ~Colleague() = default;
    virtual void send(std::string const &message) = 0;
    virtual void receive(std::string const &message) = 0;

protected:
    Mediator *m_mediator;
    std::string m_name;
};

// 聊天室
class ChatRoom : public Mediator {
public:
    void registerColleague(Colleague *colleague) override {
        m_colleagues.push_back(colleague);
    }

    void removeColleague(Colleague *colleague) override {
        auto it = std::find(m_colleagues.begin(), m_colleagues.end(), colleague);
        if (it != m_colleagues.end()) {
            m_colleagues.erase(it);
        }
    }

    void send(std::string const &message, Colleague *colleague) override {
        for (Colleague *c : m_colleagues) {
            if (c != colleague) {
                c->receive(message);
            }
        }
    }

private:
    std::vector<Colleague *> m_colleagues;
};

// 用户
class User : public Colleague {
public:
    User(std::string name = "", Mediator *mediator = nullptr)
            : Colleague(name) {
        m_mediator = mediator;
    }

    void send(std::string const &message) override {
        m_mediator->send(message, this);
    }

    void receive(std::string const &message) override {
        std::cout << m_name << " received: " << message << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;
    {
        // 用户组，在客户端使用智能指针维护用户的生存期
        std::unordered_map<std::string, std::unique_ptr<Colleague>> colleagues;
        // 聊天室，中介者
        std::unique_ptr<Mediator> mediator(new ChatRoom());

        while (n--) {
            std::string name;
            std::cin >> name;

            auto user = std::make_unique<User>(name, mediator.get());

            mediator->registerColleague(user.get());
            colleagues[name] = std::move(user);
        }

        std::string user, msg;

        while (std::cin >> user >> msg) {
            mediator->send(msg, colleagues[user].get());
        }

        // 当用户组colleagues析构时，释放内存，聊天室里面维护的同事指针也需要remove
        for (auto const &c : colleagues) {
            mediator->removeColleague(c.second.get());
        }
    }

    return 0;
}