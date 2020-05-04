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
        int sum=0;
        for(auto &it:arr)
        {
            cin>>it;
        }
        int dp[N+1]={0};
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<N;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        cout<<dp[N-1]<<endl;
    }
	return 0;
}
