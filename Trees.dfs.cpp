//(A) INPUT ADJACENCY LIST
    for( int i=1; i<=n ;i++) adj[i].clear() , vis[i]=0 ;

    for(int i=0 ;i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b) , adj[b].push_back(a);
    }

//(B) DFS 
vector<int> adj[MN];
bool vis[MN] ;

void dfs( int node ){
    vis[node]=1;
    //cout<<v<<"->";
    for( auto child : adj[node]){
        if( vis[child]==0)
            dfs( child);
    }
}   


//(C) COUNT COMPONENTS
    int count=0;
    for( int i=1; i<=n; i++){
        if( vis[i]!=1){
            count++;
            dfs(i);
        }
    }
