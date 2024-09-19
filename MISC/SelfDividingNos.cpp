#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Self dividing numbers: no. that is divisible buy its own digits and must not have a 0 (728 LC)
// $ TC: O() | SC: O()
class Solution {
    public:
    vi selfDividingNumbers(int left, int right){
        vi ans;
        for(int i = left; i <= right; i++){
            int temp = i;
            bool flag = false;
            while(temp > 0){
                int dig = temp % 10;
                if(dig != 0 && i % dig == 0) flag = true;
                else{
                    flag = false;
                    break;
                }
                temp /= 10;
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution ob1;
    int left = 1, right = 35;

    vi result = ob1.selfDividingNumbers(left, right);
    cout << "Self-dividing numbers between " << left << " and " << right << " are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

}