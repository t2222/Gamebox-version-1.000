#ifndef NUMBER_KNOT_H
#define NUMBER_KNOT_H
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
namespace knot
{
string getFileContents (ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
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
    ifstream Reader ("art_numberknot.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file

    cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file
}

void introduction()
{
    print_ascii_art();
    cout << ">Welcome to Number Knot (cloned) game (version-1.006) by Tousif.\n";
    cout << std::setfill ('*') << std::setw (100);
    cout << "\n>This is the simulation of famous Puzzle Board Game Hidato.\n";
    cout << std::setfill ('*') << std::setw (100);
    cout << "\n>You will be provided with a 3X3 grid and some numbers.";
    cout << "\n>Your Task is to place numbers in the grid in such a way that it forms a loop.\n";
    cout << ">Note that there is only one possible solution. It is better to solve the riddle by pen and paper and then input on the game board.\n";
    cout << ">This game will take input and draw the loop based on it at each step.\n";
    cout << ">At the end you will see the errored part and the actual solution of that level.\n";
    cout << std::setfill ('*') << std::setw (100);
    cout << "\n>Please input from 1 to 9 and do not press other keys.\n";
    system("pause");
    system("cls");
}
}

void play_number_knot()
{
    while(1)
    {
        system("cls");
        knot::introduction();
        player playa(1);
        master_base *p;
        cout << ">Input the level you want to play.\n>1.Level-1\n>2.Level-2\n";
        cout << ">Press any key to exit.\n";
        int choice;
        cin >> choice;
        choice = choice%10;
        try
        {
            if (choice > 2 || (choice != 1 && choice != 2))
                throw choice;
        }
        catch(int c)
        {
            cout << ">Thanks for trying out this game " << playa.get_name() << "\n";
            exit(1);
        }

        if (choice == 1)
        {
            lvl_1::level_1 ob(3,3);
            p = &ob;
        }

        if(choice == 2)
        {
            lvl_2::level_2 ob(3,3);
            p = &ob;
        }

        playa.set_name();
        cout << playa.get_name() << " Your game is begining.\n";
        p->draw_board();
        p->process_question();
        p->draw_board();
        p->play();
        p->error_detection();

        system("pause");
        getchar();
        system("cls");
        cout << ">Hey," << playa.get_name() << " do you like play another round? 0 = no, 1 = yes.\n>Enter :";
        cin >> choice;
        if (!choice)
        {
            cout << ">Thanks for trying out this game " << playa.get_name() << "\n";
            system("pause");
            system("cls");
            return;
        }
    }

}
#endif // NUMBER_KNOT_H
