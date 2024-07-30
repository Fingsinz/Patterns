#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 备忘录模式：不暴露对象实际内部状态的情况下保存状态到另一对象。
 */

#include <iostream>
#include <vector>

// 备忘录
class Memento {
public:
    Memento(std::string state)
            : m_state(state) {}

    std::string getState() const {
        return m_state;
    }

private:
    std::string m_state;
};

// 发起人
class Originator {
public:
    void setState(std::string state) {
        m_state = state;
    }

    std::string getState() const {
        return m_state;
    }

    Memento *createMemento() {
        return new Memento(m_state);
    }

    void restoreFromMemento(Memento *memento) {
        m_state = memento->getState();
    }

private:
    std::string m_state;
};

// 管理者
class Caretaker {
public:
    void addMemento(Memento *memento) {
        m_mementos.emplace_back(memento);
    }

    Memento *getMemento(int idx) {
        if (idx >= 0 && idx < m_mementos.size())
            return m_mementos[idx];
    }

private:
    std::vector<Memento *> m_mementos;
};