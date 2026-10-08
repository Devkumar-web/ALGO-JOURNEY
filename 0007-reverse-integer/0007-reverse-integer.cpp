#include<limits.h>
class Solution {
public:
    int reverse(int x) {
        int new_num=0;
        if(x<=INT_MIN){
            return 0;
        }
        while(x){
            if(new_num>INT_MAX/10){
                return 0;
            }
            if(new_num<INT_MIN/10){
                return 0;
            }
            int last_digit=x%10;
            x=x/10;
            new_num=new_num*10+last_digit;
        }

        return new_num;
        
    }
};