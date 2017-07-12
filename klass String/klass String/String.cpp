#include "stdafx.h"
#include "String.h"


String::String()
{
	this->arr = { 0 };
}


String::~String()
{
	delete[] this->arr;
}

String::String(const String &m) :size(m.size), arr(new char[m.size])                           //copy constructor
{
	if (m.arr == nullptr)return;
	memcpy_s(this->arr, sizeof(char)*this->size, m.arr, m.size);
}

String::String(String &&m) : arr(m.arr)                                                        //migration constructor
{
	m.arr = nullptr;
}

String::String(const char *buf){                                                               //row copy constructor
	if (buf == nullptr || buf[0] == '\0')return;
	this->size = strlen(buf) + 1;
	this->arr = new char[this->size];
	if (buf[this->size - 2] == '\n')this->size = this->size - 1;
	strncpy_s(this->arr, this->size, buf, this->size - 1);
}

String::String(std::size_t i, char c){                                                         // fillout character fill character
	this->size = i + 1;
	this->arr = new char[this->size];
	_strnset(this->arr, c, this->size);
	this->arr[this->size - 1] = '\0';
}

String::String(const char *buf, std::size_t n){                                                 //string constructor and number of elements
	if (buf == nullptr || strlen(buf) == 0) return;
	if (n == 0 || n > strlen(buf))this->size = strlen(buf) + 1;                                  //check for too high values 
	else this->size = n + 1;
	if (buf[this->size - 2] == '\n')this->size = this->size - 1;
	this->arr = new char[this->size];
	memset(this->arr, 0, this->size);
	memcpy_s(this->arr, sizeof(char)*this->size, buf, this->size - 1);
}

String & String::operator+=(const String &m){                                                //concatenation
	if (this->arr == nullptr && m.arr == nullptr){
		String buf;
		return buf;
	}
	if (this->arr == nullptr){
		this->arr = nullptr;
		this->size = m.size;
		this->arr = new char[this->size];
		memset(this->arr, 0, this->size);
		memcpy_s(this->arr, sizeof(char)*this->size, m.arr, m.size);
		return *this;
	}
	if (m.arr == nullptr) return *this;
	if (this->arr == m.arr) return *this;
	String buf;
	delete[] buf.arr;
	buf.arr = nullptr;
	buf.size = this->size;
	buf.arr = new char[buf.size];
	memset(buf.arr, 0, buf.size);
	memcpy_s(buf.arr, sizeof(char)*buf.size, this->arr, this->size);
	delete[] this->arr;
	this->arr = nullptr;
	this->size = (this->size + m.size) - 1;
	this->arr = new char[this->size];
	memset(this->arr, 0, this->size);
	memcpy_s(this->arr, sizeof(char)*this->size, buf.arr, buf.size);
	strcat_s(this->arr, this->size, m.arr);
	return *this;
}

bool & String :: operator <(const String &m)const{                                                //operator <
	bool a;
	if (this->arr == nullptr || m.arr == nullptr)return a;
	this->size <= m.size ? a = true : a = false;
	return a;
}

bool & String ::operator>(const String &m)const{                                                //operator >
	bool a;
	if (this->arr == nullptr || m.arr == nullptr)return a;
	this->size >= m.size ? a = true : a = false;
	return a;
}

String & String:: operator = (const String &m){                                                 //assignment operator
	if (&m == this)return *this;
	if (m.arr == nullptr)return *this;
	delete[] this->arr;
	this->arr = nullptr;
	this->size = m.size;
	this->arr = new char[this->size];
	memcpy_s(this->arr, sizeof(char)*this->size, m.arr, m.size);                              //copying line items
	return *this;                                                                             // each operator should return a reference to the object under which it was called
}

String & String::operator=(String&&m){                                                        // carry statement
	if (&m == this)return *this;
	if (m.arr == nullptr)return *this;
	delete[] this->arr;
	this->arr = nullptr;
	this->size = m.size;
	this->arr = m.arr;
	m.arr = nullptr;
	return *this;
}

char & String::operator[](std::size_t i){                                                     //operator index
	if (this->size < i){
		char a = '0';
		std::cout << "Неправильное значение параметра" << std::endl;
		return a;
	}
	return this->arr[i - 1];
}

const char & String::operator[](std::size_t i)const{                                         //const operator index
	if (this->size < i){
		char a = '0';
		std::cout << "Неправильное значение параметра" << std::endl;
		return a;
	}
	return this->arr[i];
}

