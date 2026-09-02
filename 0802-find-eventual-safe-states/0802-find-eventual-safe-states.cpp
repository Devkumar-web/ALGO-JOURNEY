class Solution {
public:
    
bool dfs(vector<vector<int>> &graph,vector<int> &visited,vector<int> &pathvisited,int node,vector<int> &check){
    visited[node]=1;
    pathvisited[node]=1;
    //check[node]=0;

    for(auto it:graph[node]){

        if(!visited[it]){

            if(dfs(graph,visited,pathvisited,it,check)){
                    //from this -> cycle is reachable 
                    check[node]=0;
                    return true;

            }


        }

        else if(pathvisited[it]==1){
            //that's mean we encountered cycle 
            //we should come back without making backtrack
            //check[node]=0;
            return true;
        }


    }

    //check[node]=1;
    pathvisited[node]=0;

    return false;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        //we are doing with bfs
        int v=graph.size();
        //now we need to work on adjacency list
        vector<int> check(v,0);

        vector<int> visited(v,0);

        vector<int> pathvisited(v,0);


        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(graph,visited,pathvisited,i,check);
            }
        }

        

        vector<int> result;



        for(int i=0;i<v;i++){

            if(pathvisited[i]==0){
                result.push_back(i);
            }

        }

        sort(result.begin(),result.end());

        return result;


    }
};