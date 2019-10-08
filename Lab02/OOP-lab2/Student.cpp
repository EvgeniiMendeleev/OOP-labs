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

SimplyStudent::SimplyStudent(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance)
	: Student(lastName, firstName, patronymic, performance){}

#pragma endregion Methods_of_SimplyStudent

#pragma region Methods_of_Botanist

Mark Botanist::takeASession()
{
	return static_cast<Mark>(rand() % 4 + 2);
}

Botanist::Botanist(const string& lastName, const string& firstName, const string& patronymic, const string& nickname)
	:Student(lastName, firstName, patronymic, TypeOfPerformance::perfectly) 
{
	this->nickname = nickname;
}

#pragma endregion Methods_of_Botanist

#pragma region Methods_of_MemberOfStudentSenate

Mark MemberOfStudentSenate::takeASession()
{
	static unsigned short numberOfPass = 0;			//Изначально он не идёт на пересдачу, поэтому ноль
	Mark mark = static_cast<Mark>(rand() % 4);

	(mark == Mark::two) ? ++numberOfPass : numberOfPass = 0;

	//Если уже вторая, т.е. последняя, пересдача, то получает тройку
	if (numberOfPass == 2)
	{
		return Mark::three;
	}

	return mark;
}

MemberOfStudentSenate::MemberOfStudentSenate(const string& lastName, const string& firstName, const string& patronymic, const string& post, const TypeOfPerformance performance)
	:SimplyStudent(lastName, firstName, patronymic, performance){}

#pragma endregion Methods_of_MemberOfStudentSenate

ostream& operator<<(ostream& stream, Student& student)
{
	stream << "-----------------------------------------------------------------------------------------------" << endl;
	stream << "Имя студента: " << student.getLastName() << " " << student.getFirstName() << " " << student.getPatronymic() << endl;
	stream << "Успеваемость студента: " << static_cast<unsigned>(student.getPerformance()) << endl;
	stream << "-----------------------------------------------------------------------------------------------" << endl;

	return stream;
}
