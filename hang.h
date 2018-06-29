#ifndef _HANGMAN_H_
#define _HANGMAN_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <windows.h>
#include <map>
#include <utility>
#include "player.h"
using namespace std;

const int MAX_GUESS = 7;
string THE_WORD;
string topic;
vector<string> words;
map<string,string> m;
int wrong;

namespace hang
{
void introduction()
{
    system("cls");
    cout << ">Welcome to hangman version 1.000 by Tousif.\n";
    cout << "\t" << " __   __  _______  __    _  _______  __   __  _______  __    _ " << endl
             << "\t" << "|  | |  ||   _   ||  |  | ||       ||  |_|  ||   _   ||  |  | |" << endl
             << "\t" << "|  |_|  ||  |_|  ||   |_| ||    ___||       ||  |_|  ||   |_| |" << endl
             << "\t" << "|       ||       ||       ||   | __ |       ||       ||       |" << endl
             << "\t" << "|       ||       ||  _    ||   ||  ||       ||       ||  _    |" << endl
             << "\t" << "|   _   ||   _   || | |   ||   |_| || ||_|| ||   _   || | |   |" << endl
             << "\t" << "|__| |__||__| |__||_|  |__||_______||_|   |_||__| |__||_|  |__|" << endl << endl;
    system("pause");
    system("cls");
}
}

class hangman
{
public:
    void hangmandrawing()
    {
        if(wrong==0 || wrong==1)
        {
            cout << " ___________"<<endl;
            cout << " |        }"<<endl;
            cout << " |         " <<endl;
            cout << "_|______________"<<endl;
        }
        else if(wrong==2)
        {
            cout << " ___________"<<endl;
            cout << " |        }"<<endl;
            cout << " |       \\  " <<endl;
            cout << "_|______________"<<endl;
        }
        else if(wrong==3)
        {
            cout << " ___________"<<endl;
            cout << " |         }"<<endl;
            cout << " |       \\ 0 " <<endl;
            cout << "_|______________"<<endl;
        }
        else if(wrong==4)
        {
            cout << " ___________"<<endl;
            cout << " |         }"<<endl;
            cout << " |       \\ 0 /" <<endl;
            cout << "_|______________"<<endl;
        }
        else if(wrong==5)
        {
            cout << " ___________"<<endl;
            cout << " |        }"<<endl;
            cout << " |      \\ 0 /" <<endl;
            cout << " |        |"<<endl;
            cout << "_|______________"<<endl;
        }
        else if(wrong==6)
        {
            cout << " ___________"<<endl;
            cout << " |         }"<<endl;
            cout << " |       \\ 0 /"<<endl;
            cout << " |         | "<<endl;
            cout << " |        /  "<<endl;
            cout << "_|______________"<<endl;
        }
        else
        {
            cout << " ___________"<<endl;
            cout << " |         }"<<endl;
            cout << " |       \\ 0 /"<<endl;
            cout << " |         | "<<endl;
            cout << " |        / \\ "<<endl;
            cout << "_|______________"<<endl;
        }
    }

    void process_words()
    {
        words.push_back("GUESS");
        words.push_back("HANGMAN");
        words.push_back("DIFFICULT");
        words.push_back("TOUSIF");
        words.push_back("BANGLADESH");
        words.push_back("SPAIN");
        words.push_back("BRASIL");
        words.push_back("RUSSIA");

        m.insert(pair<string,string>("GUESS","Think"));
        m.insert(pair<string,string>("HANGMAN","This game"));
        m.insert(pair<string,string>("DIFFICULT","HARD"));
        m.insert(pair<string,string>("TOUSIF","Developer of this app"));
        m.insert(pair<string,string>("BANGLADESH","OUR COUNTRY"));
        m.insert(pair<string,string>("SPAIN","COUNTRY"));
        m.insert(pair<string,string>("BRASIL","COUNTRY"));
        m.insert(pair<string,string>("RUSSIA","COUNTRY"));
    }

    void find_topic(string key)
    {
        map<string,string>::iterator iter;
        iter = m.find(key);
        if (iter!=m.end())
        {
            cout << "\n>Topic : " << iter->second << "\n";
        }
        else
        {
            cout << ">Topic can not be displayed.\n";
        }
    }

    void random_word_generator()
    {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(words.begin(),words.end());
        THE_WORD = words[0];
        find_topic(THE_WORD);
    }

    void game()
    {
        wrong = 0;
        string sofar_guessed(THE_WORD.size(),'-');
        string used = "";
        while((wrong < MAX_GUESS)&&(sofar_guessed!=THE_WORD))
        {
            cout << ">You have: " << MAX_GUESS-wrong << " incorrect guesses left.\n";
            cout << ">You have used the following letters:\n" << used << endl;
            cout << ">The word so far is: " << sofar_guessed << endl;

            char guess;
            cout << "\n>Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
            while(used.find(guess)!=string::npos)
            {
                cout << "\n>You have already guessed: " << guess << endl;
                cout << "\n>Again enter your guess: ";
                cin >> guess;
                guess = toupper(guess);
            }

            used += guess;

            if(THE_WORD.find(guess)!=string::npos)
            {
                cout << ">That's right! " << guess << " is in the word.\n";
                for (unsigned int i = 0; i < THE_WORD.length(); i++)
                {
                    if (THE_WORD[i]==guess)
                    {
                        sofar_guessed[i] = guess;
                    }
                }
            }
            else
            {
                cout << ">Sorry. " << guess << " is not in the word.\n";
                ++wrong;
                cout << ">Your state:\n";
                hangmandrawing();
            }
        }

        if(wrong == MAX_GUESS)
            cout << "\n>YOU HAVE BEEN HANGED!";
        else
            cout << "\n>You have guessed it. CONGRATULATIONS!\n";

        cout << "\nThe word was: " << THE_WORD << endl;

    }

    friend void reset_global_stuff();
};

void reset_global_stuff()
{
    THE_WORD = "";
    topic = "";
    words.clear();
    m.clear();
    wrong = 0;
}

void play_hangman()
{
    while(1)
    {
        reset_global_stuff();
        hangman ob;
        player p(1);
        hang::introduction();
        p.set_name();
        ob.process_words();
        ob.random_word_generator();
        ob.game();
        cout << p.get_name() << ", do you love to play again?\n";
        cout                 << "\t\t\t\t" << "---------------------" << endl
                             << "\t\t\t\t" << "| 1) Play again     |" << endl
                             << "\t\t\t\t" << "| press) Exit       |" << endl
                             << "\t\t\t\t" << "---------------------" << endl
                             << "\t\t\t\t" << "Selected : ";
        try
        {
            int c;
            getchar();
            cin>>c;
            if (c!=1)
                throw c;
        }
        catch(...)
        {
            cout << "Bye player " << p.get_name() << ". Come back again. Exiting!!!\n\n";
            break;
        }

    }
    system("cls");
    return;
}

#endif // _HANGMAN_H_
