class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long k = n-1;
        //we need to make non-set bits of last = k-1
        for(int i=0, j = 0; i<63; i++){
            if ((x & (1LL << i)) == 0){
                if (k & (1LL << j)) ans |= (1LL << i);
                j++;
            }
        }
        return ans;
    }
};