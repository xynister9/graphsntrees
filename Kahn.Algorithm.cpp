
vector<int> adj[MN]; // adjacency list of graph
vector<int> ind(MN); ; // in-degree 

// take input indegree ( ind[b]++ ) 
vector<int> toposort( int n ){

    vector<int> topo;

    priority_queue<int , vector<int> , greater<int> >  pq ;

    for(int i=1; i<=n; i++){
        if( ind[i]==0 ) pq.push(i) ;
    }

    while(!pq.empty()){
        int curr = pq.top() ;
        topo.pb(curr) ;
        pq.pop();

        for(auto child : adj[curr]){
            ind[child]--;

            if(ind[child]==0) pq.push(child) ;
        }
    }

    if(topo.size()<n) topo.clear() ;
    // topo means no toposort - cycle detected 
    
    return topo ;
}
