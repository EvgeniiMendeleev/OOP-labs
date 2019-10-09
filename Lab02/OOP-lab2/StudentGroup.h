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

class StudentGroup
{
public:
	StudentGroup(unsigned numberOfGroup);
	~StudentGroup() = default;

#pragma region Actions

	void deleteStudent(const Student& student);			//Delete a student from group.

#pragma endregion Describes all actions that can be performed on an object.

#pragma region Setters

	bool setStudent(Student& student);				//Accept a student to group.

#pragma endregion Set a something value.

#pragma region Getters

	const Student* const getStudent(const string& lastName, const string& firstName, const string& patronymic) const;		//Get a student by name.
	unsigned getNumber() const;																								//Get a number of group.
	unsigned getCountOfStudent();																							//Get a number of students in group.
	vector<Student*> getSortStudents(TypeOfSort type);																		//Get a sorted list of students of group depending on the type of sorting.
	const Student& getConstStudentOnNumber(unsigned i) const;																//Get a student on index in list for read-only.
	Student& getStudentOnNumber(unsigned i) const;																			//Get a student on index in list.

#pragma endregion Get a something value.

private:
	unsigned numberOfGroup;						//Number of group.
	vector<Student*> studentsOfGroup;			//Students of group.
};

ostream& operator<<(ostream& stream, StudentGroup& group);

