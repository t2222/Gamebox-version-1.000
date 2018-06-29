#ifndef PLAYER_H
#define PLAYER_H
class player
{
    int player_no;
    char symbol;
    string name;
public:
    player(int n)
    {
        player_no = n;
    }

    void set_name()
    {
        cout << ">Player: " << player_no << " input your name :: ";
        cin >> name;
    }

    void set_symbol(char c)
    {
        symbol = c;
    }

    string get_name()
    {
        return name;
    }

    char get_symbol()
    {
        return symbol;
    }

};


#endif // PLAYER_H
