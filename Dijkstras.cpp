//(J) DIJKSTRAS ALGORITHM FOR SHORTEST PATH IN WEIGHTED GRAPH 

vpi adj[MN];
vi dis(MN,imax);
vi par(MN,0);

void dijkstra_bfs( int src ){

    dis[src]=0;

    par[src]=src; // parent array is for retrieval of shortest path
    //imp as most oftenly shortest route is required not only shortest ditance
    
    priority_queue< pi , vector<pi> , greater<pi> > pq;
    pq.push( {0 , src } ) ;

    while( !pq.empty() ){

        int curr_dis = pq.top().fi ;
        int curr_node = pq.top().se ;

        pq.pop();

        if (curr_dis > dis[curr_node])   continue;  // very important unless can give O(n*m) inr worst case

        for(auto child : adj[curr_node] ){
            
            if(curr_dis+child.se < dis[child.fi]){
                dis[child.fi] =  curr_dis+child.se ;
                pq.push({dis[child.fi] , child.fi }) ;
                par[child.fi] = curr_node ;
            }
            
        }
    }
}
