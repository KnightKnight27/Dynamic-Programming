#include <bits/stdc++.h>
// #include<iomaniap>
#include<vector>
using namespace std;

int main() 
{
	int T;
	cin>>T;
	while(T--)
	{
	    long double K,x,y;
	    cin>>K>>x>>y;
	    vector<vector<long double > > dp(1001,vector<long double>(1001,0));
	    dp[1][1]=K;
	    for(int i=1;i<=x;i++)
	    {
	        for(int j=1;j<=i;j++)
	        {
	            if(dp[i][j]>1)
	            {
	                long double diff=dp[i][j]-1;
	                dp[i][j]=1;
	                dp[i+1][j]+=diff/2;
	                dp[i+1][j+1]+=diff/2;
	            }
	        }
	    }
	    cout<<fixed<<setprecision(6)<<dp[x][y]<<endl;
	}
	return 0;
}
