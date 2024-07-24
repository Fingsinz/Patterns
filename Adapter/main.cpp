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

class Adapter : public TypeC {
public:
	Adapter(USB *usb) {
		m_usb.reset(usb);
	}

	void interface() override {
		m_usb->interface();
	}

private:
	std::unique_ptr<USB> m_usb;
};

int main() {
	int n;
	std::cin >> n;

	while (n --) {
		int type;
		std::cin >> type;

		if (type == 1) {
			std::unique_ptr<TypeC> computer(new TypeC());
			computer->interface();
		} else if (type == 2) {
			std::unique_ptr<Adapter> adapterComputer(new Adapter(new USB()));
			adapterComputer->interface();
		}
	}
	return 0;
}