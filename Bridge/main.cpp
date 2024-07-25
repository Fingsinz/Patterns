#include <iostream>
#include <memory>

class TV {
public:
	virtual void on() = 0;
	virtual void off() = 0;
	virtual void switchChannel() = 0;
	virtual ~TV() {}
};

class SonyTV : public TV {
public:
	void on() {
		std::cout << "Sony TV is ON" << std::endl;
	}

	void off() {
		std::cout << "Sony TV is OFF" << std::endl;
	}

	void switchChannel() {
		std::cout << "Switching Sony TV channel" << std::endl;
	}
};

class TCLTV : public TV {
public:
	void on() {
		std::cout << "TCL TV is ON" << std::endl;
	}

	void off() {
		std::cout << "TCL TV is OFF" << std::endl;
	}

	void switchChannel() {
		std::cout << "Switching TCL TV channel" << std::endl;
	}
};

class Operation {
public:
	Operation(TV *tv) : m_tv(std::move(tv)) {}

	virtual void work() = 0;

	virtual ~Operation() {}

protected:
	std::unique_ptr<TV> m_tv;
};

class TurnOn : public Operation {
public:
	TurnOn(TV *tv) : Operation(tv) {}
	void work() override {
		m_tv->on();
	}
};

class TurnOff : public Operation {
public:
	TurnOff(TV *tv) : Operation(tv) {}
	void work() override {
		m_tv->off();
	}
};

class SwitchChannel : public Operation {
public:
	SwitchChannel(TV *tv) : Operation(tv) {}
	void work() override {
		m_tv->switchChannel();
	}
};

int main() {
	int n;
	std::cin >> n;

	while (n--) {
		int type, op;
		std::cin >> type >> op;

		TV *tv = nullptr;

		if (type == 0) {
			tv = new SonyTV;
		} else if (type == 1) {
			tv = new TCLTV;
		}

		std::unique_ptr<Operation> oper;
		if (op == 2) {
			oper.reset(new TurnOn(tv));
		} else if (op == 3) {
			oper.reset(new TurnOff(tv));
		} else if (op == 4) {
			oper.reset(new SwitchChannel(tv));
		}

		oper->work();
	}
}