#include <iostream>
#include <memory>

class House {
public:
	House(int area = 0) : m_area(area) {}

	virtual ~House() = default;
	virtual bool isBig() const = 0;

protected:
	int m_area;
};

class RealHouse : public House {
public:
	RealHouse(int area) : House(area) {}

	bool isBig() const override {
		return m_area > 100;
	}
};

class Proxy : House {
public:
	Proxy(int size) {
		m_house.reset(new RealHouse(size));
	}

	bool isBig() const override {
		return m_house->isBig();
	}

private:
	std::unique_ptr<RealHouse> m_house;
};

int main() {
	int n;
	std::cin >> n;

	while (n --) {
		int size;
		std::cin >> size;
		Proxy house(size);
		if (house.isBig()) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}