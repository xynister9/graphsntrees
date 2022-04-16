//(O) CENTROID FIND ALGIRITHM

set<int> adj[MN] ;
vi subtree(MN) ;

int predfs(int node , int par ){
        subtree[node] = 1 ;
        for(auto child : adj[node] ){
                if(child==par)continue ;
                subtree[node] += predfs(child , node ) ;
        }
        return subtree[node] ;
} // call at root 

int dfs_centroid(int node , int par , int size ){

        for(auto child : adj[node] ){
                if(child==par)continue ;
                if(subtree[child]>size/2){
                        return dfs_centroid(child , node , size );
                }
        }
        return node ;
} // call at root with size 
