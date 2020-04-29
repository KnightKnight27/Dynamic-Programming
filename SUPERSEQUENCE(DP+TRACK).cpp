string shortestCommonSupersequence(string A, string B) 
    {
        int N=A.size();
        int M=B.size();
        int dp[N+1][M+1];
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(A[i-1]==B[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=N;
        int j=M;
        string res="";
        while(i>0 and j>0)
        {
            if(A[i-1]==B[j-1])
            {
                res.push_back(A[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    res.push_back(A[i-1]);
                    i--;
                }
                else
                {
                    res.push_back(B[j-1]);
                    j--;
                    
                }
            }
        }
        while(i>0)
        {
            res.push_back(A[i-1]);
            i--;
        }
        while(j>0)
        {
            res.push_back(B[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
