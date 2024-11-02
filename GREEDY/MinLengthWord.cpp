#include<bits/stdc++.h>
using namespace std;

// $ Minimum length word (IBM QUESTION PRAC)[CHECK OBSIDIAN FOR PS]

int findMinMoves(string &word){
    if(word == "") return -1;
    int moves = 0;
    unordered_map<char, int> mpp;
    for(int i = 0; i < word.size(); i++){
        mpp[word[i]]++;
    }
    for(auto it: mpp){
        if(it.second > 1) moves += (it.second) / 2;
    }
    return moves;
}

int main(){
    string word = "baabacaa";
    int res = findMinMoves(word);
    cout << res << endl;
}