class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        //lets write bfs()
        queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
        
       
       int srcR;
       int srcC;
        //i->j->mask->e->steps
        int row=classroom.size();
        int col=classroom[0].size();

        vector<vector<int>> lid(row,vector<int>(col,-1));


        int delrow[]={0,1,0,-1};
        int delcol[]={-1,0,1,0};


        int cnt=0;

        //now we need to work on this 
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(classroom[i][j]=='L'){
                    lid[i][j]=cnt++;
                }
                else if(classroom[i][j]=='S'){
                        srcR=i;
                        srcC=j;
                }
            }
        }


        int targetmask=(1<<cnt)-1;


        vector<vector<vector<int>>> bestenergy(row,vector<vector<int>>(col,vector<int>((1<<cnt),-1)));

        q.push({{srcR,srcC},{{0,energy},0}});
        bestenergy[srcR][srcC][0]=energy;
        while(!q.empty()){
            auto detail=q.front();
            q.pop();
            int i=detail.first.first;
            int j=detail.first.second;

            //store mask
            int mask=detail.second.first.first;

            int e=detail.second.first.second;

            int steps=detail.second.second;

            if(mask==targetmask){
                return steps;
            }
            if(e==0){

             if(classroom[i][j]=='R'){
                //now i need to check energy
                //we have to check for the same mask
                if(bestenergy[i][j][mask]<energy){
                    q.push({{i,j},{{mask,energy},steps}});
                    bestenergy[i][j][mask]=energy;
                }
             }


                continue ;
            }

            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];

                int ncol=j+delcol[k];

                if(nrow>=0 && ncol>=0 && nrow<row && ncol<col && classroom[nrow][ncol]!='X'){
                    //now we got valid neighbhour
                    //now we need to check whether 
                    //visited[nrow][ncol]=1;
                    int newmask=mask;

                    if(classroom[nrow][ncol]=='L'){
                        int id=lid[nrow][ncol];
                        newmask |= (1<<id);
                         if(e-1 > bestenergy[nrow][ncol][newmask]){

                            bestenergy[nrow][ncol][newmask]=e-1;
                             q.push({{nrow,ncol},{{newmask,e-1},steps+1}});    
                        }
                    }
                    else if(classroom[nrow][ncol]=='R'){
                        if(energy>bestenergy[nrow][ncol][mask]){
                            bestenergy[nrow][ncol][mask]=energy;
                             q.push({{nrow,ncol},{{newmask,energy},steps+1}}); 
                        }
                    }
                    else{
                        if(e-1<=bestenergy[nrow][ncol][mask]){
                            continue ;
                        }
                        else{
                            bestenergy[nrow][ncol][mask]=e-1;
                             q.push({{nrow,ncol},{{mask,e-1},steps+1}});
                        }
                       
                    }
                }
            }



        }

        return -1;



    }
};