
vi adj[MN]; // adjacency list of graph
int ind[MN] ; // in-degree 

// take input indegree ( ind[b]++ ) 
vi toposort( int n ){

    vi topo;

    priority_queue<int , vi , greater<int> >  pq ;
    for(int i=1; i<=n; i++){
        if(ind[i]==0  ) pq.push(i) ;
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

    if(topo.sz<n){
        topo.clear() ;
    }

    return topo ;
}
