//  FLOYS WARSHAL for all pairs shortest path      - N*N*N 
//                            while DIJKSTRAS         - N*N*logN

const int inf = 1e15 ;

vvi dp( MN , vi( MN, inf ) ) ;

void all_pair_shortes_path( vpi adj[] , int n ){

        for(int i = 1 ; i<=n; i++ ){
                dp[i][i] = 0 ;
                for(auto j : adj[i] ){
                        dp[i][j.fi] = j.se ;
                }
        }

        for (int k = 1; k <= n; ++k) {
                for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= n; ++j) {

                                // for negative weights include this line 
                                if(dp[i][k]!=inf and dp[j][k]!=inf) 
                                      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
                          
                        }
                }
        }
}
