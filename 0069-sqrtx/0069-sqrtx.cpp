class Solution {
public:
    long mySqrt(long x) {
        long l=0;
        long r=x;
        while(l<=r){
            long mid=(l+r)/2;
            if((mid*mid)==x){
                return mid;
            }
            else if((mid*mid)>x){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l-1;
    }
};