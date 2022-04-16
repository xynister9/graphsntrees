//( KOSA RAJUS ALGORITHM 

int const MN = 1e5+1;

vi adj[MN] , tadj[MN] ;
bool vis[MN] ;
vi order , scc ; 

void dfs1( int node ){
    vis[node] = 1 ;
    for(auto child : adj[node] ){
        if(vis[child]==0)
            dfs1(child) ;
    }
    order.pb(node) ;
}  // order  = reverse toposort


void dfs2 ( int node ){
    vis[node] = 1 ;
    scc.pb(node) ;
    for(auto child : tadj[node] ){
        if(vis[child]==0)
            dfs2(child) ;
    }
}

void solve(int tc){
    
        int n , m , a , b ;
        cin >> n >> m ;

        rep(i,0,m){
            cin >> a >> b ;
            adj[a].pb(b);
            tadj[b].pb(a);
        }

        for(int i=1; i<=n; i++){
            if(vis[i]==0)
                dfs1(i);
        }

        for(int i=1; i<=n; i++) vis[i] = 0 ;

        reverse(all(order));

        for(auto & x : order ){
            if(vis[x]==0){
                dfs2(x);
                // scc is strongly connected component ;
                // do the fuck wanna do 
                scc.clear();
            }
        }

        
}
