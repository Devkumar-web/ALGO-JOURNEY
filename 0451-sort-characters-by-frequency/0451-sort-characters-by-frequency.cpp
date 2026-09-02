class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char> > pq;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            //now we need to get pair 
            char ch=it.first;
            int freq=it.second;

            pq.push({freq,ch});
        }

        //now we have ready priority queue
        //we can now extract every element
        string result;
        while(!pq.empty()){
            pair<int,char> p=pq.top();
            pq.pop();
            result+=string(p.first,p.second);
        }
        return result;
    }
};