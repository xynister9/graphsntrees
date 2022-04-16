//  LOWEST COMMON ANCESTER 

const int M=1e5+1;
const int MX = 21 ;

vi  adj[MN] ;
int level [MN] ;
int par[MN][MX+1] ;

void dfs (int node , int parent , int lvl  ){
    level[node] = lvl ;
    par[node][0] = parent; 

    for(auto child : adj[node]){
        if(child!=parent){
            dfs(child , node , lvl+1) ; 
        }
    }
}

void dfs_for_lca(int n ){

    dfs(1,-1,0) ;

    for(int i=1;i<=MX;i++){
        for(int j=1;j<=n;j++){
            if(par[j][i-1] != -1){
                par[j][i] = par[ par[j][i-1] ][i-1];
            }
        }
    }
}

int lca (int a, int b ){
    
    if(level[a] > level[b] ) swap(a,b) ;

    int d = level[b] - level[a] ;

    while(d>0){
        int i = log2(d) ;
        b = par[b][i] ;
        d-= (1<<i) ;
    }

    if(a==b) return a ;

    for(int i = MX ; i>=0 ;i--){

        if(par[a][i]!=1 and (par[a][i] != par[b][i]) )
            a=par[a][i] , b=par[b][i] ;
    }
    return par[a][0] ; 
} // reset adj and  dp with -1 
