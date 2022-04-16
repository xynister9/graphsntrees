// COUNTING ARTICULATION POINTS 

const int N = 1e5+1 ; // number of nodes
vi adj[MN]; // adjacency list of graph

vector<bool> vis(MN);
vector<int> tin(MN), low(MN);
int timer;

set<int> cutver ;

void dfs(int node , int par = -1) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    int children=0;

    for (int child : adj[node]) {
        if (child == par) continue;
        if (vis[child]) {
            low[node] = min(low[node], tin[child]);
        } 
        else {
            children++;
            dfs(child, node);
            if (low[child] >= tin[node] && par!=-1){
                cutver.insert(node);
            }
            low[node] = min(low[node], low[child]);
        }
    }
    if(par == -1 && children > 1)
        cutver.insert(node);
}

void find_cutpoints(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs (i);
    }
}
