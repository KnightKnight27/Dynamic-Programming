class Solution {
public:
    int ans(vector<vector<int> > &dp,int start,int end,string &s)
    {
        if(start>=end)
        {
            return 0;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        if(s[start]==s[end])
        {
            return dp[start][end]=ans(dp,start+1,end-1,s);
        }
        return dp[start][end]=1+min(ans(dp,start+1,end,s),ans(dp,start,end-1,s));
    }
    int minInsertions(string s) 
    {
        int N=s.size();
        vector< vector<int> > dp(N,vector<int>(N,-1));
        return ans(dp,0,N-1,s);
    }
};
