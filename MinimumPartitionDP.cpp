#include<bits/stdc++.h>
using namespace std;
int MinPartition(vector<int> arr,int N,int Sum)
{
	int dp[N+1][Sum+1];
	for(int i=0;i<=N;i++)
	{
		dp[i][0]=true;
	}
	for(int j=1;j<=Sum;j++)
	{
		dp[0][j]=false;
	}
// 	dp[0][arr[0]]=true;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=Sum;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(arr[i-1]<=j)
			{
				dp[i][j]|=dp[i-1][j-arr[i-1]];
			}
		}
	}
	for(int j=Sum/2;j>=0;j--)
	{
		if(dp[N][j]==true)
			return Sum-2*j;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); 
	    cin.tie(NULL); 
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
	int N;
	cin>>N;
	vector<int> arr(N,0);
	int Sum=0;
	for(auto &it:arr)
	{	
		cin>>it;
		Sum+=it;
	}
	cout<<MinPartition(arr,N,Sum)<<endl;
    }
}
