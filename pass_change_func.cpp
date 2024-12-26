#include <iostream>
#include <Windows.h>
#include <conio.h>
#include<string>
#include <array>
#include <fstream>

using namespace std;
int main();
int pass_change() {
	//char pass;

	string pass_char, stored_pass_str;
	char admin_pass[16] = { 0 };
	ofstream temppass("temppass.txt");
	string temppass_str, admin_pass_str;
	ifstream passfile("password.txt");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);


	cout << "\n\n\t\tEnter new password: ";
	//cin.ignore();
	getline(cin, temppass_str);
			temppass << temppass_str;
			passfile.close();
			temppass.close();
			remove("password.txt");				// File With the Word to be Deleted Removed
			rename("temppass.txt", "password.txt");

	SetConsoleTextAttribute(h, 10);
	cout << "\n\t\tPassword Changed Successfully.\n";
	SetConsoleTextAttribute(h, 14);
	cout << "\n\n\t\t"
		<< "Press any key to return to main menu...";
	SetConsoleTextAttribute(h, 15);

	_getch();
	system("CLS");
	main();
	return 0;
}