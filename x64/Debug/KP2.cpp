#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct tovar
{
	string name, si, si2;
	double quantity, price, count;
};

struct user
{
	string name, surname, patronymic, sex, birthDate, country, city, street, house, apart,
		phone, password;
};

struct admin
{
	string login, password;
};

user* users;
tovar* tovars;
admin* admins;
int usersNum, tovarsNum, adminsNum, g;
double orderCost;

void mainMenu();
void userMenu();
void adminMenu();
void add(string path);
void del();
void show(string path);
void order(string path);
void confrimOrder();
void changeCount();
void clear();
void basket();
void catalog();
void catalogPlus();
void catalogMinus();
void userCatalog();
void userProfile();
void catalogFruitsVegetables();
void order_catalogFruitsVegetables();
void plus_catalogFruitsVegetables();
void minus_catalogFruitsVegetables();
void catalogMeat();
void order_catalogMeat();
void plus_catalogMeat();
void minus_catalogMeat();
void showUsers();
void login();
void adminLogin();
void registration();
void writeStr(string x, string& y, string z, string where);
void chooseSex(string& x);
void writeBirthDate(string& x);
void writeHouse(string& x);
void writeApart(string& x);
void writePhoneNum(string y, string& x, string type, string where);
void writePassword(string& x);
void customAdress();
void userInfo();
void rewriteUsers();
void adminInfo();
void tovarInfo(string path);
void basketInfo();


void mainMenu()
{
	userInfo();

	system("cls");
	cout << "\t\t\tГлавное меню" << endl;
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Авторизация" << endl;
	cout << "[3] Регистрация" << endl;
	cout << "[4] Войти от имени администратора" << endl << endl;
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
			login();
			break;
		case 51:
			flag = true;
			registration();
			break;
		case 52:
			flag = true;
			adminLogin();
			break;
		case 27:
			flag = true;
			system("cls");
			exit(0);
			break;
		}
	}
}

void userMenu()
{
	system("cls");
	cout << "\t\t\t Меню пользователя" << endl;
	cout << "[1] Продуктовый каталог" << endl;
	cout << "[2] Корзина" << endl;
	cout << "[3] Профиль" << endl << endl;
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
			userCatalog();
			break;
		case 50:
			flag = true;
			basket();
			break;
		case 51:
			flag = true;
			userProfile();
			break;
		case 27:
			flag = true;
			ofstream record("Basket.txt");
			mainMenu();
			break;
		}
	}
}

void adminMenu()
{
	system("cls");
	cout << "\t\t\t Меню администратора" << endl;
	cout << "[1] Добавить новый товар" << endl;
	cout << "[2] Удалить товар" << endl;
	cout << "[3] Посмотреть список пользоватей" << endl << endl;
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
			catalogPlus();
			break;
		case 50:
			flag = true;
			catalogMinus();
			break;
		case 51:
			flag = true;
			showUsers();
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
	string name, si;
	double quantity, price;
	system("cls");
	ofstream record(path, ios::app);
	writeStr("Введите название товара", name, "first", "admin");
	while (true) {
		cout << "Введите единицу измерения товара: ";
		getline(cin, si);
		if (size(si) == 0) {
			clear(); continue;
		}
		else break;
	}
	cout << "Введите количество (только цифра): ";
	cin >> quantity;
	cin.ignore();
	cout << "Введите цену: ";
	cin >> price;
	cin.ignore();
	char choose;
	bool flag;
	flag = false;
	cout << endl;
	record << name << endl;
	record << quantity << endl;
	record << " " << si << endl;
	record << price << endl;
	cout << "Товар добавлен" << endl << endl;
	cout << "[Esc] Вернуться в меню" << endl;
	tovarInfo(path);
	do choose = _getch(); while (choose != 27);
	adminMenu();
}

void del(string path)
{
	system("cls");
	tovarInfo(path);
	for (int i = 0; i < tovarsNum; i++)
	{
		int n = i;
		cout << tovars[i].name << endl;
		cout << tovars[i].quantity;
		cout << tovars[i].si << endl;
		cout << tovars[i].price << "р" << endl << endl;
	}
	string str;
	cout << "Введите название товара, который хотите удалить: ";
	do// это все можно заменить одной строчкой
	{
		getline(cin, str);
		if (size(str) == 0)
		{
			clear();
		}
	} while (size(str) == 0);
	if (str[0] >= 'а' && str[0] <= 'я')
	{
		str[0] = 'А' + (str[0] - 'а');
	}
	if (str[0] == 'ё')
	{
		str[0] = 'Ё';
	}
	if (str == "1")
	{
		adminMenu();
	}
	else
	{//----------------------------------
		int l = 0, j = 0;
		for (int i = 0; i < tovarsNum; i++)
		{
			if (str == tovars[i].name)
			{
				l++;
				j = i;
			}
		}
		if (l != 0)
		{
			cout << "Вы точно хотите удалить товар " << tovars[j].name << "?" << endl << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl;
			char choose;
			bool flag;
			flag = false;
			while (flag == false)
			{
				choose = _getch();
				switch (choose)
				{
				case 49:
				{
					flag = true;
					ofstream record(path);
					for (int i = 0; i < tovarsNum; i++)
					{
						if (tovars[i].name != tovars[j].name)
						{
							record << tovars[i].name << endl;
							record << tovars[i].quantity;
							record << " " << tovars[i].si << endl;
							record << tovars[i].price << endl;
						}
					}
					system("cls");
					cout << "Товар удален" << endl << endl;
					char choose;
					bool flag1;
					flag1 = false;
					cout << "[Esc] Вернуться в меню" << endl;
					while (flag1 == false)
					{
						choose = _getch();
						switch (choose)
						{
						case 27:
							flag1 = true;
							adminMenu();
							break;
						}
					}
					break;
				}
				case 50:
					flag = true;
					del(path);
					break;
				}
			}
		}
		else
		{
			cout << "Товар не найден";
			_getch();
			del(path);
		}
	}
}

