#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int helper(int start,int end,string &S)
{
    if(start>end)
    return 0;
    if(start==end)
    {
        return dp[start][end]=1;
    }
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    if(S[start]==S[end])
    {
        return dp[start][end]=2+helper(start+1,end-1,S);
    }
    else
    {
        return dp[start][end]=max(helper(start+1,end,S),helper(start,end-1,S));
    }
}
int main() 
{
	int T;
	cin>>T;
	while(T--)
	{
	    string S;
	    cin>>S;
	    int N=S.size();
	    memset(dp,-1,sizeof(dp));
	    cout<<helper(0,N-1,S)<<endl;
	}
}
