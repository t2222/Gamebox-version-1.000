#ifndef LEVEL_1_H
#define LEVEL_1_H
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
namespace lvl_1
{

class level_1:public master_base
{
    int score;
public:

    void set_row_col(int r,int c)
    {
        row = r;
        col = c;
    }

    void increment_score()
    {
        ++score;
    }

    level_1(int m,int n):master_base(m,n)
    {
        score = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                board[i][j] = '_';
                temp_board[i][j] = '_';
                mask_board[i][j] = false;
                //mask_correction_board[i][j] = false;
            }
        }
    }

    void process_question()
    {
        board[0][1] = '2';
        board[1][0] = '8';
        board[2][1] = '6';
        mask_board[0][1] = true;
        mask_board[1][0] = true;
        mask_board[2][1] = true;
    }

    void process_solution_board()
    {
        solution_board[0][0] = '1';
        solution_board[0][1] = '2';
        solution_board[0][2] = '3';
        solution_board[2][2] = '5';
        solution_board[2][1] = '6';
        solution_board[2][0] = '7';
        solution_board[1][0] = '8';
        solution_board[1][1] = '9';
        solution_board[1][2] = '4';
    }

    void process_answer()
    {
        for(int i = 0 ; i < 3 ; i++)
            board[0][i] = '-';
        board[1][2] = 'I';
        board[2][2] = 'I';
        board[2][1] = '-';
        board[2][0] = '-';
        board[1][0] = 'I';
        board[1][1] = '*';
    }

    void process_numeric_view()
    {
        board[0][0] = '1';
        board[0][1] = '2';
        board[0][2] = '3';
        board[2][2] = '5';
        board[2][1] = '6';
        board[2][0] = '7';
        board[1][0] = '8';
        board[1][1] = '9';
        board[1][2] = '4';
    }

    void process_temp_answer(int r,int c,char val)
    {
        temp_board[0][1] = '-';
        temp_board[1][0] = 'I';
        temp_board[2][1] = '-';
        if (r == 0)
        {
            if (c == 0 && val == '1')
                temp_board[r][c] = '-';
            if (c == 1 && val == '2')
                temp_board[r][c] = '-';
            if (c == 2 && val == '3')
                temp_board[r][c] = '-';
        }
        else if (r == 1 && c == 0 && val == '8')
            temp_board[r][c] = 'I';
        else if (r == 1 && c == 1 && val == '9')
            temp_board[r][c] = '-';
        else if (r == 1 && c == 2 && val == '4')
            temp_board[r][c] = 'I';
        else if (r == 2 && c == 0 && val == '7')
            temp_board[r][c] = '-';
        else if (r == 2 && c == 1 && val == '6')
            temp_board[r][c] = '-';
        else if (r == 2 && c == 2 && val == '5')
            temp_board[r][c] = 'I';
    }

    void draw_board()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                cout << board[i][j] << "|";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void draw_temp_board()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                cout << temp_board[i][j] << "|";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    bool exit_status()
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                if(board[i][j] == '_')
                    return false;
            }
        }
        return true;
    }

    bool check_input_validity(int r,int c)
    {
        if ((r >= 3 || c >= 3 || r<0 ||c<0) || (r == 0 && c == 1))
            return false;
        else if ((r >= 3 || c >= 3) || (r == 1 && c == 0))
            return false;
        else if ((r >= 3 || c >= 3) || (r == 2 && c == 1))
            return false;
        else if (mask_board[r][c] == false)
            return true;
        else
            return false;
    }

    bool is_input_correct(int r,int c,char val)
    {
        if (solution_board[r][c] == val)
            return true;
        else
            return false;
    }

    int input_as_int()
    {
        string theInput;
        int inputAsInt;

        cin >> theInput;
        //cin.fail() == wrong input
        //theInput.find_first_not_of("0123456789") != npos__find first missing digit
        //npos == last of string
        while(cin.fail() || cin.eof() || theInput.find_first_not_of("0123456789") != string::npos)
        {

            cout << "Error" << endl;

            //find 1st missing and then clear error flag of cin.
            //then ignore buffer and take next input
            if( theInput.find_first_not_of("0123456789") == string::npos)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            cin >> theInput;
        }

        string::size_type st;
        inputAsInt = std::stoi(theInput,&st);
        return inputAsInt;
    }

    void input()
    {
        char inp;
        string s;
        int r,c;
        cout << ">Input array index you want to access: ";
        getchar();//stoi() was crashing, pressing enter caught
        r = input_as_int();
        c = input_as_int();
        if (!check_input_validity(r,c))
            cout << ">Wrong indices. Try again.\n";
        else
        {
            set_row_col(r,c);
            mask_board[r][c] = true;
            cout << "\n>Input digit for ";
            cout << "board[" << row << "]" << "[" << col << "]" << " = ";
            while(1)
            {
                cin >> inp;
                if (inp >= '1' && inp <= '9')
                {
                    break;
                }
                else
                    cout << "Input must be integer from 1 to 9. Try again.\n";
            }
            board[row][col] = inp;

            if (!is_input_correct(r,c,inp))
            {
                is_error = true;
                //mask_correction_board[r][c] = true;
            }

            cout << ">Main board looks like -\n";
            draw_board();
            process_temp_answer(row,col,inp);
            cout << "\n>Temporary graphic solution looks like this :\n";
            draw_temp_board();
        }
    }

    void error_detection()
    {
        //from mask2 to the mask1 matrix
        int i,j;
        if (is_error)
        {
            for (i = 0 ; i < 3 ; i++)
            {
                for (j = 0 ; j < 3 ; j++)
                {
//                if (mask_correction_board[i][j] == true)
//                    cout << ">error at row: " << i << " col: " << j << endl;
//                    //mask_board[i][j] = false;
                    if (temp_board[i][j] == '_')
                        cout << ">error at row: " << i << " col: " << j << endl;
                }
            }
        }

    }

    int matching_and_scoring()
    {
        if (board[0][0] == '1' )
            increment_score();
        if (board[0][2] == '3')
            increment_score();
        if (board[1][1] == '9')
            increment_score();
        if (board[1][2] == '4')
            increment_score();
        if (board[2][0] == '7')
            increment_score();
        if (board[2][2] == '5')
            increment_score();
        return score;
    }

    void play()
    {
        int moves = 10;
        cout << ">Moves remaining " << moves << endl;
        while (--moves)
        {
            input();
            cout << ">Moves remaining " << moves << endl;
            if (exit_status())
            {
                {
                    cout << ">Game finished\n";
                    break;
                }
            }
        }
        int base_score;
        base_score = matching_and_scoring();
        std::ofstream file("numberknot_log.txt",std::ios_base::app);
        ///Functor
        class score_gen
        {
            int b,m;
        public:
            score_gen(int x = 1, int y = 1):
                b(x),m(y) {}
            int operator()(int b,int m)
            {
                if (m!=0)
                    return b*m;
                else
                    return b;
            }
        };
        score_gen s1(moves);
        int total = s1(base_score,moves);
        //cout << total << endl;
        cout << ">You saved " << moves << " moves. Your base score is " << base_score << ". Multiplying these,\n";
        file << ">You saved " << moves << " moves. Your base score is " << base_score << ". Multiplying these,\n";
        cout << ">Your total score is : " << total << endl;
        file << ">Your total score is : " << total << endl;
        cout << ">Numeric view of standard solution board :\n";
        process_numeric_view();
        draw_board();
        cout << ">Graphical view of standard solution board :\n";
        process_answer();
        draw_board();
    }

};

}
#endif
