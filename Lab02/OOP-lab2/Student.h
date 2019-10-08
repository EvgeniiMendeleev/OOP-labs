#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum class TypeOfPerformance { perfectly, good, bad, nothing };				//Тип успеваемости: отличник, хорошист, двоечник, пока оценок нету.
enum class Layer { botan, common_student, member_of_student_senate };		//Слои студентов.
enum class Mark { two, three, four, five };

class Student
{
public:
	Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	~Student() = default;

	void goToAnotherLayer(Layer layer);						//Перейти в другое общество: ботан, член студенческого совета, обычный студент.
	virtual Mark takeASession() = 0;						//Сдать сессию.

	//------------------GET------------------
	const string& getFirstName() const;						//Получить имя.
	const string& getLastName() const;						//Получить фамилию.
	const string& getPatronymic() const;					//Получить отчество.
	TypeOfPerformance getPerformance() const;				//Получить успеваемость.
	//---------------------------------------

protected:
	string firstName;					//Имя
	string lastName;					//Фамилия
	string patronymic;					//Отчество

	TypeOfPerformance performance;		//Успеваемость студента.
};

class SimplyStudent : public Student
{
public:
	Mark takeASession() override;

private:
};

class MemberOfStudentSenate final : public SimplyStudent
{
public:
	Mark takeASession() override final;

private:
	string post;		//Должность студента в студсовете.
};

class Botanist final : public Student
{
public:
	Mark takeASession() override final;

private:
	string nickname;	//Кличка ботаника.
};

ostream& operator<<(ostream& stream, Student& student);