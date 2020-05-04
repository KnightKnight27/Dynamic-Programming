class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int size=triangle.size();
        int N=triangle[size-1].size();
        int dp[N+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            dp[i]=triangle[size-1][i];
        }
        for(int i=size-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};
