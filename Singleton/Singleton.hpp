#pragma once

class Singleton {
private:
	Singleton() = default;

public:
	static Singleton *GetInstance() {
		static Singleton instance;
		return &instance;
	}

	Singleton(Singleton const &other) = delete;
	Singleton(Singleton const &&other) = delete;
	Singleton &operator=(Singleton const &other) = delete;
	Singleton &operator=(Singleton const &&other) = delete;
};

static Singleton *sInstance = Singleton::GetInstance();