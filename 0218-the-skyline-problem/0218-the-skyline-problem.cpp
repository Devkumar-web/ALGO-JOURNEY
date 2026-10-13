class segment{
    public:
        //lets see what we can do for this 
        int size=1;
        vector<int> tree;
        segment(int n){
            while(size<n){
                size*=2;
            }
            tree.resize(2*size,0);
        }

        //lets build  the
        //no need to build
        //just update with flow
        //lets see what we can do to solve this 
        void update(int l,int r,int start,int end,int node,int value){
            if(l>end || r<start){
                return ;
            }

            if(l<=start && r>=end){
                //lets see what we can do to solve this 
                tree[node]=max(tree[node],value);

                return ;
            }

            int mid=start+(end-start)/2;

            update(l,r,start,mid,node*2+1,value);
            update(l,r,mid+1,end,node*2+2,value);

            return ;
        } 

        int value(int start,int end,int node,int index){
            if(start==end){
                return tree[node];
            }
            int mid=start+(end-start)/2;
            //lets see what we can do 
            int child;
            if(index<=mid){
                child=value(start,mid,node*2+1,index);
            }
            else{
                child=value(mid+1,end,node*2+2,index);
            }

            return max(child,tree[node]);
        }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //let's collect all points
        vector<int> points;
        int n=buildings.size();
        for(int i=0;i<n;i++){
            //let's see what we can do for this 
            //first and second are the points
            points.push_back(buildings[i][0]);
            points.push_back(buildings[i][1]);
        }
        //sort(points.begin(),points.end());
        sort(points.begin(),points.end());

        points.erase(unique(points.begin(),points.end()),points.end());
        int actualsize=points.size();

        //we also need to find lower_bound and upper_bound
        //lets form a segment tree
        segment st(actualsize);
        //now we from are segment tree for actual size
        for(auto b:buildings){
            //b store left right height
            int left=b[0];
            int right=b[1];
            int height=b[2];
            int l=lower_bound(points.begin(),points.end(),left)-points.begin();
            int r=lower_bound(points.begin(),points.end(),right)-points.begin()-1;
            st.update(l,r,0,actualsize-1,0,height);
        }
        //new we need to take output of answer
        int last=st.value(0,actualsize-1,0,0);
        vector<vector<int>> result;
        result.push_back({points[0],last});
        //now i need to go through all remaining
        for(int i=1;i<actualsize;i++){
            int curr=st.value(0,actualsize-1,0,i);
            if(curr!=last){
                //then only we need to push
                result.push_back({points[i],curr});
            }
            last=curr;
        }

        return result;

    }
};