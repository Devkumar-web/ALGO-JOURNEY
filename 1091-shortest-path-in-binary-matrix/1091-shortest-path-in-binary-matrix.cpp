class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //we can go for bfs as it would always generate shortest path once we reached to bottom-right cell
        int row=grid.size();
        int col=grid[0].size();


        if(grid[0][0]==1 || grid[row-1][col-1]==1){
            return -1;
        }
        int ans=0;

        //-1 , 0 , 1
        //-1 , 0 , 1
        //now we need to 
        queue<pair<int ,pair<int,int> > > q;
        q.push({1,{0,0}});
        grid[0][0]=1;


        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int steps=p.first;
            int i=p.second.first;
            int j=p.second.second;

            if(i==row-1 && j==col-1){
                return steps;
            }

            //now we need to find all its neightbhout
            for(int t=-1;t<=1;t++){
                for(int x=-1;x<=1;x++){
                    int nrow=i+t;
                    int ncol=j+x;

                    //they should be valid
                    if(nrow>=0 && ncol>=0 && nrow<row && ncol<col && grid[nrow][ncol]==0){
                        //now we are eligible
                        grid[nrow][ncol]=1;
                        q.push({steps+1,{nrow,ncol}});

                    }
                }
            }
        }

        return -1;

    }
};