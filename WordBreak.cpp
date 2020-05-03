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
	    vector<string> arr(N);
	    for(auto &it:arr)
	    {
	        cin>>it;
	    }
	   string x;
	   cin>>x;
	   vector<bool> dp(x.size()+1,false);dp[0]=true;
	   for(int i=1;i<=x.size();i++)
	   {
	       for(auto it:arr)
	       {
	           int index=i-it.size();
	           if(index<0 or dp[index]==false)continue;
	           if(it==x.substr(index,it.size()))
	           {
	               dp[i]=true;
	               break;
	           }
	       }
	   }
	   cout<<dp[x.size()]<<endl;
	}
	return 0;
}
