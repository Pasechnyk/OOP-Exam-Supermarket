
#include "Supermarket.h"

// ***** supermarket methods *****
void Supermarket::AddProduct(Product product)
{
	productList.push_back(product);
}

void Supermarket::AddGoods(Goods goods)
{
	goodsList.push_back(goods);
}

void Supermarket::DeleteProduct(string name)
{
	for (auto i = productList.begin(); i < productList.end(); ++i)
	{
		if (i->name == name)
		{
			productList.erase(i);
			return;
		}
	}
}

void Supermarket::DeleteGoods(string name)
{
	for (auto i = goodsList.begin(); i < goodsList.end(); ++i)
	{
		if (i->name == name)
		{
			goodsList.erase(i);
			return;
		}
	}
}

void Supermarket::FindGoods(string name)
{
	for (auto goods : goodsList)
	{
		for (auto i : goods.name)
		{
			if (goods.name == name)
			{
				cout << "----- Info about given goods ----- ";
				cout << "Goods name: " << goods.name << endl;
				cout << "Category: " << goods.category << endl;
				cout << "Price: " << goods.price << endl;
				cout << "Left: " << goods.amount << endl;
				return;
			}
			else throw exception("There is no such goods in this database!");
		}
	}
}

void Supermarket::FindProduct(string name)
{
	for (auto product : productList)
	{
		for (auto i : product.name)
		{
			if (product.name == name)
			{
				cout << "----- Info about given goods ----- ";
				cout << "Product name: " << product.name << endl;
				cout << "Expiration date: " << product.expirationDate << endl;
				cout << "Category: " << product.category << endl;
				cout << "Product category: " << product.productCategory << endl;
				cout << "Price: " << product.price << endl;
				cout << "Left: " << product.amount << endl;
				return;
			}
			else throw exception("There is no such product in this database!");
		}
	}
}

void Supermarket::ShowAll()
{
	cout << "------------- SUPERMARKET DATABASE -------------" << endl;
	cout << "------------------ PRODUCTS ------------------" << endl;
	for (auto product : productList)
	{
		cout << " -------------------------------------- " << endl;
		cout << "Product name: " << product.name << endl;
		cout << "Expiration date: " << product.expirationDate << endl;
		cout << "Category: " << product.category << endl;
		cout << "Product category: " << product.productCategory << endl;
		cout << "Price: " << product.price << endl;
		cout << "Left: " << product.amount << endl;
	}
	cout << "------------------- GOODS -------------------" << endl;
	for (auto goods : goodsList)
	{
		cout << " -------------------------------------- " << endl;
		cout << "Goods name: " << goods.name << endl;
		cout << "Category: " << goods.category << endl;
		cout << "Price: " << goods.price << endl;
		cout << "Left: " << goods.amount << endl;
	}
}

void Supermarket::Save()
{
	ofstream out("supermarket.txt");

	out << this->goodsList.size() << endl;

	for (auto goods : goodsList)
	{
		out << goods.name << endl;
		out << goods.category << endl;
		out << goods.price << endl;
		out << goods.amount << endl;
	}

	out << this->productList.size() << endl;

	for (auto product : productList)
	{
		out << product.name << endl;
		out << product.expirationDate << endl;
		out << product.category << endl;
		out << product.productCategory << endl;
		out << product.price << endl;
		out << product.amount << endl;
	}

	out.close();
}

void Supermarket::Load()
{
	ifstream in("supermarket.txt");

	int count = 0;
	in >> count;
	in.ignore();

	for (size_t i = 0; i < count; i++)
	{
		Goods goods;
		getline(in, goods.name);

		in >> goods.category;
		in >> goods.price;
		in >> goods.amount;

		goodsList.push_back(goods);
	}

	for (size_t i = 0; i < count; i++)
	{
		Product product;
		getline(in, product.name);

		in >> product.expirationDate;
		in >> product.category;

		getline(in, product.productCategory);

		in >> product.price;
		in >> product.amount;

		productList.push_back(product);
	}
}

// ***** database methods *****
void DatabaseMenu::Show()
{
	cout << "------------------------ SUPERMARKET DATABASE ------------------------" << endl;
	cout << AddG << " - Add New Goods" << endl;
	cout << AddP << " - Add New Product" << endl;
	cout << DeleteG << " - Delete Goods" << endl;
	cout << DeleteP << " - Delete Product" << endl;
	cout << ShowAll << " - Show All Database Information" << endl;
	cout << FindG << " - Find Goods by Name" << endl;
	cout << FindP << " - Find Product by Name" << endl;
	cout << Save << " - Save" << endl;
	cout << Load << " - Load" << endl;
	cout << Exit << " - Exit" << endl;
}

OperationType DatabaseMenu::Operation()
{
	int value = 0;
	cout << "Please enter operation number: ";
	cin >> value;

	while (value < 0 || value > 10)
	{
		throw exception("Invalid operation! Try again: ");
		cin >> value;
	}
	return (OperationType)value;
}

// ***** program methods *****
void SupermarketProgram::ProgramAddGoods()
{
	market.AddGoods(Goods());
}

void SupermarketProgram::ProgramAddProduct()
{
	market.AddProduct(Product());
}

void SupermarketProgram::ProgramDeleteGoods()
{
	string name;
	cout << "Goods name to delete: ";
	cin >> name;
	market.DeleteGoods(name);
}

void SupermarketProgram::ProgramDeleteProduct()
{
	string name;
	cout << "Product name to delete: ";
	cin >> name;
	market.DeleteProduct(name);
}

void SupermarketProgram::ProgramShowAll()
{
	market.ShowAll();
}

void SupermarketProgram::ProgramFindGoods()
{
	string name;
	cout << "Goods name to find: ";
	cin >> name;
	market.FindGoods(name);
}

void SupermarketProgram::ProgramFindProduct()
{
	string name;
	cout << "Product name to find: ";
	cin >> name;
	market.FindProduct(name);
}

void SupermarketProgram::ProgramSave()
{
	market.Save();
	cout << "Saved!" << endl;
}

void SupermarketProgram::ProgramLoad()
{
	market.Load();
	cout << "File was loaded!" << endl;
}

void SupermarketProgram::Start()
{
	menu.Show();
	OperationType operation = Exit;

	string name;
	do
	{
		operation = menu.Operation();

		switch (operation)
		{
		case AddG:
			ProgramAddGoods();
			break;
		case AddP:
			ProgramAddProduct();
			break;
		case DeleteG:
			ProgramDeleteGoods();
			break;
		case DeleteP:
			ProgramDeleteProduct();
			break;
		case ShowAll:
			ProgramShowAll();
			break;
		case FindG:
			ProgramFindGoods();
			break;
		case FindP:
			ProgramFindProduct();
			break;
		case Save:
			ProgramSave();
			break;
		case Load:
			ProgramLoad();
			break;
		}
	} while (operation != Exit);
}
