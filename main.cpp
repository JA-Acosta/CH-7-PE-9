// JAAR
// 05/23/2023
// C++ Primer Plus 6th Ed
// CH 7 Program Ex 9
// Version 1

// Updates:

// Future goals:

// Potential Use cases/errors:

// ------------------------------ Prompt---------------------------------------
// Complete the program skeleton based on the functions requested.
// ------------------------------ Prompt---------------------------------------

// Headers:
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Global Constants and Structures:
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

// Prototypes:
// getinfo() has 2 arguments: a pointer to the first element of an array of student structures and an int representing
// the number of elemnts of the array. The function solicits and stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);

// display1() takes a student struct as it's argument and displays it's contents.
void display1(student st);

// display2() takes the address of student structure as an argument and displays the structure's content
void display2(student* p_st);

// display3() takes the address of the first element of an array of students structures and the nuymber of array elements
// as arguments and displays the contents of the structures
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
}