class Solution {
public:
    int numDistinct(string S, string T)
    {
        long int N=S.size();
        long int M=T.size();
        vector<vector<long int> > dp(M+1,vector<long int>(N+1));
        for(int i=1;i<=M;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=N;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(S[j-1]==T[i-1])
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[M][N];
        
    }
};
