// COUNT OR FIND BRIDGES IN A GRAPH 

vi adj[MN]; // adjacency list of graph

vector<bool> vis(MN);
vector<int> tin(MN), low(MN);
int timer;

void dfs(int node, int par = -1) {
    vis[node] = 1 ;
    low[node] = tin[node] = timer++;

    for(auto child : adj[node] ) {

        if(child == par ) continue ;

        else if(vis[child]) 
            low[node] = min( low[node] , tin[child] ) ;

        else{
            dfs(child ,node) ;
            if(low[child]>tin[node]){
                // THIS IS A BRIDGE -> DO WHATEVER 
            }
            low[node] = min( low[node] , low[child] ) ;
        }
    }
}
