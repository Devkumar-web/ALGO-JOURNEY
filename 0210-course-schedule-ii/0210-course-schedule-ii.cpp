class Solution {
public:
int bfs(vector<vector<int>> &edges,int n,vector<int> &topo){
    //now we got edges
    //u->v
    vector<vector<int>> adj(n);

    vector<int> indegree(n,0);
    queue<int> q;

    for(auto it:edges){
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
        //u->v
    }

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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        if(numCourses != bfs(prerequisites,numCourses,topo)){
            return {};
        }

        return topo;
    }
};