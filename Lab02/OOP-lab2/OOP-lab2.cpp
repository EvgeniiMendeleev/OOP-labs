// OOP-lab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include "StudentGroup.h"

using namespace std;

int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");

	StudentGroup group(7091);
	Botanist Evgenii("���������", "�������", "���������", "������� �����");
	SimplyStudent katya("���������", "���������", "�������������", TypeOfPerformance::good);
	MemberOfStudentSenate arkasha("���������", "�������", "��������", "���������", TypeOfPerformance::bad);

	group.setStudent(Evgenii);
	group.setStudent(katya);
	group.setStudent(arkasha);

	vector<Student*> a = group.getSortStudents(TypeOfSort::marks);

	for (unsigned i = 0; i < a.size(); i++)
	{
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "��� ��������: " << a[i]->getLastName() << " " << a[i]->getFirstName() << " " << a[i]->getPatronymic() << endl;
		cout << "������������ ��������: " << static_cast<unsigned>(a[i]->getPerformance()) << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
	}

	system("Pause");
	return 0;
}

