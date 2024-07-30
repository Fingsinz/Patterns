/*
 * Author: Fingsinz
 * Date: 2024.07.24
 *
 * 适配器模式：将一个类的接口转换成客户希望的另一个接口，充当两个不同接口的桥梁，让不兼容的类一起工作。
 *
 * 题目链接：https://kamacoder.com/problempage.php?pid=1085
 */

#include <iostream>
#include <memory>

class TypeC {
public:
    virtual void interface() {
        std::cout << "TypeC\n";
    }
};

class USB {
public:
    virtual void interface() {
        std::cout << "USB Adapter\n";
    }
};

// 适配器，适配上USB
class Adapter : public TypeC {
public:
    Adapter(USB *usb) {
        m_usb.reset(usb);
    }

    void interface() override {
        m_usb->interface();
    }

private:
    std::unique_ptr<USB> m_usb; // 包含一个USB引用，使其支持USB接口。
};

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int type;
        std::cin >> type;

        std::unique_ptr<TypeC> computer;

        if (type == 1) {
            // 无需适配器，new TypeC
            computer.reset(new TypeC());
        } else if (type == 2) {
            // 需要适配器，new Adapter(new USB())
            computer.reset(new Adapter(new USB()));
        }

        computer->interface();
    }
    return 0;
}