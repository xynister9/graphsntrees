// BELLMAN FORD FOR SHORTEST PATH WITH NEGATIVE CYCLE 
// CAN ALSO DETECT NEGATIVE CYCLE - if runs for nth time then negative cycle present 

vector <int> bellman_ford(int N, int src ,  vector<vector<int>> &edges) {
        // Code here
        vector<int> dis(N+1,1e8) ;
        dis[src] = 0 ;

        for(int i = 0 ; i<V-1; i++ ){
            int ct = 0 ;
            for(int j = 0 ; j<edges.size() ;j++){
                if( dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]] ){
                    dis[edges[j][1]] = dis[edges[j][0]] + edges[j][2] ; 
                    ct++ ;
                }
            }
            if(ct==0) break;
        }
  
        // run again to check for cycle 

        return dis ;
}
