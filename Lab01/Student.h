#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

enum class TypeOfPerformance { Perfectly, Good, Bad, Nothing };		//Тип успеваемости: отличник, хорошист, двоечник, пока оценок нету.

class Student
{
	string firstName;					//Имя
	string lastName;					//Фамилия
	string patronymic;					//Отчество

	TypeOfPerformance performance;		//Успеваемость студента.
	vector<unsigned> numbersOfGroup;	//Номера групп, в которых находится студент.

public:
	Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	~Student() = default;

	bool escapeFromGroup(unsigned nmumberOfGroup);			//Уйти из группы.

	//------------------SET------------------
	void setNumberOfGroup(unsigned numberOfGroup);			//Установить номер группы, в которой находится студент.
	//---------------------------------------

	//------------------GET------------------
	const string& getFirstName() const;						//Получить имя.
	const string& getLastName() const;						//Получить фамилию.
	const string& getPatronymic() const;					//Получить отчество.
	unsigned getNumberOfGroup(unsigned i) const;			//Получить номер i - ой группы из numbersOfGroup.
	unsigned getCountOfGroup();								//Получить число групп, в которых находится студент.
	TypeOfPerformance getPerformance() const;				//Получить успеваемость.
	//---------------------------------------

};

ostream& operator<<(ostream& stream, Student& student);
