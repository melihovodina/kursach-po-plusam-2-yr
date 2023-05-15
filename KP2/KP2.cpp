#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

struct FRUITS
{
	string Name, Sort, Country;
	int MinWeight, MaxWeight, Price;
};

void MainMenu();
void Catalog_1();
void Catalog_fruits();
void Catalog_vegetables();
void Catalog_berries();
void Catalog_greenery();
void Login();
void Registration();
void Admin();
void Fruits();
void Vegetables();
void CatalogFilter();

void MainMenu()
{
	system("cls");
	cout << "\tГлавное меню" << endl;
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Авторизация" << endl;
	cout << "[3] Регистрация" << endl;
	cout << "[4] Войти от имени администратора" << endl;
	cout << "[5] Выход" << endl;
	int _mainmenu;
	cin >> _mainmenu;
	switch (_mainmenu)
	{
	case 1: Catalog_1();
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

void Catalog_vegetables()
{
	cout << "[1] Баклажаны" << endl;
	cout << "[2] Имбирь" << endl;
	cout << "[3] Капуста" << endl;
	cout << "[4] Картофель" << endl << endl;
	cout << "[5] Лук, чеснок" << endl;
	cout << "[6] Морковь" << endl;
	cout << "[7] Огурцы" << endl;
	cout << "[8] Перцы" << endl;
	cout << "[9] Редис, редька" << endl;
	cout << "[10] Свекла" << endl << endl;
	cout << "[11] Томаты" << endl;
	cout << "[12] Другие овощи" << endl << endl;
	cout << "[13] Главное меню" << endl;
}

void Catalog_berries()
{

}

void Catalog_greenery()
{
	cout << "[1] Лук" << endl;
	cout << "[2] Петрушка" << endl;
	cout << "[3] Укроп" << endl;
	cout << "[4] Зелень" << endl << endl;
	cout << "[5] Салаты" << endl;
	cout << "[6] Пряные травы" << endl << endl;
	cout << "[7] Главное меню" << endl;
}

void Catalog_1()
{
	system("cls");
	cout << "[1] Овощи" << endl;
	cout << "[2] Фрукты" << endl;
	cout << "[3] Ягоды" << endl;
	cout << "[4] Зелень" << endl << endl;
	cout << "[5] Главное меню" << endl;
	int _catalog_1;
	cin >> _catalog_1;
	switch (_catalog_1)
	{
	case 1:	Catalog_vegetables();
		break;
	case 2:	Catalog_fruits();
		break;
	case 3:	Catalog_berries();
		break;
	case 4:	Catalog_greenery();
		break;
	case 5: MainMenu();
		break;
	}
}

void Catalog_fruits()
{
	system("cls");
	cout << "[1] Авокадо" << endl;
	cout << "[2] Ананасы" << endl;
	cout << "[3] Апельсины" << endl;
	cout << "[4] Бананы" << endl;
	cout << "[5] Виноград" << endl;
	cout << "[6] Груши" << endl;
	cout << "[7] Киви" << endl;
	cout << "[8] Манго" << endl;
	cout << "[9] Цитрусы" << endl;
	cout << "[10] Яблоки" << endl;
	cout << "[11] Другие фрукты" << endl << endl;
	cout << "[12] Главное меню" << endl;
	int _catalog;
	string _fruitchoice;
	cin >> _catalog;
	switch (_catalog)
	{
	case 1: _fruitchoice = "avocado";
		break;
	case 2: _fruitchoice = "pineapple";
		break;
	case 3: _fruitchoice = "orange";
		break;
	case 4: _fruitchoice = "banana";
		break;
	case 5: _fruitchoice = "citruses";
		break;
	case 6: _fruitchoice = "pear";
		break;
	case 7: _fruitchoice = "kiwi";
		break;
	case 8: _fruitchoice = "mango";
		break;
	case 9: _fruitchoice = "citruses";
		break;
	case 10: _fruitchoice = "apple";
		break;
	case 11: _fruitchoice = "otherfruits";
		break;
	case 12: MainMenu();
		break;
	}
	
	ifstream Reading("Grocery catalog.txt");

}

void CatalogFilter(name)
{
	system("cls");
	ifstream Reading(name)
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MainMenu();
}