void show(string path)
{
	system("cls");
	tovarInfo(path);
	for (int i = 0; i < tovarsNum; i++)
	{
		int n = i;
		cout << tovars[i].name << endl;
		cout << tovars[i].quantity;
		cout << tovars[i].si << endl;
		cout << tovars[i].price << "р" << endl << endl;
	}
	char choose;
	bool flag;
	flag = false;
	cout << "[Esc] Назад" << endl;
	cout << "[1] Вернуться в главное меню" << endl;
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
			mainMenu();
			break;
		}
	}
}

void order(string path)
{
	system("cls");
	tovarInfo(path);
	for (int i = 0; i < tovarsNum; i++)
	{
		int n = i;
		cout << tovars[i].name << endl;
		cout << tovars[i].quantity;
		cout << tovars[i].si << endl;
		cout << tovars[i].price << "р" << endl << endl;
	}
	cout << endl << endl << endl;
	cout << "[0] Назад" << endl;
	cout << "[1] Вернуться в главное меню" << endl;
	cout << "\033[4F";
	string str;
	do
	{
		cout << "Введите название товара, который хотите добавить в корзину: ";
		getline(cin, str);
		if (size(str) == 0) clear();
	} while (size(str) == 0);
	if (str[0] >= 'а' && str[0] <= 'я')
	{
		str[0] = 'А' + (str[0] - 'а');
	}
	if (str[0] == 'ё')
	{
		str[0] = 'Ё';
	}
	if (str == "0")
	{
		if (path == "Vegetables.txt")
		{
			order_catalogFruitsVegetables();
		}
		else if (path == "Fruits.txt")
		{
			order_catalogFruitsVegetables();
		}
		else if (path == "Berries.txt")
		{
			order_catalogFruitsVegetables();
		}
		else if (path == "Greenery.txt")
		{
			order_catalogFruitsVegetables();
		}
		else if (path == "MilkEggs.txt")
		{
			userCatalog();
		}
		else if (path == "Bread.txt")
		{
			userCatalog();
		}
		else if (path == "Pork.txt")
		{
			order_catalogMeat();
		}
		else if (path == "Chicken.txt")
		{
			order_catalogMeat();
		}
		else if (path == "Sauseges.txt")
		{
			order_catalogMeat();
		}
		else if (path == "Drinks.txt")
		{
			userCatalog();
		}
		else if (path == "Cereals.txt")
		{
			userCatalog();
		}
		else if (path == "Pasta.txt")
		{
			userCatalog();
		}
		else if (path == "Sweets.txt")
		{
			userCatalog();
		}
		else if (path == "OilSauces.txt")
		{
			userCatalog();
		}
	}
	if (str == "1")
	{
		userMenu();
	}
	else
	{
		int l = 0, j = 0;
		for (int i = 0; i < tovarsNum; i++)
		{
			if (str == tovars[i].name)
			{
				l++;
				j = i;
			}
		}
		if (l != 0)
		{
			system("cls");
			cout << "Вы выбрали товар: " << endl;
			cout << tovars[j].name << endl;
			cout << tovars[j].quantity;
			cout << tovars[j].si << endl;
			cout << tovars[j].price << "р." << endl << endl;
			string str;
			if (path == "Vegetables.txt" || path == "Fruits.txt" || path == "Berries.txt" || path == "Greenery.txt")
			{
				double a;
				cout << "Введите количество (кг): ";
				cin >> a;
				cin.ignore();
				tovars[j].count = a;
				clear(); cout << "Количество: " << tovars[j].count << "кг." << endl;
			}
			else
			{
				while (true) {
					cout << "Введите количество (шт): ";
					getline(cin, str);
					if (size(str) == 0) {
						clear(); continue;
					}
					else {
						string c = "0123456789";
						int k = 0;
						for (int i = 0; i < size(str); i++) {
							int index;
							index = c.find(str[i]);
							if (index >= 0) k++;
						}
						if (k == size(str)) break;
						else {
							clear(); continue;
						}
					}
				}
				tovars[j].count = stoi(str);
				clear(); cout << "Количество: " << tovars[j].count << " шт." << endl;
			}
			cout << "Цена: " << tovars[j].price * tovars[j].count << "р." << endl << endl;
			cout << "Верно?" << endl;
			cout << "[1] Да" << endl;
			cout << "[2] Нет" << endl << endl;
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
					if (path == "Vegetables.txt" || path == "Fruits.txt" || path == "Berries.txt" || path == "Greenery.txt")
					{
						tovars[j].si2 = " кг";
						ofstream record("Basket.txt", ios::app);
						record << tovars[j].name << endl;
						record << tovars[j].quantity;
						record << " " << tovars[j].si << endl;
						record << tovars[j].count;
						record << tovars[j].si2 << endl;
						record << tovars[j].price * tovars[j].count << endl;
					}
					else
					{
						tovars[j].si2 = " шт";
						ofstream record("Basket.txt", ios::app);
						record << tovars[j].name << endl;
						record << tovars[j].quantity;
						record << " " << tovars[j].si << endl;
						record << tovars[j].count;
						record << tovars[j].si2 << endl;
						record << tovars[j].price * tovars[j].count << endl;
					}
					system("cls");
					cout << "Товар добавлен в корзину" << endl;
					cout << "[1] Перейти в корзину" << endl;
					cout << "[Esc] Вернуться в продуктовый каталог" << endl;
					char choose;
					bool flag1 = false;
					while (flag1 == false)
					{
						choose = _getch();
						switch (choose)
						{
						case 49:
						{
							flag1 = true;
							basket();
							break;
						}
						case 27:
						{
							flag1 = true;
							userCatalog();
							break;
						}
						}
					}
					break;
				}
				case 50:
					flag = true;
					order(path);
					break;
				}
			}
		}
		else
		{
			cout << "Товар не найден, попробуйте еще раз";
			_getch();
			order(path);
		}
	}
}

