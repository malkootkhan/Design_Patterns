#include <iostream>
#include <string>

using namespace std;

// Product Interface
class Product {
public:
    virtual ~Product() {}
    virtual void productLookLike() = 0;
};

// Concrete Product: Smartphone
class Smartphone : public Product {
public:
    void productLookLike() override {
        cout << "this is our Smartphone product" << endl;
    }
};

// Concrete Product: Computer
class Computer : public Product {
public:
    void productLookLike() override {
        cout << "this is our Computer product" << endl;
    }
};

// Creator Class
class Factory {
public:
    virtual ~Factory() {}
    virtual Product* createProduct() = 0;
};

// Concrete Creator: Smartphone Creator
class SmartphoneFactory : public Factory {
public:
    Product* createProduct() override {
        return new Smartphone();
    }
};

// Concrete Creator: Computer Creator
class ComputerFactory : public Factory {
public:
    Product* createProduct() override {
        return new Computer();
    }
};

int main() {
    Factory* myFactory = nullptr;
    Product* myProduct = nullptr;

    // Create a Smartphone
    myFactory = new SmartphoneFactory();
    myProduct = myFactory->createProduct();
    myProduct->productLookLike();
    delete myProduct;
    delete myFactory;

    // Create a Computer
    myFactory = new ComputerFactory();
    myProduct = myFactory->createProduct();
    myProduct->productLookLike();
    delete myProduct;
    delete myFactory;

    return 0;
}
