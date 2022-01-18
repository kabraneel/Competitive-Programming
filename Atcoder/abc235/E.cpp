// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define int long long
#ifndef ONLINE_JUDGE
#define LOCAL
#include "/home/kabraneel/coding/debug.h"
#else
#define debug(x...)
#define debugln(x...)
#endif

#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;



const int N = 4e5 + 10;

// 0 -> cost
// 1 -> u
// 2 -> v
// 3 -> true if G, else false
// 4 -> 
vector<vector<int>> edges;


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

void solve(){
    initialize(N-1);
    int n,m,q; cin>>n>>m>>q;

    for(int i = 0; i<m; i++){
        vector<int> temp(5);
        cin>>temp[1]>>temp[2];
        cin>>temp[0];
        temp[3] = 1;
        edges.PB(temp);
    }

    int count = m;

    int q1 = q;
    while(q1--){

        vector<int> temp(5);
        cin>>temp[1]>>temp[2];
        cin>>temp[0];
        temp[3] = 0;
        temp[4] = count - m;
        count++;
        edges.PB(temp);
    }

    sort(all(edges));

    debug(edges);
    vector<int> ans(q);
    for(int i = 0; i<m+q; i++){
        if(edges[i][3] == 1){
            if(find_set(edges[i][1]) != find_set(edges[i][2])){
                union_sets(edges[i][1], edges[i][2]);
            }
            else{
                continue;
            }
        }
        else{
            if(find_set(edges[i][1]) != find_set(edges[i][2])){
                ans[edges[i][4]] = 1;
                // continue;
            }
            else{
                continue;
            }
        }
    }
    
    for(int i = 0; i<q; i++){
        if(ans[i] == 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

}

signed main(){

#ifndef ONLINE_JUDGE
freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
#endif

ios_base::sync_with_stdio(false);
cin.tie(NULL);
auto start = chrono::high_resolution_clock::now();

int t=1;
// cin>>t;
while(t--){
  solve();
}

auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

time_taken *= 1e-9;

cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
return 0;
}