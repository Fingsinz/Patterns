#include <iostream>
#include <memory>
#include <vector>

class Observer {
public:
    Observer(std::string name = "")
            : m_name(name) {}
    virtual ~Observer() = default;
    virtual void update(int time) = 0;

protected:
    std::string m_name;
};

class Student : public Observer {
public:
    Student(std::string name = "")
            : Observer(name) {}

    void update(int time) override {
        std::cout << m_name << " " << time << std::endl;
    }
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObserver() = 0;
    virtual void setTime() = 0;
};

class Clock : public Subject {
public:
    void registerObserver(Observer *observer) override {
        std::unique_ptr<Observer> ptr(observer);
        observers.push_back(std::move(ptr));
    }

    void removeObserver(Observer *observer) override {
        for (auto it = observers.begin(); it != observers.end(); it++) {
            if (it->get() == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObserver() override {
        for (auto &observer : observers) {
            observer->update(m_time);
        }
    }

    void setTime() override {
        m_time += 1;

        if (m_time == 24) {
            m_time = 0;
        }

        notifyObserver();
    }

private:
    std::vector<std::unique_ptr<Observer>> observers;
    int m_time = 0;
};

int main() {
    std::unique_ptr<Subject> clock = std::make_unique<Clock>();

    int numOfStudent;
    std::cin >> numOfStudent;
    while (numOfStudent--) {
        std::string name;
        std::cin >> name;
        Observer *stu = new Student(name);

        clock->registerObserver(stu);
    }

    int updateTimes;
    std::cin >> updateTimes;
    while (updateTimes--) {
        clock->setTime();
    }

    return 0;
}