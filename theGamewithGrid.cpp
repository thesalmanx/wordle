#include <iostream>
#include <string>
#include <fstream>     // file management
#include <stdlib.h>    // srand, rand
#include <time.h>      // time
#include <cstring> //strcopy
#include <Windows.h>
#include <conio.h>
#include <cwchar>
//#include "guess.cpp"

using namespace std;
int user_func();
int scoring(string, int);
int guess(string guessword);
int theGame(string username)
{
    HANDLE hCursor = GetStdHandle(STD_OUTPUT_HANDLE);
    int loginchoice, adminchoice, userchoice, listcount = 0, wordcount = 0, correctcount = 0, attempts = 0;
    bool found;
    string password = "testy", passwordtry, word, searchword, guessword;
    bool repeat, passwrong, length;
    char wordarray[6], guessarray[6], displayarray[6][7], resultsarray[5][6];

    ofstream addfile;
    ofstream tempfile("temp.txt");
    ifstream myfile("wordlist.txt");

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);

    system("CLS");
    if (myfile.is_open())
    {
        while (getline(myfile, word))
        {
            ++listcount;
        }
        myfile.close();
        // cout << listcount << endl; // total words

        srand(time(NULL));
        wordcount = rand() % listcount + 1;
        // cout << wordcount << endl; // randomized line count

        listcount = 1;
        myfile.open("wordlist.txt");
        while (listcount <= wordcount)
        {
            if (myfile.is_open())
            {
                getline(myfile, word);

                ++listcount;
            }
        }
        cout << "\t\t";
        //cout << word << endl;
        cout << "\n";
        // converting word into a character array !
        strcpy_s(wordarray, word.c_str());
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    // display array
    SetConsoleTextAttribute(h, 11);
    cout << "\t\t             * Wordle *\n"
        << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n";
    int y = 5;
    for (int j = 0; j < 6; j++)
    {

        cout << "\t\t";
        int x = 26;
        for (int i = 0; i < 5; i++)
        {
            COORD pos = { x, y };
            SetConsoleCursorPosition(hCursor, pos);
            displayarray[j][i] = '*';
            cout << displayarray[j][i];
            cout << " ";
            x += 4;
        }
        cout << endl; // clear stream
        y += 2;
    }
    COORD res = { 4,18 };
    SetConsoleCursorPosition(hCursor, res);


    while (attempts < 6 && correctcount != 5)
    {

        do
       {
            cout << "\t\tEnter guess word." << endl;
            cout << "\t\t";
            cin >> guessword;

           found = guess(guessword);
         
        } while (found == 0);
        system("CLS");
        strcpy_s(guessarray, guessword.c_str()); // guess word array
        strcpy_s(wordarray, word.c_str());       // word array
        correctcount = 0;

        for (int j = 0; j < 5; j++) // guessword letters
        {
            int match = 0;
            for (int i = 0; i < 5; i++) // checked against each word letter
            {

                if (guessarray[j] == wordarray[i])
                {

                    if (i == j)
                    {
                        match = 2; // green
                        ++correctcount;
                    }

                    else if (match == 0)
                    {
                        match = 1; // yellow
                    }
                }
            }

            if (match == 2)
            {
                displayarray[attempts][j] = guessarray[j];
                resultsarray[attempts][j] = 2;
            }
            else if (match == 1)
            {

                displayarray[attempts][j] = guessarray[j];
                resultsarray[attempts][j] = 1;
            }
            else
            {
                displayarray[attempts][j] = guessarray[j];
                resultsarray[attempts][j] = 0;
            }
        }

        cout << endl;

        /*for (int i = 0; i < 5; i++)
        {

            displayarray[attempts][i] = guessarray[i];
        }*/
        cout << "\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n\t\t\t|   |   |   |   |   |\n\t\t\t|---|---|---|---|---|\n";
        int y = 2;
        for (int j = 0; j < 6; j++)
        {
            cout << "\t\t";
            //int i = 0;
           
            int x = 26;
            for (int i = 0; i < 5; i++)
            {
                
                COORD pos = { x, y };
                SetConsoleCursorPosition(hCursor, pos);
                if (resultsarray[j][i] == 2)
                {
                   
                    printf("\x1b[32;40m"); // changes text color to green in Mac
                    cout << displayarray[j][i];
                    printf("\x1b[0m"); // changes text back to default
                }
                else if (resultsarray[j][i] == 1)
                {
                    printf("\x1b[33;40m"); // changes text color to yellow in Mac
                    cout <<displayarray[j][i];
                    printf("\x1b[0m"); // changes text back to default
                }
                else
                {
                    cout << displayarray[j][i];
                }
                //printf("\x1b[37;42m");
                cout << " ";
                x += 4;
            }
            cout << endl; // clear stream
            y += 2;
        }
        COORD res = { 4,18 };
        SetConsoleCursorPosition(hCursor, res);
        
        ++attempts;
        cout << "\t\t";
        cout << "Attempts: " << attempts << endl;
        cout << "\t\t";
        cout << "Correct Letters: " << correctcount << endl;
    }
    if (((attempts < 6) && (correctcount == 5)) || correctcount == 5)
    {
        cout << "\t\t";
        cout << "Congratulations! You've guessed the word ! \n";
        cin.ignore();
        scoring(username, attempts);
        SetConsoleTextAttribute(h, 14);
        cout << "\n\n\t\t"
            << "Press any key to return to user menu...";
        SetConsoleTextAttribute(h, 15);
        myfile.close();
        tempfile.close();
        _getch();
        system("CLS");
        user_func();
    }
    else if ((attempts == 6) && (correctcount < 5))
    {
        cout << "\t\t";
        cout << "You've run out of turns ! The correct word was: ";
        for (int i = 0; i < 5; i++)
        {
            cout << wordarray[i];
        }
        cout << "\n";
        cout << "\t\t";
        cout << "Better luck next time!" << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "\n\n\t\t"
            << "Press any key to return to user menu...";
        SetConsoleTextAttribute(h, 15);
        myfile.close();
        tempfile.close();
        _getch();
        system("CLS");
        user_func();
    }
    return 0;
}