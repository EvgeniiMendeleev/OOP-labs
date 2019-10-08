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

	bool deleteStudent(Student& student);			//���������� �������� �� ������.

#pragma endregion Describes all actions that can be performed on an object.

#pragma region Setters

	bool setStudent(Student& student);				//������� �������� � ������.

#pragma endregion Set something value.

#pragma region Getters

	const Student* getStudent(const string& lastName, const string& firstName, const string& patronymic) const;		//�������� �������� �� ���.
	unsigned getNumber() const;																						//�������� ����� ������.
	unsigned getCountOfStudent();																					//�������� ����� ��������� � ������.
	vector<Student*> getSortStudents(TypeOfSort type);																//�������� ��������������� ������ ��������� ������, � ����������� �� ���� ����������.
	Student& getStudentOnNumber(unsigned i) const;																	//�������� �������� �� ������ � ������.

#pragma endregion Get something value.

private:
	unsigned numberOfGroup;						//����� ������.
	vector<Student*> studentsOfGroup;			//�������� ������.
};

ostream& operator<<(ostream& stream, StudentGroup& group);

