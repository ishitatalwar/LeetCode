class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l <= r){
            int m = l + (r - l) / 2;
            long long square = (long long) m*m;
            if(square == x){
                return m;
            }
            else if(square < x){
                l = m +1;
            }
            else{
                r = m - 1;
            }
        }
        return r;
        
    }
};