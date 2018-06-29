#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <fstream>
#include <iomanip>
const int x = 4;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ofstream;
class game
{
    char board[4][4];
public:
    game()
    {
        for (int i = 0 ; i < x ; i++)
        {
            for (int j = 0 ; j < x ; j++)
            {
                board[i][j] = '_';
            }
        }
    }

    friend ostream &operator<< (ostream &output, game ob);

    void draw_board()
    {
        ofstream file1("tictactoe_log.txt",std::ios_base::app);
        for (int i = 0 ; i < x ; i++)
        {
            for (int j = 0 ; j < x ; j++)
            {
                cout << board[i][j] << "|";
                file1 << board[i][j] << "|";
            }
            cout << endl;
            file1 << "\n";
        }
    }

    void set_position(char symbol)
    {
        int row,col;
        while(1)
        {
            while (1)
            {
                cout << "\n>Input row and column(array based indexing method) : ";
                cin >> row >> col;
                if (row < 0 || row > x || row == x || col < 0 || col > x || col == x)
                    cout << "\n>Invalid input. Please try again. ";
                else
                    break;
            }
            if (board[row][col] == '_')
            {
                board[row][col] = symbol;
                break;
            }
            else
                cout << "\n>position is taken .\n";
        }

    }

    int check_horizontal(char symbol)
    {
        int counter;
        for (int i = 0 ; i < x ; i++)
        {
            counter = 0;
            for (int j = 0 ; j < x ; j++)
            {
                if (board[i][j] == symbol)
                {
                    ++counter;
                }
                if (counter==x)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    int check_vertical(char symbol)
    {
        int counter;
        for (int i = 0 ; i < x ; i++)
        {
            counter = 0;
            for (int j = 0 ; j < x ; j++)
            {
                if (board[j][i] == symbol)
                {
                    ++counter;
                }
                if (counter==x)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    int check_principle_diagonal(char symbol)
    {
        int counter = 0;
        for (int i = 0 ; i < x ; i++)
        {
            if (board[i][i] == symbol)
            {
                ++counter;
            }
            else
                break;
        }
        if (counter==x)
        {
            return 1;
        }
        else
            return 0;
    }

    int check_other_principle_diagonal(char symbol)
    {
        int counter,r,c;
        r = 0;
        c = x-1;
        counter = 0;
        /// r|c, x=3, c=3-1=2, r=0
        /// 0|2
        /// 1|1
        /// 2|0
        while(r<x && c>-1)
        {
            if (board[r][c] == symbol)
                ++counter;
            r++;
            c--;
        }
        if (counter == x)
            return 1;
        else
            return 0;
    }

    int check_draw()
    {
        //any unused space found, break loop ie: no draw
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<x; j++)
            {
                if(board[i][j]=='_')
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

ostream &operator<< (ostream &output, game ob)
{
    ofstream file1("tictactoe_log.txt",std::ios_base::app);
    for (int i = 0 ; i < x ; i++)
    {
        for (int j = 0 ; j < x ; j++)
        {
            cout << ob.board[i][j] << "|";
            file1 << ob.board[i][j] << "|";
        }
        cout << endl;
        file1 << "\n";
    }
    return output;
}

namespace tic
{
string getFileContents (ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
        while (File.good ())
        {
            string TempLine;                  //Temp line
            getline (File, TempLine);         //Get temp line
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
    ifstream Reader ("art_tictactoe.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file

    cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file
}

void introduction()
{
    system("cls");
    print_ascii_art();
    cout << "\nWelcome to 2-player Tic-Tac-Toe (version 1.003) by Tousif\nThis is a game of classic Tic-Tac-Toe. Rules are given.\n";
    cout << std::setfill ('*') << std::setw (200);
    cout << "\nA Cyber Oculus web page (Copyright 1998-2000) describes Tic-Tac-Toe as follows:\n";
    cout << "The object of Tic Tac Toe is to get three in a row. \nYou play on a three by three game board. \nThe first player is known as X and the second is O. \nPlayers alternate placing Xs and Os on the game board until either oppent has three in a row or all nine squares are filled. \nX always goes first, and in the event that no one has three in a row, the stalemate is called a cat game.\n";
    cout << std::setfill ('*') << std::setw (187);
    cout << "\nJust remember vertical, horizontal, diagonal matching is possible.\n";
    cout << "Press any key to continue....\n";
    getchar();
}
}


void play_tictactoe()
{
    tic::introduction();
    game ob;
    player p1(1),p2(2);
    char symbol1,symbol2;

    p1.set_name();
    cout << "\n>Player-1(" << p1.get_name() << ")input your preferred symbol :: ";
    cin >> symbol1;
    p1.set_symbol(symbol1);
    cout << endl;

    p2.set_name();
    while(1)
    {
        cout << "\n>Player-2(" << p2.get_name() << ")input your preferred symbol :: ";
        cin >> symbol2;
        if (symbol1 == symbol2)
            cout << "Try again. Symbol taken.\n";
        else
            break;
    }
    p2.set_symbol(symbol2);

    cout << "\n>Player-1:\n\t\tname :"<< p1.get_name() << endl;
    cout << "\t\tsymbol :"<< p1.get_symbol() << endl;
    cout << ">Player-2:\n\t\tname :"<< p2.get_name() << endl;
    cout << "\t\tsymbol :"<< p2.get_symbol() << endl;
    cout << ">LET THE GAME BEGIN !" << endl;

    //ob.draw_board();
    cout << ob;
    while(1)
    {
        cout <<  ">" << p1.get_name() << " Player-1 it is your turn.\n";
        ob.set_position(symbol1);
        //ob.draw_board();
        cout << ob;
        ofstream file1("tictactoe_log.txt",std::ios_base::app);
        if(ob.check_horizontal(symbol1)==1 || ob.check_vertical(symbol1)==1 ||
                ob.check_principle_diagonal(symbol1)==1 || ob.check_other_principle_diagonal(symbol1)==1)
        {
            cout << "\n>Player-1(" << p1.get_name() << ")has won...\n\n>End of game.\n\n";
            file1 << "\n>Player-1(" << p1.get_name() << ")has won...\n\n>End of game.\n\n";
            break;
        }

        cout <<  ">" << p2.get_name() << " Player-2 it is your turn.\n";
        ob.set_position(symbol2);
        //ob.draw_board();
        cout << ob;
        if(ob.check_horizontal(symbol2)==1 || ob.check_vertical(symbol2)==1 ||
                ob.check_principle_diagonal(symbol2)==1 || ob.check_other_principle_diagonal(symbol2)==1)
        {
            cout << "\n>Player-2(" << p2.get_name() << ")has won...\n\n>End of game.\n\n";
            file1 << "\n>Player-2(" << p2.get_name() << ")has won...\n\n>End of game.\n\n";
            break;
        }

        if (ob.check_draw()==0)
        {
            cout << ">Draw.\n>End of game.\n";
            file1 << ">Draw.\n>End of game.\n";
            break;
        }
    }

    system("pause");
    system("cls");
    ofstream file1("tictactoe_log.txt",std::ios_base::app);
    file1 << "\nFinish..........";
    cout << "\nThanks for playing TicTacToe.\nExiting...\n";
    return;
}
#endif // TICTACTOE_H
