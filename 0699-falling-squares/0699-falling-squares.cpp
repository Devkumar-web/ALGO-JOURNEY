class segment{
    public:
    int size;
    vector<int> tree;
    vector<int> lazy;
    segment(int n){
        size=1;
        while(size<n){
            size*=2;
        }

        tree.resize(2*size,0);
        lazy.resize(2*size,0);
    }

    void update(int start,int end,int node,int value,int l,int r){
        if(l>end || r<start){
            return ;
        }
        //non we need to resolve if any current lazy propogation is left
        if(lazy[node]!=0){

            tree[node]=lazy[node];

            if(start!=end){

            lazy[node*2+1]=lazy[node];
            lazy[node*2+2]=lazy[node];
            }
            lazy[node]=0;
        }


        if(l<=start && r>=end){
            tree[node]=value;
            if(start!=end){
                lazy[node*2+1]=value;
                lazy[node*2+2]=value;
            }
            return ;
        }
        int mid=start+(end-start)/2;
        update(start,mid,node*2+1,value,l,r);
        update(mid+1,end,node*2+2,value,l,r);
        tree[node]=max(tree[node*2+1],tree[node*2+2]);
        return ;
    }

    int maximum(int start,int end,int node,int l,int r){
                if(l>end || r<start){
                    return 0;
                }

                if(lazy[node]!=0){
                    tree[node]=lazy[node];
                    if(start!=end){
                        lazy[node*2+1]=lazy[node];
                        lazy[node*2+2]=lazy[node];
                    }
                }
              if(l<=start && r>=end){
                return tree[node];
              }  

              int mid=start+(end-start)/2;

              int left=maximum(start,mid,node*2+1,l,r);
              int right=maximum(mid+1,end,node*2+2,l,r);

              return max(left,right);


    }
};
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
      vector<int> demo;
      unordered_map<int,int> mp;
      for(auto it:positions){
            int x=it[0];
            int size=it[1];
            demo.push_back(x);
            demo.push_back(x+size);
      }
      sort(demo.begin(),demo.end());
      //now lets see how we can solve this problem
      demo.erase(unique(demo.begin(),demo.end()) , demo.end());
      int index=0;
        for(int i=0;i<demo.size();i++){
            mp[demo[i]]=i;
        }

        segment st(demo.size());


        vector<int> results;
        int n=demo.size();
        int ans=0;
        for(auto it:positions){
            int left=it[0];
            int side=it[1];
            int right=left+side;

            int l=mp[left];
            int r=mp[right];

            int base=st.maximum(0,n-1,0,l,r-1);

            int newheight=base+side;

            st.update(0,n-1,0,newheight,l,r-1);
            ans=max(ans,newheight);
            results.push_back(ans);

        }
        return results;
    }
};