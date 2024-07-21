#include <iostream>
#include <memory>
#include <vector>

class Block {
public:
	Block() = default;
	virtual ~Block() {};
	virtual void show() = 0;
};

class CircleBlock : public Block {
public:
	virtual ~CircleBlock() {}
	void show() override {
		std::cout << "Circle Block\n";
	}
};

class SquareBlock : public Block {
public:
	virtual ~SquareBlock() {}
	void show() override {
		std::cout << "Square Block\n";
	}
};

class Factory {
public:
	Factory() = default;
	virtual ~Factory() {};

	virtual Block *createProduct() = 0;
};

class CircleFactory : public Factory {
public:
	virtual ~CircleFactory() {}
	Block *createProduct() override {
		return new CircleBlock();
	}
};

class SquareFactory : public Factory {
public:
	virtual ~SquareFactory() {}
	Block *createProduct() override {
		return new SquareBlock();
	}
};

class BlockFactory {
public:
	BlockFactory() = default;

	void buildBlock(std::string type, int count) {
		std::unique_ptr<Factory> factory;
		if (type == "Circle") {
			factory.reset(new CircleFactory());
		} else if (type == "Square") {
			factory.reset(new SquareFactory());
		}

		for (int i = 0; i < count; i++) {
			if (factory) {
				std::unique_ptr<Block> block(factory->createProduct());
				m_block.push_back(std::move(block));
			}
		}
	}

	void showBlock() {
		for (auto &block : m_block) {
			block->show();
		}
	}

private:
	std::vector<std::unique_ptr<Block>> m_block;
};

int main() {
	BlockFactory blockFactory;

	int n;
	std::cin >> n;

	while (n--) {
		std::string type;
		int count;
		std::cin >> type >> count;
		blockFactory.buildBlock(type, count);
	}

	blockFactory.showBlock();

	return 0;
}