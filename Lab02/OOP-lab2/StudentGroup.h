#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include "Student.h"

using namespace std;

enum class TypeOfSort { lexicogrpahic, marks };

class Student;

class StudentGroup
{
public:
	StudentGroup(unsigned numberOfGroup);
	~StudentGroup() = default;

	bool deleteStudent(Student& student);			//���������� �������� �� ������.

	//------------------SET------------------
	bool setStudent(Student& student);				//������� �������� � ������.
	//---------------------------------------

	//------------------GET------------------
	const Student* getStudent(const string& lastName, const string& firstName, const string& patronymic) const;		//�������� �������� �� ���.
	unsigned getNumber() const;																						//�������� ����� ������.
	unsigned getCountOfStudent();																					//�������� ����� ��������� � ������.
	vector<Student> getSortStudents(TypeOfSort type);																//�������� ��������������� ������ ��������� ������, � ����������� �� ���� ����������.
	Student& getStudentOnNumber(unsigned i) const;																	//�������� �������� �� ������ � ������.
	//---------------------------------------

private:
	unsigned numberOfGroup;						//����� ������.
	vector<Student*> studentsOfGroup;			//�������� ������.
};

ostream& operator<<(ostream& stream, StudentGroup& group);

