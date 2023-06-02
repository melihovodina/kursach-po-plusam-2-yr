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
	string name, surname, patronymic, sex, birthDate, country, city, street, house, apart,
	phone, password;
};

void mainMenu();
void userMenu();
void adminMenu();
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
void registration(user mas[], int n);
void admin();
void writeStr(string x, string& y, string z);
void chooseSex(string& x);
void writeBirthDate(string& x);
void writeHouse(string& x);
void writeApart(string& x);
void writePhoneNum(user mas[], int n, string y, string& x, string type, string where);
void writePassword(string& x);
void userCount(int& num);
void tovarCount(string path, int& num);
void userInfo(int num, user* (&mas));
void tovarInfo(string path, int num, tovar* (&mas));


void mainMenu()
{
	int usersQuantity;
	userCount(usersQuantity);
	user* users = new user[usersQuantity];
	userInfo(usersQuantity, users);

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
		case 49: 
			flag = true;
			catalog();
			break;
		case 50: 
			flag = true;
			login();
			break;
		case 51: 
			flag = true;
			registration(users, usersQuantity);
			break;
		case 52: adminMenu();
			flag = true;
			break;
		case 27: 
			flag = true;
			system("cls");
			break;
		}
	}
}

void userMenu()
{
	system("cls");
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Корзина" << endl;
	cout << "[Esc] Выход" << endl;
	char choose;
	bool flag;
	flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49:
			flag = true;
			catalog();
			break;
		case 50:
			flag = true;
			mainMenu;
			break;
		case 27:
			flag = true;
			mainMenu;
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
		case 49:
			flag = true;
			chooseCatalog();
			break;
			//case 50: 
			flag = true;
			//Login();
			break;
			//case 51: 
			flag = true;
			//Registration();
			break;
			//case 52: 
			flag = true;
			//Admin();
			break;
		case 27: 
			flag = true;
			system("cls");
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

void checkTovar(string path, tovar mas[], int n)
{
	system("cls");
	//ifstream read_num(path);
	//string str;
	//int k = 0;
	//while (!read_num.eof())
	//{
	//	getline(read_num, str);
	//	k++;
	//};
	//int num = k / 3;
	//read_num.close();
	//ifstream read(path);
	//tovar* mas = new tovar[num];
	//for (int i = 0; i < num; i++)
	//{
	//	int n = i;
	//	getline(read, mas[i].name);
	//	cout << mas[i].name << endl;
	//	getline(read, mas[i].quantity);
	//	cout << mas[i].quantity << endl;
	//	read >> mas[i].price;
	//	read.ignore();
	//	cout << mas[i].price << "р" << endl << endl;
	//}
	//read.close();
	cout << endl << endl;
	cout << "[0] Назад" << endl;
	cout << "[1] Вернуться в главный католог" << endl;
	cout << "\033[2F";
	cout << "Введите товар, который хотите добавить в корзину: ";
	string str;
	do
	{
		getline(cin, str);
		if (size(str) == 0)
		{
			clear();
		}
	}while(size(str) == 0);
	if (str == "0")
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
	}
	if (str == "1")
	{
		catalog();
	}
	else
	{
		int l = 0, j = 0;
		for (int i = 0; i < n; i++)
		{
			if (str == mas[i].name)
			{
				l++;
				j = i;
			}
		}
		if (l != 0)
		{
			int count;
			system("cls");
			cout << "Вы выбрали товар: " << endl;
			cout << mas[j].name << endl;
			cout << mas[j].quantity << endl;
			cout << mas[j].price << endl << endl;
			cout << "Введите количество: ";
			cin >> count;
			cin.ignore();
			clear(); cout << "Количество: " << count << " шт." << endl;
			cout << "Цена: " << mas[j].price * count << endl << endl;
			cout << "Верно?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char choose;
			bool flag = false;
			while (flag == false)
			{
				choose = _getch();
				switch (choose)
				{
				case 49:
				{
					flag = true;
					ofstream record("Basket.txt");
					record << mas[j].name << endl;
					record << mas[j].quantity << endl;
					record << count << endl;
					record << mas[j].price * count << endl;
					break;
				}
				case 50:
					flag = true;
					checkTovar(path, mas, n);
					break;
				}
			}
		}
		else
		{
			cout << "Товар не найден";
		}
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
		case 49:
			flag = true;
			catalogFruitsVegetables();
			break;
		case 50: 
			flag = true;
			show("MilkEggs.txt");
			break;
		case 51: 
			flag = true;
			show("Bread.txt");
			break;
		case 52: 
			flag = true;
			catalogMeat();
			break;
		case 53: 
			flag = true;
			show("Drinks.txt");
			break;
		case 54: 
			flag = true;
			show("Cereals.txt");
			break;
		case 55: 
			flag = true;
			show("Pasta.txt");
			break;
		case 56: 
			flag = true;
			show("Sweets.txt");
			break;
		case 57: 
			flag = true;
			show("OilSauces.txt");
			break;
		case 27: 
			flag = true;
			system("cls");
			mainMenu();
			break;
		}
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
		case 49: 
			flag = true;
			red_catalogFruitsVegetables();
			break;
		case 50:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Молоко, яйца>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: 
					flag1 = true;
					add("MilkEggs.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 51:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Хлеб>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49:
					flag1 = true;
					add("Bread.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 52:
			flag = true;
			red_catalogMeat();
			break;
		case 53:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Напитки>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: 
					flag1 = true;
					add("Drinks.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 54:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Крупы>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: 
					flag1 = true;
					add("Cereals.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 55:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Макароны>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: 
					flag1 = true;
					add("Pasta.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 56:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Сладости>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: 
					flag1 = true;
					add("Sweets.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 57:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Масло, соусы>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49:
					flag1 = true;
					add("OilSauces.txt");
					break;
				case 50: 
					flag1 = true;
					chooseCatalog();
					break;
				}
			}
			break;
		}
		case 27:
			flag = true;
			system("cls");
			adminMenu();
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
		case 49: 
			flag = true;
			show("Vegetables.txt");
			break;
		case 50: 
			flag = true;
			show("Fruits.txt");
			break;
		case 51: 
			flag = true;
			show("Berries.txt");
			break;
		case 52: 
			flag = true;
			show("Greenery.txt");
			break;
		case 27: 
			flag = true;
			system("cls");
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
		case 49: 
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Овощи>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49:
					flag1 = true;
					add("Vagetables.txt");
					break;
				case 50:
					flag1 = true;
					red_catalogFruitsVegetables();
					break;
				}
			}
			break;
		}
		case 50:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Фрукты>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: add("Fruits.txt");
					flag1 = true;
					break;
				case 50: red_catalogFruitsVegetables();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 51: 
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Ягоды>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: add("Berries.txt");
					flag1 = true;
					break;
				case 50: red_catalogFruitsVegetables();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 52:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Зелень>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: add("Greenery.txt");
					flag1 = true;
					break;
				case 50: red_catalogFruitsVegetables();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 27: 
			flag = true;
			system("cls");
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
	cout << "[Esc] Назад" << endl;
	char choose;
	bool flag = false;
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
	cout << "[Esc] Назад" << endl;
	char choose;
	bool flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Свинина>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49:
					flag1 = true;
					add("Pork.txt");
					break;
				case 50: 
					flag1 = true;
					red_catalogMeat();
					break;
				}
			}
			break;
		}
		case 50:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Курица>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: add("Chicken.txt");
					flag1 = true;
					break;
				case 50: red_catalogMeat();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 51:
		{
			flag = true;
			system("cls");
			cout << "Вы точно хотите добавить новый товар в каталог <<Колбаса>> ?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char conf;
			bool flag1 = false;
			while (flag1 == false)
			{
				conf = _getch();
				switch (conf)
				{
				case 49: add("Sauseges.txt");
					flag1 = true;
					break;
				case 50: red_catalogMeat();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 27: 
			flag = true;
			system("cls");
			chooseCatalog();
			break;
		}
	}
}

