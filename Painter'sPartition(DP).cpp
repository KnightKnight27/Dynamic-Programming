#include<bits/stdc++.h>
using namespace std;
const int N=int(1e5+100);
int recursion(int index,int *prefix,int k,vector< vector<int> > &dp)
{
    if (dp[index][k]!=-1)
    {
        return dp[index][k];
    }
    if(index==0)
    {
        return dp[index][k]=prefix[0];
    }
    if(k==1)
    {
        return dp[index][k]=prefix[index];
    }
    int best=INT_MAX;
    for(int i=index;i>=0;i--)
    {
        best=min(best,max(recursion(i,prefix,k-1,dp),prefix[index]-prefix[i]));
    }
    return dp[index][k]=best;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>K>>N;
        int arr[N];
        for(auto &it:arr)
        {
            cin>>it;
        }
        int prefix[N];
        prefix[0]=arr[0];
        for(int i=1;i<N;i++)
        {
            prefix[i]=prefix[i-1]+arr[i];
        }
        vector<vector<int> > dp(N+1,vector<int>(K+1,-1));
        cout<<recursion(N-1,prefix,K,dp)<<endl;

    }
}
