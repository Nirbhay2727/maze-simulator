#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>

int coin_map[38][70];

using namespace std;

int main(){

    int map[38][70]={
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,5,5,5,1,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,19,19,19,19,0,1,0,0,20,20,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,5,5,5,1,5,5,5,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,19,19,19,19,0,1,0,0,20,20,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,5,5,5,1,5,5,5,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,19,19,19,19,0,1,0,0,20,20,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,5,5,5,1,5,5,5,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,1,0,0,0,1,1,0,0,0,0,0,21,21,21,21,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,1,4,4,4,4,1,4,4,4,0,0,0,0,1,13,13,13,13,13,13,13,13,13,13,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,21,21,21,21,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,1,4,4,4,4,1,4,4,4,2,2,2,0,1,13,13,13,13,13,13,13,13,13,13,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,6,6,1,0,0,0,0,0,0,0,0,1,0,21,21,21,21,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,2,2,2,0,1,13,13,13,13,13,13,13,13,13,13,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,6,6,1,7,7,7,14,14,14,14,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,2,2,2,0,1,13,13,13,13,13,13,13,13,13,13,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,7,7,7,14,14,14,14,1,1,1,1,1,1,1,1,1,6,6,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,13,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,18,18,18,18,0,1,7,7,7,14,14,14,14,0,1,0,0,0,0,0,0,1,6,6,0,0,0,0,0,0,0,0,1,0,0,0,0,7,7,7,1,26,26,26,26,26,26,0,1,25,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,18,18,18,18,0,1,0,0,0,14,14,14,14,0,1,0,0,0,0,0,0,1,0,0,0,0,0,15,15,15,15,0,1,10,10,10,10,7,7,7,1,26,26,26,26,26,26,0,1,25,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,18,18,18,18,0,1,0,0,0,14,14,14,14,0,1,0,22,22,22,22,0,1,0,0,0,0,0,15,15,15,15,0,1,10,10,10,10,7,7,7,1,26,26,26,26,26,26,0,1,25,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,1,0,0,0,14,14,14,14,0,1,0,22,22,22,22,0,1,7,7,7,0,0,15,15,15,15,0,1,10,10,10,10,7,7,7,1,26,26,26,26,26,26,0,1,25,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,1,0,0,0,14,14,14,14,0,1,0,22,22,22,22,0,1,7,7,7,0,0,15,15,15,15,0,1,10,10,10,10,7,7,7,1,26,26,26,26,26,26,0,1,25,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,0,0,0,14,14,14,14,0,1,0,0,1,1,0,0,1,7,7,7,0,0,15,15,15,15,0,1,0,1,0,0,7,7,7,1,26,26,26,26,26,26,0,1,25,25,25,25,25,25,25,25,25,25,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,8,8,8,8,8,8,8,8,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0},
    {0,0,17,17,17,17,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,8,8,8,8,8,8,8,8,0,1,1,0,0,0,0,0,1,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0},
    {0,0,17,17,17,17,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,8,8,8,8,8,8,8,8,0,1,1,0,0,0,0,0,1,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0},
    {0,0,17,17,17,17,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,8,8,8,8,8,8,8,8,0,1,1,0,0,0,0,0,1,1,24,24,24,24,0,0,0,0,23,23,23,23,0,0},
    {0,0,0,1,1,0,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,8,8,8,8,8,8,8,8,0,1,1,6,6,0,0,0,1,0,0,0,0,0,0,0,0,0,23,23,23,23,0,0},
    {0,0,0,1,1,0,0,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,0,1,1,6,6,0,0,0,1,0,0,0,0,0,0,0,0,0,23,23,23,23,0,0},
    {0,0,0,1,1,1,1,1,13,13,13,13,13,13,13,13,13,13,13,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,6,6,1,13,13,13,13,13,13,13,13,13,13,13,1,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,1,0,0,12,12,12,12,12,12,12,12,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,12,12,12,12,12,12,12,12,0,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0},
    {0,0,16,16,16,16,0,1,0,0,12,12,12,12,12,12,12,12,0,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0},
    {0,0,16,16,16,16,0,1,0,0,12,12,12,12,12,12,12,12,0,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,16,16,16,16,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,1,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    ofstream fout;
    fout.open("roadMap.txt");
    string s="{\n";

    for(int i=0;i<38;i++){
        for(int j=0;j<70;j++){
            if(map[i][j]==1){
                s+="\t{"+to_string(i)+","+to_string(j)+"},\n";
            }
        }
    }
    s+="}";

    fout << s;
    return 0;
}