#include <bits/stdc++.h>
#include<iostream>
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
	    sort(arr,arr+N);
    	for(auto &it:arr)
    	{
    	    cin>>it;
    	}
	    int M;
	    cin>>M;
	    int dp[M+1]={0};
	    dp[0]=1;
	    for(int i=0;i<N;i++)
	    {
	        for(int j=1;j<=M;j++)
	        {
	            if(arr[i]<=j)
	            {
	                dp[j]+=dp[j-arr[i]];
	            }
	        }
	    }
	    cout<<dp[M]<<endl;
    }
}
