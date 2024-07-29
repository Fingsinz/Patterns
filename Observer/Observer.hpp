#pragma once

#include <iostream>
#include <vector>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(std::string message) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObserver() = 0;
};

class ConcreteSubject : public Subject {
public:
    ~ConcreteSubject() = default;
    void registerObserver(Observer *observer) override {
        observers.emplace_back(observer);
    }

    void removeObserver(Observer *observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObserver() override {
        for (auto &observer : observers) {
            observer->update(state);
        }
    }

    void setState(std::string state) {
        this->state = state;
        notifyObserver();
    }

private:
    std::vector<Observer *> observers;
    std::string state;
};

class ConcreteObserver : public Observer {
public:
    ~ConcreteObserver() = default;
    void update(std::string message) override {
        std::cout << "ConcreteObserver: " << message << std::endl;
    }
};