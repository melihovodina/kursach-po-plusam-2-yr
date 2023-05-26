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

struct user
{
	string name, surname, patronymic, phone, password;
};

void mainMenu();
void add(string path);
void show(string path);
void checkTovar(string path);
void clear();
void catalog();
void catalogFruitsVegetables();
void red_catalogFruitsVegetables();
void catalogMeat();
void red_catalogMeat();
void chooseCatalog();
void login();
void registration();
void admin();
void writeStr(string x, string& y, string z);
void writePhone();
void adminMenu();

void mainMenu()
{
	system("cls");
	cout << "\tГлавное меню" << endl;
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Авторизация" << endl;
	cout << "[3] Регистрация" << endl;
	cout << "[4] Войти от имени администратора" << endl << endl;
	cout << "[Esc] Выход" << endl;
	char choose;
	bool flag;
	flag = false;
	while(flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: catalog();
			flag = true;
			break;
			//case 50: Login();
			flag = true;
			break;
			//case 51: Registration();
			flag = true;
			break;
		case 52: adminMenu();
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			break;
		}
	}
}

void adminMenu()
{
	system("cls");
	cout << "[1] Добавить новый товар" << endl;
	cout << "[2] Посмотреть список пользоватей" << endl << endl;
	cout << "[Esc] Выйти" << endl;
	char choose;
	bool flag;
	flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: chooseCatalog();
			flag = true;
			break;
			//case 50: Login();
			flag = true;
			break;
			//case 51: Registration();
			flag = true;
			break;
			//case 52: Admin();
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			mainMenu();
			break;
		}
	}
}

void add(string path)
{
	string name, quantity;
	double price;
	system("cls");
	ofstream record(path, ios::app);
	cout << "Введите название товара" << endl;
	getline(cin, name);
	record << name << endl;
	cout << "Введите количество с измерением через пробел" << endl;
	getline(cin, quantity);
	record << quantity << endl;
	cout << "Введите цену" << endl;
	cin >> price;
	record << price << endl;
	char choose;
	bool flag;
	flag = false;
	cout << "[Esc] Вернуться в главное меню" << endl;
	cout << "[1] Добавить еще один товар" << endl;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 27:
			flag = true;
			mainMenu();
			break;
		case 49:
			flag = true;
			add(path);
			break;
		}
	}
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
		cout << mas[i].name << endl;
		getline(read, mas[i].quantity);
		cout << mas[i].quantity << endl;
		read >> mas[i].price;
		read.ignore();
		cout << mas[i].price << "р" << endl << endl;
	}
	read.close();
	char choose;
	bool flag;
	flag = false;
	cout << "[Esc] Назад" << endl;
	cout << "[1] Вернуться в главный католог" << endl;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 27:
			flag = true;
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
				catalog();
			}
			else if (path == "Cereals.txt")
			{
				catalog();
			}
			else if (path == "Pasta.txt")
			{
				catalog();
			}
			else if (path == "Sweets.txt")
			{
				catalog();
			}
			else if (path == "OilSauces.txt")
			{
				catalog();
			}
			break;
		case 49:
			flag = true;
			catalog();
			break;
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

void clear()
{
	cout << "\033[1F";
	for (int i = 0; i < 120; i++)
	{
		_putch(32);
	}
	for (int i = 0; i < 120; i++)
	{
		_putch(8);
	}
}

void chooseCatalog()
{
	system("cls");
	cout << "Выберите католог, в который хотите добавить новый товар" << endl << endl;
	cout << "[1] Овощи, фрукты" << endl;
	cout << "[2] Молоко, яйца" << endl;
	cout << "[3] Хлеб" << endl;
	cout << "[4] Мясо" << endl;
	cout << "[5] Напитки" << endl;
	cout << "[6] Крупы" << endl;
	cout << "[7] Макароны" << endl;
	cout << "[8] Сладости" << endl;
	cout << "[9] Масло, соусы" << endl << endl;
	cout << "[Esc] Главное меню" << endl;
	char choose;
	bool flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: red_catalogFruitsVegetables();
			flag = true;
			break;
		case 50: 
		{
			cout << "Вы точно хотите редактировать каталог <<Молоко, яйца>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: add("MilkEggs.txt");
					flag1 = true;
					break;
				case 50: chooseCatalog();
					flag1 = true;
					break;
				}
			}
			}
			flag = true;
			break;
		case 51: add("Bread.txt");
			flag = true;
			break;
		case 52: red_catalogMeat();
			flag = true;
			break;
		case 53: add("Drinks.txt");
			flag = true;
			break;
		case 54: add("Cereals.txt");
			flag = true;
			break;
		case 55: add("Pasta.txt");
			flag = true;
			break;
		case 56: add("Sweets.txt");
			flag = true;
			break;
		case 57: add("OilSauces.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			mainMenu();
			break;
		}
	}
}

