#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &dp,int start,int end,int * arr)
    {
        if(start==end)
        {
            return 0;
        }
        if(start>end or arr[start]==0)
        {
            return INT_MAX;
        }
        if(dp[start]!=0)
        {
            return dp[start];
        }
        int ans=INT_MAX;
        for(int i=start+1;i<=start+arr[start];i++)
        {
            int cost=helper(dp,i,end,arr);
            if(cost!=INT_MAX)
            {
                ans=min(ans,cost+1);
            }
        }
        return dp[start]=ans;
    }
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int arr[N];
        for(auto &it:arr)
        {
            cin>>it;
        }
        vector<int> dp(N,0);
        int x=helper(dp,0,N-1,arr);
        if(x==INT_MAX)
        cout<<-1<<endl;
        else
        cout<<x<<endl;
        
    }
	return 0;
}
