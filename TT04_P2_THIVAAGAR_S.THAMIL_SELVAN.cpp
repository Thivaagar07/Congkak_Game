/**********|**********|**********|
Program: TT04_P2_THIVAAGAR_S.THAMIL_SELVAN.cpp
Course: BACHELOR OF COMPUTER SCIENCE
Year: 2016/17 Trimester 1
Name: THIVAAGAR A/L S.THAMIL SELVAN
ID: 1151101888
Email: thivaagarthamilselvan@gmail.com
Phone: 016-316 4267
**********|**********|**********/

#include <iostream>
#include <cstdlib>  //used of srand()
#include <ctime>    //used for time
#include <iomanip>  //used for board alignment
using namespace std;

/* The program just show the total progress to reduce the screen buffering size.
   If you want see the each seed progress please kindly disable the comment line from line 213 - 215.
   Thank You.
*/

int total, now;
int House[16]; //House[0] is p2 storehouse, House[8] is p1 storehouse
               //House[1]..House[7] for p1 houses, House[9]..House[15] is p2 houses starting from number 1 to number 7
int Store[2];  //Store[0] is player1 storehouse, Store[1] is player 2 storehouse

struct p
{
    string name;
    int score;
};
 struct p game[2];

 void board() //created congkak board for display
 {
      cout << "\n\t\t\t" << game[0].name << "\n" << endl;
      cout << "\t    - 1 - 2 - 3 - 4 - 5 - 6 - 7 - " << endl;
      cout << "\t    -----------------------------" << endl;
      cout << "           " << setw(2) << "|";
      cout << setw(2) << House[1];
      cout << setw(2) << "|";
      cout << setw(2) << House[2];
      cout << setw(2) << "|";
      cout << setw(2) << House[3];
      cout << setw(2) << "|";
      cout << setw(2) << House[4];
      cout << setw(2) << "|";
      cout << setw(2) << House[5];
      cout << setw(2) << "|";
      cout << setw(2) << House[6];
      cout << setw(2) << "|";
      cout << setw(2) << House[7];
      cout << setw(2) << "|" << endl;
      cout << setw(10) << House[0];
      cout << setw(11) << "  -----------------------------";
      cout << setw(3) << House[8] << endl;
      cout << "           " << setw(2) << "|";
      cout << setw(2) << House[15];
      cout << setw(2) << "|";
      cout << setw(2) << House[14];
      cout << setw(2) << "|";
      cout << setw(2) << House[13];
      cout << setw(2) << "|";
      cout << setw(2) << House[12];
      cout << setw(2) << "|";
      cout << setw(2) << House[11];
      cout << setw(2) << "|";
      cout << setw(2) << House[10];
      cout << setw(2) << "|";
      cout << setw(2) << House[9];
      cout << setw(2) << "|" << endl;
      cout << "\t    -----------------------------" << endl;
      cout << "\t    - 7 - 6 - 5 - 4 - 3 - 2 - 1 - " << endl;
      cout << "\n\n\t\t\t" <<game[1].name << endl;
}

 void start()
 {
     game[0].name = "Player 1"; //Player 1
     game[1].name = "Player 2"; //Player 2

     srand(time(NULL));
     now=rand()%2; //choose random Player 1 or Player 2

     cout<<endl;
     House[1]=7;  //House 1 assigned
     House[2]=7;  //House 2 assigned
     House[3]=7;  //House 3 assigned
     House[4]=7;  //House 4 assigned
     House[5]=7;  //House 5 assigned
     House[6]=7;  //House 6 assigned
     House[7]=7;  //House 7 assigned
     House[9]=7;  //House 9 assigned
     House[10]=7; //House 10 assigned
     House[11]=7; //House 11 assigned
     House[12]=7; //House 12 assigned
     House[13]=7; //House 13 assigned
     House[14]=7; //House 14 assigned
     House[15]=7; //House 15 assigned
     total = 98;  //total value assigned

     cout<<endl;
 }

 void end() //Game winning condition
 {
     cout<<endl;
     if(game[1].score>game[0].score) //Player 2 wins if seeds in store house more than Player 1 store house
     {
         cout<<"Winner is "<<game[1].name<<"\n";
         cout<<"Score : "<< game[1].score<<"\n";
     }
     else if (game[1].score<game[0].score) //Player 1 wins if seeds in store house more than Player 2 store house
     {
         cout<<"Winner is "<<game[0].name<<"\n";
         cout<<"Score : "<< game[0].score<<"\n";
     }
     else //If both players store house has the same amount of seed then the game will be tie
    {
        cout <<"Game Tie \n";
        cout<<"Score: "<<game[1].score<<"\n";
    }
 }

 int main()
 {
    cout<<"\n";
    cout<<"\t\t   ==================="<<endl; //Header
    cout<<"\t\t   The Game of Congkak"<<endl;
    cout<<"\t\t   ==================="<<endl;
     start(); //call start function

     while(total>0) //Loop until the total amount of seed becomes zero
     {
         int pick;
         if(House[1]==0 && House[2]==0 && House[3]==0 && House[4]==0 && House[5]==0 && House[6]==0 && House[7]==0)
         {
             now=1;
             cout << "Player 2 plays again" << endl;
         } //Skip turn for Player 1 if all the houses for Player 1 is empty
         else if(House[9]==0 && House[10]==0 && House[11]==0 && House[12]==0 && House[13]==0 && House[14]==0 && House[15]==0)
         {
            now=0;
            cout << "Player 1 plays again" << endl;
         } //Skip turn for Player 2 if all the houses for Player 2 is empty

         board();
         cout<<"\n"<<game[now].name<<"\n";
         cout<<"Please choose your location (1 to 7) => ";
         cin>>pick;

         while (!cin.good() || pick<1 || pick>7 )   //Created a loop for input and error checking
         {
            cin.clear();
            cin.ignore(1000,'\n');
            cout <<"You entered wrong input or empty value!!\n" << endl;
            cout <<game[now].name<<endl;
            cout <<"Please choose your location (1 to 7) => ";
            cin >> pick;
         }

         if(now==0) //now 0 is for the player 1
         {
                 while(House[pick]==0) //House has zero seed
                 {
                     cout << "You cannot select an empty house !!\n" << endl;
                     cout << "Please choose your location (1 to 7) => ";
                     cin >> pick;
                 }
         }

         else if(now==1) //now 1 is for the Player 2
         {
                 while(House[pick+8]==0) //House has zero seed
                 {
                     cout << "You cannot select an empty house !!\n" << endl;
                     cout << "Please choose your location (1 to 7) => ";
                     cin >> pick;
                 }
         }

             cout<<endl;
             if(now==1){ //if Player 2 add 8 into choosen house number
                pick = pick + 8;
             }
             int t=House[pick]; //t will become the choosen house seed number value

             House[pick]=0; //House choosen will become zero

             while (t>0) //loop until number of seed is zero of choosen House
             {
                pick = (pick + 1) % 16;
                if (now == 0 && pick != 0) //run if Player 1 and pick value is not 0
                {
                    t--;           //decrease seed number in choosen House
                    House[pick]++; //add seed except Player 2 storehoue
                }
                if (now == 1 && pick != 8) //run if Player 2 and pick value is not 8
                {
                    t--;           //decrease seed number in choosen House
                    House[pick]++; //add seed except Player 1 storehoue
                }
                if(now !=0 && pick==0) //run if not Player 1's turn and pick is 0
                {
                    game[1].score++; //add score for Player 2
                    total--;         //decrease total value
                }
                if(now !=1 && pick==8) //run if not Player 2's turn and pick is 8
                {
                    game[0].score++; //add score for Player 1
                    total--;         //decrease total value
                }
                //board();
                //cin.get();
                //cin.ignore();
             }

             if(now==0) //run after Player 1's turn
             {
                 now=1; //next turn will be for Player 2
             }
             else if (now==1){ //run after player 2's turn
                now=0; //next turn will be for Player 1
             }
     }
     board(); //call board for display
     end();   //if total is zero run this for show wiining status
     return 0;
 }
