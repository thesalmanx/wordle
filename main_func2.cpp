#include <iostream>	 //basic inputs & output
#include <iomanip>	 //formatting purposes
#include <conio.h>	 //_getch() function
#include <Windows.h> //sleep function
#include <string>	 //string handling and use
#include <fstream>	 // file management
#include <array>
using namespace std;

int password_func();
int admin_func();
int user_func();
bool fullscrn=false;
bool fullscrn_func() {

	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 36;
	fontex.dwFontSize.Y = 36;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	fullscrn = true;
	return fullscrn;
}
int main()
{
	char login;
	string top_bar = "	   -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
	if (fullscrn == false) {
		fullscrn_func();
	}
	// Color Changing Purposes
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);
	// Main Menu:
	//cout << endl
		// << endl
		 cout << top_bar;
	SetConsoleTextAttribute(h, 11); // Changes Color
	cout << "\t\t       * Welcome to WORDLE *\n"
		 << endl;
	SetConsoleTextAttribute(h, 15); // Sets Back to Default Color
	cout << "\t\tLogin as: \n" << endl;
	cout << "\t\t1. User\n"; // Displays the Login Options To the User
	cout << "\t\t2. Admin\n";
	cout << "\t\t3. Exit\n"
		 << endl;
	cout << "\t\tSelect an option: ";

	do // Loops Until User Enters a 1,2 or 3
	{
		login = _getch(); // User Enters Their Desired Login Option
		cout << login;
		do // Loops Until Valid
		{
			if (cin.fail()) // Data Type Check, if Not Valid, Returns an Error
			{
				cin.clear();
				cin.ignore(1000, '\n');
				SetConsoleTextAttribute(h, 4);
				cout << "\n\n\t\t"
					 << "Incorrect Input. Press any key to return to main menu...";
				SetConsoleTextAttribute(h, 15);
				_getch();
				cin.ignore();

				system("CLS"); // Clears Terminal
				main();		   // Returns to Main Menu
			}
		} while (false);

		switch (login) // Presents Menus based on the Login Option
		{
		case '1':
			// User Menu:
			user_func();
			break;
			// Admin Menu
		case '2':
			password_func();
			break;

		case '3': // Exits the Program
			cout << endl
				 << "\t\tExiting";
			for (int i = 0; i <= 12; i++)
			{
				cout << ".";
				Sleep(100);
			}
			cout << "\n";
			exit(EXIT_SUCCESS);
			break;

		default: // Default Error Message For Entering the Wrong Login Option
			SetConsoleTextAttribute(h, 4);
			cout << "\n\t\tIncorrect input. Please try again\a\n"
				 << "\t\tSelect an option: ";
			SetConsoleTextAttribute(h, 15);
			break;
		}
	} while (login != '1' && login != '2' && login != '3');
	return 0;
}



