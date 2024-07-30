/*
 * Author: Fingsinz
 * Date: 2024.07.30
 *
 * 迭代器模式：提供一种统一的方式访问一个聚合对象中的各个元素
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1099
 */

#include <iostream>
#include <memory>
#include <vector>

// 抽象迭代器
template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

// 具体迭代器
template <typename T>
class ConcreteIterator : public Iterator<T> {
public:
    ConcreteIterator(std::vector<T> elements)
            : m_elements(elements)
            , m_idx(0) {}

    bool hasNext() override {
        return m_idx < m_elements.size();
    }

    T next() override {
        if (hasNext()) {
            return m_elements[m_idx++];
        }
        return T();
    }

private:
    int m_idx;
    std::vector<T> m_elements;
};

// 抽象聚合
template <typename T>
class Iterable {
public:
    virtual ~Iterable() = default;
    virtual Iterator<T> *createIterator() = 0;
};

// 具体聚合
template <typename T>
class StudentList : public Iterable<T> {
public:
    void addElement(T data) {
        m_elements.push_back(data);
    }

    Iterator<T> *createIterator() override {
        return new ConcreteIterator<T>(m_elements);
    }

private:
    std::vector<T> m_elements;
};

// 本题中的特殊数据结构
struct Student {
    std::string name;
    std::string no;
};

int main() {
    int n;
    std::cin >> n;

    StudentList<Student> list;

    while (n--) {
        std::string name, no;
        std::cin >> name >> no;

        list.addElement({name, no});
    }

    {
        std::unique_ptr<Iterator<Student>> iter(list.createIterator());
        while (iter->hasNext()) {
            auto s = iter->next();
            std::cout << s.name << " " << s.no << std::endl;
        }
    }

    return 0;
}