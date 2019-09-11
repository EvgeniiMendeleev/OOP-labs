#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class StudentGroup;

class Student
{
	string firstName;					//Имя
	string lastName;					//Фамилия
	string patronymic;					//Отчество

	vector<unsigned> numbersOfGroup;	//Номера групп, в которых находится студент.

public:
	Student(string lastName, string firstName, string patronymic);
	~Student();

	void escape_from_group(StudentGroup* group);

	//------------------SET------------------
	void set_number_of_group(unsigned numberOfGroup);		//Установить номер группы, в которой находится студент.
	//---------------------------------------

	//------------------GET------------------
	string get_firstName();								//Получить имя.
	string get_lastName();								//Получить фамилию.
	string get_patronymic();							//Получить отчество.
	unsigned get_number_of_group(unsigned i);			//Получить номер i - ой группы из numbersOfGroup.
	unsigned get_count_of_group();						//Получить число групп, в которых находится студент.
	//---------------------------------------

	//------------------SHOW------------------
	void show_student();								//Показать информацию о студенте.
	//----------------------------------------
};
