#include<bits/stdc++.h>
using namespace std;
int max(int A,int B)
{
	return A>B?A:B;
}
int main()
{

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
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
	int dp[N];
	memset(dp,-1,sizeof(dp));
	for(int it=0;it<N;it++)
	{
		dp[it]=-dp[it];
	}
	int max=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
	}
	for(auto it:dp)
	{
		if(it>max)
			max=it;
	}
	cout<<max<<endl;
}
}
