#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision;
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int512_t catlan[n+2];
	    catlan[0]=1;
	    catlan[1]=1;
	    for(int i = 2;i<=n+1;i++)
	    {
	        catlan[i]=0;
	        for(int j=0;j<i;j++)
	        {
	            catlan[i]+=(catlan[j]*catlan[i-j]) ;
	        }
	        
	    }
	    cout << catlan[n+1] << endl;
	    
	}
	return 0;
}
