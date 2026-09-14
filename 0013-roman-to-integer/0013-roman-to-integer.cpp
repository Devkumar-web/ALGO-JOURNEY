class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int total=0;
        int last=0;
        for(auto it:s){
            if(last<mp[it]){
                total-=last;
                total+=mp[it]-last;
                last=mp[it];
            }
            else{
                total+=mp[it];
                last=mp[it];
            }
        }

        return total;
    }
};