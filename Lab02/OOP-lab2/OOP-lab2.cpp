// OOP-lab2.cpp: определяет точку входа для консольного приложения.
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
	
	Botanist Evgenii("Менделеев", "Евгений", "Андреевич");
	SimplyStudent katya("Богданова", "Екатерина", "Александровна", TypeOfPerformance::good);
	MemberOfStudentSenate arkasha("Абросимов", "Аркадий", "Иванович", TypeOfPerformance::bad);

	Botanist Katya = katya.toBeBotanist();
	cout << "Оценка за экзамен ботаника Кати:" << static_cast<int>(Katya.takeASession()) << endl;

	SimplyStudent againKatya = Katya.toBeSimplyStudent(TypeOfPerformance::good);
	cout << "Оценка за экзамен обычного студента Кати:" << static_cast<int>(Katya.takeASession()) << endl;

	MemberOfStudentSenate ohKatya = Katya.toBeMemberOfStudentSenate(TypeOfPerformance::bad);
	cout << "Оценка за экзамен члена студенческого совета Кати:" << static_cast<int>(Katya.takeASession()) << endl;
	
	group.setStudent(Evgenii);
	group.setStudent(katya);
	group.setStudent(arkasha);

	vector<Student*> a = group.getSortStudents(TypeOfSort::lexicographic);

	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "!!!!!ОТСОРТИРОВАЛИ СТУДЕНТОВ!!!!!" << endl;
	
	for (unsigned i = 0; i < a.size(); i++)
	{
		cout << *a[i];
	}

	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "!!!!!УДАЛИЛИ СТУДЕНТА!!!!!" << endl;
	
	group.deleteStudent(arkasha);
	cout << group;

	system("Pause");
	return 0;
}

