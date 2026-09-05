class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }

        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ')
        i++;

        if(i==n){
            return 0;
        }

            int sign=1;
            if(s[i]=='-'){
                sign=-1;
                i++;
            }
            else if(s[i]=='+'){
                sign=1;
                i++;
            }
            long long res=0;
            while(i<n && isdigit(s[i])){
                res*=10;
                res+=s[i]-'0';

                if(res*sign <= INT_MIN){
                    return INT_MIN;
                }
                if(res*sign >= INT_MAX){
                    return INT_MAX;
                }

                i++;
            }

            return res*sign;
    }
};