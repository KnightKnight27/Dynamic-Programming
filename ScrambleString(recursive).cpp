class Solution {
public:
    bool isScramble(string s1, string s2)
    {
        if(s1==s2)
        {    return true; }
        string x=s1;
        string y=s2;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x!=y){return false;}
        int N=s1.size();
        for(int i=1;i<N;i++)
        {
            if( isScramble(s1.substr(0,i) , s2.substr( 0,i ) ) && isScramble(s1.substr(i) , s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i),s2.substr(N-i)) && isScramble(s1.substr(i,N-i),s2.substr(0,N-i)))
                return true;
            
        }
        return false;
    }
};
