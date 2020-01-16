#include<bits/stdc++.h>
using namespace std;
int Max(int A,int B)
{
	return A>B?A:B;
}
int Min(int A,int B)
{
	return A<B?A:B;
}
int MiniumumPartition(vector<int> arr,int N,int SumTotal,int SumCalculated)
{
	if(N==0)
		return abs(SumTotal-(SumCalculated)-SumCalculated);
	int included=MiniumumPartition(arr,N-1,SumTotal,SumCalculated+arr[N]);
	int excluded=MiniumumPartition(arr,N-1,SumTotal,SumCalculated);
	return Min(included,excluded);
}
int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N;
	cin>>N;
	vector<int> arr(N);
	int SumTotal=0;
	for(auto &it:arr)
	{
		cin>>it;
		SumTotal+=it;
	}
	cout<<MiniumumPartition(arr,N-1,SumTotal,0);
	
}
