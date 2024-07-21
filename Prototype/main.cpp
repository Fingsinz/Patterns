#include <iostream>
#include <memory>

class Prototype {
public:
	virtual ~Prototype() = default;
	virtual Prototype *clone() = 0;
	virtual void print() = 0;
};

class Rectangle : public Prototype {
public:
	Rectangle(std::string const &color, int width, int height)
		: m_color(color)
		, m_width(width)
		, m_height(height) {}
	virtual ~Rectangle() = default;

	Prototype *clone() override {
		return new Rectangle(this->m_color, this->m_width, this->m_height);
	}

	void print() {
		std::cout << "Color: " << m_color << ", Width: " << m_width << ", Height: " << m_height << std::endl;
	}

private:
	std::string m_color;
	int m_width = 0;
	int m_height = 0;
};

int main() {
	std::string color;
	int w, h;
	std::cin >> color >> w >> h;
	std::unique_ptr<Prototype> rectangle = std::make_unique<Rectangle>(color, w, h);

	int n;
	std::cin >> n;

	for (size_t i = 0; i < n; ++i) {
		std::unique_ptr<Prototype> clone(rectangle->clone());
		clone->print();
	}

	return 0;
}