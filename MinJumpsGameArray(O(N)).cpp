class Solution {
public:
    
    int jump(vector<int>& arr) 
    {
        int N=arr.size();
        int jumps=1;
        int left=arr[0];
        int maxii=arr[0];
        if(N==1)
        {
            return 0;
        }
        for(int i=1;i<N;i++)
        {
            if(i==N-1)
            {
                return jumps;
            }
            if(i>maxii)
            {
                return -1;
            }
            left--;
            maxii=max(maxii,arr[i]+i);
            if(left==0)
            {
                jumps++;
                left=maxii-i;
            }
        }
        return jumps;
    }
};
