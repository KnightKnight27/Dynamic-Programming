#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL recursion(vector<vector<LL> > &dp,LL start,LL end,vector<LL> &arr)
{
    if(start+1>=end)
        return dp[start][end]= 0;
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    LL Min=INT_MAX;
    for(LL i=start+1;i<=end-1;i++)
    {
        Min=min(Min,arr[start]*arr[i]*arr[end] + recursion(dp,start,i,arr) + recursion(dp,i,end,arr));
    }
    return dp[start][end]=Min;
}
int main()
{
   
    ios_base::sync_with_stdio(false);
    LL T;
    cin>>T;
    while(T--)
    {
        LL N;
        cin>>N;
        vector<LL> arr(N);
        for(auto &it:arr)
        {
            cin>>it;
        }
        vector<vector<LL> > dp(N+1,vector<LL>(N+1,-1));
        cout<<recursion(dp,0,N-1,arr)<<endl;
    }
        
}
