class segment{
    public:
     int size=1;
     vector<int> treeleft;
     vector<int> treeright;

     segment(int n){
        while(size<n){
            size*=2;
        }
        treeleft.resize(2*size,0);
        treeright.resize(2*size,0);
     }
     void buildright(int index,int node,int start,int end){
        if(start==end){
            treeright[node]+=1;
            return ;

        }
        //now we need to think of something else
        int mid=start+(end-start)/2;

        if(index<=mid){
            buildright(index,node*2,start,mid);
        }

        else{
            buildright(index,node*2+1,mid+1,end);
        }

        treeright[node]=treeright[node*2]+treeright[node*2+1];

        return ;
     }


     void updateleft(int index,int node,int start,int end){
        if(start==end){
            treeleft[node]+=1;
            return ;
        }
        int mid=start+(end-start)/2;

        if(index<=mid){
            updateleft(index,node*2,start,mid);
        }
        else{
            updateleft(index,node*2+1,mid+1,end);
        }

        treeleft[node]=treeleft[node*2]+treeleft[node*2+1];

        return ;
     }


     void updateright(int index,int node,int start,int end){
        if(start==end){
            if(treeright[node]>0)
            treeright[node]-=1;
            return ;
        }

        int mid=start+(end-start)/2;

        if(index<=mid){
            updateright(index,node*2,start,mid);
        }
        else{
            updateright(index,node*2+1,mid+1,end);
        }

        treeright[node]=treeright[node*2]+treeright[node*2+1];

        return ;
        

     }

     int total_left(int l,int r,int node,int start,int end){
        if(l>end || r<start){
            return 0;
        }
        if(l<=start && r>=end){
            return treeleft[node];
        }
        int mid=start+(end-start)/2;

        int left=total_left(l,r,node*2,start,mid);

        int right=total_left(l,r,node*2+1,mid+1,end);


        return left+right;

     }

     int total_right(int l,int r,int node,int start,int end){
        if(l>end || r<start){
            return 0;
        }
        if(l<=start && r>=end){
            return treeright[node];
        }

        int mid=start+(end-start)/2;
         
         int left=total_right(l,r,node*2,start,mid);

         int right=total_right(l,r,node*2+1,mid+1,end);

         return left+right;
        
     }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int maximum=*max_element(rating.begin(),rating.end());
        //now we got maximum
        int n=rating.size();
        int result=0;
        segment st(maximum);
       for(int i=0;i<n;i++){
        //now we need to think of something that we can work
        st.buildright(rating[i],1,1,maximum);

       }
        for(int i=0;i<n;i++){
            int curr=rating[i];
            int leftless=st.total_left(1,curr-1,1,1,maximum);
            int leftgreator=st.total_left(curr+1,maximum,1,1,maximum);
            int rightless=st.total_right(1,curr-1,1,1,maximum);
            int rightgreator=st.total_right(curr+1,maximum,1,1,maximum);

            result+=(leftless*rightgreator)+(leftgreator*rightless);
            st.updateleft(curr,1,1,maximum);
            st.updateright(curr,1,1,maximum);
        }

        return result;
    }

};