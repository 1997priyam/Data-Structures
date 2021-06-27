// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    vector<string> ans;
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int x=n;
        solve(x, x, x*2, "");
        return ans;
    }
    void solve(int open, int close, int max, string str) {
        if(str.length() == max) {
            ans.push_back(str);
            return;
        }
        
        if(open>0) solve(open-1, close, max, str+'(');
        if(open<close && close>0) solve(open, close-1, max, str+')');
    }
    
};