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

const Student* const StudentGroup::getStudent(const string& lastName, const string& firstName, const string& patronymic) const
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

void StudentGroup::deleteStudent(const Student& student)
{
	studentsOfGroup.erase(std::remove(studentsOfGroup.begin(), studentsOfGroup.end(), &student), studentsOfGroup.end());
}

vector<Student*> StudentGroup::getSortStudents(TypeOfSort type)
{
	vector<Student*> sortedStudents = studentsOfGroup;

	if (type == TypeOfSort::lexicographic)
	{
		sort(sortedStudents.begin(), sortedStudents.end(), []
		(Student* v1, Student* v2)
		{ 
			return v1->getLastName() < v2->getLastName(); 
		});
	}
	else if (type == TypeOfSort::marks)
	{
		sort(sortedStudents.begin(), sortedStudents.end(), []
		(Student* v1, Student* v2)
		{ 
			return v1->getPerformance() < v2->getPerformance(); 
		});
	}

	return sortedStudents;
}

const Student& StudentGroup::getConstStudentOnNumber(unsigned i) const
{
	return (*studentsOfGroup[i]);
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
		stream << "Name Of student: " << group.getStudentOnNumber(i).getLastName() << " " << group.getStudentOnNumber(i).getFirstName() << " " << group.getStudentOnNumber(i).getPatronymic() << endl;
		stream << "It's his the academic performance: " << static_cast<unsigned>(group.getStudentOnNumber(i).getPerformance()) << endl;
		stream << "---------------------------------------------------------------------------"<< endl;
	}

	return stream;
}