void registration(user mas[], int n)
{
	string surname, name, patronymic, sex, birthDate, country = "Беларусь", city, street, house, apart,
	phone, password;
	system("cls");

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "Введите 0 чтобы вернуться в главное меню" << endl;
	cout << "\033[21F";
	writeStr("Фамилия", surname, "every");
	writeStr("Имя", name, "every");
	writeStr("Отчество", patronymic, "every");
	chooseSex(sex);
	writeBirthDate(birthDate);
	cout << "Страна: " << country << endl;
	writeStr("Город", city, "first");
	writeStr("Улица", street, "first");
	writeHouse(house);
	writeApart(apart);
	writePhoneNum(mas, n, "Номер телефона: +375", phone, "reg", "main");
	writePassword(password);
	cout << endl << endl << endl << endl << endl;
	clear(); clear();
	cout << "\033[2F";
	cout << "[1] Подтвердить регистрацию" << endl;
	cout << "[2] Отменить и вернуться в главное меню" << endl;

	char choose;
	bool flag = false;
	while (flag == false)
	{
		choose = _getch();
		if (choose == 49)
		{
			flag = true;
			system("cls");
			ofstream record("users.txt", ios::app);
			record << surname << endl;
			record << name << endl;
			record << patronymic << endl;
			record << sex << endl;
			record << birthDate << endl;
			record << country << endl;
			record << city << endl;
			record << street << endl;
			record << house << endl;
			record << apart << endl;
			record << phone << endl;
			record << password << endl;
			record.close();

			cout << "Регистрация завершена успешно." << endl << endl;
			cout << "[1] Войти в личный кабинет" << endl;
			cout << "[2] Вернуться в главное меню" << endl;

			char choose;
			bool flag1 = false;
			while (flag1 == false)
			{
				choose = _getch();
				switch (choose)
				{
				case 49:
					flag1 = true;
					login();
					break;
				case 50:
					flag1 = true;
					mainMenu();
					break;
				}
			}
		}
		if (choose == 50)
		{
			flag = true;
			mainMenu();
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

void chooseSex(string& x)
{
	cout << "Пол: 1. Мужской   2. Женский" << endl;
	char choose;
	bool flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 48:
			flag = true;
			mainMenu();
			break;
		case 49:
			flag = true;
			x = "Мужской";
			break;
		case 50:
			flag = true;
			x = "Женский";
			break;
		}
		clear();
		cout << "Пол: " << x << endl;
	}
}

void writeBirthDate(string& x)
{
	cout << "Дата рождения (00 00 0000): ";
	string num = "0123456789 ";
	getline(cin, x);
	if (size(x) != 0)
	{
		if (x == "0")
		{
			mainMenu();
		}
		else
		{
			int k = 0;
			if (x[2] == ' ' && x[5] == ' ' && size(x) == 10)
			{
				for (int i = 0; i < size(x); i++)
				{
					int index;
					index = num.find(x[i]);
					if (index >= 0) k++;
				}
				if (k == 10)
				{
					SYSTEMTIME t;
					GetLocalTime(&t);
					string d, m, y;
					d = x.substr(0, 2);
					m = x.substr(3, 2);
					y = x.substr(6);
					if (((stoi(m) == 1 || stoi(m) == 3 || stoi(m) == 5 || stoi(m) == 7 || stoi(m) == 8 || stoi(m) == 10 || stoi(m) == 12) && stoi(d) <= 31)
						|| ((stoi(m) == 4 || stoi(m) == 6 || stoi(m) == 9 || stoi(m) == 11) && stoi(d) <= 30)
						|| (stoi(m) == 2 && stoi(d) <= 29))
					{
						int age;
						if (stoi(y) < t.wYear)
						{
							if (stoi(m) > t.wMonth)
								age = t.wYear - stoi(y) - 1;
							else if (stoi(m) < t.wMonth)
								age = t.wYear - stoi(y);
							else if (stoi(m) == t.wMonth)
							{
								if (stoi(d) > t.wDay)
									age = t.wYear - stoi(y) - 1;
								if (stoi(d) <= t.wDay)
									age = t.wYear - stoi(y);
							}
							if (age >= 14 && age <= 100)
							{
								clear();
								cout << "Дата рождения: ";
								x = d + '.' + m + '.' + y;
								cout << x << endl;
							}
							else if (age > 100 || age < 1)
							{
								clear();
								writeBirthDate(x);
							}
							else if (age >= 1 && age < 14)
							{
								clear();
								cout << "Пользоваться услугами нашего сервиса можно только с 14-ти лет." << endl << "Нажмите любую клавишу чтобы повторить." << endl;
								_getch();
								clear();
								clear();
								writeBirthDate(x);
							}
						}
						else
						{
							clear();
							writeBirthDate(x);
						}
					}
					else
					{
						clear();
						writeBirthDate(x);
					}
				}
				else
				{
					clear();
					writeBirthDate(x);
				}
			}
			else
			{
				clear();
				writeBirthDate(x);
			}
		}
	}
	else
	{
		clear();
		writeBirthDate(x);
	}
}

void writeHouse(string& x)
{
	cout << "Дом: ";
	getline(cin, x);
	if (size(x) != 0)
	{
		if (x == "0")
		{
			mainMenu;
		}
		else
		{
			string num = "0123456789";
			string letters = "абвгдАБВГД/";
			int first = num.find(x[0]);
			if (first >= 0)
			{
				int k = 0, j = 0;
				for (int i = 0; i < size(x); i++)
				{
					int index;
					index = num.find(x[i]);
					if (index >= 0) k++;
				}
				for (int i = 0; i < size(x); i++)
				{
					int index;
					index = letters.find(x[i]);
					if (index >= 0) j++;
				}
				if ((k + j) != size(x))
				{
					clear();
					writeHouse(x);
				}
			}
			else
			{
				clear();
				writeHouse(x);
			}
		}
	}
	else
	{
		clear();
		writeHouse(x);
	}
}

void writeApart(string& x)
{
	cout << "Квартира: ";
	getline(cin, x);
	if (size(x) != 0)
	{
		if (x == "0")
		{
			mainMenu();
		}
		else
		{
			string num = "0123456789";
			int k = 0, j = 0;
			for (int i = 0; i < size(x); i++)
			{
				int index;
				index = num.find(x[i]);
				if (index >= 0) k++;
			}
			if (k != size(x))
			{
				clear();
				writeApart(x);
			}
		}
	}
	else
	{
		clear();
		writeApart(x);
	}
}

void writePhoneNum(user mas[], int n, string y, string& x, string type, string where)
{
	int usersQuantity;
	userCount(usersQuantity);
	user* users = new user[usersQuantity];
	userInfo(usersQuantity, users);

	cout << y;
	getline(cin, x);
	if (size(x) != 0)
	{
		if (x == "0")
		{
			if (where == "admin")
			{
				adminMenu();
			}
			else if (where == "main")
			{
				mainMenu();
			}
		}
		else
		{
			string num = "0123456789";
			int k = 0;
			if (size(x) == 9)
			{
				for (int i = 0; i < size(x); i++)
				{
					int index;
					index = num.find(x[i]);
					if (index >= 0) k++;
				}
				if (k != size(x))
				{
					clear();
					writePhoneNum(mas, n, y, x, type, where);
				}
				int ph = 0;
				for (int i = 0; i < n; i++)
				{
					if (mas[i].phone == x) ph++;
				}
				if (type == "reg" && ph != 0)
				{
					cout << "Этот номер уже зарегистрирован в системе." << endl;
					cout << "Нажмите Enter чтобы повторить" << endl;
					cout << "[Esc] Вернуться в главное меню" << endl;
					char choice;
					bool flag = false;
					while (flag == false)
					{
						choice = _getch();
						switch (choice)
						{
						case 13:
						{
							flag = true;
							clear();
							clear();
							clear(); 
							clear();
							writePhoneNum(mas, n, y, x, type, where);
							break;
						}
						case 27:
						{
							flag = true;
							mainMenu();
							break;
						}
						}

					}
				}
				else if (type == "search" && ph == 0)
				{
					if (x != "000000000")
					{
						cout << "Этот номер не зарегистрирован в системе." << endl;
						cout << "Нажмите Enter чтобы повторить." << endl;
						_getch();
						clear();
						clear();
						clear();
						writePhoneNum(mas, n, y, x, type, where);
					}
				}
			}
			else
			{
				clear();
				writePhoneNum(mas, n, y, x, type, where);
			}
		}
	}
	else
	{
		clear();
		writePhoneNum(mas, n, y, x, type, where);
	}
}

void writePassword(string& x)
{
	cout << "Пароль: ";
	getline(cin, x);
	if (size(x) != 0)
	{
		if (x == "0")
		{
			mainMenu();
		}
		else
		{
			if (size(x) < 8 || size(x) > 32)
			{
				cout << "Пароль должен состоять из 8-ми до 32-х символов." << endl << "Нажмите Enter чтобы повторить." << endl;
				_getch();
				clear();
				clear();
				clear();
				writePassword(x);
			}
			else
			{
				string stars = "";
				for (int i = 0; i < size(x); i++)
				{
					stars += '*';
				}
				clear();
				cout << "Пароль: " << stars << endl;
			}
		}
	}
	else
	{
		clear();
		writePassword(x);
	}
}

void login()
{
	int usersQuantity;
	userCount(usersQuantity);
	user* users = new user[usersQuantity];
	userInfo(usersQuantity, users);

	string userPhone, userPassword;
	int k = 0, j;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "Введите 0 чтобы вернуться в главное меню" << endl;
	cout << "\033[7F";
	writePhoneNum(users, usersQuantity, "Номер телефона: +375", userPhone, "search", "main");
	for (int i = 0; i < usersQuantity; i++)
	{
		if (userPhone == users[i].phone)
		{
			k++;
			j = i;
		}
	}
	if (k != 0)
	{
		writePassword(userPassword);
		if (userPassword == users[j].password)
		{
			cout << "Вход выполнен";
			userMenu();
		}
		else
		{
			cout << "Неверный пароль." << endl << "Нажмите ENTER чтобы повторить попытку." << endl;
			_getch();
			writePassword(userPassword);
		}
	}
	else
	{
		cout << "Пользователь с этим номером не найден." << endl << "Нажмите ENTER чтобы повторить." << endl;
		_getch();

	}
}

void userCount(int& num)
{
	ifstream read_num("Users.txt");
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	}
	num = k / 12;
	read_num.close();
}

void tovarCount(string path, int& num)
{
	ifstream read_num(path);
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	}
	num = k / 3;
	read_num.close();
}

void userInfo(int num, user* (&mas))
{
	ifstream read("Users.txt");
	for (int i = 0; i < num; i++)
	{
		getline(read, mas[i].surname);
		getline(read, mas[i].name);
		getline(read, mas[i].patronymic);
		getline(read, mas[i].sex);
		getline(read, mas[i].birthDate);
		getline(read, mas[i].country);
		getline(read, mas[i].city);
		getline(read, mas[i].street);
		getline(read, mas[i].house);
		getline(read, mas[i].apart);
		getline(read, mas[i].phone);
		getline(read, mas[i].password);
	}
	read.close();
}

void tovarInfo(string path, int num, tovar* (&mas))
{
	ifstream read(path);
	for (int i = 0; i < num; i++)
	{
		getline(read, mas[i].name);
		getline(read, mas[i].quantity);
		read >> mas[i].price;
		read.ignore();
	}
	read.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mainMenu();
}