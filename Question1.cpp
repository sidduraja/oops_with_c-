#include <bits/stdc++.h>
using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;

public:
    Product(int id, string n, double p) : productId(id), name(n), price(p) {}

    Product comparePrice(const Product& other) const {
        if (this->price >= other.price) {
            return *this;
        } else {
            return other;
        }
    }

    void display() const {
        cout << "Product ID: " << productId << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    Product p1(101, "Laptop", 899.99);
    Product p2(102, "Smartphone", 1099.49);

    Product higher = p1.comparePrice(p2);

    cout << "Higher priced product details:" << endl;
    higher.display();

    return 0;
}
