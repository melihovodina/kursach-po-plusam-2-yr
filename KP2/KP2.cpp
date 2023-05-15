#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

void mainMenu();
void catalog();
void catalogFruitsVegetables();
void catalogMilkEggs();
void catalogBread();
void catalogMeat();
void catalogSasueges();
void catalogDrinks();
void catalogCerealsSugar();
void catalogPasta();
void catalogSweets();
void catalogOilSauces();
void catalogFruits();
void catalogVegetables();
void catalogBerries();
void catalogGreenery();
void login();
void registration();
void admin();
void fruits();
void vegetables();

void mainMenu()
{
	system("cls");
	cout << "\tГлавное меню" << endl;
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Авторизация" << endl;
	cout << "[3] Регистрация" << endl;
	cout << "[4] Войти от имени администратора" << endl;
	cout << "[5] Выход" << endl;
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

void catalog()
{
	system("cls");
	cout << "[1] Овощи и фрукты" << endl;
	cout << "[2] Молоко, яйца" << endl;
	cout << "[3] Хлеб, выпечка" << endl;
	cout << "[4] Мясо" << endl << endl;
	cout << "[5] Колбаса" << endl;
	cout << "[6] Напитки" << endl;
	cout << "[7] Крупы, сахар" << endl;
	cout << "[8] Макароны" << endl;
	cout << "[9] Сладости" << endl;
	cout << "[10] Масло, соусы" << endl;
	cout << "[11] Главное меню" << endl;
	int _catalog;
	cin >> _catalog;
	switch (_catalog)
	{
	case 1: catalogFruitsVegetables();
		break;
	case 2: catalogMilkEggs();
		break;
	case 3: catalogBread();
		break;
	case 4: catalogMeat();
		break;
	case 5: catalogSasueges();
		break;
	case 6: catalogDrinks();
		break;
	case 7: catalogCerealsSugar();
		break;
	case 8: catalogPasta();
		break;
	case 9: catalogSweets();
		break;
	case 10: catalogOilSauces();
		break;
	case 11: system("cls");
		catalog();
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
	cout << "[5] Главное меню" << endl;
	int _catalog_1;
	cin >> _catalog_1;
	switch (_catalog_1)
	{
	case 1:	catalogVegetables();
		break;
	case 2:	catalogFruits();	
		break;
	case 3:	catalogBerries();
		break;
	case 4:	catalogGreenery();
		break;
	case 5: mainMenu();
		break;
	}
}

void catalogMilkEggs()
{
	system("cls");
	cout << "[1] Яйца" << endl;
	cout << "[2] Молоко" << endl;
	cout << "[3] Кефир" << endl;
	cout << "[4] Сыр" << endl;
	cout << "[5] Йогурты, десерты" << endl;
	cout << "[6] Сметана, творог" << endl;
	cout << "[7] Главное меню" << endl;
}

void catalogBread()
{
	system("cls");
	cout << "[1] Хлеб, лепешки" << endl;
	cout << "[2] Торты, пирожные" << endl;
	cout << "[3] Сушки, пряники" << endl;
	cout << "[4] Главное меню" << endl;
}

void catalogVegetables()
{
	cout << "[1] Баклажан" << endl;
	cout << "[2] Имбирь" << endl;
	cout << "[3] Капуста" << endl;
	cout << "[4] Картофель" << endl << endl;
	cout << "[5] Лук" << endl;
	cout << "[6] Чеснок" << endl;
	cout << "[7] Морковь" << endl;
	cout << "[8] Огурец" << endl;
	cout << "[9] Перец" << endl;
	cout << "[10] Редис" << endl;
	cout << "[11] Свекла" << endl << endl;
	cout << "[12] Томат" << endl;
	cout << "[13] Главное меню" << endl;
}

void catalogBerries()
{
	cout << "[1] Голубика свежая" << endl;
	cout << "[2] Рябина замороженная" << endl;
	cout << "[3] Клубника замороженная" << endl;
	cout << "[4] Малина замороженная" << endl;
	cout << "[5] Вишня замороженная" << endl;
}

void catalogGreenery()
{
	cout << "[1] Лук" << endl;
	cout << "[2] Петрушка" << endl;
	cout << "[3] Укроп" << endl;
	cout << "[4] Пекинская капуста" << endl;
	cout << "[5] Главное меню" << endl;
}

void catalogFruits()
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
	cout << "[11] Главное меню" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mainMenu();
}