void confrimOrder()
{
	system("cls");
	userInfo();
	cout << "Доставить заказ по адресу: г." << users[g].city << " ул." << users[g].street << " д." << users[g].house << " кв." << users[g].apart << " ?" << endl << endl;
	cout << "[Enter] Подтвердить заказ" << endl;
	cout << "[1] Изменить адрес доставки" << endl;
	cout << "[Esc] Назад" << endl;
	char choose;
	bool flag;
	flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 13:
		{
			flag = true;
			system("cls");
			cout << "Заказ принят" << endl;
			cout << "Общая сумма заказа: " << orderCost << "р" << endl;
			cout << "Адрес доставки г." << users[g].city << " ул." << users[g].street << " д." << users[g].house << " кв." << users[g].apart << endl << endl;
			cout << "[Enter] Вернуться в меню" << endl;
			cout << "[1] Показать список продуктов" << endl;
			char choose;
			bool flag1;
			flag1 = false;
			while (flag1 == false)
			{
				choose = _getch();
				switch (choose)
				{
				case 13:
				{
					flag1 = true;
					ofstream record("Basket.txt");
					userMenu();
					break;
				}
				case 49:
				{
					flag1 = true;
					clear();
					clear();
					basketInfo();
					for (int i = 0; i < tovarsNum; i++)
					{
						int n = i;
						cout << tovars[i].name << " ";
						cout << tovars[i].quantity;
						cout << tovars[i].si << endl;
						cout << tovars[i].count;
						cout << tovars[i].si2 << endl;
						cout << tovars[i].price << "р" << endl << endl;
					}
					cout << "[Enter] Вернуться в меню" << endl;
					char choose;
					bool flag2;
					flag2 = false;
					while (flag2 == false)
					{
						choose = _getch();
						switch (choose)
						{
						case 13:
							flag2 = true;
							ofstream record("Basket.txt");
							userMenu();
							break;
						}
					}
					break;
				}
				}
			}
			break;
		}
		case 49:
		{
			flag = true;
			customAdress();
		}
		case 27:
			flag = true;
			basket();
			break;
		}
	}
}

