#include <iostream>
using namespace std;
class Field{
    public:
        char field[3][3] = {
        '.', '.', '.',
        '.', '.', '.',
        '.', '.', '.',
    };
      void read_coordinates(int &row, int &column){  
        cout << "Insert Column: " ;
        cin >> column;
        cout << "Insert Row: " ;
        cin >> row;
        column--;row--;
    };
      //PRINT THE GAME FIELD
      void GameField(){   
        cout << "    [1]   [2]   [3]" << endl;
        for(int x=0;x<3;x++) 
        {
            cout << "["<<x+1<<"]";
            for(int y=0;y<3;y++) 
            {
                cout<< "  " << field[x][y] << "   ";\
            }
        cout<<endl;  
        }
        cout<<endl;  
    }
      bool checkVictory(char cursor){
        if (field[0][0] == cursor){
           if(field[1][0] == cursor){
              if(field[2][0] == cursor){
               return true;
              } 
           }
        }

        if (field[0][1] == cursor){
           if(field[1][1] == cursor){
              if(field[2][1] == cursor){
               return true;
              } 
           }
        }


        if (field[0][2] == cursor){
           if(field[1][2] == cursor){
              if(field[2][2] == cursor){
               return true;
              } 
           }
        }




        if (field[0][0] == cursor){
           if(field[0][1] == cursor){
              if(field[0][2] == cursor){
               return true;
              } 
           }
        }
        if (field[1][0] == cursor){
           if(field[1][1] == cursor){
              if(field[1][2] == cursor){
               return true;
              } 
           }
        }
        if (field[2][0] == cursor){
           if(field[2][1] == cursor){
              if(field[2][2] == cursor){
               return true;
              } 
           }
        }




        if (field[0][0] == cursor){
           if(field[1][1] == cursor){
              if(field[2][2] == cursor){
               return true;
              } 
           }
        }

        if (field[2][0] == cursor){
           if(field[1][1] == cursor){
              if(field[0][2] == cursor){
               return true;
              } 
           }
        }
        return false;
      }
      void empty(){
         for(int x=0;x<3;x++) 
        {
            for(int y=0;y<3;y++) 
            {
               field[x][y] = '.';
            }
        }
      }
      bool isFull(){
         for(int x=0;x<3;x++) 
        {
            for(int y=0;y<3;y++) 
            {
               if(field[x][y] == '.') return false;
            }
        }
        return true;
      }
} game;
