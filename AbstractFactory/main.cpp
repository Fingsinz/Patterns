#include <iostream>
#include <memory>

class Sofa {
public:
    virtual ~Sofa() = default;
    virtual void show() = 0;
};

class ModernSofa : public Sofa {
public:
    void show() override {
        std::cout << "modern sofa\n";
    }
};

class ClassicalSofa : public Sofa {
public:
    void show() override {
        std::cout << "classical sofa\n";
    }
};

class Chair {
public:
    virtual ~Chair() = default;
    virtual void show() = 0;
};

class ModernChair : public Chair {
public:
    void show() override {
        std::cout << "modern chair\n";
    }
};

class ClassicalChair : public Chair {
public:
    void show() override {
        std::cout << "classical chair\n";
    }
};

class Factory {
public:
    virtual ~Factory() = default;
    virtual Sofa *createSofa() = 0;
    virtual Chair *createChair() = 0;
};

class ModernFactory : public Factory {
public:
    Sofa *createSofa() override {
        return new ModernSofa();
    }
    Chair *createChair() override {
        return new ModernChair();
    }
};

class ClassicalFactory : public Factory {
public:
    Sofa *createSofa() override {
        return new ClassicalSofa();
    }
    Chair *createChair() override {
        return new ClassicalChair();
    }
};

class Orders {
public:
    void addOrder(std::string type) {
        std::unique_ptr<Factory> factory;

        if (type == "modern") {
            factory = std::make_unique<ModernFactory>();
        } else if (type == "classical") {
            factory = std::make_unique<ClassicalFactory>();
        }

        if (factory) {
            std::unique_ptr<Chair> chair(std::move(factory->createChair()));
            std::unique_ptr<Sofa> sofa(std::move(factory->createSofa()));
            chair->show();
            sofa->show();
        }
    }
};

int main() {
    Orders orders;

    int n;
    std::cin >> n;

    while (n--) {
        std::string type;
        std::cin >> type;
        orders.addOrder(type);
    }

    return 0;
}