#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
using namespace std;

// Ckeck-up task: Create Supermarket database using oop and stl.

/* Супермаркет
Створити ієрархію класів для подання товарів Супермаркету
	+ Продукт( назва, термін споживання, категорія - молочні. хлібобулочні та ін., ціна, кількість)
	+ Товар (назва, категорія - побутова хімія, текстиль та ін., ціна, кількість)
Створити програму для роботи Супермаркету
	+ Додавання  продукту(товару) у базу
	+ Збереження бази товарів( у файл)
	+ Завантаження бази товарів з файлу
	+ Перегляд усіх продуктів(товарів)
	+ Пошук певного товару(продукту) з видачею інформації про товар(продукт)
	+ Видалення певного товару(продукту) з бази
	+ Створення меню програми для вибору операції */

enum OperationType { AddG, AddP, DeleteG, DeleteP, ShowAll, FindG, FindP, Save, Load, Exit };

struct Goods
{
public:
	string name;
	string category;
	double price;
	int amount;

	Goods() {};
	Goods(string name, string category, double price, int amount)
		: name(name), category(category), price(price), amount(amount)
	{ }
};

struct Product : public Goods
{
public:
	float expirationDate;
	string productCategory;

	Product() {};
	Product(float expirationDate, string productCategory, string name, string category, double price, int amount)
		: Goods(name, category, price, amount), expirationDate(expirationDate), productCategory(productCategory)
	{ }
};

class Supermarket
{
private:
	string supermarketName;
	string address;

public:
	vector<Product> productList;
	vector<Goods> goodsList;

	Supermarket(string supermarketName, string address) : supermarketName(supermarketName), address(address)
	{
		productList.push_back(Product(08.24, "Sweets", "Chockolate Paradise", "Chockolate Products", 17, 80));
		productList.push_back(Product(05.04, "Sweets", "Snickers", "Chockolate Products", 8, 90));
		productList.push_back(Product(05.04, "Diary", "Galychyna Milk", "Milk Products", 12, 68));
		productList.push_back(Product(05.04, "Diary", "Galychyna Sour Cream", "Milk Products", 9, 84));
		productList.push_back(Product(05.04, "Exotic Fruits", "Mango", "Fruits", 2, 161));
		productList.push_back(Product(05.04, "Exotic Fruits", "Coconut", "Fruits", 3, 105));


		goodsList.push_back(Goods("Spoon", "Kitchen Equipment", 0.4, 180));
		goodsList.push_back(Goods("Fork", "Kitchen Equipment", 0.4, 160));
		goodsList.push_back(Goods("Knives", "Kitchen Equipment", 0.4, 170));
		goodsList.push_back(Goods("Table Lamp", "Furniture", 4, 30));
		goodsList.push_back(Goods("Coffee Table", "Furniture", 37, 124));
	}

	void AddProduct(Product product);
	void AddGoods(Goods goods);

	void DeleteProduct(string name);
	void DeleteGoods(string name);

	void FindGoods(string name);
	void FindProduct(string name);

	void ShowAll();
	void Save();
	void Load();
};

class DatabaseMenu
{
public:
	void Show();
	OperationType Operation();
};

class SupermarketProgram
{
private:
	DatabaseMenu menu;
	Supermarket market;

public:
	SupermarketProgram() : market("Silpo", "Gagaryna Street, 22")
	{
		cout << "--------------- Welcome to our supermaket Database! ---------------" << endl;
	}
	void ProgramAddGoods();
	void ProgramAddProduct();
	void ProgramDeleteGoods();
	void ProgramDeleteProduct();
	void ProgramShowAll();
	void ProgramFindGoods();
	void ProgramFindProduct();
	void ProgramSave();
	void ProgramLoad();

	void Start();
};

int main()
{
	SupermarketProgram program;
	program.Start();

	return 0;
}
