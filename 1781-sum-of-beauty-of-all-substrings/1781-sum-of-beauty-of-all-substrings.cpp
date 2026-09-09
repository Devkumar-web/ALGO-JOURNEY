class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            int freq[26]={0};
        for(int j=i;j<n;j++){
                
                freq[s[j]-'a']++;

                long long maxi=INT_MIN;
                long long mini=INT_MAX;
                
                for(auto it:freq){
                    if(it==0) continue;
                     maxi=max(maxi,(long long)it);
                     mini=min(mini,(long long)it);
                }

                sum+=(maxi-mini);
            }
        }

        return sum;
    }
};