#include <iostream>
#include <memory>

class Discount {
public:
    virtual ~Discount() = default;
    virtual void apply(int price) = 0;
};

class TenPercentDiscount : public Discount {
public:
    void apply(int price) override {
        std::cout << static_cast<int>(price * 0.9) << std::endl;
    }
};

class FullDiscount : public Discount {
public:
    void apply(int price) {
        if (price >= 300) {
            price -= 40;
        } else if (price >= 200) {
            price -= 25;
        } else if (price >= 150) {
            price -= 15;
        } else if (price >= 100) {
            price -= 5;
        }

        std::cout << price << std::endl;
    }
};

class Context {
public:
    void setDiscount(Discount *discount) {
        m_discount = std::unique_ptr<Discount>(discount);
    }

    void applyDiscount(int price) {
        m_discount->apply(price);
    }

private:
    std::unique_ptr<Discount> m_discount;
};

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int price, type;
        std::cin >> price >> type;

        Context context;
        if (type == 1) {
            context.setDiscount(new TenPercentDiscount());
        } else if (type == 2) {
            context.setDiscount(new FullDiscount());
        }

        context.applyDiscount(price);
    }

    return 0;
}