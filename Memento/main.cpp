/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 备忘录模式：不暴露对象实际内部状态的情况下保存状态到另一对象。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1095
 */

#include <iostream>
#include <memory>
#include <vector>

// 备忘录
class Memento {
public:
    Memento(int cnt = 0)
            : m_cnt(cnt) {}

    int getCnt() const {
        return m_cnt;
    }

private:
    int m_cnt = 0;
};

// 发起者，此处是计数器
class Counter {
public:
    void increment() {
        m_cnt += 1;
    }

    void decrement() {
        m_cnt -= 1;
    }

    int getCnt() const {
        return m_cnt;
    }

    std::unique_ptr<Memento> createMemento() {
        std::unique_ptr<Memento> memento(new Memento(m_cnt));
        return std::move(memento);
    }

    void restoreFromMemento(Memento *memento) {
        m_cnt = memento->getCnt();
    }

private:
    int m_cnt = 0; // 计数器值
};

// 管理者
class Caretaker {
public:
    void addMemento(std::unique_ptr<Memento> memento = nullptr) {
        m_mementos.emplace_back(std::move(memento));
        curIdx = m_mementos.size() - 1;
    }

    void undo() {
        if (curIdx > 1) {
            curIdx -= 1;
        }
    }

    void redo() {
        if (curIdx < m_mementos.size() - 1) {
            curIdx += 1;
        }
    }

    Memento *getMemento(int idx) const {
        if (idx >= 0 && idx < m_mementos.size())
            return m_mementos[idx].get();
    }

    Memento *getMemento() const {
        return m_mementos[curIdx].get();
    }

private:
    std::vector<std::unique_ptr<Memento>> m_mementos; // 备忘录组
    int curIdx = -1;                                  // 当前状态所指备忘录下标
};

int main() {
    std::string op;

    Counter counter;
    Caretaker caretaker;
    caretaker.addMemento(std::move(counter.createMemento()));

    while (std::cin >> op) {
        if (op == "Increment") {
            counter.increment();
            caretaker.addMemento(std::move(counter.createMemento()));
        } else if (op == "Decrement") {
            counter.decrement();
            caretaker.addMemento(std::move(counter.createMemento()));
        } else if (op == "Undo") {
            caretaker.undo();
            counter.restoreFromMemento(caretaker.getMemento());
        } else if (op == "Redo") {
            caretaker.redo();
            counter.restoreFromMemento(caretaker.getMemento());
        }
        std::cout << counter.getCnt() << std::endl;
    }

    return 0;
}