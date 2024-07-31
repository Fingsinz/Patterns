/*
 * Author: Fingsinz
 * Date: 2024.07.31
 *
 * 解释器模式：定义了语言的文法，并且建立一个解释器解释句子。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1096
 */

#include <iostream>
#include <memory>
#include <sstream>
#include <stack>

// 抽象表达式
class Expression {
public:
    virtual ~Expression() = default;
    virtual int interpret() = 0;
};

// 终结符表达式
class Number : public Expression {
public:
    Number(int value = 0)
            : m_value(value) {}

    int interpret() override {
        return m_value;
    }

private:
    int m_value;
};

// 非终结符表达式：加法
class AddExpression : public Expression {
public:
    AddExpression(Expression *left = nullptr, Expression *right = nullptr)
            : m_left(left)
            , m_right(right) {}

    int interpret() override {
        return m_left->interpret() + m_right->interpret();
    }

private:
    Expression *m_left;
    Expression *m_right;
};

// 非终结符表达式：乘法
class MultiplyExpression : public Expression {
public:
    MultiplyExpression(Expression *left = nullptr, Expression *right = nullptr)
            : m_left(left)
            , m_right(right) {}

    int interpret() override {
        return m_left->interpret() * m_right->interpret();
    }

private:
    Expression *m_left;
    Expression *m_right;
};

// 上下文类，此处负责处理表达式并计算
class Context {
public:
    /*
     * @brief 将中缀表达式转换为后缀表达式
     * @param input 中缀表达式
     */
    void toPostfix(std::string const input) {
        std::stack<char> ops;
        std::stringstream output;

        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] == ' ') {
                continue;
            } else if (input[i] >= '0' and input[i] <= '9') {
                while (input[i] >= '0' and input[i] <= '9' and i < input.size()) {
                    output << input[i];
                    i += 1;
                }
                i -= 1; // 处理边界
                output << " ";
            } else {
                if (ops.empty()) {
                    ops.push(input[i]);
                } else if (input[i] == '(') {
                    ops.push(input[i]);
                } else if (input[i] == ')') {
                    while (ops.top() != '(') {
                        output << ops.top();
                        ops.pop();
                    }
                    ops.pop();
                } else {
                    while (!ops.empty() and prio(input[i]) <= prio(ops.top())) {
                        output << ops.top();
                        ops.pop();
                    }
                    ops.push(input[i]);
                }
            }
        }

        while (!ops.empty()) {
            output << ops.top();
            ops.pop();
        }

        postExp = output.str();
    }

    /*
     * @brief 计算后缀表达式
     * @return 计算结果
     */
    int calculate() {
        for (size_t i = 0; i < postExp.size(); ++i) {
            if (postExp[i] >= '0' and postExp[i] <= '9') {
                int d = 0;
                while (postExp[i] >= '0' and postExp[i] <= '9' and i < postExp.size()) {
                    d = 10 * d + postExp[i] - '0';
                    i += 1;
                }
                push(std::move(std::make_unique<Number>(d)));
            } else if (postExp[i] == '+') {
                std::unique_ptr<Expression> num1 = top();
                pop();
                std::unique_ptr<Expression> num2 = top();
                pop();
                std::unique_ptr<Expression> tmp(new AddExpression(num1.get(), num2.get()));
                std::unique_ptr<Expression> ans(new Number(tmp->interpret()));
                push(std::move(ans));
            } else if (postExp[i] == '*') {
                std::unique_ptr<Expression> num1 = top();
                pop();
                std::unique_ptr<Expression> num2 = top();
                pop();
                std::unique_ptr<Expression> tmp(new MultiplyExpression(num1.get(), num2.get()));
                std::unique_ptr<Expression> ans(new Number(tmp->interpret()));
                push(std::move(ans));
            } // 加减乘除
        }
        return top()->interpret();
    }

private:
    // 算术符的优先级
    static int prio(char op) {
        switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
        }
    }

    /*
     * @brief 表达式栈压栈
     * @param expr 表达式
     */
    void push(std::unique_ptr<Expression> expr) {
        m_stack.push(std::move(expr));
    }

    /*
     * @brief 获取表达式栈栈顶
     * @return 栈顶表达式
     */
    std::unique_ptr<Expression> top() {
        return std::move(m_stack.top());
    }

    /*
     * @brief 表达式出栈
     */
    void pop() {
        m_stack.pop();
    }

private:
    std::stack<std::unique_ptr<Expression>> m_stack; // 表达式栈
    std::string postExp;                             // 后缀表达式
};

int main() {
    std::string exp;

    while (std::getline(std::cin, exp)) {
        Context context;
        context.toPostfix(exp);
        std::cout << context.calculate() << std::endl;
    }

    return 0;
}