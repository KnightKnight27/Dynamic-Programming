#include<bits/stdc++.h>
using namespace std;
int Min(int A,int B)
{
	return A<B?A:B;
}
int EDITDISTANCE(string A,string B,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if (A[i-1]==B[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+Min(Min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}
	return dp[m][n];

}
int main()
{
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
    int m,n;
    cin>>m>>n;
	string A;
	string B;
	cin>>A;
	cin>>B;
	
	cout<<EDITDISTANCE(A,B,m,n)<<endl;
    }
}
