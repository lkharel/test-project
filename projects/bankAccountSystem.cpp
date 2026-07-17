#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class BankAccount {
private:
    int accountNumber_;
    std::string owner_;
    double balance_;
    std::vector<std::string> history_;

    void record(const std::string& message) {
        history_.push_back(message);
    }

public:
    BankAccount(int accountNumber, std::string owner, double initialBalance)
        : accountNumber_(accountNumber),
          owner_(std::move(owner)),
          balance_(initialBalance) {
        if (initialBalance < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
        record("Account opened with balance $" + std::to_string(initialBalance));
    }

    int accountNumber() const { return accountNumber_; }
    const std::string& owner() const { return owner_; }
    double balance() const { return balance_; }

    void deposit(double amount) {
        if (amount <= 0.0) {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance_ += amount;
        record("Deposited $" + std::to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance_) {
            throw std::runtime_error("Insufficient funds.");
        }
        balance_ -= amount;
        record("Withdrew $" + std::to_string(amount));
    }

    void printStatement() const {
        std::cout << "\nStatement for " << owner_
                  << " (Account " << accountNumber_ << ")\n";
        for (const auto& entry : history_) {
            std::cout << "  - " << entry << '\n';
        }
        std::cout << "Current balance: $" << std::fixed
                  << std::setprecision(2) << balance_ << "\n";
    }
};

class Bank {
private:
    std::unordered_map<int, std::unique_ptr<BankAccount>> accounts_;

public:
    void createAccount(int number, const std::string& owner, double initialBalance) {
        if (accounts_.contains(number)) {
            throw std::runtime_error("Account number already exists.");
        }
        accounts_[number] =
            std::make_unique<BankAccount>(number, owner, initialBalance);
    }

    BankAccount& getAccount(int number) {
        auto it = accounts_.find(number);
        if (it == accounts_.end()) {
            throw std::runtime_error("Account not found.");
        }
        return *it->second;
    }

    void transfer(int from, int to, double amount) {
        BankAccount& sender = getAccount(from);
        BankAccount& receiver = getAccount(to);

        sender.withdraw(amount);
        try {
            receiver.deposit(amount);
        } catch (...) {
            sender.deposit(amount);
            throw;
        }
    }
};

int main() {
    try {
        Bank bank;
        bank.createAccount(1001, "Laxman", 1200.00);
        bank.createAccount(1002, "Maya", 800.00);

        bank.getAccount(1001).deposit(250.00);
        bank.transfer(1001, 1002, 300.00);

        bank.getAccount(1001).printStatement();
        bank.getAccount(1002).printStatement();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
}
