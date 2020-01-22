#include<bits/stdc++.h>
using namespace std;
int Max(int A,int B)
{
	return A>B?A:B;
}
int EggPuzzleDP(int N,int K)
{
	int dp[N+1][K+1];
	for(int i=0;i<=K;i++)
	{
		dp[1][i]=i;
	}
	for(int i=1;i<=N;i++)
	{
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=2;j<=K;j++)
		{
			int Min=INT_MAX;
			for(int x=1;x<=j;x++)
			{
				int res=1+Max(dp[i-1][x-1],dp[i][j-x]);
				if (res<Min)
					Min=res;
			}
			dp[i][j]=Min;
		}
	}
	return dp[N][K];
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
	int N,K;
	cin>>N>>K;
	cout<<EggPuzzleDP(N,K)<<endl;
    }
}
