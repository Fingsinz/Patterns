#pragma once

#include <iostream>

class Product {
public:
    void setPart1(const std::string& part1) {
        this->part1 = part1;
    }

    void setPart2(const std::string& part2) {
        this->part2 = part2;
    }

    std::string getProduct() const {
        return part1 + " " + part2;
    }

private:
    std::string part1;
    std::string part2;
};

class Builder {
public:
    virtual ~Builder() = default;
    virtual void buildPart1() = 0;
    virtual void buildPart2() = 0;
    virtual Product* getProduct() = 0;
};

class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() {
        product = new Product();
    }

    ~ConcreteBuilder() {
        delete product;
    }

    void buildPart1() override {
        product->setPart1("Part1");
    }

    void buildPart2() override {
        product->setPart2("Part2");
    }

    Product* getProduct() override {
        return product;
    }

private:
    Product* product = nullptr;
};

class Director {
public:
    void construct(Builder* builder) {
        builder->buildPart1();
        builder->buildPart2();
    }
};