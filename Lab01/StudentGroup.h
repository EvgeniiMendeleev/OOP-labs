#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>

using namespace std;

enum TypeOfSort { lexicographic, marks };

class Student;

class StudentGroup
{
	unsigned numberOfGroup;						//Номер группы.
	vector<Student*> studentsOfGroup;			//Студенты группы.

public:
	StudentGroup(unsigned numberOfGroup);
	~StudentGroup();

	bool delete_student(Student* student);		//Исключение студента из группы.

	//------------------SET------------------
	bool set_student(Student* student);												//Принять студента в группу.
	//---------------------------------------

	//------------------GET------------------
	Student* get_student(string lastName, string firstName, string patronymic);		//Получить студента по ФИО.
	unsigned get_number();															//Получить номер группы.
	unsigned get_count_of_student();												//Получить число студентов в группе.
	vector<Student*>::iterator get_end();											//Получить итератор на конец списка студентов.
	vector<Student*>::iterator get_start();											//Получить итератор на начало списка студентов.
	vector<Student*>& get_list();													//Получить список студентов группы.
	vector<Student*>& get_sort_students(TypeOfSort sort);							//Получить отсортированный список студентов группы, в зависимости от типа сортировка.
	//---------------------------------------

	//-----------------SHOW------------------
	void show_students();															//Показать всех студентов.
	//---------------------------------------
};