void changeCount()
{
	string str;
	clear();
	clear();
	clear();
	cout << "Введите название товара, кол-во которого хотите изменить: ";
	do
	{
		getline(cin, str);
		if (size(str) == 0)
		{
			clear();
		}
	} while (size(str) == 0);
	if (str[0] >= 'а' && str[0] <= 'я')
	{
		str[0] = 'А' + (str[0] - 'а');
	}
	if (str[0] == 'ё')
	{
		str[0] = 'Ё';
	}
	if (str == "1")
	{
		basket();
	}
	else
	{
		int l = 0, j = 0;
		for (int i = 0; i < tovarsNum; i++)
		{
			if (str == tovars[i].name)
			{
				l++;
				j = i;
			}
		}
		if (l != 0)
		{
			cout << "[1] Добавить" << endl;
			cout << "[2] Убрать" << endl;
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
					double count;
					cout << "Введите количество, которое нужно добавить: ";
					cin >> count;
					cin.ignore();
					clear();
					clear();
					clear();
					clear();
					cout << "Вы хотите добавить: ";
					cout << tovars[j].name;
					if (tovars[j].si2 == "кг")
					{
						cout << " " << count << " кг" << endl;
					}
					else
					{
						cout << " " << count << " шт" << endl;
					}
					cout << "Верно?" << endl;
					cout << "[1] Да" << endl;
					cout << "[2] Нет" << endl;
					char choose;
					bool flag1 = false;
					while (flag1 == false)
					{
						choose = _getch();
						switch (choose)
						{
						case 49:
						{
							flag1 = true;
							double newCount;
							newCount = tovars[j].count + count;
							ofstream record("Basket.txt");
							for (int i = 0; i < tovarsNum; i++)
							{
								if (tovars[i].count == tovars[j].count && tovars[i].name == tovars[j].name)
								{
									record << tovars[i].name << endl;
									record << tovars[i].quantity;
									record << " " << tovars[i].si << endl;
									record << newCount;
									record << " " << tovars[i].si2 << endl;
									record << (tovars[i].price / tovars[i].count) * newCount << endl;
								}
								else
								{
									record << tovars[i].name << endl;
									record << tovars[i].quantity;
									record << " " << tovars[i].si << endl;
									record << tovars[i].count;
									record << " " << tovars[i].si2 << endl;
									record << tovars[i].price * tovars[i].count << endl;
								}
							}
							basket();
							break;
						}
						case 50:
							flag1 = true;
							basket();
							break;
						}
					}
				}
				case 50:
				{
					flag = true;
					double count;
					cout << "Введите количество, которое нужно убрать: ";
					cin >> count;
					cin.ignore();
					clear();
					clear();
					clear();
					clear();
					cout << "Вы хотите убрать: ";
					cout << tovars[j].name;
					if (tovars[j].si2 == "кг")
					{
						cout << " " << count << " кг" << endl;
					}
					else
					{
						cout << " " << count << " шт" << endl;
					}
					cout << "Верно?" << endl;
					cout << "[1] Да" << endl;
					cout << "[2] Нет" << endl;
					char choose;
					bool flag1 = false;
					while (flag1 == false)
					{
						choose = _getch();
						switch (choose)
						{
						case 49:
						{
							flag1 = true;
							if (count == tovars[j].count)
							{
								ofstream record("Basket.txt");
								for (int i = 0; i < tovarsNum; i++)
								{
									if (tovars[i].name != tovars[j].name)
									{
										record << tovars[i].name << endl;
										record << tovars[i].quantity;
										record << " " << tovars[i].si << endl;
										record << tovars[i].count;
										record << " " << tovars[i].si2 << endl;
										record << tovars[i].price * tovars[i].count << endl;
									}
								}

							}
							else if (count > tovars[j].count)
							{
								cout << "Вы ввели неверное количество, попробуйте еще раз" << endl;
								_getch();
								clear();
								clear();
								changeCount();
							}
							else if (count < tovars[j].count)
							{
								double newCount;
								newCount = tovars[j].count - count;
								ofstream record("Basket.txt");
								for (int i = 0; i < tovarsNum; i++)
								{
									if (tovars[i].count != tovars[j].count && tovars[i].name != tovars[j].name)
									{
										record << tovars[i].name << endl;
										record << tovars[i].quantity;
										record << " " << tovars[i].si << endl;
										record << tovars[i].count;
										record << " " << tovars[i].si2 << endl;
										record << tovars[i].price * tovars[i].count << endl;
									}
									else
									{
										record << tovars[i].name << endl;
										record << tovars[i].quantity;
										record << " " << tovars[i].si << endl;
										record << newCount;
										record << " " << tovars[i].si2 << endl;
										record << (tovars[i].price / tovars[i].count) * newCount << endl;
									}
								}
							}
							basket();
							break;
						}
						case 50:
							flag1 = true;
							basket();
							break;
						}
					}
				}

				}

			}
		}
		else
		{
			cout << "Товар не найден";
			_getch();
			basket();
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

void basket()
{
	system("cls");
	basketInfo();
	orderCost = 0;
	if (tovarsNum == 0)
	{
		cout << "Ваша корзина пуста" << endl << endl;
		char choose;
		bool flag;
		flag = false;
		cout << "[Esc] Назад";
		while (flag == false)
		{
			choose = _getch();
			switch (choose)
			{
			case 27:
				flag = true;
				userMenu();
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < tovarsNum; i++)
		{
			int n = i;
			cout << tovars[i].name << " ";
			cout << tovars[i].quantity;
			cout << tovars[i].si << endl;
			cout << tovars[i].count;
			cout << tovars[i].si2 << endl;
			cout << tovars[i].price << "р" << endl << endl;
			orderCost += tovars[i].price;
		}
		cout << "Общая сумма заказа: " << orderCost << "р" << endl << endl;
		char choose;
		bool flag;
		flag = false;
		cout << "[Enter] Подтвердить заказ" << endl;
		cout << "[1] Изменить количество товара" << endl;
		cout << "[Esc] Вернуться в меню" << endl;
		while (flag == false)
		{
			choose = _getch();
			switch (choose)
			{
			case 13:
				flag = true;
				confrimOrder();
				break;
			case 49:
				flag = true;
				changeCount();
				break;
			case 27:
				flag = true;
				userMenu();
				break;
			}
		}
	}
}

void catalog()
{
	system("cls");
	cout << "\t\t\tПродуктовый каталог" << endl;
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
	while (flag == false)
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

void userCatalog()
{
	system("cls");
	cout << "\t\t\t Продуктовый каталог" << endl;
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
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49:
			flag = true;
			order_catalogFruitsVegetables();
			break;
		case 50:
			flag = true;
			order("MilkEggs.txt");
			break;
		case 51:
			flag = true;
			order("Bread.txt");
			break;
		case 52:
			flag = true;
			order_catalogMeat();
			break;
		case 53:
			flag = true;
			order("Drinks.txt");
			break;
		case 54:
			flag = true;
			order("Cereals.txt");
			break;
		case 55:
			flag = true;
			order("Pasta.txt");
			break;
		case 56:
			flag = true;
			order("Sweets.txt");
			break;
		case 57:
			flag = true;
			order("OilSauces.txt");
			break;
		case 27:
			flag = true;
			system("cls");
			userMenu();
			break;
		}
	}
}

void userProfile()
{
	system("cls");
	cout << "\t\t\tПрофиль" << endl << endl;
	cout << "Фамилия: " << users[g].surname << endl;
	cout << "Имя: " << users[g].name << endl;
	cout << "Отчество: " << users[g].patronymic << endl;
	cout << "Пол: " << users[g].sex << endl;
	cout << "Дата рождения: " << users[g].birthDate << endl;
	cout << "Страна: " << users[g].country << endl;
	cout << "Город: " << users[g].city << endl;
	cout << "Улица: " << users[g].street << endl;
	cout << "Дом: " << users[g].house << endl;
	cout << "Квартира: " << users[g].apart << endl;
	cout << "Номер телефона: +375" << users[g].phone << endl << endl;
	cout << "[1] Изменить информицию" << endl;
	cout << "[Esc] Вернуться назад";
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
			cout << "[1]" << "Фамилия: " << users[g].surname << endl;
			cout << "[2]" << "Имя: " << users[g].name << endl;
			cout << "[3]" << "Отчество: " << users[g].patronymic << endl;
			cout << "[4]" << "Пол: " << users[g].sex << endl;
			cout << "[5]" << "Дата рождения: " << users[g].birthDate << endl;
			cout << "[6]" << "Страна: " << users[g].country << endl;
			cout << "[7]" << "Город: " << users[g].city << endl;
			cout << "[8]" << "Улица: " << users[g].street << endl;
			cout << "[9]" << "Дом: " << users[g].house << endl;
			cout << "[10]" << "Квартира: " << users[g].apart << endl;
			cout << "[11]" << "Номер телефона: +375" << users[g].phone << endl;
			cout << "[12]" << "Пароль" << endl << endl;
			int point;
			bool flag1;
			flag1 = false;
			cout << "Введите номер пункта который хотите изменить " << endl << endl;
			cout << "Введите 0 чтобы вернуться назад" << endl;
			cout << "\033[2F";
			while (flag1 == false)
			{
				cout << "Пункт: ";
				cin >> point;
				cin.ignore();
				system("cls");
				cout << "Введите новые данные ";
				switch (point)
				{
				case 0:
					flag1 = true;
					userProfile();
					break;
				case 1:
					flag1 = true;
					writeStr("Фамилия", users[g].surname, "every", "user");
					break;
				case 2:
					flag1 = true;
					writeStr("Имя", users[g].name, "every", "user");
					break;
				case 3:
					flag1 = true;
					writeStr("Отчество", users[g].patronymic, "every", "user");
					break;
				case 4:
					flag1 = true;
					chooseSex(users[g].sex);
					break;
				case 5:
					flag1 = true;
					writeStr("Страна", users[g].country, "first", "user");
					break;
				case 6:
					flag1 = true;
					writeStr("Город", users[g].city, "first", "user");
					break;
				case 7:
					flag1 = true;
					writeStr("Улица", users[g].street, "first", "user");
					break;
				case 8:
					flag1 = true;
					writeHouse(users[g].house);
					break;
				case 9:
					flag1 = true;
					writeApart(users[g].apart);
					break;
				case 10:
					flag1 = true;
					writePhoneNum("Номер телефона: +375", users[g].phone, "user", "nelogin");
					break;
				case 11:
					flag = true;
					writePassword(users[g].password);
					break;
				}
			}
			break;
		}
		case 27:
		{
			flag = true;
			userMenu();
			break;
		}
		}
	}
	rewriteUsers();
	system("cls");
	cout << "Данные успешно изменены" << endl << endl;
	cout << "[Esc] Вернуться в профиль";
	char choose1;
	do
	{
		choose1 = _getch();
		if (choose1 == 27) userProfile();
	} while (choose1 != 27);
}

