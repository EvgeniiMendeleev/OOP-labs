#include "stdafx.h"
#include "StudentGroup.h"

StudentGroup::StudentGroup(unsigned numberOfGroup)
{
	this->numberOfGroup = numberOfGroup;
}

bool StudentGroup::setStudent(Student& student)
{
	if (studentsOfGroup.size() != 20)
	{

		for (unsigned i = 0; i < studentsOfGroup.size(); i++)
		{
			if (studentsOfGroup[i] == &student)
			{
				return false;
			}
		}

		studentsOfGroup.push_back(&student);

		return true;
	}

	return false;
}

Student* const StudentGroup::getStudent(const string& lastName, const string& firstName, const string& patronymic) const
{
	for (unsigned i = 0; i < studentsOfGroup.size(); i++)
	{
		if (studentsOfGroup[i]->getFirstName() == firstName && studentsOfGroup[i]->getLastName() == lastName && studentsOfGroup[i]->getPatronymic() == patronymic)
		{
			return studentsOfGroup[i];
		}
	}

	return nullptr;
}

unsigned StudentGroup::getNumber() const
{
	return numberOfGroup;
}

unsigned StudentGroup::getCountOfStudent()
{
	return studentsOfGroup.size();
}

bool StudentGroup::deleteStudent(Student& student)
{
	vector<Student*>::iterator it = studentsOfGroup.begin();

	while (true)
	{
		if (*it == &student)
		{
			studentsOfGroup.erase(it);
			return true;
		}
		if (it == studentsOfGroup.end())
		{
			return false;
		}

		++it;
	}
}

vector<Student*> StudentGroup::getSortStudents(TypeOfSort type)
{
	vector<Student*> sortedStudents;

	for (unsigned i = 0; i < studentsOfGroup.size(); i++)
	{
		sortedStudents.push_back(studentsOfGroup[i]);
	}

	if (type == TypeOfSort::lexicographic)
	{
		sort(sortedStudents.begin(), sortedStudents.end(), [](Student* v1, Student* v2){ return v1->getLastName() < v2->getLastName(); });
	}
	else if (type == TypeOfSort::marks)
	{
		sort(sortedStudents.begin(), sortedStudents.end(), [](Student* v1, Student* v2){ return v1->getPerformance() < v2->getPerformance(); });
	}

	return sortedStudents;
}

Student& StudentGroup::getStudentOnNumber(unsigned i) const
{
	return (*studentsOfGroup[i]);
}

ostream& operator<<(ostream& stream, StudentGroup& group)
{
	for (unsigned i = 0; i < group.getCountOfStudent(); i++)
	{
		stream << "---------------------------------------------------------------------------" << endl;
		stream << "Имя студента: " << group.getStudentOnNumber(i).getLastName() << " " << group.getStudentOnNumber(i).getFirstName() << " " << group.getStudentOnNumber(i).getPatronymic() << endl;
		stream << "Успеваемость студента: " << static_cast<unsigned>(group.getStudentOnNumber(i).getPerformance()) << endl;
		stream << "---------------------------------------------------------------------------"<< endl;
	}

	return stream;
}