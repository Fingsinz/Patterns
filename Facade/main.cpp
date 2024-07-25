#include <iostream>

class AirConditioner {
public:
	void turnOff() {}
};

class DeskLamp {
public:
	void turnOff() {}
};

class Television {
public:
	void turnOff() {}
};

class Facade {
public:

	void turnOffAirConditioner() {
		airConditioner.turnOff();
		std::cout << "Air Conditioner is turned off." << std::endl;
	}

	void turnOffDeskLamp() {
		deskLamp.turnOff();
		std::cout << "Desk Lamp is turned off." << std::endl;
	}

	void turnOffTelevision() {
		television.turnOff();
		std::cout << "Television is turned off." << std::endl;
	}

	void turnOffEverything() {
		airConditioner.turnOff();
		deskLamp.turnOff();
		television.turnOff();
		std::cout << "All devices are off." << std::endl;
	}

private:
	AirConditioner airConditioner;
	DeskLamp deskLamp;
	Television television;
};

int main() {
	int n;
	std::cin >> n;

	Facade facade{};
	while (n --) {
		int type;
		std::cin >> type;

		if (type == 1) {
			facade.turnOffAirConditioner();
		} else if (type == 2) {
			facade.turnOffDeskLamp();
		} else if (type == 3) {
			facade.turnOffTelevision();
		} else if (type == 4) {
			facade.turnOffEverything();
		}
	}

	return 0;
}