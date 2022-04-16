//(Q) KRUSKALS ALGORITHM FOR MST 

// include dsu 

int spanningTree(int N , vector<vector<int>> edges ){
        
        sort(edges.begin() , edges.end() , [](vector<int> &a , vector<int> &b){ return a[2]<b[2]; } ) ;
        
        DSU mds(N) ;

        int mst = 0 ;
        
        for(auto x : edges ){
            int u = x[0] ; 
            int v = x[1] ;
            int w = x[2] ;
            
            u = mds.find_set(u) ;
            v = mds.find_set(v) ; 
            
            if(u!=v){
                mds.union_sets(u,v) ;
                mst+=w;
            }
        }
        return mst ;
}


// PRIMS - DOES THE SAME - MST 

 int spanningTree(int N, vector<vector<int>> adj[])
    {
        // code here
    
        vector<int> vis(N+1) ;
   
        priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >  pq ;
        pq.push({0,1}) ; // root as you wish
   
        int mst = 0 ;
     
        while(pq.size()){
            int e = pq.top().second ;
            int w = pq.top().first ;
            pq.pop() ;
            
            if(vis[e]) continue ;
            
            vis[e] = 1 ;
            mst+=w ;
            
            for(auto x : adj[e] ) {
                if(!vis[x[0]]){
                    pq.push({x[1] , x[0]}) ;
                }
            }
            
        }
        return mst ;
    }
