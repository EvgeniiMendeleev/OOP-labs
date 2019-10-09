#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum class TypeOfPerformance { perfectly, good, bad, nothing };				//��� ������������: ��������, ��������, ��������, ���� ������ ����.
enum class Mark { two, three, four, five };							//������������ ������

class SimplyStudent;
class Botanist;
class MemberOfStudentSenate;

class Student
{
public:
	Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance);
	virtual ~Student() = default;

	virtual Mark takeASession() = 0;													//����� ������.
	SimplyStudent toBeSimplyStudent(TypeOfPerformance performance);						//����� ������� ���������.
	Botanist toBeBotanist();															//����� ���������.
	MemberOfStudentSenate toBeMemberOfStudentSenate(TypeOfPerformance performance);		//����� ������ ������������� ������.

#pragma region Getters

	const string& getFirstName() const;						//�������� ���.
	const string& getLastName() const;						//�������� �������.
	const string& getPatronymic() const;					//�������� ��������.
	TypeOfPerformance getPerformance() const;				//�������� ������������.

#pragma endregion Get a something value

protected:
	string firstName;					//���
	string lastName;					//�������
	string patronymic;					//��������

	TypeOfPerformance performance;		//������������ ��������.
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
	unsigned short numberOfPass = 0;	//����� ��������, ������� �������� �������. ���������� �� �� ��� �� ���������, ������� ����
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