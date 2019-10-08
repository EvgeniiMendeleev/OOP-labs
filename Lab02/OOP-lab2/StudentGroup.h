#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include "Student.h"

using namespace std;

enum class TypeOfSort { lexicographic, marks };

class Student;
class Botabist;
class MemberOfStudentSenate;
class SimplyStudent;

class StudentGroup
{
public:
	StudentGroup(unsigned numberOfGroup);
	~StudentGroup() = default;

#pragma region Actions

	bool deleteStudent(Student& student);			//Исключение студента из группы.

#pragma endregion Describes all actions that can be performed on an object.

#pragma region Setters

	bool setStudent(Student& student);				//Принять студента в группу.

#pragma endregion Set something value.

#pragma region Getters

	const Student* getStudent(const string& lastName, const string& firstName, const string& patronymic) const;		//Получить студента по ФИО.
	unsigned getNumber() const;																						//Получить номер группы.
	unsigned getCountOfStudent();																					//Получить число студентов в группе.
	vector<Student*> getSortStudents(TypeOfSort type);																//Получить отсортированный список студентов группы, в зависимости от типа сортировка.
	Student& getStudentOnNumber(unsigned i) const;																	//Получить студента по номеру в списке.

#pragma endregion Get something value.

private:
	unsigned numberOfGroup;						//Номер группы.
	vector<Student*> studentsOfGroup;			//Студенты группы.
};

ostream& operator<<(ostream& stream, StudentGroup& group);

