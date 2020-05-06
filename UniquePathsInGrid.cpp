int Solution::uniquePathsWithObstacles(vector<vector<int> > &arr) 
{
    int N=arr.size();
    int M=arr[0].size();
    vector<vector<int> > dp(N+1,vector<int>(M+1));
    if(arr[0][0]==0)
    {
        dp[0][0]=1;
    }
    for(int i=1;i<N;i++)
    {
        if(arr[i][0]==0)
        dp[i][0]=dp[i-1][0];
    }
    for(int j=1;j<M;j++)
    {
        if(arr[0][j]==0)
        dp[0][j]=dp[0][j-1];
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
            if(arr[i][j]==0)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[N-1][M-1];
}
