# include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack <pair<char, int>> st;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            if ( s[i] == '(') st.push({s[i],i});
            else{
                if (st.empty()) st.push({s[i],i});
                else if (st.top().first == '(') {
                    st.pop();
                    int top = (!st.empty()) ? st.top().second : -1;
                    ans = max(ans, i - top);
                }
                else st.push({s[i],i});
            }
        }
        return ans;
    }
};