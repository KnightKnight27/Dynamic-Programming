#include <iostream>
using namespace std;
int main() 
{   
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        string A;
        string B;
        cin>>A;
        cin>>B;
        int dp[N+1][M+1];
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(A[i-1]==B[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int max=dp[i][j-1]>dp[i-1][j]?dp[i][j-1]:dp[i-1][j];
                    dp[i][j]=max;
                }
            }
        }
        printf("%d\n",dp[N][M]);
    }
	return 0;
}
