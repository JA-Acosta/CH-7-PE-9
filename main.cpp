// JAAR
// 05/24/2023
// C++ Primer Plus 6th Ed
// CH 7 Program Ex 9
// Version 2

// Updates:
// +int age; struct student
// -int ooplevel; struct student
// +getinfo function
// +display1 function
// +display2 function
// +display3 function
// -display1 call in main
// -display2 call in main


// Future goals:
// Update the program to reflect if the user enters no students.

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
	int age;
};

// Prototypes:
int getinfo(student pa[], int n);
void display1(student st);
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
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
}

// For a class, creates a list containing each students name, a hobby they
// provided, and their age. The function will add students up to the class
// size or until the name inputted is blank.
// !Assume the user inputs an integer for the age
// !Assume the user inputs a character string less than the SLEN for name 
// !and hobby.
// !Assume the user inputs at least one student
// Param: student pa, int n
// Return: int n
int getinfo(student pa[], int n)
{
	int i = 0;
	cout << "Input the full name for student #" << i+1 << ": ";
	while (cin.getline(pa[i].fullname, SLEN) && (pa[i].fullname)[0] != '\0' &&
		i < n)
	{
		cout << "Input their hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Input their age: ";
		cin >> pa[i].age;
		cin.get();
		i++;
		cout << "Input the full name for student #" << i + 1 << ": ";
	}
	return i;
}

// Displays the information inputted for a given student.
// Param: student st
void display1(student st)
{
	cout << "Full Name: " << st.fullname << "\n";
	cout << "Hobby: " << st.hobby << "\n";
	cout << "Age: " << st.age << "\n";
}

// Displays the information inputted for a given student.
// Param: student* p_st
void display2(student* p_st)
{
	cout << "Full Name: " << p_st->fullname << "\n";
	cout << "Hobby: " << p_st->hobby << "\n";
	cout << "Age: " << p_st->age << "\n";
}

// Displays the information for all the students in a given class.
void display3(const student pa[], int n)
{
	cout << "Class Roster:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Full Name: " << pa[i].fullname << "\n";
		cout << "Hobby: " << pa[i].hobby << "\n";
		cout << "Age: " << pa[i].age << "\n";
	}
}