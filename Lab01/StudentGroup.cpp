#include "stdafx.h"
#include "StudentGroup.h"
#include "Student.h"

StudentGroup::StudentGroup(unsigned numberOfGroup)
{
	this->numberOfGroup = numberOfGroup;
}

bool StudentGroup::set_student(Student* student)
{
	if (studentsOfGroup.size() != 20)
	{
		for (unsigned i = 0; i < student->get_count_of_group(); i++)
		{
			if (student->get_number_of_group(i) == numberOfGroup)
			{
				return false;
			}
		}

		student->set_number_of_group(numberOfGroup);
		studentsOfGroup.push_back(student);

		return true;
	}

	return false;
}

void StudentGroup::show_students()
{
	for (unsigned i = 0; i < studentsOfGroup.size(); i++)
	{
		studentsOfGroup[i]->show_student();
		cout << endl;
	}
}

Student* StudentGroup::get_student(string lastName, string firstName, string patronymic)
{
	for (unsigned i = 0; i < studentsOfGroup.size(); i++)
	{
		if (studentsOfGroup[i]->get_firstName() == firstName && studentsOfGroup[i]->get_lastName() == lastName && studentsOfGroup[i]->get_patronymic() == patronymic)
		{
			return studentsOfGroup[i];
		}
	}

	return nullptr;
}

unsigned StudentGroup::get_number()
{
	return numberOfGroup;
}

unsigned StudentGroup::get_count_of_student()
{
	return studentsOfGroup.size();
}

vector<Student*>::iterator StudentGroup::get_end()
{
	return studentsOfGroup.end();
}

vector<Student*>::iterator StudentGroup::get_start()
{
	return studentsOfGroup.begin();
}

bool StudentGroup::delete_student(Student* student)
{
	student->escape_from_group(this);
	return false;
}

vector<Student*>& StudentGroup::get_list()
{
	return studentsOfGroup;
}

vector<Student*>& StudentGroup::get_sort_students(TypeOfSort sort)
{
	if (sort == lexicographic)
	{
		size_t i = 1;

		while (i < studentsOfGroup.size())
		{
			if (i == 0)
			{
				i = 1;
			}

			Student* ItFirst = studentsOfGroup[i - 1];
			Student* ItSecond = studentsOfGroup[i];

			if (strcmp(ItFirst->get_lastName().c_str(), ItSecond->get_lastName().c_str()) < 0)
			{
				++i;
			}
			else
			{
				Student* t = studentsOfGroup[i - 1];
				studentsOfGroup[i - 1] = studentsOfGroup[i];
				studentsOfGroup[i] = t;

				--i;
			}
		}
	}
	else if (sort == marks)
	{

	}

	return studentsOfGroup;
}

StudentGroup::~StudentGroup()
{
}
