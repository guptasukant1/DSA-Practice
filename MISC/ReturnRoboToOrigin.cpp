#include<bits/stdc++.h>
using namespace std;

// $ Return Robot To Origin: Check if the robot after a seq of moves "U", "D", "R", "L" returns back to origin i.e. (0, 0)

class Solution{
    public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'R') x--;
            else if(moves[i] == 'L') x++;
            else if(moves[i] == 'U') y++;
            else y--;
        }
        if(x == 0 && y == 0) return true;
        return false;
    }
};