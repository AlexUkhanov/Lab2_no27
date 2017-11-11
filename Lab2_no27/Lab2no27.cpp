/*27. Создать абстрактный класс Currency для работы с денежными суммами.Определить
виртуальные функции перевода в рубли и вывода на экран.Реализовать производные
классы Dollar и Euro.
Автор: Алексей Уханов*/


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

class Currency
{
protected:
	double amount; //количество денег
	double rate; //текущий курс валюты
public:

	virtual void Display() = 0;
	virtual double Convert(int choise) = 0;
	virtual string toString() = 0;

	Currency() //инициализация нулями
	{
		amount = 0;
		rate = 0;
	}

	void Read()
	{
		cout << "Введите сумму денег" << endl;
		while (amount <= 0)
			cin >> amount;
	}
};

class Dollar : public Currency
{
public:
	Dollar()
	{
		rate = 59.18; //курс доллара на 11.11.2017
	}
	/*конвертирует в рубли и выводит на экран,
	choise принимает значения 0-работать стандартно
	1-вернуть результат с заданным по-умолчанию курсом
	2-задать курс, а позже вычислить сумму в рублях*/
	virtual double Convert(int choise)
	{
		if (choise != 1)
		{
			cout << "Выберите пункт:" << endl;
			cout << "1 - Посчитать по курсу доллара за 11.11.2017" << endl;
			cout << "2 - Ввести актуальные данные" << endl;
		}
		while ((choise != 1) && (choise != 2))
		{
			cin >> choise;
		}
		if (choise == 2)
		{
			cout << "Введите курс доллара:" << endl;
			rate = 0;
			while (rate <= 0)
				cin >> rate;
		}
		return amount*rate;
	}

	virtual void Display()
	{
		cout.width(2);//устанавливаем вывод до 2 знаков после запятой
		cout << "Курс:" << rate << " рублей за доллар" << endl;
		cout << "В наличии:" << amount << " долларов, т.е. " << Convert(1) << " рублей" << endl;
	}

	virtual string toString()
	{
		ostringstream out;
		out << "Курс:" << rate << " рублей за доллар" << endl;
		out << "В наличии:" << amount << " долларов, т.е. " << Convert(1) << " рублей" << endl;
		return out.str();
	}

};

class Euro : public Currency
{
public:
	Euro()
	{
		rate = 69.03;//курс доллара на 11.11.2017
	}
	/*конвертирует в рубли и выводит на экран,
	choise принимает значения 0-работать стандартно
	1-вернуть результат с заданным по-умолчанию курсом
	2-задать курс, а позже вычислить сумму в рублях*/
	virtual double Convert(int choise)
	{
		if (choise != 1)
		{
			cout << "Выберите пункт:" << endl;
			cout << "1 - Посчитать по курсу евро за 11.11.2017" << endl;
			cout << "2 - Ввести актуальные данные" << endl;
		}
		while ((choise != 1) && (choise != 2))
		{
			cin >> choise;
		}
		if (choise == 2)
		{
			cout << "Введите курс евро:" << endl;
			rate = 0;
			while (rate <= 0)
				cin >> rate;
		}
		return amount*rate;
	}
	virtual void Display()
	{
		cout.width(2); //устанавливаем вывод до 2 знаков после запятой
		cout << "Курс:" << rate << " рублей за евро" << endl;
		cout << "В наличии:" << amount << " евро, т.е. " << Convert(1) << " рублей" << endl;
	}
	virtual string toString()
	{
		ostringstream out;
		out << "Курс:" << rate << " рублей за евро" << endl;
		out << "В наличии:" << amount << " евро, т.е. " << Convert(1) << " рублей" << endl;
		return out.str();
	}
};


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	Dollar d;
	Euro e;

	int anwser = -1;

	while (anwser != 0)
	{
		cout << "Меню" << endl;
		cout << "1 - Задать сумму долларов" << endl;
		cout << "2 - Задать сумму евро" << endl;
		cout << "3 - Конвертировать доллары в рубли" << endl;
		cout << "4 - Конвертировать евро в рубли" << endl;
		cout << "5 - Вывести информацию о долларах" << endl;
		cout << "6 - Вывести информацию о евро" << endl;
		cout << "7 - Тест вывода в строку для долларов" << endl;
		cout << "8 - Тест вывода в строку для евро" << endl;
		cout << "0 - Выход" << endl;

		cin >> anwser;
		while ((anwser < 0) || (anwser > 8))
		{
			cout << "Ошибка ввода. Повторите ввод:" << endl;
			cin >> anwser;
		}

		switch (anwser)
		{
		case 1:
			d.Read();
			break;
		case 2:
			e.Read();
			break;
		case 3:
			cout << d.Convert(0) << " рублей" << endl;
			break;
		case 4:
			cout << e.Convert(0) << " рублей" << endl;
			break;
		case 5:
			d.Display();
			break;
		case 6:
			e.Display();
			break;
		case 7:
			cout << d.toString() << endl;
			break;
		case 8:
			cout << e.toString() << endl;
			break;
		}

	};

	return 0;
}

