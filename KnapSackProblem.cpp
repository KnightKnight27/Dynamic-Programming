#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int W,N;
    cin>>W>>N;
    int val[N];
    int wt[N];
    for(int i=0;i<N;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int dp[N+1][W+1];
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    cout<<dp[N][W];
}
