#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum class TypeOfPerformance { perfectly, good, bad, nothing };				//Type of academic performance
enum class Mark { two, three, four, five };									//All marks of student.

class Student
{
public:

	Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	virtual ~Student() = default;

	class Simply;
	class Botanist;
	class MemberOfSenate;

	virtual Mark takeASession() = 0;													//Pass a session.

	Simply toBeSimplyStudent(TypeOfPerformance performance);							//To be a common student.
	Botanist toBeBotanist();															//To be a botanist.
	MemberOfSenate toBeMemberOfStudentSenate(TypeOfPerformance performance);			//To be a member of student senate

#pragma region Getters

	const string& getFirstName() const;						//Get first name.
	const string& getLastName() const;						//Get last name.
	const string& getPatronymic() const;					//Get patronymic.
	TypeOfPerformance getPerformance() const;				//Get performance of student.

#pragma endregion Get a something value

protected:

	string firstName;
	string lastName;
	string patronymic;

	TypeOfPerformance performance;		//Academic performance of student.
};

#pragma region SimplyStudent

class Student::Simply: public Student
{
public:
	Simply(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	virtual ~Simply() = default;

	Mark takeASession() override;

private:
};

#pragma endregion Class of simple student

#pragma region MemberOfStudentSenate

class Student::MemberOfSenate final : public Student::Simply
{
public:
	MemberOfSenate(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	~MemberOfSenate() = default;

	Mark takeASession() override final;

private:
	unsigned short numberOfPass = 0;
};

#pragma endregion Class of member student's senate 

#pragma region StudentBotanist

class Student::Botanist final : public Student
{
public:
	Botanist(const string& lastName, const string& firstName, const string& patronymic);
	~Botanist() = default;

	Mark takeASession() override final;

private:
};

#pragma endregion Class of student botanist

ostream& operator<<(ostream& stream, Student& student);