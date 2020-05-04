#include <iostream>
using namespace std;
int main() 
{
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
        int dp[N+1];
        for(int i=0;i<N;i++)
        {
            dp[i]=arr[i];
        }
        int ans=0;
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    dp[i]=max(dp[i],dp[j]+arr[i]);
                }
                ans=max(ans,dp[i]);
            }
        }
        ans=max(ans,dp[0]);
        cout<<ans<<endl;
    }
	return 0;
}
