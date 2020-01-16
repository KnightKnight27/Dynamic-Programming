#include<bits/stdc++.h>
using namespace std;
int max(int A,int B)
{
	return A>B?A:B;
}
int LIS(int *arr ,int i,int prev,int N)
{
	if(i==N)
		return 0;
	int exclude=LIS(arr,i+1,prev,N);
	int include=0;
	if(arr[i]>prev)
	{
		include=1+LIS(arr,i+1,arr[i],N);
	}
	return max(include,exclude);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); 
	  cin.tie(NULL); 
	int N;
	cin>>N;
	int arr[N];
	for(auto &it:arr)
	{
		cin>>it;
	}
	printf("%d",LIS(arr,0,INT_MIN,N));
}
