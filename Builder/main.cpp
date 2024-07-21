#include <iostream>
#include <memory>

class Bicycle {
public:
    void setFrame(const std::string& frame) {
        m_frame = frame;
    }
    void setTires(const std::string& tires) {
        m_tires = tires;
    }

    void getInfo() {
        std::cout << m_frame << " Frame " << m_tires << " Tires" << std::endl;
    }

private:
    std::string m_frame;
    std::string m_tires;
};

class Builder {
public:
    virtual ~Builder() = default;
    virtual void setFrame() = 0;
    virtual void setTires() = 0;
    virtual Bicycle getBicycle() = 0;
};

class MotorcycleBuilder : public Builder {
public:
    void setFrame() override {
        m_bicycle.setFrame("Aluminum");
    }
    void setTires() override {
        m_bicycle.setTires("Knobby");
    }
    Bicycle getBicycle() override {
        return m_bicycle;
    }

private:
    Bicycle m_bicycle;
};

class RoadBikeBuilder : public Builder {
public:
    void setFrame() override {
        m_bicycle.setFrame("Carbon");
    }
    void setTires() override {
        m_bicycle.setTires("Slim");
    }
    Bicycle getBicycle() override {
        return m_bicycle;
    }

private:
    Bicycle m_bicycle;
};

class Director {
public:
    void construct(Builder* builder) {
        builder->setFrame();
        builder->setTires();
    }
};

int main() {
    int n;
    std::cin >> n;

    Director* director = new Director();

    std::string type;
    while (n--) {
        std::cin >> type;

        std::unique_ptr<Builder> builder;
        if (type == "mountain") {
            builder.reset(new MotorcycleBuilder());
        } else if (type == "road") {
            builder.reset(new RoadBikeBuilder());
        }

        director->construct(builder.get());

        Bicycle bicycle = builder->getBicycle();
        bicycle.getInfo();
    }

    return 0;
}