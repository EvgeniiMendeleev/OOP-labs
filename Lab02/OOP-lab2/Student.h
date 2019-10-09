#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum class TypeOfPerformance { perfectly, good, bad, nothing };				//Тип успеваемости: отличник, хорошист, двоечник, пока оценок нету.
enum class Mark { two, three, four, five };							//Всевозможные оценки

class SimplyStudent;
class Botanist;
class MemberOfStudentSenate;

class Student
{
public:
	Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	virtual ~Student() = default;

	virtual Mark takeASession() = 0;													//Сдать сессию.
	SimplyStudent toBeSimplyStudent(TypeOfPerformance performance);						//Стать обычным студентом.
	Botanist toBeBotanist();															//Стать ботаником.
	MemberOfStudentSenate toBeMemberOfStudentSenate(TypeOfPerformance performance);		//Стать членом студенческого совета.

#pragma region Getters

	const string& getFirstName() const;						//Получить имя.
	const string& getLastName() const;						//Получить фамилию.
	const string& getPatronymic() const;					//Получить отчество.
	TypeOfPerformance getPerformance() const;				//Получить успеваемость.

#pragma endregion Get a something value

protected:
	string firstName;					//Имя
	string lastName;					//Фамилия
	string patronymic;					//Отчество

	TypeOfPerformance performance;		//Успеваемость студента.
};

class SimplyStudent : public Student
{
public:
	SimplyStudent(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	virtual ~SimplyStudent() = default;
	
	Mark takeASession() override;

private:
};

class MemberOfStudentSenate final : public SimplyStudent
{
public:
	MemberOfStudentSenate(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	~MemberOfStudentSenate() = default;

	Mark takeASession() override final;

private:
	unsigned short numberOfPass = 0;	//Число пересдач, которые совершил студент. Изначально он не идёт на пересдачу, поэтому ноль
};

class Botanist final : public Student
{
public:
	Botanist(const string& lastName, const string& firstName, const string& patronymic);
	~Botanist() = default;

	Mark takeASession() override final;

private:
};

ostream& operator<<(ostream& stream, Student& student);