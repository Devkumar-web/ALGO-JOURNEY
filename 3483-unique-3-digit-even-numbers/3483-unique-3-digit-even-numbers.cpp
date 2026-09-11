class Solution {
public:
    bool possible(unordered_map<int,int> mp,int num){

        while(num){
            if(mp[num%10]==0){
                return false;
            }
            mp[num%10]--;
            num=num/10;
        }
        return true;
    }
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> freq;
        for(auto it:digits){
            freq[it]++;
        }
        int count=0;
        for(int i=100;i<999;i+=2){
            if(possible(freq,i)){
                count++;
            }
        }
        return count;
    }
};