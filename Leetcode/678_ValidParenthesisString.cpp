# include<iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for (char i : s){
            if( i == '(') min++, max++;
            else if (i == ')'){
                if (min -1 >= 0) min--;
                max--;
            }
            else{
                if (min -1 >= 0) min--;
                max++;
            }
            cout << min << ' ' << max << '\n';
            if ( max < 0) return false;
            
        }
        if (min == 0 || max == 0) return true;
        return false;
    }
};