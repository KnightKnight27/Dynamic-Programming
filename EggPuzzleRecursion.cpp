#include<bits/stdc++.h>
using namespace std;
int Max(int A,int B)
{
	return A>B?A:B;
}
int EggPuzzleRecursion(int N,int K)
{
	if(K==1 or K==0)
		return K;
	if(N==1)
		return K;
	int Min=INT_MAX;
	int res;
	for(int i=1;i<=K;i++)
	{
		res=Max(EggPuzzleRecursion(N-1,i-1),EggPuzzleRecursion(N,K-i));
		if (res<Min)
			Min=res;
	}
	return Min+1;
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N,K;
	cin>>N>>K;
	cout<<EggPuzzleRecursion(N,K);
}
