#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

struct Product
{
	int id{};
	std::string name;
	int quantity{};
	double price{};
};

class Inventory
{
private:
	std::map<int, Product> products_;

public:
	void addProduct(const Product &product)
	{
		if (product.quantity < 0 || product.price < 0.0)
		{
			throw std::invalid_argument("Quantity and price cannot be negative.");
		}
		if (!products_.emplace(product.id, product).second)
		{
			throw std::runtime_error("Product ID already exists.");
		}
	}

	void updateQuantity(int id, int change)
	{
		auto it = products_.find(id);
		if (it == products_.end())
		{
			throw std::runtime_error("Product not found.");
		}

		const int updated = it->second.quantity + change;
		if (updated < 0)
		{
			throw std::runtime_error("Not enough stock.");
		}
		it->second.quantity = updated;
	}

	void removeProduct(int id)
	{
		if (products_.erase(id) == 0)
		{
			throw std::runtime_error("Product not found.");
		}
	}

	double totalValue() const
	{
		double total = 0.0;
		for (const auto &[id, product] : products_)
		{
			total += product.quantity * product.price;
		}
		return total;
	}

	void display() const
	{
		std::cout << std::left
				  << std::setw(8) << "ID"
				  << std::setw(24) << "Name"
				  << std::setw(12) << "Quantity"
				  << std::setw(10) << "Price" << '\n';

		for (const auto &[id, product] : products_)
		{
			std::cout << std::left
					  << std::setw(8) << product.id
					  << std::setw(24) << product.name
					  << std::setw(12) << product.quantity
					  << "$" << std::fixed << std::setprecision(2)
					  << product.price << '\n';
		}
	}

	void saveToFile(const std::string &filename) const
	{
		std::ofstream output(filename);
		if (!output)
		{
			throw std::runtime_error("Unable to open output file.");
		}

		for (const auto &[id, product] : products_)
		{
			output << product.id << ','
				   << product.name << ','
				   << product.quantity << ','
				   << product.price << '\n';
		}
	}

	void loadFromFile(const std::string &filename)
	{
		std::ifstream input(filename);
		if (!input)
		{
			throw std::runtime_error("Unable to open input file.");
		}

		products_.clear();
		std::string line;

		while (std::getline(input, line))
		{
			std::stringstream stream(line);
			std::string idText;
			std::string name;
			std::string quantityText;
			std::string priceText;

			std::getline(stream, idText, ',');
			std::getline(stream, name, ',');
			std::getline(stream, quantityText, ',');
			std::getline(stream, priceText);

			Product product{
				std::stoi(idText),
				name,
				std::stoi(quantityText),
				std::stod(priceText)};

			products_[product.id] = product;
		}
	}
};

int main()
{
	try
	{
		Inventory inventory;
		inventory.addProduct({101, "Wireless Keyboard", 12, 39.99});
		inventory.addProduct({102, "USB-C Hub", 8, 54.50});
		inventory.addProduct({103, "Laptop Stand", 15, 29.75});

		inventory.updateQuantity(102, -2);
		inventory.saveToFile("inventory.csv");

		inventory.display();
		std::cout << "\nTotal inventory value: $"
				  << std::fixed << std::setprecision(2)
				  << inventory.totalValue() << '\n';
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Error: " << ex.what() << '\n';
		return 1;
	}
}