bool & String::operator == (const String &m)const{                                           //comparison operator
	bool a = false;
	if (this->arr == nullptr || m.arr == nullptr)return a;
	(this->size == m.size && strcmp(this->arr, m.arr) == 0) ? a = true : a = false;
	return a;
}

bool & String :: operator!=(const String &m)const{                                             //// comparison operator string object
	bool a = false;
	if (this->arr == nullptr || m.arr == nullptr)return a;
	strcmp(this->arr, m.arr) == 0 ? a = true : a = false;
	return a;
}

String String::operator+(const String &m)const{                                                 // the operator of summation of objects
	if (this->arr == nullptr && m.arr == nullptr){
		String buf;
		return buf;
	};
	if (this->arr == nullptr) return m;
	if (m.arr == nullptr) return *this;
	String buf;
	buf.size = m.size + this->size - 1;
	buf.arr = new char[buf.size];
	memcpy_s(buf.arr, sizeof(char)*buf.size, this->arr, this->size);
	strcat(buf.arr, m.arr);
	return buf;
}

int String::Icount()const{                                                                  //counting the number of elements
	if (this->arr == nullptr){
		std::cout << "Пустой объект" << std::endl;
		return 0;
	}
	return strlen(this->arr);
}


std::ostream & operator << (std::ostream & os, const String &m){                           //operator in
	if (m.arr == nullptr){
		return os << "Пустой обьект";
	}
	os << m.arr;
	return os;
}

void String::Clear(){                                                                     //method of stripping and nulling values
	if (this->arr == nullptr){
		std::cout << "Пустой объект" << std::endl;
		return;
	}
	delete[] this->arr;
	this->arr = nullptr;
	this->size = 0;
}

const char * String::Privat(){                                                             //method to return a pointer to a string in public
	return this->arr;
}

void String::Down_registr(){                                                                   //metov translation of the symbols in the lower case
	if (this->arr == nullptr || this->size == 0) return;
	for (auto i = std::size_t(0); i < this->size; i++){
		if ((int)this->arr[i] >= 65 && (int)this->arr[i] <= 90){
			this->arr[i] = (int)arr[i] + 32;
		}
	}
}

void String::Up_registr(){                                                                      //method of translating characters to the parent register
	if (this->arr == nullptr || this->size == 0) return;
	for (auto i = std::size_t(0); i < this->size; i++){
		if ((int)this->arr[i] >= 97 && (int)this->arr[i] <= 122){
			this->arr[i] = (int)arr[i] - 32;
		}
	}
}

char* String::Insert(std::size_t i, const String &m){                                                   //insert method
	if (this->arr == nullptr || m.arr == nullptr){
		std::cout << "Пустой обьект" << std::endl;
		return 0;
	}
	if (i >= this->size || i == 0){
		std::cout << "Неправильное значения параметров" << std::endl;
		return 0;
	}
	String buf;
	buf.size = this->size;
	buf.arr = new char[buf.size];
	memcpy_s(buf.arr, buf.size*sizeof(char), this->arr, sizeof(char)*this->size);
	delete[] this->arr;
	this->arr = nullptr;
	this->size = (this->size + m.size) - 1;
	this->arr = new char[this->size];
	memset(this->arr, 0, this->size);
	strncat(this->arr, buf.arr, i);
	strcat(this->arr, m.arr);
	buf.arr = buf.arr + i;
	strcat(this->arr, buf.arr);
	buf.arr = buf.arr - i;
	return this->arr;
}


char* String::Delete(std::size_t start, std::size_t end){                                                       // delete method
	if (this->arr == nullptr){
		std::cout << "Пустой обьект" << std::endl;
		return 0;
	}
	if (end == 0)end = this->size - 1;
	if (start > end || start > this->size || end > this->size){
		std::cout << "Не верные параметры" << std::endl;
		return 0;
	}
	if (start == 0){
		this->Clear();
		return this->arr;
	}
	String buf;
	buf.size = this->size;
	buf.arr = new char[buf.size];
	memcpy_s(buf.arr, buf.size*sizeof(char), this->arr, sizeof(char)*this->size);
	delete[] this->arr;
	this->arr = nullptr;
	this->size = this->size - (end - start);
	this->arr = new char[this->size];
	memset(this->arr, 0, (this->size - 1));
	strncat(this->arr, buf.arr, start);
	buf.arr = buf.arr + (end);
	strcat(this->arr, buf.arr);
	buf.arr = buf.arr - (end);
	return this->arr;
}

