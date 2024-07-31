#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.31
 *
 * 访问者模式：在不改变对象结构的前提下，对对象中的元素进行新的操作。
 */

#include <iostream>
#include <vector>

class Visitor;

// 抽象元素类
class Element {
public:
    virtual ~Element() = default;
    virtual void accept(Visitor *visitor) = 0;
};

// 具体元素 A
class ConcreteElementA : public Element {
public:
    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }
};

// 具体元素 B
class ConcreteElementB : public Element {
public:
    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }
};

// 抽象访问者
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(ConcreteElementA *element) = 0;
    virtual void visit(ConcreteElementB *element) = 0;
};

// 抽象访问者 A
class ConcreteVisitorA : public Visitor {
public:
    void visit(ConcreteElementA *element) override {
        std::cout << "ConcreteVisitorA visit ConcreElementA\n";
    }

    void visit(ConcreteElementB *element) override {
        std::cout << "ConcreteVisitorA visit ConcreElementB\n";
    }
};

// 抽象访问者 B
class ConcreteVisitorB : public Visitor {
public:
    void visit(ConcreteElementA *element) override {
        std::cout << "ConcreteVisitorB visit ConcreElementA\n";
    }

    void visit(ConcreteElementB *element) override {
        std::cout << "ConcreteVisitorB visit ConcreElementB\n";
    }
};

// 对象结构
class ObjectStructure {
public:
    void attach(Element *element) {
        m_elements.emplace_back(element);
    }

    void detach(Element *element) {
        auto it = std::find(m_elements.begin(), m_elements.end(), element);
        if (it != m_elements.end()) {
            m_elements.erase(it);
        }
    }

    void accept(Visitor *visitor) {
        for (Element *element : m_elements) {
            element->accept(visitor);
        }
    }

private:
    std::vector<Element *> m_elements;
};