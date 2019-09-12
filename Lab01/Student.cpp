#include "stdafx.h"
#include "Student.h"
#include "StudentGroup.h"

Student::Student(string lastName, string firstName, string patronymic, TypeOfPerformance performance)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->patronymic = patronymic;

	this->performance = performance;
}

unsigned Student::get_number_of_group(unsigned i)
{
	return numbersOfGroup[i];
}

unsigned Student::get_count_of_group()
{
	return numbersOfGroup.size();
}

string Student::get_firstName()
{
	return firstName;
}

string Student::get_lastName()
{
	return lastName;
}

string Student::get_patronymic()
{
	return patronymic;
}

void Student::set_number_of_group(unsigned numberOfGroup)
{
	this->numbersOfGroup.push_back(numberOfGroup);
}

bool Student::escape_from_group(StudentGroup* group)
{
	if (group != nullptr)
	{
		for (unsigned i = 0; i < numbersOfGroup.size(); i++)
		{
			if (numbersOfGroup[i] == group->get_number())
			{
				numbersOfGroup.erase(numbersOfGroup.begin() + i);

				vector<Student*>& listOfStudents = group->get_list();

				for (unsigned j = 0; j < listOfStudents.size(); j++)
				{
					if (listOfStudents[j] == this)
					{
						listOfStudents.erase(listOfStudents.begin() + j);
						break;
					}
				}

				/*vector<Student*>::iterator it = group->get_start();

				for (unsigned j = 0; j < group->get_count_of_student(); j++, ++it)
				{
					if (*it == this)
					{
						vector<Student*>& tmpList = group->get_list();
						tmpList.erase(it);
						break;
					}
				}*/

				return true;
			}
		}
	}

	return false;
}

TypeOfPerformance Student::get_performance()
{
	return performance;
}

void Student::show_student()
{
	cout << this->lastName << " " << this->firstName << " " << this->patronymic << " " << this->performance << endl;
	
	cout << "Номера групп, в которых находится данный студент: ";
	for (unsigned i = 0; i < numbersOfGroup.size(); i++)
	{
		cout << numbersOfGroup[i] << " ";
	}

}

Student::~Student()
{
}
