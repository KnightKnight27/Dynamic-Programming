#include <iostream>
using namespace std;

int main() 
{
    int T;
    cin>>T; 
    while(T--)
    {
        string S;
        cin>>S;
        int N=S.size();
        int dp[N][N]={0};
        for(int k=1;k<N;k++)
        {
            for(int i=0,j=k;j<N;j++,i++)
            {
                if(S[i]==S[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[0][N-1]<<endl;
    }
	return 0;
}
