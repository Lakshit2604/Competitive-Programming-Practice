# include <iostream>
using namespace std;

class Solution {
public:
    void solve(int n , stack <char> st, string s, vector<string> &ans){
        char arr[] = {'(', ')'};
        for (int i = 0; i < 2; i++){
            if (i == 0) {
                if ( n != 0 ){
                    st.push(arr[i]);
                    s.push_back(arr[i]);
                    solve(n-1, st, s, ans);
                    st.pop();
                    s.pop_back();
                }
            }
            else{
                if (st.empty()){
                    if ( n == 0 ) ans.push_back(s);
                    continue;
                }
                st.pop();
                s.push_back(arr[i]);
                solve(n, st, s, ans);
                st.push('(');
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> st;
        string s;
        solve(n,st, s, ans );
        return ans;
    }
};