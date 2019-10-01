#include "stdafx.h"
#include "Student.h"

Student::Student(const string& lastName, const string& firstName, const string& patronymic, const TypeOfPerformance performance)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->patronymic = patronymic;

	this->performance = performance;
}

unsigned Student::getNumberOfGroup(unsigned i) const
{
	return numbersOfGroup[i];
}

unsigned Student::getCountOfGroup()
{
	return numbersOfGroup.size();
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

void Student::setNumberOfGroup(unsigned numberOfGroup)
{
	this->numbersOfGroup.push_back(numberOfGroup);
}

TypeOfPerformance Student::getPerformance() const
{
	return performance;
}

bool Student::escapeFromGroup(unsigned numberOfGroup)
{
	vector<unsigned>::iterator it = numbersOfGroup.begin();

	while (true)
	{
		if (*it == numberOfGroup)
		{
			numbersOfGroup.erase(it);
			return true;
		}
		if (it == numbersOfGroup.end())
		{
			return false;
		}

		++it;
	}
}

ostream& operator<<(ostream& stream, Student& student)
{
	stream << "-----------------------------------------------------------------------------------------------" << endl;
	stream << "Имя студента: " << student.getLastName() << " " << student.getFirstName() << " " << student.getPatronymic() << endl;
	stream << "Успеваемость студента: " << static_cast<unsigned>(student.getPerformance()) << endl;
	stream << "Номера групп, в которых находится студент: ";

	for (unsigned i = 0; i < student.getCountOfGroup(); i++)
	{
		stream << student.getNumberOfGroup(i) << " ";
	}
	stream << endl;

	stream << "-----------------------------------------------------------------------------------------------" << endl;

	return stream;
}
