class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //now i fucked up
        //now we need to store distance on each cell
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>> effort(row,vector<int>(col,INT_MAX));
        effort[0][0]=0;
        //now we need to take a priority queue
        priority_queue< pair<int,pair<int,int>> , vector<pair<int ,pair<int,int> > > , greater<pair<int,pair<int,int>>> > q;
        q.push({0,{0,0}});

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            //now go for neightbhour
            int crow=q.top().second.first;
            int ccol=q.top().second.second;
            int sofar=q.top().first;

            q.pop();

                     if(crow==row-1 && ccol==col-1){
                        return sofar;
                     }


            for(int i=0;i<4;i++){
                int nrow=crow+delrow[i];
                int ncol=ccol+delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<row && ncol<col){
                    //now we are at valid position
                    int diff=abs(heights[crow][ccol]-heights[nrow][ncol]);

                    diff=max(diff,sofar);

                    //let suppose we faced this effort currently
                    //and we want to minimize overall effort so we should replace it with less value
                    if(diff<effort[nrow][ncol]){
                        q.push({diff,{nrow,ncol}});
                        effort[nrow][ncol]=diff;
                    }
                }
            }

        }


        return effort[row-1][col-1];
    }
};