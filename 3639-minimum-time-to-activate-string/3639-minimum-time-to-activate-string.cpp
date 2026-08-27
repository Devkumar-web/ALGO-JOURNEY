class Solution {
public: bool ispossible(int size,vector<int>&order,int k,int timelimit,long long total){
    vector<bool> demo(size,true);
    long long count=0;
    long long invalid=0;
    for(int i=0;i<=timelimit;i++){
        demo[order[i]]=false;
    }

    for(auto it:demo){
        if(it==false){
            count>0 ? invalid+=count*(count+1)/2:count=0;
            count=0;
        }
        else{
            count++;
        }
    }
     count>0 ? invalid+=count*(count+1)/2:count=0;

    //so after coming out of loop let suppose count is greater than count


    return (total - invalid )>=k;


}
    int minTime(string s, vector<int>& order, int k) {
        //time would increase one by one
        //so if given time 't' then till t index in order would give me index to replace all *
        //is there any way i can count all subarray containig atleast one aestrick
        //a particular aestrick gonna play it's role till next aestrick encounterd
        //now evalute how many subarray is possible 
        int size=s.size();
        long long total=(long long)size*(size+1)/2;
        int ans=-1;
            int lo=0;
        int high=order.size()-1;
        while(lo<=high){
            int mid=(lo+high)/2;
            if(ispossible(size,order,k,mid,total)){
                ans=mid;
                high=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
    
    return ans;
    }


};