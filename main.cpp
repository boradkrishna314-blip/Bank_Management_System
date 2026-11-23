#include <iostream>
#include <fstream>
#include <string>

class BankAccount {
private:
    std::string name;
    double balance;

    // Saves the current account name and balance to accounts.txt
    void saveToFile() {
        std::ofstream outFile("accounts.txt");
        if (outFile.is_open()) {
            outFile << name << "\n" << balance << "\n";
            outFile.close();
        }
    }

public:
    BankAccount(std::string accountName, double initialBalance)
        : name(accountName), balance(initialBalance) {
        saveToFile();
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            saveToFile();
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            saveToFile();
            std::cout << "Withdrawn: $" << amount << std::endl;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    void display() {
        std::cout << "\nAccount: " << name << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    std::string name;
    double initialDeposit = 0.0;
    bool loaded = false;

    // Check if a saved account already exists in accounts.txt
    std::ifstream inFile("accounts.txt");
    if (inFile.is_open() && std::getline(inFile, name) && (inFile >> initialDeposit)) {
        loaded = true;
        inFile.close();
        std::cout << "Loaded existing account for: " << name << std::endl;
    } else {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
        std::cout << "Enter initial deposit: ";
        std::cin >> initialDeposit;
    }

    BankAccount account(name, initialDeposit);

    int choice;
    double amount;

    do {
        std::cout << "\n1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Display Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdraw amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.display();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
