// klass String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "String.h"
#include <iostream>
#include <locale>
#include <Windows.h>



char * Stroka(char *mass, unsigned char iSize, int i = 0){
	std::cout << "Введите строку:";
	if (i == 0)std::cin.get();
	fgets(mass, iSize, stdin);
	return mass;
}
void Constructor_string(char *mass, unsigned char iSize){
	String s2(Stroka(mass, iSize));
}

void Count_simvol(char *mass, unsigned char iSize){
	String s2(Stroka(mass, iSize));
	std::cout << s2.Icount() << std::endl;
}

void Clear_func(char *mass, unsigned char iSize){
	String s2(Stroka(mass, iSize));
	s2.Clear();
}

void Operator_index(char *mass, unsigned char iSize){
	int number;
	String s2(Stroka(mass, iSize));
	std::cout << "Введите индекс:";
	std::cin >> number;
	std::cout << s2[number] << std::endl;
}

void Operator_out(char *mass, unsigned char iSize){
	String s2(Stroka(mass, iSize));
	std::cout << s2;
}

void Operator_comparison(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	bool thet = s1 == s2;
	std::cout << thet << std::endl;
}

void Operator_comparison_string(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	bool thet = s1 != s2;
	std::cout << thet << std::endl;
}

void Operator_addition_object(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	String s3 = s1 + s2;
}

void Constructor_string_number(char *mass, unsigned char iSize){
	int number;
	std::cout << "Введите количество символов:";
	std::cin >> number;
	String s2Stroka((mass, iSize), number);
}
void Operator_concatenation(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	s1 += s2;
	std::cout << s1 << std::endl;
}

void Operator_less(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	bool thet = s1 < s2;
	if (thet){
		std::cout << "Правда" << std::endl;
	}
	else std::cout << "Ложь" << std::endl;
}

void Operator_more(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	bool thet = s1 > s2;
	if (thet){
		std::cout << "Правда" << std::endl;
	}
	else std::cout << "Ложь" << std::endl;
}

void Metod_Privat(char *mass, unsigned char iSize){
	String s2(Stroka(mass, iSize));
	const char *buf_arr = s2.Privat();
	if (buf_arr != NULL)std::cout << *buf_arr;
}

void Metod_down_registr(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	s1.Down_registr();
	std::cout << s1 << std::endl;
}

void Metod_up_registr(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	s1.Up_registr();
	std::cout << s1 << std::endl;
}

void Constructor_simvol_number(char *mass, unsigned char iSize){
	std::size_t i = 0;
	char simb = { 0 };
	std::cout << "Введите значение для выделения памяти:";
	std::cin >> i;
	std::cout << "Введите символ заполнения:";
	std::cin >> simb;
	String s1(i, simb);
}

void Metod_inserd(char *mass, unsigned char iSize){
	std::size_t i = 0;
	String s1(Stroka(mass, iSize));
	String s2(Stroka(mass, iSize, 1));
	std::cout << "Введите значения индекс:";
	std::cin >> i;
	s2.Insert(i, s1);
}

void Metod_delete(char *mass, unsigned char iSize){
	std::size_t i = 0;
	std::size_t j = 0;
	String s1(Stroka(mass, iSize));
	std::cout << "Введите стартовый индекс:";
	std::cin >> i;
	std::cout << "Введите финальны индекс:";
	std::cin >> j;
	s1.Delete(i, j);
}

void Metod_index_char(char *mass, unsigned char iSize){
	String s1(Stroka(mass, iSize));
	char simvol = { 0 };
	std::cout << "Введите искомый символ:";
	std::cin >> simvol;
	int index = s1.Index_char(simvol);
	if (index >= 0)std::cout << "Индекс символа:" << index << std::endl;
}

void Metod_find_string(char *mass, unsigned char iSize){
	std::size_t i = 0;
	String s(Stroka(mass, iSize));
	std::cout << "Введите искомую строку:";
	fgets(mass, iSize, stdin);
	std::cout << "Введите индекс поиска:";
	std::cin >> i;
	auto index = s.Find(mass,i);
	if (index != nullptr)std::cout << *index;
	else std::cout << "Eror" << std::endl;
}

