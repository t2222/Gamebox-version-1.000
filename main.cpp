#include "master.h"
#include "level_1.h"
#include "level_2.h"
#include "player.h"
#include "number_knot.h"
#include "tictactoe.h"
#include "hang.h"
int choice;
void about()
{
    system("cls");
    cout << "Gamebox is a collection of board games and puzzle games. Most of the games are classic and well known.\n";
    cout << "But many new puzzles are involved. Rules of every games are included. But if you can't figure out yourself, try google. ^_^\n";
    cout << "Gamebox has games like:\n";
    cout << "\t\t" << "1.TicTacToe\n";
    cout << "\t\t" << "2.Hangman\n";
    cout << "\t\t" << "3.Number-knot\n";
    cout << "\t\t" << "4.Connect-4\n";
    cout << "\t\t" << "5.Reversi\n";
    cout << "\t\t" << "6.Snake\n";
    cout << "\t\t" << "7.Space-shooter\n";
    cout << "\t\t" << "8.Black-jack\n";
    cout << "\t\t" << "9.Chess...etc\n";
    cout << "Many new games will be included in next versions. This is version 1.000 beta.\n";
    cout << "Most of the games have 2 player implementation. AI will be implemented in later versions.\n";
    cout << "Releases : Windows XP,7,8,10.\n";
    cout << "\t\t\t____________________________________\n";
    cout << "\t\t\t|Developer: Tousif,CSE,KUET,1607015|\n";
    cout << "\t\t\t------------------------------------\n";
    cout << "\nThis project was developed for CSE2102 course of KUET.\n\n";
    cout << "Press any key to clear screen.\n";
    system("pause");
    system("cls");
}

string getFileContents (ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      // Returns true if none of the stream's error state flags (eofbit, failbit and badbit) is set.
    {
        while (File.good())
        {
            string TempLine;                  //Temp line
            getline (File, TempLine);         //Get temp line
            TempLine += "\n";                 //Add newline character

            Lines += TempLine;                 //Add newline
        }
        return Lines;
    }
    else                           //Return error
    {
        return "ERROR File does not exist.";
    }
}

void print_ascii_art()
{
    ifstream Reader ("art_main.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file

    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file
}

void message()
{
    cout << "\n\n";
    print_ascii_art();
    cout             << "\t\t\t\t" << "Welcome to Gamebox(version 1.000) by Tousif\n";
    cout             << "\t\t\t\t" << "-----------------------" << endl
                     << "\t\t\t\t" << "| 1. Play Hangman     |" << endl
                     << "\t\t\t\t" << "| 2. Play TicTacToe   |" << endl
                     << "\t\t\t\t" << "| 3. Play Number-knot |" << endl
                     << "\t\t\t\t" << "| 4. About Gamebox    |" << endl
                     << "\t\t\t\t" << "| 0. Exit Gamebox     |" << endl
                     << "\t\t\t\t" << "-----------------------" << endl
                     << "\t\t\t\t" << "Selected : ";

}

void input_choice()
{
    while(1)
    {
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 0)
            break;
        else
            cout << "\nInvalid choice. Press from 0 to 4 and enter.\n";
    }
}

int main()
{
    while(1)
    {
        message();
        input_choice();
        switch(choice)
        {
        case 1:
            play_hangman();
            break;
        case 2:
            play_tictactoe();
            break;
        case 3:
            play_number_knot();
            break;
        case 4:
            about();
            break;
        case 0:
            cout << "\n\t\t\t\tExiting Gamebox\n";
        }
    }

}
/// level2 0 0 2 0 2 9 1 1 8 2 0 4 2 1 5 2 2 6
/// level1 0 0 1 0 2 3 1 1 9 1 2 4 2 0 7 2 2 5
/// hangman
