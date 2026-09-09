class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                long long maxi=INT_MIN;
                long long mini=INT_MAX;
                
                for(auto it:mp){
                     maxi=max(maxi,(long long)it.second);
                     mini=min(mini,(long long)it.second);
                }

                sum+=(maxi-mini);
            }
        }

        return sum;
    }
};