void catalogPlus()
{
	system("cls");
	cout << "\t\t\t Добавление товара" << endl;
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
			plus_catalogFruitsVegetables();
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
					catalogPlus();
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
					catalogPlus();
					break;
				}
			}
			break;
		}
		case 52:
			flag = true;
			plus_catalogMeat();
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
					catalogPlus();
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
					catalogPlus();
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
					catalogPlus();
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
					catalogPlus();
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
					catalogPlus();
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

void catalogMinus()
{
	system("cls");
	cout << "\t\t\t Удаление товара" << endl;
	cout << "[1] Овощи и фрукты" << endl;
	cout << "[2] Молоко, яйца" << endl;
	cout << "[3] Хлеб" << endl;
	cout << "[4] Мясо" << endl;
	cout << "[5] Напитки" << endl;
	cout << "[6] Крупы" << endl;
	cout << "[7] Макароны" << endl;
	cout << "[8] Сладости" << endl;
	cout << "[9] Масло, соусы" << endl << endl;
	cout << "[Esc] Вернуться в меню" << endl;
	char choose;
	bool flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49:
			flag = true;
			minus_catalogFruitsVegetables();
			break;
		case 50:
			flag = true;
			del("MilkEggs.txt");
			break;
		case 51:
			flag = true;
			del("Bread.txt");
			break;
		case 52:
			flag = true;
			minus_catalogMeat();
			break;
		case 53:
			flag = true;
			del("Drinks.txt");
			break;
		case 54:
			flag = true;
			del("Cereals.txt");
			break;
		case 55:
			flag = true;
			del("Pasta.txt");
			break;
		case 56:
			flag = true;
			del("Sweets.txt");
			break;
		case 57:
			flag = true;
			del("OilSauces.txt");
			break;
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
	cout << "\t\t\t Овощи и фрукты" << endl;
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

void order_catalogFruitsVegetables()
{
	system("cls");
	cout << "\t\t\t Овощи и фрукты" << endl;
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
			flag = true;
			order("Vegetables.txt");
			break;
		case 50:
			flag = true;
			order("Fruits.txt");
			break;
		case 51:
			flag = true;
			order("Berries.txt");
			break;
		case 52:
			flag = true;
			order("Greenery.txt");
			break;
		case 27:
			flag = true;
			system("cls");
			userCatalog();
			break;
		}
	}
}

void plus_catalogFruitsVegetables()
{
	system("cls");
	cout << "\t\t\t Добавление товара" << endl;
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
					add("Vegetables.txt");
					break;
				case 50:
					flag1 = true;
					plus_catalogFruitsVegetables();
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
				case 50: plus_catalogFruitsVegetables();
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
				case 50: plus_catalogFruitsVegetables();
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
				case 50: plus_catalogFruitsVegetables();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 27:
			flag = true;
			system("cls");
			catalogPlus();
			break;
		}
	}
}

