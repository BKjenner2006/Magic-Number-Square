/*==========================================================
//---------------Magic Number Square Program---------------
//Programmed By: Britton Kjenner
//Last Modified: 8/5/2013
//Description:  This program discovers all magic number
//squares for the number of tiles in the square the user
//supplies.  It discovers the squares via a brute force
//method.
===========================================================*/
#include <iostream>
#include <math.h>
using namespace std;

void findSquare(int,int,int[]);
void printSquare(int, int[]);
bool searchList(int, int, int[]);
bool checkSquare(int, int[]);

int main(){
    int magicnum[3];
    cout << "This is a program that calculates magic number squares" << endl;
    cout << "Computing..." << endl;
    findSquare(0,9, magicnum);
    return 0;
}

void findSquare(int spot, int size, int square[]){
    int order[size];

    for (int i=0; i < spot; i++){
        order[i] = square[i];
    }

    for (int nums=0; nums < size; nums++){
        if (!searchList(nums+1, size, order)){
            order[spot] = nums+1;
            if (spot+1 != size){
                findSquare(spot+1, size, order);
            }
            if (spot == size-1){
                if(checkSquare(size, order)){
                    printSquare(size, order);
                }
            }
        }
    }
}

bool checkSquare(int size, int square[]){
    int total = 0;
    int diag1 = 0;
    int diag2 = 0;
    int offset, offset2;
    //first compute the constant that will be the result of all lines
    int magicConst = (sqrt(size)*(size+1))/2;
    //check horizontal rows first
    for (int start=0; start < size; start += sqrt(size)){
        for (int spot=0; spot < sqrt(size); spot++){
            total += square[start + spot];
        }
        
        if (total != magicConst){
            return false;
        }else{
            total = 0;
        }
    }
    //proceed to check vertical columns
    for (int start=0; start < sqrt(size); start++){
        for (int spot=0; spot < size; spot += sqrt(size)){
            total += square[start + spot];
        }

        if (total != magicConst){
            return false;
        }else{
            total = 0;
        }
    }
    //finally, check diagonals
    offset = (int)sqrt(size) + 1;
    offset2 = (int)sqrt(size) - 1;

    for (int row=0; row < sqrt(size); row++){
        diag1 += square[0 + (row * offset)];
        diag2 += square[(size-3) - (row * offset2)];
    }
    if (diag1 != magicConst || diag2 != magicConst){
        return false;
    }
    return true;
}

bool searchList(int num, int size,  int list[]){
    bool found = false;
    for (int lcv=0; lcv < size; lcv++){
        if (list[lcv] == num){
            found = true;
            break;
        }
    }
    return found;
}

void printSquare(int size, int square[]){
    int x = (int)sqrt(size);
    for (int row=0; row < sqrt(size); row++){
        for (int col=0; col < sqrt(size); col++){
            cout << square[(x * row) + col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