int String::Index_char(char c){
	if (this->arr == nullptr){
		std::cout << "Обьект пуст" << std::endl;
		return -1;
	}
	std::size_t i = 0;
	for (; this->arr[i] != c & i < this->size - 1; i++);
	if (i == this->size - 1){
		std::cout << "Обьект не найден" << std::endl;
		return -1;
	}
	return i;
}


String* String::Find(char *buf, std::size_t i){
	if (buf[strlen(buf) - 1] == '\n'){
		buf[strlen(buf) - 1] = '\0';
	}
	if (buf[0] == ' ')buf = buf + 1;
	int worls = 0;
	for (std::size_t i = 0; i < strlen(buf);){
		for (; buf[i] != ' '; i++);
		for (; buf[i] == ' '; i++);
		if (i = this->size-1)break;
		worls++;
		if (worls > 0)return 0;
	}
	if (i > (this->size - 1) || buf == nullptr)return 0;
	if (this->arr == nullptr)return 0;
	int object = 0;
	std::size_t sum = i;
	std::size_t b = i;
	if (i != 0){
		if ((this->arr + sum)[0] == ' '){
			std::size_t j = 1;
			for (; this->arr[j] == ' ' && j < this->size; j++);
			sum = j;
		}
		else if (this->arr[0] != ' '){
			std::size_t j = 1;
			for (; this->arr[j] != ' ' && j < this->size; j++);
			for (; this->arr[j] == ' ' && j < this->size; j++);
			sum = j;
		}
	}
	for (std::size_t j = 0; sum < this->size - 1;){
		int k = strncmp(this->arr + sum, buf, strlen(buf));
		if (k == 0)object++;
		for (; this->arr[b] != ' ' && j < this->size; b++, j++);
		for (; this->arr[b] == ' '&& j < this->size; b++, j++);
		sum += b;
		b = 0;
		if (sum >= this->size)break;
	}
	std::cout << object << std::endl;
	if (object > 0){
		String *new_arr = new String[object];
		for (int i = 0; i < object; i++)new_arr[i] = String(buf);
		return new_arr;
	}
	if (object == 0){
		return 0;
	}
}

String String::Sort(){
	if (this->arr == nullptr)return *this;
	std::size_t number = 0, sum = 0;
	for (std::size_t i = 0; i < this->size; i++){
		for (; this->arr[i] != ' ' && i < this->size; i++);
		for (; this->arr[i] == ' '&& i < this->size; i++);
		number++;
	}
	char **arr_buf = new char*[number];
	for (int i = 0; i < number; i++){
		arr_buf[i] = new char[35];
		memset(arr_buf[i], 0, 35);
	}
	number = 0;
	std::size_t z = 0;
	for (std::size_t i = 0; i < this->size;){
		std::size_t letter = 0;
		for (; this->arr[i] != ' ' && this->arr[i] != '\0'; letter++, i++);
		strncat(arr_buf[number], this->arr + sum, letter);
		arr_buf[number][strlen(arr_buf[number])] = ' ';
		arr_buf[number][strlen(arr_buf[number]) + 1] = '\0';
		for (; this->arr[i] == ' '&& this->arr[i] != '\0'; z++, i++);
		if (i == this->size - 1)break;
		sum = i;
		number++;
	}
	memset(this->arr, 0, this->size);
	char min[35];
	for (std::size_t i = 0; i <= number; i++){
		for (std::size_t j = 1; j <= number; j++){
			int a = strcmp(arr_buf[j - 1], arr_buf[j]);
			if (a > 0){
				char a = ' ';
				strcpy_s(min,35, arr_buf[j]);
				strcpy_s(arr_buf[j],35, arr_buf[j - 1]);
				strcpy_s(arr_buf[j - 1],35, min);
			}
		}
	}
	for (std::size_t i = 0; i <= number; i++){
		if (i == number)arr_buf[number][strlen(arr_buf[number])-1] = '\0';
		strcat_s(this->arr,this->size, arr_buf[i]);
	}
	for (int i = 0; i < number; i++){
		delete[] arr_buf[i];
	}
	delete arr_buf;
	return *this;
}


