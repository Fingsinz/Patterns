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
    virtual T *next() = 0;
};

// 具体迭代器
template <typename T>
class ConcreteIterator : public Iterator<T> {
public:
    ConcreteIterator(std::vector<T *> elements)
            : m_elements(elements)
            , m_idx(0) {}

    bool hasNext() override {
        return m_idx < m_elements.size();
    }

    T *next() override {
        if (hasNext()) {
            return m_elements[m_idx++];
        }
        return nullptr;
    }

private:
    int m_idx;
    // 使用裸指针，仅访问数据，不管理内存
    std::vector<T *> m_elements;
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
    void addElement(T *data) {
        std::unique_ptr<T> ptr(data);
        m_elements.emplace_back(std::move(ptr));
    }

    Iterator<T> *createIterator() override {
        // 将智能指针转为裸指针，提供给迭代器
        std::vector<T *> elements;
        for (std::unique_ptr<T> &ptr : m_elements) {
            elements.emplace_back(ptr.get());
        }
        return new ConcreteIterator<T>(elements);
    }

private:
    // 智能指针管理数据内存，实际数据内存应在聚合中管理。
    std::vector<std::unique_ptr<T>> m_elements;
};

// 本题中的特殊数据结构
struct Student {
    std::string name;
    std::string no;

    Student(std::string _name, std::string _no)
            : name(_name)
            , no(_no) {}

    void print() const {
        std::cout << name << " " << no << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    StudentList<Student> list;

    while (n--) {
        std::string name, no;
        std::cin >> name >> no;

        Student *stu = new Student(name, no);
        list.addElement(stu);
    }

    {
        std::unique_ptr<Iterator<Student>> iter(list.createIterator());
        while (iter->hasNext()) {
            auto s = iter->next();
            s->print();
        }
    }

    return 0;
}