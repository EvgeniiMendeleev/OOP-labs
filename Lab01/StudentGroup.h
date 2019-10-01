#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <algorithm>

using namespace std;

enum class TypeOfSort { lexicogrpahic, marks };

class Student;

class StudentGroup
{
	unsigned numberOfGroup;						//Номер группы.
	vector<Student*> studentsOfGroup;			//Студенты группы.

public:
	StudentGroup(unsigned numberOfGroup);
	~StudentGroup() = default;

	bool deleteStudent(Student& student);		//Исключение студента из группы.

	//------------------SET------------------
	bool setStudent(Student& student);									//Принять студента в группу.
	//---------------------------------------

	//------------------GET------------------
	const Student* getStudent(const string& lastName, const string& firstName, const string& patronymic) const;		//Получить студента по ФИО.
	unsigned getNumber() const;																						//Получить номер группы.
	unsigned getCountOfStudent();																					//Получить число студентов в группе.
	vector<Student> getSortStudents(TypeOfSort type);																//Получить отсортированный список студентов группы, в зависимости от типа сортировка.
	Student& getStudentOnNumber(unsigned i) const;																	//Получить студента по номеру в списке.
	//---------------------------------------

};

ostream& operator<<(ostream& stream, StudentGroup& group);

