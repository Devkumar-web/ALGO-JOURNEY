class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
    int i=0;
    int j=0;
    for(;i<n;i++){
        if(s[i]=='*'){
            j--;
        }
        else{
            s[j++]=s[i];
        }
    }

    return s.substr(0,j);
    }
};