void minus_catalogFruitsVegetables()
{
	system("cls");
	cout << "\t\t\t Удаление товара" << endl;
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
			flag = true;
			del("Vegetables.txt");
			break;
		case 50:
			flag = true;
			del("Fruits.txt");
			break;
		case 51:
			flag = true;
			del("Berries.txt");
			break;
		case 52:
			flag = true;
			del("Greenery.txt");
			break;
		case 27:
			flag = true;
			system("cls");
			catalogMinus();
			break;
		}
	}
}

void catalogMeat()
{
	system("cls");
	cout << "\t\t\t Мясо" << endl;
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

void order_catalogMeat()
{
	system("cls");
	cout << "\t\t\t Мясо" << endl;
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
		case 49: order("Pork.txt");
			flag = true;
			break;
		case 50: order("Chicken.txt");
			flag = true;
			break;
		case 51: order("Sauseges.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			userCatalog();
			break;
		}
	}
}

void plus_catalogMeat()
{
	system("cls");
	cout << "\t\t\t Добавление товара" << endl;
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
					plus_catalogMeat();
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
				case 50: plus_catalogMeat();
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
				case 50: plus_catalogMeat();
					flag1 = true;
					break;
				}
			}
			break;
		}
		case 27:
			flag = true;
			system("cls");
			catalogPlus();
			break;
		}
	}
}

void minus_catalogMeat()
{
	system("cls");
	cout << "\t\t\t Удаление товара" << endl;
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
		case 49: del("Pork.txt");
			flag = true;
			break;
		case 50: del("Chicken.txt");
			flag = true;
			break;
		case 51: del("Sauseges.txt");
			flag = true;
			break;
		case 27: system("cls");
			flag = true;
			catalogMinus();
			break;
		}
	}
}

void showUsers() 
{
	userInfo();
	system("cls");
	for (int i = 0; i < usersNum; i++)
	{
		cout << "Фамилия: " << users[i].surname << endl;
		cout << "Имя: " << users[i].name << endl;
		cout << "Отчество: " << users[i].patronymic << endl;
		cout << "Пол: " << users[i].sex << endl;
		cout << "Дата рождения: " << users[i].birthDate << endl;
		cout << "Страна: " << users[i].country << endl;
		cout << "Город: " << users[i].city << endl;
		cout << "Улица: " << users[i].street << endl;
		cout << "Дом: " << users[i].house << endl;
		cout << "Квартира: " << users[i].apart << endl;
		cout << "Номер телефона: +375" << users[i].phone << endl << endl;
	}
	cout << "Общее число пользователей: " << usersNum << endl << endl;
	char choose;
	bool flag;
	flag = false;
	cout << "[Esc] Вернуться в меню" << endl;
	do choose = _getch(); while (choose != 27);
	adminMenu();
}

