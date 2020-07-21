class Solution {
public:
    unordered_map< string,vector<string> >  dp;
    vector<string> solve(string S,unordered_set<string> &words)
    {
        int N=S.size();
        vector<string> send;
        if(S.size()==0)
        {
            vector<string> send{""};
            return send;
        }
        if(dp.find(S)!=dp.end())
        {
            return dp[S];
        }
        string curr="";
        for(int i=0;i<N;i++)
        {
            curr+=S[i];
            if(words.find(curr)!=words.end())
            {
                vector<string> aagese=solve(S.substr(i+1), words);
                if(aagese.size())
                {
                    for(auto x:aagese)
                    {
                        string temp=curr;
                        if(i!=N-1)
                        temp+=" "+x;
                        send.push_back(temp);
                    }
                }
            }
        }
        return dp[S]=send;
        
    }
    vector<string> wordBreak(string s, vector<string>& w) 
    {
        unordered_set<string> words(w.begin(),w.end());
        return solve(s,words);
    }
};
