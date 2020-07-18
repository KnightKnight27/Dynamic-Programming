class Solution {
public:
    bool recursion(string &s,string &p,int i,int j,  unordered_map<string, bool> &dp)
    {
        string key=to_string(i) + '|' + to_string(j);
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        if(j==p.size())
        {
            return dp[key]= i==s.size();
        }
        if(i==s.size())
        {
            for(int k=j;k<p.size();k++)
            {
                if(p[k]!='*')
                {
                    return dp[key]= false;
                }
            }
            return dp[key]=true;
        }
        if(s[i] == p[j] or p[j]=='?')
        {
            return dp[key]=recursion(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*')
        {
            return dp[key]= recursion(s,p,i+1,j,dp) || recursion(s,p,i,j+1,dp);
        }
        return dp[key]=false;
    }
    bool isMatch(string s, string p) 
    {
        int i=0;
        int j=0;
        unordered_map<string, bool> dp; 
        return recursion(s,p,i,j,dp);
    }
};
