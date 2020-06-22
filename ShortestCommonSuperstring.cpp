int dist(vector<string> &arr,int last,int ne,vector<vector<int> >&length)
{
    if(last==-1)
    {
        return arr[ne].size();
    }
    if(length[last][ne]!=-1)
    {
        return length[last][ne];
    }
    int i,j;
    for(i=0;i<arr[last].size();i++)
    {
        bool suffix=true;
        for(j=0; j<arr[ne].size() && i+j<arr[last].size();j++)
        {
            if(arr[ne][j]!=arr[last][i+j])
            {
                suffix=false;
                break;
            }
        }
        if(suffix)
        {
            return length[last][ne]=(arr[ne].size())-(arr[last].size()-i);
        }
    }
    return length[last][ne]=arr[ne].size();
}
int recursion(int last,int mask,vector<string> &arr, vector<vector<int> > &dp,int targetMask,vector<vector<int> > &length)
{
    if(mask==targetMask){dp[last+1][mask]=0;return dp[last+1][mask];}
    if(dp[last+1][mask]!=-1)
    {
        return dp[last+1][mask];
    }
    int ans=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        if( ((mask)&(1<<i))==0 )
        {
            ans = min (ans , recursion(i ,mask | (1<<i) ,arr,dp,targetMask,length) + dist(arr,last,i,length));
        }
    }
    return dp[last+1][mask]=ans;
}
int Solution::solve(vector<string> &A) 
{
    int N=A.size();
    if(N==1){return A[0].size();}
    int masks=(1<<N);
    vector< vector<int> > dp (N+2, vector<int> (masks+10 , -1 ) );
    vector< vector<int> > length( N+1 , vector<int> (N+1 , -1 ) );
    int targetMask=masks-1;
    return recursion(-1,0,A,dp,targetMask,length);
}
