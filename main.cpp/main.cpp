// main.cpp
#include "Models/Product.h"
#include "Helpers/ProductHelper.h"
#include <vector>
#include <iostream>

int main() {
    // Products.txt dosyasından ürünleri yükle
    std::vector<Product> products = ProductHelper::loadProductsFromFile("Products.txt");

    // Her bir ürünü ekrana yazdır
    for (const auto& product : products) {
        std::cout << product << std::endl;
    }

    // Toplam bakiye hesapla
    double totalBalance = ProductHelper::getTotalBalance(products);
    std::cout << "Total balance with VAT: " << totalBalance << std::endl;

    return 0;
}
