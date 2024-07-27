#include <iostream>
#include <memory>
#include <vector>

// 组件
class Info {
public:
    Info(std::string name = "", int level = 0)
            : m_name(name)
            , m_level(level) {}

    virtual ~Info() = default;

    virtual void show() = 0;

    virtual void add(std::unique_ptr<Info> &info) = 0;

protected:
    std::string m_name;
    int m_level;
};

// 部门叶子节点
class Department : public Info {
public:
    Department(std::string name, int level)
            : Info(name, level) {}

    ~Department() = default;

    void show() override {
        for (int i = 0; i < m_level; ++i) {
            std::cout << "  ";
        }

        std::cout << m_name << std::endl;

        for (int i = 0; i < m_empolyee.size(); ++i) {
            m_empolyee[i]->show();
        }
    }

    void add(std::unique_ptr<Info> &emp) override {
        m_empolyee.emplace_back(std::move(emp));
    }

private:
    std::vector<std::unique_ptr<Info>> m_empolyee;
};

// 员工叶子节点
class Empolyee : public Info {
public:
    Empolyee(std::string name, int level)
            : Info(name, level) {}
    ~Empolyee() = default;

    void show() override {
        for (int i = 0; i < m_level; i++) {
            std::cout << "  ";
        }
        std::cout << m_name << std::endl;
    }

    void add(std::unique_ptr<Info> &) override {}
};

// 合成类， 作⽤是存储⼦部件，并且在Composite中实现了对⼦部件的相关操作，⽐如添加、删除等
class Company : public Info {
public:
    Company(std::string name = "My Company", int level = 0)
            : Info(name, level) {}
    ~Company() = default;

    void show() override {
        std::cout << "Company Structure:" << std::endl << m_name << std::endl;

        for (int i = 0; i < m_dep.size(); ++i) {
            m_dep[i]->show();
        }
    }

    void add(std::unique_ptr<Info> &dep) override {
        m_dep.emplace_back(std::move(dep));
    }

private:
    std::vector<std::unique_ptr<Info>> m_dep;
};

int main() {
    std::string c_name;
    int n;
    std::cin >> c_name >> n;

    Info *company = new Company(c_name, 0);
    Info *currDep = nullptr;

    while (n--) {
        char type;
        std::string name;
        std::cin >> type >> name;

        if (type == 'D') {
            std::unique_ptr<Info> info(new Department(name, 1));
            currDep = info.get();
            company->add(info);
        } else if (type == 'E') {
            std::unique_ptr<Info> info(new Empolyee(name, 2));
            currDep->add(info);
        }
    }

    currDep = nullptr;
    company->show();

    return 0;
}