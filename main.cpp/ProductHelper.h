// ProductHelper.h
#ifndef PRODUCTHELPER_H
#define PRODUCTHELPER_H

#include "Product.h"
#include <vector>
#include <fstream>
#include <sstream>

class ProductHelper {
public:
    static Product createItemFromText(const std::string& line) {
        std::istringstream iss(line);
        std::string name;
        double price;
        int quantity;
        std::string token;

        // Parse comma-separated values
        std::getline(iss, name, ',');
        std::getline(iss, token, ',');
        price = std::stod(token);
        std::getline(iss, token, ',');
        quantity = std::stoi(token);

        return Product(name, price, quantity);
    }

    static double getTotalBalance(const std::vector<Product>& products) {
        double total = 0;
        for (const auto& product : products) {
            total += product.getTotalPrice();
        }
        // Add 20% VAT
        return total * 1.20;
    }

    static std::vector<Product> loadProductsFromFile(const std::string& filename) {
        std::vector<Product> products;
        std::ifstream file(filename);
        std::string line;
        
        while (std::getline(file, line)) {
            try {
                Product product = createItemFromText(line);
                products.push_back(product);
            } catch (const std::exception& e) {
                std::cerr << "Error creating product from line: " << line 
                          << ". " << e.what() << std::endl;
            }
        }
        
        file.close();
        return products;
    }
};

#endif // PRODUCTHELPER_H
