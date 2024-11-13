// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <ctime>

class Product {
private:
    std::string name;
    double price;
    int quantity;

    // Kapsülleme için setter methodları
    void setName(const std::string& name) {
        if (name.length() >= 3 && name.length() <= 8) {
            this->name = name;
        } else {
            throw std::invalid_argument("Name should be between 3 and 8 characters.");
        }
    }

    void setPrice(double price) {
        if (price >= 0) {
            this->price = price;
        } else {
            throw std::invalid_argument("Price cannot be negative.");
        }
    }

    void setQuantity(int quantity) {
        if (quantity >= 1) {
            this->quantity = quantity;
        } else {
            throw std::invalid_argument("Quantity must be at least 1.");
        }
    }

public:
    // Constructors
    Product() : name("Unknown"), price(0), quantity(1) {
        printCreationMessage();
    }

    Product(const std::string& name) : price(0), quantity(1) {
        setName(name);
        printCreationMessage();
    }

    Product(const std::string& name, double price) : quantity(1) {
        setName(name);
        setPrice(price);
        printCreationMessage();
    }

    Product(const std::string& name, double price, int quantity) {
        setName(name);
        setPrice(price);
        setQuantity(quantity);
        printCreationMessage();
    }

    double getTotalPrice() const {
        return price * quantity;
    }

    // Overloaded << operator for custom output
    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        os << "Product: " << product.name << ", Price: " << product.price 
           << ", Quantity: " << product.quantity;
        return os;
    }

private:
    void printCreationMessage() const {
        std::time_t now = std::time(nullptr);
        std::cout << "Product '" << name << "' created at " 
                  << std::ctime(&now) << std::endl;
    }
};

#endif // PRODUCT_H
