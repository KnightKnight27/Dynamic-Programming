class Solution {
public:
    struct Trie
    {
        unordered_map<char,Trie *> children;
        bool ok;
        Trie()
        {
            ok=false;
        }
    }*root;
    void insert(string &S)
    {
        Trie *curr=root;
        for(int i=0;i<S.size();i++)
        {
            if(curr->children.find(S[i]) == curr->children.end())
            {
                curr->children[S[i]]=new Trie;
            }
            curr=curr->children[S[i]];
        }
        curr->ok=true;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        root=new Trie;
        for(auto it:wordDict)
        {
            insert(it);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        int N=s.size();
        for(int i=0;i<N;i++)
        {
            if(dp[i]==true)
            {
                Trie *curr=root;
                for(int j=i;j<N;j++)
                {
                    if(curr==NULL)
                    {
                        break;
                    }
                    curr=curr->children[s[j]];
                    if(curr!=NULL and curr->ok==true)
                    {
                        dp[j+1]=true;
                    }
                }
            }
        }
        return dp[N];
    }
};
