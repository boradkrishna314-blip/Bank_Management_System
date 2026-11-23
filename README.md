# Bank Management System (C++ OOP & File Handling)

A console-based **Bank Management Application** built in C++ using Object-Oriented Programming (OOP) and file handling (`<fstream>`). The program simulates core banking operations—including deposits, withdrawals, and balance checks—while persisting customer account data locally in a text file.

## Features

- **Account Initialization & Persistence:** Automatically loads an existing account from `accounts.txt` or initializes a new customer account with an opening deposit.
- **Deposit Funds:** Add funds to the account with validation for positive amounts and immediate file synchronization.
- **Withdraw Funds:** Deduct funds with built-in overdraft protection (`Insufficient funds` check) and automatic balance updates.
- **Balance Inquiry:** View the current account holder's name and available balance.

## Project Structure

```text
Bank-Management-System/
├── main.cpp             # Complete C++ source code (BankAccount class & menu)
├── accounts.txt         # Auto-generated file storing persistent customer balance
├── README.md            # Project documentation
└── .gitignore           # Git ignore rules for binaries and runtime data
