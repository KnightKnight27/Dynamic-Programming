#include <iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    string S;cin>>S;
	    vector<vector<int> > dp(N+1,vector<int>(N+1,0));
	    for(int i=1;i<=N;i++)
	    {
	        for(int j=1;j<=N;j++)
	        {
	            if(S[i-1]==S[j-1] and i!=j)
	            {
	                dp[i][j]=dp[i-1][j-1]+1;
	            }
	            else
	            {
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    cout<<dp[N][N]<<endl;
	}
	return 0;
}
