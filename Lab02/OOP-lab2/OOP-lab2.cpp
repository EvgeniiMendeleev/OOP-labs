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
	
	Botanist Evgenii("���������", "�������", "���������");
	SimplyStudent katya("���������", "���������", "�������������", TypeOfPerformance::good);
	MemberOfStudentSenate arkasha("���������", "�������", "��������", TypeOfPerformance::bad);

	Botanist Katya = katya.toBeBotanist();
	cout << "������ �� ������� �������� ����:" << static_cast<int>(Katya.takeASession()) << endl;

	SimplyStudent againKatya = Katya.toBeSimplyStudent(TypeOfPerformance::good);
	cout << "������ �� ������� �������� �������� ����:" << static_cast<int>(Katya.takeASession()) << endl;

	MemberOfStudentSenate ohKatya = Katya.toBeMemberOfStudentSenate(TypeOfPerformance::bad);
	cout << "������ �� ������� ����� ������������� ������ ����:" << static_cast<int>(Katya.takeASession()) << endl;
	
	group.setStudent(Evgenii);
	group.setStudent(katya);
	group.setStudent(arkasha);

	vector<Student*> a = group.getSortStudents(TypeOfSort::lexicographic);

	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "!!!!!������������� ���������!!!!!" << endl;
	
	for (unsigned i = 0; i < a.size(); i++)
	{
		cout << *a[i];
	}

	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "!!!!!������� ��������!!!!!" << endl;
	
	group.deleteStudent(arkasha);
	cout << group;

	system("Pause");
	return 0;
}

