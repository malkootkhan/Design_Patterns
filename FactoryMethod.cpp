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



class Delivery
{
    public:
        virtual ~Delivery() {}
        string CarriageType;
        virtual void carriage() = 0;
    
};
class Truck:public Delivery
{
    public:
        void carriage() override
        {
            CarriageType = "Truck";
            cout<<CarriageType<<" is used to deliver the product"<<endl;
        }
};

class Ship:public Delivery
{
    public:
        void carriage() override
        {
            CarriageType = "Ship";
            cout<<CarriageType<<" is used to deliver the product"<<endl;
        }
};


// Creator Class
class Factory {
public:
    virtual ~Factory() {}
    virtual Product* createProduct() = 0;
    virtual Delivery* createTransport() = 0;
};

// Concrete Creator: Smartphone Creator
class SmartphoneFactory : public Factory {
public:
    Product* createProduct() override {
        return new Smartphone();
    }
    Delivery* createTransport() override {
      return new Truck();  
    }
};

// Concrete Creator: Computer Creator
class ComputerFactory : public Factory {
public:
    Product* createProduct() override {
        return new Computer();
    }
    Delivery* createTransport() override {
        return new Ship();
    }
};



int main() {
    Factory* myFactory = nullptr;
    Product* myProduct = nullptr;
    Delivery* myDelivery = nullptr;

    // Create a Smartphone
    myFactory = new SmartphoneFactory();
    myProduct = myFactory->createProduct();
    myDelivery = myFactory->createTransport(); //creating an object that will perform the delivery meachanisms
    myProduct->productLookLike();
    myDelivery->carriage();
    delete myProduct;
    delete myDelivery;
    delete myFactory;
    

    // Create a Computer
    myFactory = new ComputerFactory();
    myProduct = myFactory->createProduct();
    myDelivery = myFactory->createTransport(); //creating an object that will perform the delivery meachanisms
    myProduct->productLookLike();
    myDelivery->carriage();
    delete myProduct;
    delete myDelivery;
    delete myFactory;

    return 0;
}