void registration()
{
	string surname, name, patronymic, sex, birthDate, country = "Беларусь", city, street, house, apart,
		phone, password;
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "Введите 0 чтобы вернуться в главное меню" << endl;
	cout << "\033[22F";
	cout << "\t\t\t Регистрация" << endl;
	writeStr("Фамилия", surname, "every", "reg");
	writeStr("Имя", name, "every", "reg");
	writeStr("Отчество", patronymic, "every", "reg");
	chooseSex(sex);
	writeBirthDate(birthDate);
	cout << "Страна: " << country << endl;
	writeStr("Город", city, "first", "reg");
	writeStr("Улица", street, "first", "reg");
	writeHouse(house);
	writeApart(apart);
	writePhoneNum("Номер телефона: +375", phone, "reg", "main");
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

void writeStr(string x, string& y, string z, string where)
{
	while (true) {
		cout << x << ": ";
		getline(cin, y);
		if (y == "0") {
			if (where == "reg") mainMenu();
			else if (where == "user") userMenu();
			else if (where == "admin") adminMenu();
		}
		if (size(y) == 0) {
			clear();
			continue;
		}
		string correctstring = "ёйцукенгшщзхъфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ- ";
		int k = 0;
		for (int i = 0; i < size(y); i++) {
			int index;
			index = correctstring.find(y[i]);
			if (index >= 0) k++;
		}
		if (k == size(y)) {
			if (z == "every") {
				if (y[0] >= 'а' && y[0] <= 'я') y[0] = 'А' + (y[0] - 'а');
				if (y[0] == 'ё') y[0] = 'Ё';
				for (int i = 0; i < size(y); i++) {
					if (y[i] == ' ' || y[i] == '-') {
						if (y[i + 1] >= 'а' && y[i + 1] <= 'я') y[i + 1] = 'А' + (y[i + 1] - 'а');
						if (y[i + 1] == 'ё') y[i + 1] = 'Ё';
					}
				}
			}
			else if (z == "first") {
				if (y[0] >= 'а' && y[0] <= 'я') y[0] = 'А' + (y[0] - 'а');
				if (y[0] == 'ё') y[0] = 'Ё';
			}
			clear();
			cout << x << ": " << y << "\n";
			break;
		}
		else {
			clear(); continue;
		}
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
	}
	clear();
	cout << "Пол: " << x << endl;
}

void writeBirthDate(string& x)
{
	while (true) {
		cout << "Дата рождения (00 00 0000): ";
		string Numbers = "0123456789 ";
		getline(cin, x);
		if (x == "0") {
			mainMenu();
		}
		if (size(x) == 10) {
			int k = 0;
			if (x[2] == ' ' && x[5] == ' ' && size(x) == 10) {
				for (int i = 0; i < size(x); i++) {
					int index;
					index = Numbers.find(x[i]);
					if (index >= 0) k++;
				}
				if (k == 10) {
					SYSTEMTIME t;
					GetLocalTime(&t);
					string d, m, y;
					d = x.substr(0, 2); m = x.substr(3, 2); y = x.substr(6);
					if (((stoi(m) == 1 || stoi(m) == 3 || stoi(m) == 5 || stoi(m) == 7 || stoi(m) == 8 || stoi(m) == 10 || stoi(m) == 12) && stoi(d) <= 31)
						|| ((stoi(m) == 4 || stoi(m) == 6 || stoi(m) == 9 || stoi(m) == 11) && stoi(d) <= 30)
						|| (stoi(m) == 2 && stoi(d) <= 29)) {
						int age;
						if (stoi(y) < t.wYear) {
							if (stoi(m) > t.wMonth)	age = t.wYear - stoi(y) - 1;
							else if (stoi(m) < t.wMonth) age = t.wYear - stoi(y);
							else if (stoi(m) == t.wMonth) {
								if (stoi(d) > t.wDay) age = t.wYear - stoi(y) - 1;
								if (stoi(d) <= t.wDay) age = t.wYear - stoi(y);
							}
							if (age >= 16 && age <= 120) {
								clear();
								cout << "Дата рождения: ";
								x = d + '.' + m + '.' + y;
								cout << x << endl;
								break;
							}
							else if (age > 120 || age < 1) {
								clear(); continue;
							}
							else if (age >= 1 && age < 16) {
								cout << "Пользоваться услугами нашего сервиса можно только с 14-ти лет." << endl << "Нажмите любую клавишу чтобы повторить." << endl;
								_getch(); clear(); clear(); clear(); continue;
							}
						}
						else {
							clear(); continue;
						}
					}
					else {
						clear(); continue;
					}
				}
				else {
					clear(); continue;
				}
			}
			else {
				clear(); continue;
			}
		}
		else {
			clear(); continue;
		}
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
			mainMenu();
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

void writePhoneNum(string y, string& x, string type, string where)
{
	userInfo();
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
					writePhoneNum(y, x, type, where);
				}
				int ph = 0;
				for (int i = 0; i < usersNum; i++)
				{
					if (users[i].phone == x) ph++;
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
							writePhoneNum(y, x, type, where);
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
					cout << "Этот номер не зарегистрирован в системе." << endl;
					cout << "Нажмите Enter чтобы повторить." << endl;
					_getch();
					clear();
					clear();
					clear();
					writePhoneNum(y, x, type, where);
				}
			}
			else
			{
				clear();
				writePhoneNum(y, x, type, where);
			}
		}
	}
	else
	{
		clear();
		writePhoneNum(y, x, type, where);
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

void rewriteUsers()
{
	ofstream record("Users.txt");
	for (int i = 0; i < usersNum; i++)
	{
		record << users[i].surname << "\n";
		record << users[i].name << "\n";
		record << users[i].patronymic << "\n";
		record << users[i].sex << "\n";
		record << users[i].birthDate << "\n";
		record << users[i].country << "\n";
		record << users[i].city << "\n";
		record << users[i].street << "\n";
		record << users[i].house << "\n";
		record << users[i].apart << "\n";
		record << users[i].phone << "\n";
		record << users[i].password << "\n";
	}
	record.close();
}

void customAdress()
{
	system("cls");
	string city, street, house, apart;
	cout << "Введите новый адрес доставки: " << endl;
	writeStr("Город", city, "first", "user");
	writeStr("Улица", street, "first", "user");
	writeHouse(house);
	writeApart(apart);
	cout << "г." << city << " ул." << street << " д." << house << " кв." << apart << endl;
	cout << "Адрес указан верно?" << endl << endl;
	cout << "[1] Да" << endl;
	cout << "[2] Нет" << endl;
	cout << "[Esc] Назад" << endl;
	char choose;
	bool flag;
	flag = false;
	while (flag == false)
	{
		choose = _getch();
		switch (choose)
		{
		case 49:
		{
			flag = true;
			system("cls");
			cout << "Заказ принят" << endl;
			cout << "Общая сумма заказа: " << orderCost << "р" << endl;
			cout << "Адрес доставки г." << city << " ул." << street << " д." << house << " кв." << apart << endl << endl;
			cout << "[Enter] Вернуться в меню" << endl;
			cout << "[1] Показать список продуктов" << endl;
			char choose;
			bool flag1;
			flag1 = false;
			while (flag1 == false)
			{
				choose = _getch();
				switch (choose)
				{
				case 13:
				{
					flag1 = true;
					ofstream record("Basket.txt");
					userMenu();
					break;
				}
				case 49:
				{
					flag1 = true;
					clear();
					clear();
					basketInfo();
					for (int i = 0; i < tovarsNum; i++)
					{
						int n = i;
						cout << tovars[i].name << " ";
						cout << tovars[i].quantity;
						cout << tovars[i].si << endl;
						cout << tovars[i].count;
						cout << tovars[i].si2 << endl;
						cout << tovars[i].price << "р" << endl << endl;
					}
					cout << "[Enter] Вернуться в меню" << endl;
					char choose;
					bool flag2;
					flag2 = false;
					while (flag2 == false)
					{
						choose = _getch();
						switch (choose)
						{
						case 13:
							flag2 = true;
							ofstream record("Basket.txt");
							userMenu();
							break;
						}
					}
					break;
				}
				}
			}
		}
		case 50:
			flag = true;
			customAdress();
			break;
		case 27:
			flag = true;
			confrimOrder();
			break;
		}
	}
}

void login()
{
	userInfo();

	string userPhone, userPassword;
	int k = 0, j;
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "Введите 0 чтобы вернуться в главное меню" << endl;
	cout << "\033[10F";
	cout << "\t\t\t Авторизация" << endl;
	writePhoneNum("Номер телефона: +375", userPhone, "search", "main");
	for (int i = 0; i < usersNum; i++)
	{
		if (userPhone == users[i].phone)
		{
			k++;
			j = i;
			g = i;
		}
	}
	if (k != 0)
	{
		int n = 2;
		while (true)
		{
			cout << "Пароль: ";
			getline(cin, userPassword);
			if (size(userPassword) == 0) {
				clear(); continue;
			}
			if (userPassword == "0") {
				mainMenu(); break;
			}
			if (userPassword == users[j].password) userMenu();
			else
			{
				if (n == 2) cout << "Неверный пароль. У вас осталось 2 попытки" << endl << "Нажмите Enter чтобы повторить попытки." << endl;
				else cout << "Неверный пароль. У вас осталось 1 попытка" << endl << "Нажмите Enter чтобы повторить попытку." << endl;
				if (n == 0) {
					mainMenu(); break;
				}
				n--;
				_getch();
				clear(); clear(); clear(); continue;
			}
		}
	}
	else
	{
		cout << "Пользователь с этим номером не найден." << endl << "Нажмите Enter чтобы повторить." << endl;
		_getch();
		login();
	}
}

void adminLogin()
{
	adminInfo();
	string adminsLogin, adminPassword;
	int k = 0, j;
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "Введите 0 чтобы вернуться в главное меню" << endl;
	cout << "\033[10F";
	cout << "\t\t\t Вход от имени администратора" << endl;
	do
	{
		cout << "Логин: ";
		getline(cin, adminsLogin);
		if (size(adminsLogin) == 0) clear();
	} while (size(adminsLogin) == 0);
	if (adminsLogin == "0") mainMenu();
	for (int i = 0; i < adminsNum; i++)
	{
		if (adminsLogin == admins[i].login)
		{
			k++;
			j = i;
		}
	}
	if (k != 0)
	{
		int n = 2;
		while (true)
		{
			cout << "Пароль: ";
			getline(cin, adminPassword);
			if (size(adminPassword) == 0) {
				clear(); continue;
			}
			if (adminPassword == "0") {
				mainMenu(); break;
			}
			if (adminPassword == admins[j].password) adminMenu();
			else
			{
				if (n == 2) cout << "Неверный пароль. У вас осталось 2 попытки" << endl << "Нажмите Enter чтобы повторить попытки." << endl;
				else cout << "Неверный пароль. У вас осталось 1 попытка" << endl << "Нажмите Enter чтобы повторить попытку." << endl;
				if (n == 0) {
					mainMenu(); break;
				}
				n--;
				_getch();
				clear(); clear(); clear(); continue;
			}
		}
	}
	else
	{
		cout << "Данный логин не найден." << endl << "Нажмите Enter чтобы повторить." << endl;
		_getch();
		adminLogin();
	}
}

void userInfo()
{
	ifstream read_num("Users.txt");
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	}
	usersNum = k / 12;
	read_num.close();
	delete[]users;
	users = new user[usersNum];
	ifstream read("Users.txt");
	for (int i = 0; i < usersNum; i++)
	{
		getline(read, users[i].surname);
		getline(read, users[i].name);
		getline(read, users[i].patronymic);
		getline(read, users[i].sex);
		getline(read, users[i].birthDate);
		getline(read, users[i].country);
		getline(read, users[i].city);
		getline(read, users[i].street);
		getline(read, users[i].house);
		getline(read, users[i].apart);
		getline(read, users[i].phone);
		getline(read, users[i].password);
	}
	read.close();
}

