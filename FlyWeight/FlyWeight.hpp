#pragma once

#include <iostream>
#include <map>

class FlyWeight {
public:
    virtual ~FlyWeight() = default;
    virtual void operation(std::string externalState) = 0;
};

class ConcreteFlyWeight : public FlyWeight {
public:
    ConcreteFlyWeight(std::string const& state)
            : m_state(state) {}

    void operation(std::string externalState) override {
        std::cout << "ConcreteFlyWeight: " << m_state << " " << externalState << std::endl;
    }

private:
    std::string m_state; // 内部状态
};

class FlyWeightFactory {
public:
    FlyWeight* getFlyWeight(std::string key) {
        if (m_flyweights.find(key) == m_flyweights.end()) {
            FlyWeight* flyweight = new ConcreteFlyWeight(key);
            m_flyweights[key] = flyweight;
        }
        return m_flyweights[key];
    }

private:
    std::map<std::string, FlyWeight*> m_flyweights;
};