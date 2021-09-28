const int N = 4e5 + 10;

int parent[N];
int sizee[N];
int total;

int find_set(int x){
    if (parent[x] == x) return x;
    parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    total--;
    if (sizee[x] > sizee[y]) swap(x,y);
    parent[x] = y;
    if (sizee[x] == sizee[y]) sizee[y]++;
}

void initialize(int n){
    FOR(i,0,n+1){
        parent[i] = i;
        sizee[i] = 1;
    }
    total = n;
}
