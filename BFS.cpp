
//(H) BFS FOR SSSP ON GRAPHS (CYCLE CONTAINING)

vector<int> adj[MN];
bool vis[MN] ;
int dist[MN];

void bfs ( int src ){
    queue <int > qu;
    qu.push(src);
    vis[src] = 1 ,  dist[src]=0;

    while( !qu.empty())
    {
        int curr = qu.front() ;
        qu.pop();
        for( auto child : adj[curr]){
            if(vis[child]==0){
                vis[child] = 1;
                dist[child] = dist[curr]+1 ;
                qu.push(child);
            }
        }
    }
}