void writeStr(string x, string& y, string z)
{
	cout << x << ": ";
	getline(cin, y);
	if (size(y) != 0)
	{
		if (y == "0")
		{
			mainMenu();
		}
		else
		{
			if (z == "every")
			{
				if (y[0] >= 'а' && y[0] <= 'я')
				{
					y[0] = 'А' + (y[0] - 'а');
				}
				if (y[0] == 'ё')
				{
					y[0] = 'Ё';
				}
				for (int i = 0; i < size(y); i++)
				{
					if (y[i] == ' ' || y[i] == '-')
					{
						if (y[i + 1] >= 'а' && y[i + 1] <= 'я')
						{
							y[i + 1] = 'А' + (y[i + 1] - 'а');
						}
						if (y[i + 1] == 'ё')
						{
							y[i + 1] = 'Ё';
						}
					}
				}
			}
			else if (z == "first")
			{
				if (y[0] >= 'а' && y[0] <= 'я')
				{
					y[0] = 'А' + (y[0] - 'а');
				}
				if (y[0] == 'ё')
				{
					y[0] = 'Ё';
				}
			}
		}
		clear();
		cout << x << ": " << y << endl;
	}
	else
	{
		clear();
		writeStr(x, y, z);
	}
}

void catalog()
{
	system("cls");
	cout << "[1] Овощи и фрукты" << endl;
	cout << "[2] Молоко, яйца" << endl;
	cout << "[3] Хлеб" << endl;
	cout << "[4] Мясо" << endl;
	cout << "[5] Напитки" << endl;
	cout << "[6] Крупы" << endl;
	cout << "[7] Макароны" << endl;
	cout << "[8] Сладости" << endl;
	cout << "[9] Масло, соусы" << endl << endl;
	cout << "[Esc] Главное меню" << endl;
	char choose;
	bool flag = false;
	while(flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: catalogFruitsVegetables();
			flag = true;
			break;
		case 50: show("MilkEggs.txt");
			flag = true;
			break;
		case 51: show("Bread.txt");
			flag = true;
			break;
		case 52: catalogMeat();
			flag = true;
			break;
		case 53: show("Drinks.txt");
			flag = true;
			break;
		case 54: show("Cereals.txt");
			flag = true;
			break;
		case 55: show("Pasta.txt");
			flag = true;
			break;
		case 56: show("Sweets.txt");
			flag = true;
			break;
		case 57: show("OilSauces.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			mainMenu();
			break;
		}
	}
}

void catalogFruitsVegetables()
{
	system("cls");
	cout << "[1] Овощи" << endl;
	cout << "[2] Фрукты" << endl;
	cout << "[3] Ягоды" << endl;
	cout << "[4] Зелень" << endl << endl;
	cout << "[Esc] Назад" << endl;
	char choose;
	bool flag = false;
	while(flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: show("Vegetables.txt");
			flag = true;
			break;
		case 50: show("Fruits.txt");
			flag = true;
			break;
		case 51: show("Berries.txt");
			flag = true;
			break;
		case 52: show("Greenery.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			catalog();
			break;
		}
	}
}

void red_catalogFruitsVegetables()
{
	system("cls");
	cout << "[1] Овощи" << endl;
	cout << "[2] Фрукты" << endl;
	cout << "[3] Ягоды" << endl;
	cout << "[4] Зелень" << endl << endl;
	cout << "[Esc] Назад" << endl;
	char choose;
	bool flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: add("Vegetables.txt");
			flag = true;
			break;
		case 50: add("Fruits.txt");
			flag = true;
			break;
		case 51: add("Berries.txt");
			flag = true;
			break;
		case 52: add("Greenery.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			chooseCatalog();
			break;
		}
	}
}

void catalogMeat()
{
	system("cls");
	cout << "[1] Cвинина" << endl;
	cout << "[2] Курица" << endl;
	cout << "[3] Колбаса" << endl << endl;
	cout << "[4] Назад" << endl;
	char choose;
	bool flag;
	flag = false;
	while(flag == false)
	{
		choose = _getch();
			switch (choose)
			{
			case 49: show("Pork.txt");
				flag = true;
				break;
			case 50: show("Chicken.txt");
				flag = true;
				break;
			case 51: show("Sauseges.txt");
				flag = true;
				break;
			case 27: system("cls");
				flag = true;
				catalog();
				break;
			}
	}
}

void red_catalogMeat()
{
	system("cls");
	cout << "[1] Cвинина" << endl;
	cout << "[2] Курица" << endl;
	cout << "[3] Колбаса" << endl << endl;
	cout << "[4] Назад" << endl;
	char choose;
	bool flag;
	flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49: add("Pork.txt");
			flag = true;
			break;
		case 50: add("Chicken.txt");
			flag = true;
			break;
		case 51: add("Sauseges.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			chooseCatalog();
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mainMenu();
}