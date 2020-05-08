class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int N=s.size();
        if(N==0)
        {
            return 0;
        }
        if(N==1)
        {
            return 1;
        }
        vector<vector<int> > dp(N+1,vector<int>(N+1,0));
        for(int i=0;i<N;i++)
        {
            dp[i][i]=1;
        }
        for(int gap=1;gap<N;gap++)
        {
            for(int i=0,j=gap;j<N;i++,j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
};
