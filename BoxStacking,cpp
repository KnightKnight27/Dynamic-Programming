#include<bits/stdc++.h>
using namespace std;
int max(int A,int B)
{
	return A>B?A:B;
}
int min(int A,int B)
{
	return A<B?A:B;
}
struct Box
{
	int L;
	int B;
	int H;
};
int comparator(const void *A,const void *B)
{
	return (*(Box *)B).B * (*(Box *)B).L - (*(Box *)A).B * (*(Box *)A).L; 
}
int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	int FLAG=1;
	while(FLAG==1)
	{
		int N;
		cin>>N;
		if(N==0)
		{
			FLAG=0;
			break;
		}
		Box Boxes[3*N];
		int count=0;
		for(int i=0;i<N;i++)
		{
			int A,B,C;
			cin>>A>>B>>C;
			Boxes[count].H=A;
			Boxes[count].B=max(B,C);
			Boxes[count].L=min(B,C);
			count++;
			Boxes[count].H=B;
			Boxes[count].B=max(A,C);
			Boxes[count].L=min(A,C);
			count++;
			Boxes[count].H=C;
			Boxes[count].B=max(A,B);
			Boxes[count].L=min(A,B);
			count++;
		}
		qsort(Boxes,3*N,sizeof(Box),comparator);
		int dp[3*N];
		for(int i=0;i<3*N;i++)
		{
			dp[i]=Boxes[i].H;
		}
		for(int i=0;i<3*N;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(Boxes[i].B < Boxes[j].B && Boxes[i].L < Boxes[j].L && dp[i]<dp[j]+Boxes[i].H)
				{
					dp[i]=dp[j]+Boxes[i].H;
				}
			}
		}
		int Ans=INT_MIN;
		for(int i=0;i<3*N;i++)
		{
			if(dp[i]>Ans)
				Ans=dp[i];
		}
		cout<<Ans<<endl;
	}
}


	
