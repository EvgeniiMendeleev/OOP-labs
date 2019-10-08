#include "stdafx.h"
#include "Student.h"

#pragma region Methods_of_student
Student::Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->patronymic = patronymic;

	this->performance = performance;
}

const string& Student::getFirstName() const
{
	return firstName;
}

const string& Student::getLastName() const
{
	return lastName;
}

const string& Student::getPatronymic() const
{
	return patronymic;
}

TypeOfPerformance Student::getPerformance() const
{
	return performance;
}
#pragma endregion Methods_of_Student

#pragma region Methods_of_SimplyStudent
Mark SimplyStudent::takeASession()
{
	return static_cast<Mark>(rand() % 4);
}
#pragma endregion Methods_of_SimplyStudent

#pragma region Methods_of_Botanist
Mark Botanist::takeASession()
{
	return static_cast<Mark>(rand() % 4 + 2);
}
#pragma endregion Methods_of_Botanist

#pragma region Methods_of_MemberOfStudentSenate
Mark MemberOfStudentSenate::takeASession()
{
	return static_cast<Mark>(rand() % 4 + 1);
}
#pragma endregion Methods_of_MemberOfStudentSenate

ostream& operator<<(ostream& stream, Student& student)
{
	stream << "-----------------------------------------------------------------------------------------------" << endl;
	stream << "Имя студента: " << student.getLastName() << " " << student.getFirstName() << " " << student.getPatronymic() << endl;
	stream << "Успеваемость студента: " << static_cast<unsigned>(student.getPerformance()) << endl;
	stream << "-----------------------------------------------------------------------------------------------" << endl;

	return stream;
}