#include <iostream>
#include <windows.h>
#ifndef MASTER_H
#define MASTER_H
using std::cin;
using std::cout;
using std::endl;
using std::string;
class master_base
{
protected:
    char board[5][5];
    char temp_board[5][5];
    char solution_board[5][5];
    bool mask_board[5][5];
    //bool mask_correction_board[5][5];
    bool is_error;
    int row,col;
public:
    master_base(int m,int n)
    {
        row = m;
        col = n;
    }
    virtual void set_row_col(int r,int c) = 0;
    virtual void process_question() = 0;
    virtual void process_numeric_view() = 0;
    virtual void process_answer() = 0;
    virtual void process_temp_answer(int r,int c,char val) = 0;
    virtual void process_solution_board() = 0;
    virtual void draw_board() = 0;
    virtual void draw_temp_board() = 0;
    virtual void play() = 0;
    virtual void input() = 0;
    virtual int matching_and_scoring() = 0;
    virtual bool check_input_validity(int r,int c) = 0;
    virtual bool is_input_correct(int r,int c,char val) = 0;
    virtual void error_detection() = 0;
};

#endif // MASTER_H
