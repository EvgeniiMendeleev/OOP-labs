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

	Student FirstStudent("Иванов", "Иван", "Иванович", Perfectly);
	Student Second("Менделеев", "Евгений", "Андреевич", Good);
	Student Thrid("Монахов", "Иван", "Михайлович", Bad);
	Student Four("Андриенко", "Степан", "Константинович", Perfectly);
	Student Five("Алексеева", "Валерия", "Александровна", Perfectly);

	StudentGroup group7091(7091);
	StudentGroup group8032(8032);

	group7091.set_student(&FirstStudent);
	group7091.set_student(&Second);
	group7091.set_student(&Thrid);
	group7091.set_student(&Four);
	group7091.set_student(&Five);
	group8032.set_student(&Thrid);

	//vector<Student*> students = group7091.get_sort_students(marks);

	//for (unsigned i = 0; i < students.size(); i++)
	//{
	//	students[i]->show_student();
	//	cout << endl;
	//	cout << endl;
	//}

	/*group7091.show_students();
	cout << endl;

	cout << "----------------------------------------" << endl;
	group7091.delete_student(&FirstStudent);
	group8032.delete_student(&Thrid);
	group7091.show_students();
	cout << endl;
	cout << "----------------------------------------" << endl;

	Thrid.show_student();
	cout << endl;

	cout << endl;*/
	system("Pause");
	return 0;
}

