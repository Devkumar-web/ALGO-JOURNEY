class Solution {
public:
int bfs(vector<vector<int>> &edges,int n){
    //now we got edges
    //u->v
    vector<vector<int>> adj(n);

    vector<int> indegree(n,0);
    queue<int> q;

    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
        //u->v
    }

    //now i need to traverse from all indegree
    vector<int> topo;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){

            q.push(i);
        }
    }


    while(!q.empty()){
        int node=q.front();
        topo.push_back(node);
        q.pop();

        for(int adjnode:adj[node]){
            indegree[adjnode]--;
            if(indegree[adjnode]==0){
                q.push(adjnode);
            }
        }

    }

    return topo.size();
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //now we need to find whether we can find or not
        //lets go with bfs
        //khan's algorithm
        if(numCourses !=bfs(prerequisites,numCourses)){
            return false;
        }

        return true;
    }
};