void adminInfo()
{
	ifstream read_num("Admins.txt");
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	}
	adminsNum = k / 2;
	read_num.close();
	delete[]admins;
	admins = new admin[adminsNum];
	ifstream read("Admins.txt");
	for (int i = 0; i < adminsNum; i++)
	{
		getline(read, admins[i].login);
		getline(read, admins[i].password);
	}
	read.close();
}

void tovarInfo(string path)
{
	ifstream read_num(path);
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	}
	tovarsNum = k / 3;
	read_num.close();
	delete[]tovars;
	tovars = new tovar[tovarsNum];
	ifstream read(path);
	for (int i = 0; i < tovarsNum; i++)
	{
		getline(read, tovars[i].name);
		read >> tovars[i].quantity;
		read.ignore();
		read >> tovars[i].si;
		read.ignore();
		read >> tovars[i].price;
		read.ignore();
	}
	read.close();
}

void basketInfo()
{
	ifstream read_num("Basket.txt");
	string str;
	int k = 0;
	while (!read_num.eof())
	{
		getline(read_num, str);
		k++;
	}
	tovarsNum = k / 4;
	read_num.close();
	delete[]tovars;
	tovars = new tovar[tovarsNum];
	ifstream read("Basket.txt");
	for (int i = 0; i < tovarsNum; i++)
	{
		getline(read, tovars[i].name);
		read >> tovars[i].quantity;
		read.ignore();
		read >> tovars[i].si;
		read.ignore();
		read >> tovars[i].count;
		read.ignore();
		read >> tovars[i].si2;
		read.ignore();
		read >> tovars[i].price;
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