#include <iostream>
#include <string>

class TradingSystem {
private:
    double balance;
    double stockPrice;

public:
    TradingSystem(double initialBalance) : balance(initialBalance), stockPrice(100.0) {}

    void displayMenu() {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Buy Stock" << std::endl;
        std::cout << "2. Sell Stock" << std::endl;
        std::cout << "3. Display Balance" << std::endl;
        std::cout << "4. Quit" << std::endl;
    }

    void buyStock(int quantity) {
        double cost = stockPrice * quantity;
        if (cost <= balance) {
            balance -= cost;
            std::cout << "Successfully bought " << quantity << " stocks." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy stocks." << std::endl;
        }
    }

    void sellStock(int quantity) {
        double revenue = stockPrice * quantity;
        balance += revenue;
        std::cout << "Successfully sold " << quantity << " stocks." << std::endl;
    }

    void displayBalance() {
        std::cout << "Current Balance: $" << balance << std::endl;
    }

    void run() {
        int choice;
        int quantity;

        do {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter quantity to buy: ";
                    std::cin >> quantity;
                    buyStock(quantity);
                    break;
                case 2:
                    std::cout << "Enter quantity to sell: ";
                    std::cin >> quantity;
                    sellStock(quantity);
                    break;
                case 3:
                    displayBalance();
                    break;
                case 4:
                    std::cout << "Exiting..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Try again." << std::endl;
                    break;
            }
        } while (choice != 4);
    }
};

int main() {
    double initialBalance;
    std::cout << "Enter initial balance: $";
    std::cin >> initialBalance;

    TradingSystem tradingSystem(initialBalance);
    tradingSystem.run();

    return 0;
}