#pragma once

#include <iostream>

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void AlgorithmInterface() override {
        std::cout << "Called ConcreteStrategyA's AlgorithmInterface" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void AlgorithmInterface() override {
        std::cout << "Called ConcreteStrategyB's AlgorithmInterface" << std::endl;
    }
};

class Context {
public:
    Context(Strategy* strategy)
            : m_strategy(strategy) {}
    void ContextInterface() {
        m_strategy->AlgorithmInterface();
    }

private:
    Strategy* m_strategy;
};