#include <iostream>	 //basic inputs & output
#include <iomanip>	 //formatting purposes
#include <conio.h>	 //_getch() function
#include <Windows.h> //sleep function
#include <string>	 //string handling and use
#include <fstream>	 // file management
#include <array>
using namespace std;


int main();
int theGame(string);
int leaderboard();
string username;
bool usrname_ent;

void username_func() {
	cout << endl
		<< endl;
	cout << "\t\tEnter your username (username should not be longer than 20 characters):\n\t\t";
	getline(cin, username); // User enters their Desired Username
}
int user_func() {
	// Declaration Block:
	
	// variables Used
	char user_menu;
	int attempts, highscore = 7, score, linecount = 0, userline = 0;
	string top_bar = "	   -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n", word, searchword,username_high;
	
	// Filing Streams
	/*fstream scorefile("scores.txt");
	fstream usersfile("users.txt");*/

	// Color Changing Purposes
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);

	// User Menu:
	do
	{
		if (usrname_ent == false) {
			username_func();
			usrname_ent = true;
		}
		if (username.length() <= 20)
		{

			system("CLS");

			cout << top_bar;
			SetConsoleTextAttribute(h, 11);
			cout << "\t\t         * Welcome " << username << " * \n"
				<< endl;
			SetConsoleTextAttribute(h, 15);
			cout << "\t\t1. Start Game\n\t\t2. View leaderboard\n\t\t3. Back to main menu\n\t\t4. Exit\n\t\t5. Instructions\n\n\t\tSelect an option: "; // User Menu Options
			do
			{
				user_menu = _getch(); // User Enters Their Choice
				cout << user_menu;

				do // Data Type Check
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1000, '\n');
						SetConsoleTextAttribute(h, 4);
						cout << "\n\n\t\t"
							<< "Incorrect Input. Re-enter: ";
						SetConsoleTextAttribute(h, 15);
					}
				} while (false);

				switch (user_menu)
				{
				case '1': // User Starts a New Game
					theGame(username);
					break;

				case '2': // View Highscore From the Leaderboard
					leaderboard();
					// Return to Main Menu
					SetConsoleTextAttribute(h, 14);
					cout << "\n\n\t\t"
						<< "Press any key to return to user menu...";
					SetConsoleTextAttribute(h, 15);
					_getch();
					system("CLS");
					user_func();
					break;

				case '3': // Returns to Main Menu
					system("CLS");
					usrname_ent = false;
					main();
					break;

				case '4': // Exit Program
					cout << endl
						<< "\t\tExiting";
					for (int i = 0; i <= 12; i++)
					{
						cout << ".";
						Sleep(100); // Prints '.'s with a Delay
					}
					cout << "\n";
					exit(EXIT_SUCCESS);
					break;

				case '5': // Instructions
					SetConsoleTextAttribute(h, 11);
					cout << setw(15) << "\n\n\t\t         * Instructions *\n";
					SetConsoleTextAttribute(h, 15);
					cout << endl
						<< "\t\t1. You have to guess the Wordle in six goes or less.";
					cout << endl
						<< "\t\t2. Every word you enter must be in the word list.";
					cout << endl
						<< "\t\t3. A correct letter turns green.";
					cout << endl
						<< "\t\t4. A correct letter in the wrong place turns yellow.";
					cout << endl
						<< "\t\t5. An incorrect letter turns gray.";
					cout << endl
						<< "\t\t6. Letters can be used more than once.";
					cout << endl
						<< "\t\t7. Answers are never plurals.";
					cout << endl;

					SetConsoleTextAttribute(h, 14);
					cout << "\n\n\t\t"
						<< "Press any key to return to user menu...";
					SetConsoleTextAttribute(h, 15);

					_getch();
					system("CLS");
					user_func();

					return 0;
					break;

				default: // Default Error for Incorect User Menu Input
					SetConsoleTextAttribute(h, 4);
					cout << "\n\t\tIncorrect input. Please try again\a\n"
						<< "\t\tSelect an option: ";
					SetConsoleTextAttribute(h, 15);
					break;
				}
			} while (user_menu != '1' && user_menu != '2' && user_menu != '3' && user_menu != '4' && user_menu != '5'); // Loop Until Valid User Menu Input
		}
		else
			cout << "\t\tThe entered username is too long. Please try again\n\a";
	} while (username.length() >= 20); // Asks User for Username Until Valid Length
}