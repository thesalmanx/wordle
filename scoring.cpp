#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int scoring(string username, int attempts)
{
    bool found = false;
    string dump;
    int linecount = 0, userline = 5, count;

    ifstream scorefile("scores.txt");
    ifstream usersfile("users.txt");
    fstream scores;
    ofstream tempscores("tempscores.txt");
    ofstream users;


    // Writing User's Score to Leaderboard
    if (usersfile.is_open())
    {
        // ifstream file ("wordlist.txt"); //declared in declaration block
        while (!usersfile.eof() && found == 0)
        {
            linecount++;
            getline(usersfile, dump);
            if (dump == username) // Username already exists, overwrite score instead
            {
                userline = linecount;
               // cout << "User " << username << " exists at line " << userline << endl;

                linecount = 1;
                found = 1;
               // cout << "Found status: --- " << found;
                // update
                while (scorefile >> count)
                {
                    if (linecount != userline)
                    {
                        tempscores << count << "\n";
                    }
                    else
                    {
                        tempscores << attempts << "\n";
                    }
                    linecount++;
                }
                scorefile.close();
                tempscores.close();
                remove("scores.txt");                   // File With the Word to be Deleted Removed
                rename("tempscores.txt", "scores.txt"); // Updated File Renamed
            }
            else
            {                                             // User Doesn't Exist !
                found = false;
            }
        }
        usersfile.close();
    }
    else
    {
        cout << "Unable to open";
    }


    //cout << "Found status: " << found;
    if (found == false) {
        scores.open("scores.txt", ios_base::app); // append instead of overwrite
        scores << attempts << "\n";
        scores.close();

        users.open("users.txt", ios_base::app); // append instead of overwrite
        users << username << "\n";
        users.close();
    }
    return 0;
}
