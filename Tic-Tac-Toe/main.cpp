#include <iostream>
using namespace std;
#include <ctime>


#include "Field.cpp";
#include "Players.cpp";



int main(){
   
   
   bool fullfield;
   
   
   // User Definition
   cout << "Insert P1 Symbol: ";
   cin >> User.cursor; 
   
   
   //Enemy Definition
   cout << "Insert P2 Symbol: ";
   cin >> Enemy.cursor; 
   
   
   char rematch = 'y';


   while(rematch == 'y' || rematch == 'Y'){
         game.empty();
         srand(time(NULL));
         int who_plays = rand() % 2;

      do {
          User.victory = 0;
          Enemy.victory = 0;
          system  ("cls");
          int column,row;
          
         if(who_plays == 1)  //if = 1 starts the 1st else the 2nd player
         {
            cout << "Player1: " << "'"<<User.cursor << "'" << ": " << User.points << " - Player2: " << "'"<<Enemy.cursor << "'" << ": " << Enemy.points << endl;   
            cout << "Currently Playing: " <<"'" << User.cursor  << "'" << endl;
            game.GameField();
            game.read_coordinates(row,column);



            //Position check
            while (game.field[row][column] == User.cursor || game.field[row][column] == Enemy.cursor || row >= 4 || column >= 4 )
            {
              system  ("cls"); 
              cout << "Position already Occuped Or Non-Existent, Please Reinsert" <<endl;
              cout << "Player1: " << "'"<<User.cursor << "'" << ": " << User.points << " - Player2: " << "'"<<Enemy.cursor << "'" << ": " << Enemy.points << endl;   
              cout << "Currently Playing: " <<"'" << User.cursor  << "'" << endl;
              game.GameField();
              game.read_coordinates(row,column);
            };


            game.field[row][column] = User.cursor;
            User.victory = game.checkVictory(User.cursor); 
            fullfield = game.isFull();
            if(fullfield == true){
               game.empty();
            }




         }
            




         if(User.victory == 0){
            system  ("cls");
            cout << "Player1: " << "'"<<User.cursor << "'" << ": " << User.points << " - Player2: " << "'"<<Enemy.cursor << "'" << ": " << Enemy.points << endl;   
            cout << "Currently Playing: " <<"'" << Enemy.cursor  << "'" << endl;
            game.GameField();
            game.read_coordinates(row,column);
            
            //Position check
            while (game.field[row][column] == User.cursor || game.field[row][column] == Enemy.cursor || row >= 4 || column >= 4 ){
               system  ("cls"); 
               cout << "Player1: " << "'"<<User.cursor << "'" << ": " << User.points << " - Player2: " << "'"<<Enemy.cursor << "'" << ": " << Enemy.points << endl;   
               cout << "Currently Playing: " <<"'" << Enemy.cursor  << "'" << endl;
               cout << "Position already Occuped Or Non Existent - Please Reinsert" <<endl;
               game.GameField();
               game.read_coordinates(row,column);
            }; 


            game.field[row][column] = Enemy.cursor;
            Enemy.victory = game.checkVictory(Enemy.cursor); 
         }
         who_plays = 1;
         

         
         fullfield = game.isFull();
         if(fullfield == true){
            game.empty();
         }

      }while (User.victory == 0 && Enemy.victory == 0);
      system("cls");
      if(User.victory == 1){
         cout << "Player1 won!" << endl;
         User.points++;
      }else if(Enemy.victory == 1){
         cout << "Player2 won!" << endl;
         Enemy.points++;
      }  

      game.GameField();
      cout << "Rematch? (Y/n) " ;
      cin >> rematch;
   }
   
    
}