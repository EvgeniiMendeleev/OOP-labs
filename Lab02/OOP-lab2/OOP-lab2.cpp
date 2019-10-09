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

	Student::Botanist Evgenii("Mendeleev", "Evgeny", "Andreevich");
	Student::Simply katya("Bogdanova", "Ekaterina", "Alecksandrovna", TypeOfPerformance::bad);
	Student::MemberOfSenate arkasha("Abrosimov", "Arckady", "Ivanovich", TypeOfPerformance::good);

	Student::Botanist Katya = katya.toBeBotanist();
	cout << "It's botanist Katya's mark for exam: " << static_cast<int>(Katya.takeASession()) + 2 << endl;

	Student::Simply againKatya = Katya.toBeSimplyStudent(TypeOfPerformance::good);
	cout << "It's simple student Katya's mark for exam: " << static_cast<int>(againKatya.takeASession()) + 2 << endl;

	Student::MemberOfSenate ohKatya = Katya.toBeMemberOfStudentSenate(TypeOfPerformance::bad);
	cout << "It's student senate's member Katya's mark for exam: " << static_cast<int>(ohKatya.takeASession()) + 2 << endl;
	
	group.setStudent(Evgenii);
	group.setStudent(katya);
	group.setStudent(arkasha);

	vector<Student*> a = group.getSortStudents(TypeOfSort::marks);

	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "!!!!!LIST OF STUDENTS WAS SORTED!!!!!" << endl;
	
	for (unsigned i = 0; i < a.size(); i++)
	{
		cout << *a[i];
	}

	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "!!!!!STUDENT WAS DELETED!!!!!" << endl;
	
	group.deleteStudent(Evgenii);

	cout << group;

	system("Pause");
	return 0;
}

