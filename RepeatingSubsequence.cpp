int Solution::anytwo(string A)
{
    map<char,int> Hash;
    for(int i=0;i<A.size();i++)
    {
        Hash[A[i]]+=1;
    }
    string S="";
    for(int i=0;i<A.size();i++)
    {
        if(Hash[A[i]]>1)
        {
            S+=A[i];
        }
        if(Hash[A[i]]>=3)
        {
            return 1;
        }
    }
    string T=S;
    reverse(S.begin(),S.end());
    if(T==S)
    return 0;
    return 1;
}
