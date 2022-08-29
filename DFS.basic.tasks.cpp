//(D) SINGLE SOURCE SHORTEST PATH FOR TREES 
vector<int> adj[MN];
bool vis[MN] ;
int dist[MN];
void dfs( int node , int d){
    vis[node]=1;
    dist[node]=d;
    //cout<<v<<"->";
    for( auto child : adj[node]){
        if( vis[child]==0)
            dfs( child , dist[node]+1);
    }
}//  CALL : dfs (node,0); where node is node number 


//(E) BIPARTITE GRAPH TEST

bool col[MN];

bool dfs ( int node, bool c){
    vis[node] =1;
    col[node] = c;
    
    for( auto child : adj[node]){
        if(vis[child]==0){
            if( dfs(child , c^1)==false) 
                return false ;
        }
        else{
            if(col[child]==col[node])
                return false ;
        }
    }
    return true;
} // CALL : dfs( node. , colour);

//(F) CYCLE DETECTION

bool dfs ( int node, int parent){
    vis[node] =1;
    
    for( auto child : adj[node]){
        if(vis[child]==0){
            if( dfs(child , node)==true) 
                return true ;
        }
        else{
            if(child != parent)
                return true ;
        }
    }
    return false;
} // returns true if cycle exists 


//(G) IN OUT TIME

int intime[MN];
int outime[MN];
int timer = 1;

void dfs(int node){
    vis[node] = 1;
    intime[node] = timer++;

    for( auto child : adj[node]){
        if( vis[child] == 0)
            dfs(child);
    }
    outime[node]=timer++;
}
