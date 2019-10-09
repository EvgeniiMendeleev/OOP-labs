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

Student::Botanist Student::toBeBotanist()
{
	return Student::Botanist(this->getLastName(), this->getFirstName(), this->getPatronymic());
}

Student::Simply Student::toBeSimplyStudent(TypeOfPerformance performance)
{
	return Student::Simply(this->getLastName(), this->getFirstName(), this->getPatronymic(), performance);
}

Student::MemberOfSenate Student::toBeMemberOfStudentSenate(TypeOfPerformance performance)
{
	return Student::MemberOfSenate(this->getLastName(), this->getFirstName(), this->getPatronymic(), performance);
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

Mark Student::Simply::takeASession()
{
	return static_cast<Mark>(rand() % 4);
}

Student::Simply::Simply(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance)
	: Student(lastName, firstName, patronymic, performance){}

#pragma endregion Methods_of_SimplyStudent

#pragma region Methods_of_Botanist

Mark Student::Botanist::takeASession()
{
	return static_cast<Mark>(rand() % 2 + 2);
}

Student::Botanist::Botanist(const string& lastName, const string& firstName, const string& patronymic)
	:Student(lastName, firstName, patronymic, TypeOfPerformance::perfectly) { }

#pragma endregion Methods_of_Botanist

#pragma region Methods_of_MemberOfStudentSenate

Mark Student::MemberOfSenate::takeASession()
{
	Mark mark = static_cast<Mark>(rand() % 4);

	numberOfPass = mark == Mark::two ? numberOfPass + 1 : 0;

	//If it's a last pass, then student gets a three.
	if (numberOfPass == 2)
	{
		numberOfPass = 0;
		return Mark::three;
	}

	return mark;
}

Student::MemberOfSenate::MemberOfSenate(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance)
	:Simply(lastName, firstName, patronymic, performance){}

#pragma endregion Methods_of_MemberOfStudentSenate

ostream& operator<<(ostream& stream, Student& student)
{
	stream << "---------------------------------------------------------------------------" << endl;
	stream << "Name of student: " << student.getLastName() << " " << student.getFirstName() << " " << student.getPatronymic() << endl;
	stream << "It's his the academic performance: " << static_cast<unsigned>(student.getPerformance()) << endl;
	stream << "---------------------------------------------------------------------------" << endl;

	return stream;
}