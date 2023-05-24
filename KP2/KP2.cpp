#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct tovar
{
	string name, quantity;
	double price;
};

void mainMenu();
void add(string path);
void show(string path);
void checkTovar(string path);
void catalog();
void catalogFruitsVegetables();
void catalogMeat();
void login();
void registration();
void admin();

void mainMenu()
{
	system("cls");
	cout << "\tГлавное меню" << endl;
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Авторизация" << endl;
	cout << "[3] Регистрация" << endl;
	cout << "[4] Войти от имени администратора" << endl;
	cout << "[5] Выход" << endl << endl;
	cout << "Введите цифру чтобы продолжить" << endl;
	int _mainMenu;
	cin >> _mainMenu;
	switch (_mainMenu)
	{
	case 1: catalog();
		break;
	//case 2: Login();
		break;
	//case 3: Registration();
		break;
	//case 4: Admin();
		break;
	case 5: system("cls");
		break;
	}
}

void add(string path)
{
	string name, quantity;
	double price;
	system("cls");
	ofstream record(path, ios::app);
	cin.ignore();
	cout << "Введите название товара" << endl;
	getline(cin, name);
	record << name << endl;
	cout << "Введите количество с измерением через пробел" << endl;
	getline(cin, quantity);
	record << quantity << endl;
	cout << "Введите цену" << endl;
	cin >> price;
	record << price << endl;
}

void show(string path)
{
	system("cls");
	ifstream read_num(path);
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	};
	int num = k / 3;
	read_num.close();
	ifstream read(path);
	tovar* mas = new tovar[num];
	for (int i = 0; i < num; i++)
	{
		int n = i;
		getline(read, mas[i].name);
		cout << "[" << n+1 << "] " << mas[i].name << endl;
		getline(read, mas[i].quantity);
		cout << mas[i].quantity << endl;
		read >> mas[i].price;
		read.ignore();
		cout << mas[i].price << "р" << endl << endl;
	}
	read.close();
	int choose;
	cout << "[1] Назад" << endl;
	cout << "[2] Вернуться в главный католог"  << endl;
	cin >> choose;
	if (choose == 2)
	{
		catalog();
	}
	else if (choose == 1)
	{
		if (path == "Vegetables.txt")
		{
			catalogFruitsVegetables();
		}
		else if (path == "Fruits.txt")
		{
			catalogFruitsVegetables();
		}
		else if (path == "Berries.txt")
		{
			catalogFruitsVegetables();
		}
		else if (path == "Greenery.txt")
		{
			catalogFruitsVegetables();
		}
		else if (path == "MilkEggs.txt")
		{
			catalog();
		}
		else if (path == "Bread.txt")
		{
			catalog();
		}
		else if (path == "Pork.txt")
		{
			catalogMeat();
		}
		else if (path == "Chicken.txt")
		{
			catalogMeat();
		}
		else if (path == "Sauseges.txt")
		{
			catalogMeat();
		}
		else if (path == "Drinks.txt")
		{
			catalogMeat();
		}
	}
}

void checkTovar(string path) 
{
	ifstream read_num(path);
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	};
	int num = k / 3;
	read_num.close();
	fstream check(path);
	string lol;
	for (int i = 0; i < k; i++) 
	{
		check >> lol;
		if (lol == "Яйца") cout << 1;
	}
}

void catalog()
{
	system("cls");
	cout << "[1] Овощи и фрукты" << endl;
	cout << "[2] Молоко, яйца" << endl;
	cout << "[3] Хлеб, выпечка" << endl;
	cout << "[4] Мясо" << endl;
	cout << "[5] Напитки" << endl;
	cout << "[6] Крупы, сахар" << endl;
	cout << "[7] Макароны" << endl;
	cout << "[8] Сладости" << endl;
	cout << "[9] Масло, соусы" << endl << endl;
	cout << "[10] Главное меню" << endl << endl;
	int _catalog;
	cin >> _catalog;
	switch (_catalog)
	{
	case 1: catalogFruitsVegetables();
		break;
	case 2: show("MilkEggs.txt");
		break;
	case 3: show("Bread.txt");
		break;
	case 4: catalogMeat();
		break;
	case 5: show("Drinks.txt");
		break;
	case 6: catalogCerealsSugar();
		break;
	/*case 7: catalogPasta();
		break;
	case 8: catalogSweets();
		break;
	case 9: catalogOilSauces();*/
		break;
	case 10: system("cls");
		mainMenu();
		break;
	}
}

void catalogFruitsVegetables()
{
	system("cls");
	cout << "[1] Овощи" << endl;
	cout << "[2] Фрукты" << endl;
	cout << "[3] Ягоды" << endl;
	cout << "[4] Зелень" << endl << endl;
	cout << "[5] Назад" << endl << endl;
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1: show("Vegetables.txt");
		break;
	case 2: show("Fruits.txt");
		break;
	case 3: show("Berries.txt");
		break;
	case 4: show("Greenery.txt");
		break;
	case 5: system("cls");
		catalog();
		break;
	}
}

void catalogMeat()
{
	system("cls");
	cout << "[1] Cвинина" << endl;
	cout << "[2] Курица" << endl;
	cout << "[3] Колбаса" << endl << endl;
	cout << "[4] Назад" << endl << endl;
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1: show("Pork.txt");
		break;
	case 2: show("Chicken.txt");
		break;
	case 3: show("Sauseges.txt");
		break;
	case 4: system("cls");
		catalogFruitsVegetables();
		break;
	}
}

void catalogCerealsSugar()
{
	cout << "[1] Рис" << endl;
	cout << "[2] Крупа гречневая" << endl;
	cout << "[3] Крупа манная" << endl;
	cout << "[4] Мука" << endl;
	cout << "[5] Сахар" << endl;
	cout << "[6] Соль" << endl;
	cout << "[4] Главное меню" << endl;
	cout << "[4] Главное меню" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mainMenu();
}