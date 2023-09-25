#include <iostream>

class ZooAnimal {
private:
    std::string nameOfAnimal;
    int birthYear;
    int cageNumber;
    float weightData;
    int height;

public:
    ZooAnimal(const std::string& a, int b, int c, float x, int h)
        : nameOfAnimal(a), birthYear(b), cageNumber(c), weightData(x), height(h) {}

    bool operator>(const ZooAnimal& a) const {
        return weightData > a.weightData;
    }

    bool operator<(const ZooAnimal& a) const {
        return weightData < a.weightData;
    }

    bool operator>=(const ZooAnimal& a) const {
        return weightData >= a.weightData;
    }

    bool operator<=(const ZooAnimal& a) const {
        return weightData <= a.weightData;
    }

    bool operator==(const ZooAnimal& a) const {
        return weightData == a.weightData;
    }

    bool operator!=(const ZooAnimal& a) const {
        return weightData != a.weightData;
    }

    ZooAnimal& operator+=(int x) {
        weightData += static_cast<float>(x);
        return *this;
    }

    ZooAnimal& operator-=(int x) {
        weightData -= static_cast<float>(x);
        return *this;
    }

    std::string getName() const {
        return nameOfAnimal;
    }

    int getBirthYear() const {
        return birthYear;
    }

    int getCageNumber() const {
        return cageNumber;
    }

    float getWeight() const {
        return weightData;
    }

    int getHeight() const {
        return height;
    }
};

int main() {
    ZooAnimal lion("Lion", 2015, 1, 250.5, 120);
    ZooAnimal elephant("Elephant", 2010, 2, 5000.0, 300);

    if (lion > elephant) {
        std::cout << "Lion is heavier than Elephant." << std::endl;
    } else {
        std::cout << "Lion is not heavier than Elephant." << std::endl;
    }

    lion += 10;
    elephant -= 100;

    std::cout << "Lion's new weight: " << lion.getWeight() << " kg" << std::endl;
    std::cout << "Elephant's new weight: " << elephant.getWeight() << " kg" << std::endl;

    return 0;
}
