#include <atomic>
#include <iostream>
#include <mutex>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class ShoppingCart {
private:
    ShoppingCart() = default;

public:
    ~ShoppingCart() = default;

    ShoppingCart(ShoppingCart const &other) = delete;
    ShoppingCart(ShoppingCart const &&other) = delete;
    ShoppingCart &operator=(ShoppingCart const &other) = delete;
    ShoppingCart &operator=(ShoppingCart const &&other) = delete;

    static ShoppingCart *GetInstance() {
        ShoppingCart *cart = mAtomic.load();
        if (cart == nullptr) {
            std::unique_lock<std::mutex> lock(mMutex);
            cart = mAtomic.load();
            if (cart == nullptr) {
                cart = new ShoppingCart;
                mAtomic.store(cart);
            }
        }
        return cart;
    }

    void addItem(std::string item, int cnt) {
        if (item.empty() or cnt <= 0)
            return;
        order.push_back(item);
        items[item] += cnt;
    }

    void showItem() {
        for (std::string const &item : order) {
            cout << item << " " << items[item] << endl;
        }
    }

private:
    std::unordered_map<std::string, int> items; // 保存购物车物品和数量
    std::vector<std::string> order;             // 保证购物车物品顺序

    static std::mutex mMutex;                   // 保证线程安全
    static std::atomic<ShoppingCart *> mAtomic; // 保证线程安全
};

std::atomic<ShoppingCart *> ShoppingCart::mAtomic;
std::mutex ShoppingCart::mMutex;

int main() {
    int cnt;
    std::string name;
    while (cin >> name >> cnt) {
        ShoppingCart::GetInstance()->addItem(name, cnt);
    }

    ShoppingCart::GetInstance()->showItem();

    return 0;
}