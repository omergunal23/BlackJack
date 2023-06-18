#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int chard_generator_player()
{
    int chard0;
    srand(time(0));
    chard0 = rand()%10+1;
    return chard0;
}
int chard_generator_bob()
{
    int chard1;
    chard1 = rand()%10+1;
    return chard1;
}
/* restart, cls !!! */
/* do the project again object oriented  (less than 0.001 probability)      */
int main()
{
 int money_in_pocket = 0;
 int player_deck = 0, bob_deck = 0;
 int chard_number_player = 0, chard_number_bob = 0;
 char play ;
 char decision;

 cout << "                                Welcome to B&J Game!                              " << endl;
 Sleep(1000);
 cout << "If you are above 21, equal or below Bob : Bob(cashier) wins 100$, otherwise you win 200$ - Less than 5 chard "<< endl;
 Sleep(3000);

 cout << "Enter 'p' to play: ";
 cin  >> play;
 while (play == 'p'){

   system("cls");

    for (int i=0; i<2; i++)
    {
        player_deck = player_deck + chard_generator_player();
        bob_deck    = bob_deck    + chard_generator_bob();
        chard_number_player ++;
        chard_number_bob    ++;
    }
   cout << "From the opening 2 cards"  << endl;
   cout << "You have: " << player_deck << endl;
   cout << "Bob have: " << bob_deck    << endl;

   cout << "Do you want to hit('h') or stand('s')?" << endl;
   cout << "-> ";
   cin  >> decision;

    while (decision == 'h') // normally you hit max 3 times
    {
        chard_number_player ++;
        player_deck = player_deck + chard_generator_player();
        cout << "You have: " << player_deck << endl;
        cout << "Bob have: " << bob_deck    << endl;
        if (player_deck > 21)
        {
            cout << "Bob wins!" << endl;
            money_in_pocket = money_in_pocket - 100;
            cout << "Money in pocket : " << money_in_pocket << endl;
                        goto restart;
        }
        else if (chard_number_player == 5 || player_deck == 21)
        {
            cout << "You win!" << endl;
            money_in_pocket = money_in_pocket + 200;
            cout << "Money in pocket : " << money_in_pocket << endl;
                        goto restart;
        }
            cout << "Do you want to hit('h') or stand('s')?" << endl;
            cout << "-> ";
            cin  >> decision;
    }

            cout << endl << "You have: " << player_deck << endl;
            cout << "Bob have: " << bob_deck    << endl << endl;

    while (decision == 's')
    {
        if (bob_deck <= player_deck)
        {
            Sleep(2000);
            bob_deck = bob_deck + chard_generator_bob();
            cout << "You have: " << player_deck << endl;
            cout << "Bob have: " << bob_deck    << endl;
        }
        else if (bob_deck > player_deck && bob_deck < 21)
        {
            cout << "Bob wins!" << endl;
            money_in_pocket = money_in_pocket - 100;
            cout << "Money in pocket : " << money_in_pocket << endl;
                       goto restart;
        }
        else if (bob_deck > 21)
        {
            cout << "You win!" << endl;
            money_in_pocket = money_in_pocket + 200;
            cout << "Money in pocket : " << money_in_pocket << endl;
                        goto restart;
        }
        else if (bob_deck == 21)
        {
            cout << "Bob wins!" << endl;
            money_in_pocket = money_in_pocket - 100;
            cout << "Money in pocket : " << money_in_pocket << endl;
                       goto restart;
        }
    }

    restart:
        player_deck = 0;
        bob_deck    = 0;
        chard_number_player = 0;
        chard_number_bob    = 0;

   cout << "Enter 'p' for play to earn (more), enter anything except 'p' to exit: ";
   cin  >> play;

 }

 cout << "Game is over!"<< endl << "Better luck next time.." << endl << endl ;


return 0;
}
