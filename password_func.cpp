#include <iostream>	 //basic inputs & output
#include <iomanip>	 //formatting purposes
#include <conio.h>	 //_getch() function
#include <Windows.h> //sleep function
#include <string>	 //string handling and use
#include <fstream>	 // file management
#include <array>

using namespace std;

int main();
int admin_func();
int password_func() {
	//char pass;
	string pass_char, stored_pass_str;
	char admin_pass[16] = { 0 };
	//ofstream temppass("temppass.txt");
	string temppass_str, admin_pass_str;
	ifstream passfile("password.txt");
	int passLength = 0;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);

	cout << endl
		<< "\t\tEnter admin password: "; // Asks Admin for Password (declared as 'admin')


	
		//passfile.open("password.txt", ios_base::app);
		passLength = 0;
		//if (passfile.is_open())
		{
			getline(passfile, stored_pass_str);
			//cout << "\n\n\t\t"
				//<< "Store pass is: " << stored_pass_str;
			passfile.close();
			passLength = 0;
			while (passLength < 16)
			{
				admin_pass[passLength] = _getch();

				if (admin_pass[passLength] > 32 && admin_pass[passLength] < 126) // valid char
				{
					cout << '*';
					passLength++;
				}

				else if (passLength > 0)
				{
					if (admin_pass[passLength] == 13) // enter key

					{
						admin_pass[passLength] = 0;
						break;
					}

					if (admin_pass[passLength] == 8) // backspace key
					{
						admin_pass[passLength] = 0;
						passLength = passLength - 1;
						cout << "\b \b";
					}
				}
			}
			admin_pass_str = admin_pass;//passLength++;
			//cout << "\n\n\t\t"
				//<< "Store pass is: " << admin_pass_str;

			if (admin_pass_str == stored_pass_str) // If Valid, Presents Admin Menu Options
			{
				admin_func();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\n\n\t\tWRONG PASSWORD! Returning to main menu.\a"; // Error Message for Entering Wrong Password, Returns User to Main Menu
				for (int i = 0; i <= 12; i++)
				{
					cout << ".";
					Sleep(100);
				}
				SetConsoleTextAttribute(h, 15);
				system("CLS");
				main();
			}
		}

		

	}