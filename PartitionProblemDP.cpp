#include<bits/stdc++.h>
using namespace std;
int main()
{
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
        if(Sum%2!=0)
        {
            printf("NO\n");
        }
        else
        {
            bool dp[N+1][Sum+1];
            for(int i=0;i<=N;i++)
            {
                dp[i][0]=true;
            }
            for(int i=1;i<=Sum;i++)
            {
                dp[0][i]=false;
            }
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
            if(dp[N][Sum/2]==true)
            printf("YES\n");
            else
            printf("NO\n");
        }
        
    }
}
