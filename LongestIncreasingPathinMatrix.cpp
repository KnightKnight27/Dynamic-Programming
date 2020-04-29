#include <bits/stdc++.h>
using namespace std;
int helper(int i,int j,int N,vector<vector<int> >& dp,vector<vector<int> > &arr)
{
    if(i<0 or j<0 or i>=N or j>=N)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int a=INT_MIN;
    int b=INT_MIN;
    int c=INT_MIN;
    int d=INT_MIN;
    if(i+1<N and arr[i+1][j]==arr[i][j]+1)
    {
        a=1+helper(i+1,j,N,dp,arr);
    }
    if(j+1<N and arr[i][j+1]==arr[i][j]+1)
    {
        b=1+helper(i,j+1,N,dp,arr);
    }
    if(i-1>=0 and arr[i-1][j]==arr[i][j]+1)
    {
        c=1+helper(i-1,j,N,dp,arr);
    }
    if(j-1>=0 and arr[i][j-1]==arr[i][j]+1)
    {
        d=1+helper(i,j-1,N,dp,arr);
    }
    return dp[i][j]=max(a,max(b,max(c,max(d,1))));
}
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<vector<int>  > arr(N,vector<int>(N));
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>arr[i][j];
        vector<vector<int> > dp(N,vector<int> (N,-1));
        int ans=INT_MIN;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(dp[i][j]==-1)
                helper(i,j,N,dp,arr);
                ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
        
    }
}
