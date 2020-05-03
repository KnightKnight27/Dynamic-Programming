#include <bits/stdc++.h>
using namespace std;
int solution(int n,int x,int y, int z, int *dp){
    if(dp[n]==-1)
    {
        if(n==0)
        {
            dp[n]=0;
            return 0;
        }
        int ans = INT_MIN;
        if(n-x>=0){
            ans = max(ans,solution(n-x,x,y,z,dp)+1);
        }
        if(n-y>=0){
            ans = max(ans,solution(n-y,x,y,z,dp)+1);
        }
        if(n-z>=0){
            ans = max(ans,solution(n-z,x,y,z,dp)+1);
        }
        return dp[n]=ans;
    }
    return dp[n];
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n,x,y,z;
	    cin>>n>>x>>y>>z;
	    int *dp = new int[100000];
    	for(int i=0;i<=n;i++) dp[i]=-1;
    	cout<<solution(n,x,y,z,dp)<<endl;
	}
	return 0;
}