void Metod_sort(char *mass, unsigned char iSize){
	String s(Stroka(mass, iSize));
	s.Sort();
	std::cout << s << std::endl;
}

void Work_one_object(char *mass, unsigned char iSize, int choise, char * buf){
	std::cout << "1)Конструктор принимающий в параметрах указатель на строку " << std::endl;
	std::cout << "2)Возвращающий количество символов в хранимой строек" << std::endl;
	std::cout << "3)Метод очистки строки и освобождения памяти" << std::endl;
	std::cout << "4)Оператор индексации" << std::endl;
	std::cout << "5)Оператор вывода содержимого на консоль" << std::endl;
	std::cout << "6)Конструктор принимающий в параметрах указатель на строку в стиле Си и количество символов" << std::endl;
	std::cout << "7)Метод возвращающий указатель на хранимую в private указатель на массив типа char" << std::endl;
	std::cout << "8)Метод переводящий все символы в нижний регистр " << std::endl;
	std::cout << "9)Метод переводящий все символы в верхний регистр" << std::endl;
	std::cout << "10)Конструктор принимающий в параметрах целочисленное значение и символ заполнитель" << std::endl;
	std::cout << "11)Метод удаления" << std::endl;
	std::cout << "12)Мето поиска символа в строке" << std::endl;
	std::cout << "13)Метод поиска строки" << std::endl;
	std::cout << "14)Метод сортировки" << std::endl;
	std::cout << "Ваш выбор:";
	std::cin >> buf;
	choise = atoi(buf);
	if (choise == 1)Constructor_string(mass, iSize);
	if (choise == 2)Count_simvol(mass, iSize);
	if (choise == 3)Clear_func(mass, iSize);
	if (choise == 4)Operator_index(mass, iSize);
	if (choise == 5)Operator_out(mass, iSize);
	if (choise == 6)Constructor_string_number(mass, iSize);
	if (choise == 7)Metod_Privat(mass, iSize);
	if (choise == 8)Metod_down_registr(mass, iSize);
	if (choise == 9)Metod_up_registr(mass, iSize);
	if (choise == 10)Constructor_string_number(mass, iSize);
	if (choise == 11)Metod_delete(mass, iSize);
	if (choise == 12)Metod_index_char(mass, iSize);
	if (choise == 13)Metod_find_string(mass, iSize);
	if (choise == 14)Metod_sort(mass, iSize);
}

void Work_two_object(char *mass, unsigned char iSize, int choise, char* buf){
	std::cout << "1)Оператор сравнения двух объектов класса String на равенство по содержимому" << std::endl;
	std::cout << "2)Оператор сравнения на неравенство двух объектов класса String по длинам строк" << std::endl;
	std::cout << "3)Оператор сложения двух объектов класса" << std::endl;
	std::cout << "4)Оператор контактенации строк" << std::endl;
	std::cout << "5)Оператор <" << std::endl;
	std::cout << "6)Оператор >" << std::endl;
	std::cout << "7)Метод вставки" << std::endl;
	std::cout << "Ваш выбор:";
	std::cin >> buf;
	choise = atoi(buf);
	if (choise == 1)Operator_comparison(mass, iSize);
	if (choise == 2)Operator_comparison_string(mass, iSize);
	if (choise == 3)Operator_addition_object(mass, iSize);
	if (choise == 4)Operator_concatenation(mass, iSize);
	if (choise == 5)Operator_less(mass, iSize);
	if (choise == 6)Operator_more(mass, iSize);
	if (choise == 7)Metod_inserd(mass, iSize);
}

int main(){
	setlocale(LC_ALL, "ru");
	enum Size :unsigned char{ iSize = 155, buffer = 10 };
	char mass[iSize] = { 0 };
	char buf[buffer] = { 0 };
	int choise = 0;
	while (choise != 3){
		std::cout << "1)Действие с одним обьектом" << std::endl;
		std::cout << "2)Действие с двумя обьектами" << std::endl;
		std::cout << "3)Выход" << std::endl;
		std::cout << "4)Ваш выбор:";
		std::cin >> buf;
		choise = atoi(buf);
		if (choise == 1)Work_one_object(mass,iSize,choise,buf);
		if (choise == 2)Work_two_object(mass, iSize, choise,buf);
		system("pause");
		system("cls");
		}
	return 0;
}

