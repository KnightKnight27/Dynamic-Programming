#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<vector<int>  > arr(N,vector<int>(N));
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>arr[i][j];
        int ans=INT_MIN;
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(j==0)
                {
                    arr[i][j]+=max(arr[i-1][j+1],arr[i-1][j]);
                }
                else if(j==N-1)
                {
                    arr[i][j]+=max(arr[i-1][j-1],arr[i-1][j]);
                }
                else
                {
                    arr[i][j]+=max(arr[i-1][j-1],max(arr[i-1][j],arr[i-1][j+1]));
                }
                ans=max(ans,arr[i][j]);
            }
        }
        cout<<ans<<endl;
        
    }
}
