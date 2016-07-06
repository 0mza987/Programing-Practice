//https://leetcode.com/problems/longest-valid-parentheses/

// One dimensional Dynamic Programing
// The code might be able to be simplified a bit, but that may reduce its readability.

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),res=0;
        if(n<2) return res;
        vector<int> dp(n,0);
        for(int i=1; i<n; ++i){
            int j=i-1;
            if(dp[j]){
                int k=j-dp[j];
                if(k>=0){
                    if(s[k]=='(' && s[i]==')'){
                        dp[i]=dp[j]+2;
                        if(k>0 && dp[k-1]){
                            dp[i] += dp[k-1];
                        }
                    }
                }
            }
            else{
                if(s[j]=='(' && s[i]==')'){
                    dp[i]=2;
                    if(j>0 && dp[j-1]){
                        dp[i] += dp[j-1];
                    }
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};

// Two dimensional Dynamic Programing.
// Initially I used 2D dp, but this method will exceed memory limit on LeetCode. 

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),res=0;
        if(n<2) return res;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-2; i>=0; --i){
            for(int j=i+1; j<n; ++j){
                if((i+1>j-1 || dp[i+1][j-1]) && (s[i]=='(' && s[j]==')')){
                    dp[i][j]=1;
                    for(int k=j+2; k<n; ++k){
                        if(dp[j+1][k]) dp[i][k]=1;
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(dp[i][j]) res=max(res,abs(i-j)+1);
            }
        }
        return res;
    }
};