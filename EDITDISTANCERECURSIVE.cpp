#include<bits/stdc++.h>
using namespace std;
int Min(int A,int B)
{
	return A<B?A:B;
}
int RECUSIVEEDITDISTANCE(string A,string B,int m,int n)
{
	if (m==0)
		return n;
	if (n==0)
		return m;
	if(A[m]==B[n])
		return RECUSIVEEDITDISTANCE(A,B,m-1,n-1);
	return 1+(Min(Min(RECUSIVEEDITDISTANCE(A,B,m-1,n-1),RECUSIVEEDITDISTANCE(A,B,m-1,n)),RECUSIVEEDITDISTANCE(A,B,m,n-1)));

}
int main()
{       
	
	
	Kunal is A BAD BOIII !
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string A;
	string B;
	cin>>A;
	cin>>B;
	int m=A.size();
	int n=B.size();
	cout<<RECUSIVEEDITDISTANCE(A,B,m-1,n-1);
}
