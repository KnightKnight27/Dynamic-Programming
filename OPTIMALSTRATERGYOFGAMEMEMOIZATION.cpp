#include <bits/stdc++.h>
using namespace std;
int ans(int i,int j,vector< vector<int> >& dp,vector<int> &arr)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return arr[i];
    }
    if(i==j-1)
    {
        return max(arr[i],arr[i+1]);
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int a= arr[i] + min(ans(i+2,j,dp,arr),ans(i+1,j-1,dp,arr));
    int b= arr[j] + min(ans(i+1,j-1,dp,arr),ans(i,j-2,dp,arr));
    return dp[i][j]=max(a,b) ;
}
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(auto &it:arr)
        {
            cin>>it;
        }
        vector< vector< int > > dp (N , vector<int> (N,-1) );
        int n=ans(0,N-1,dp,arr);
        cout<<n<<endl;
    }
}
