#pragma once

#include <iostream>

class Prototype {
public:
    virtual ~Prototype() = default;

    virtual Prototype *clone() = 0;
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype() = default;
    virtual ~ConcretePrototype() = default;

    ConcretePrototype(const ConcretePrototype &prototype) {
        this->data = prototype.data;
    }

    virtual Prototype *clone() override {
        return new ConcretePrototype(*this);
    }

    void setData(const std::string &data) {
        this->data = data;
    }

    std::string getData() const {
        return data;
    }

private:
    std::string data;
};