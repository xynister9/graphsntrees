// DSU 

struct DSU {
    vector<int> parent;
    vector<int> size;

    void make_set (int v) {
        parent[v] = v;
        size[v] = 1;
    }

    DSU(int N){
        parent.assign(N+1,0);
        size.assign(N+1,0);

        for(int i=1; i<=N; i++)
                make_set(i) ;
    }

    int find_set (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set (parent[v]);
    }

    void union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (size[a] < size[b])
                swap (a, b);

            parent[b] = a;
            size[a]+=size[b] ;
        }
    }

    int size_of(int node){
        return size[find_set(node)] ;
    }
};
