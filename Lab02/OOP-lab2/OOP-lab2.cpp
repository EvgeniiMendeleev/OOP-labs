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
	Botanist Evgenii("Менделеев", "Евгений", "Андреевич", "Книжный червь");
	SimplyStudent katya("Богданова", "Екатерина", "Александровна", TypeOfPerformance::good);
	MemberOfStudentSenate arkasha("Абросимов", "Аркадий", "Иванович", "Президент", TypeOfPerformance::bad);

	group.setStudent(Evgenii);
	group.setStudent(katya);
	group.setStudent(arkasha);

	vector<Student*> a = group.getSortStudents(TypeOfSort::marks);

	for (unsigned i = 0; i < a.size(); i++)
	{
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "Имя студента: " << a[i]->getLastName() << " " << a[i]->getFirstName() << " " << a[i]->getPatronymic() << endl;
		cout << "Успеваемость студента: " << static_cast<unsigned>(a[i]->getPerformance()) << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
	}

	system("Pause");
	return 0;
}

