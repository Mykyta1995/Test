#pragma once
#include <string>
#include <iostream>
#include <locale>

class String{
	char *arr = nullptr;
	std::size_t size = 0;
public:
	String();                                                                       //constructor by default
	~String();                                                                      //destructor
	String(const String &);                                                         //copy constructor
	String(String &&);                                                              //move designer
	explicit String(std::size_t, char);                                             //operator add object to simb char
	String & operator =(const String &);                                            //copy operator
	String & operator =(String &&);                                                 //move operator
	explicit String(const char *);                                                  //add line constructor               
	int Icount()const;                                                              //the number of elements in the array
	void Clear();                                                                   //annul the array elements and free up memory
	char & operator [](std::size_t i);                                              //indexing operator
	const char & operator [](std::size_t i)const;                                   //const оператор индексации
	friend std::ostream & operator << (std::ostream & , const String &);            //output statement
    bool & operator == (const String &)const;                                       //the comparison operator of all elements
	bool & operator !=(const String &)const;                                        //the operator of comparison of lines of objects
	String  operator +(const String &)const;                                        //add statement
	String(const char *,std::size_t);                                               //the operator of copying a line for a given number of elements
	String & operator +=(const String &);                                           //concatenation
	bool & operator <(const String &)const;                                         //operator < 
	bool & operator >(const String &)const;                                         //operator > 
	const char* Privat();                                                           //the method of a pointer to the string stored in the privat
	void Down_registr();                                                            //translate characters to lowercase
	void Up_registr();                                                              //translate characters to upper case
    char* Insert(std::size_t i,const String &);                                     //insert method
	char* Delete(std::size_t = 0, std::size_t = 0);                                 //delete method
	int Index_char(char);                                                           //Find index simvol 
	String* Find(char*, std::size_t i = 0);                                         //Find string 
	String Sort();                                                                    //sortirovka
};


