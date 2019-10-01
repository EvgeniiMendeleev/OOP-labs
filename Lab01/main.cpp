#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include "Student.h"
#include "StudentGroup.h"

using namespace std;

int main()
{
	/*!!!ДАННЫЙ ФАЙЛ ЯВЛЯЕТСЯ ТЕСТОВЫМ!!!
	!!!ЗДЕСЬ ПРОВЕРЯЕТСЯ РАБОТОСПОСОБНОСТЬ ВСЕХ МЕТОДОВ КАЖДОГО КЛАССА!!!*/
	
	setlocale(LC_ALL, "Russian");

	Student FirstStudent("Иванов", "Иван", "Иванович", TypeOfPerformance::Perfectly);
	Student Second("Менделеев", "Евгений", "Андреевич", TypeOfPerformance::Good);
	Student Thrid("Монахов", "Иван", "Михайлович", TypeOfPerformance::Bad);
	Student Four("Андриенко", "Степан", "Константинович", TypeOfPerformance::Perfectly);
	Student Five("Алексеева", "Валерия", "Александровна", TypeOfPerformance::Perfectly);
	
	StudentGroup group7091(7091);
	StudentGroup group8032(8032);
	
	group7091.setStudent(FirstStudent);
	group7091.setStudent(Second);
	group7091.setStudent(Thrid);
	group7091.setStudent(Four);
	group7091.setStudent(Five);
	group8032.setStudent(Thrid);
	
	group7091.deleteStudent(Thrid);

	vector<Student> st = group7091.getSortStudents(TypeOfSort::lexicogrpahic);

	for (unsigned i = 0; i < st.size(); i++)
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "Имя студента: " << st[i].getLastName() << " " << st[i].getFirstName() << " " << st[i].getPatronymic() << endl;
		cout << "Успеваемость студента: " << static_cast<unsigned>(st[i].getPerformance()) << endl;
		cout << "Номера групп, в которых находится студент: ";

		for (unsigned j = 0; j < st[i].getCountOfGroup(); j++)
		{
			cout << st[i].getNumberOfGroup(j) << " ";
		}
		cout << endl;

		cout << "------------------------------------------------------------------------------" << endl;
	}

	system("Pause");
	return 0;
}
