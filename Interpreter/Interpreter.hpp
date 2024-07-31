#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.31
 *
 * 解释器模式：定义了语言的文法，并且建立一个解释器解释句子。
 */

#include <iostream>

// 抽象表达式
class Expression {
public:
    virtual ~Expression() = default;
    virtual int interpret() = 0;
};

// 终结符表达式
class TerminalExpression : public Expression {
public:
    TerminalExpression(int value)
            : m_value(value) {}

    int interpret() override {
        return m_value;
    }

private:
    int m_value;
};

// 非终结符表达式，此处举例为加法
class AddExpression : public Expression {
public:
    AddExpression(Expression *left, Expression *right)
            : m_left(left)
            , m_right(right) {}

    int interpret() override {
        return m_left->interpret() + m_right->interpret();
    }

private:
    Expression *m_left;
    Expression *m_right;
};

class Context {
public:
    // 存储一些全局信息或状态
};