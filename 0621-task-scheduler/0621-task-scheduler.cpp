class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //lets go how to solve this problem
            unordered_map<char,int> mp;
            for(auto it:tasks){
                mp[it]++;
            }
            priority_queue<pair<int,char> , vector<pair<int,char>> , greater<pair<int,char> >> cooldown;
            priority_queue<pair<int,char> > pq;

            for(auto it:mp){
                pq.push({it.second,it.first});
            }
            //now we need to focus on currtime
            int currtime=0;
            while(!pq.empty() || !cooldown.empty()){
                if(pq.size()>0){
                         pair<int,char> p=pq.top();
                         pq.pop();
                         currtime++;
                    mp[p.second]--;
                    if(mp[p.second]>0){
                    //pq.push({currtime+n,p.second});
                    //here it should go for cooldown
                    cooldown.push({currtime+n,p.second});
                        }
                }
                else{
                    //main stack is empty
                    //if there is any cooldown
                    if(!cooldown.empty()){
                        //means we have to take minimum
                        currtime=cooldown.top().first;
                        pq.push({mp[cooldown.top().second],cooldown.top().second});
                        cooldown.pop();
                    }

                }

                if(!cooldown.empty() && currtime>=cooldown.top().first){
                    pq.push({mp[cooldown.top().second],cooldown.top().second});
                    cooldown.pop();
                }

            }

            return  currtime;
    }
};