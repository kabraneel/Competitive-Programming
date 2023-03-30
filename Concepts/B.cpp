// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define int long long
#ifdef KABRANEEL
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

template <class t> class MergeSortTree{
    public:
        int _l, _r, _m;
        vector<t> v;
        MergeSortTree *left, *right;
        MergeSortTree(int l, int r, vector<t> &e){
            v.resize(r-l+1);
            _l=l, _r=r, _m=(l+r)/2, v[0]=e[l];
            if(l==r)    left=right=nullptr;
            else{
                left=new MergeSortTree(_l,_m, e);
                right=new MergeSortTree(_m+1,_r, e);
                merge(left->v.begin(), left->v.end(), right->v.begin(), right->v.end(), v.begin());
            }
        }
        int count(int l, int r, t a, t b){ //Number of x -> a<=x<=b and x is between l and r
            if (l>r || a>b) return 0;  // extra
            if(l>_r || r<_l) return 0;
            if(_l>=l && _r<=r)    return upper_bound(v.begin(), v.end(), b)-lower_bound(v.begin(), v.end(), a);
            return left->count(l,r,a,b)+right->count(l,r,a,b);
        }
        // for fixing memory leaks
        void clear() {
            if (left != nullptr) {
                left->clear();
                delete left;
            }
            if (right != nullptr) {
                right->clear();
                delete right;
            }
        }
};

void solve(){
	int Y; int n; cin>>Y>>n;
	vector<int> arr(Y);
	for(int i = 0; i<Y; i++){
		cin>>arr[i];
	}

	MergeSortTree<int> mt(0, Y - 1, arr);

	for(int i = 0; i<n; i++){
		int a, p, f; cin>>a>>p>>f;
		if(arr[a-1] >= p){
			// debug("Here\n");
			cout<<"0\n";
			continue;
		}
		cout << mt.count( a , a + f - 1, p, (int) 4e5) << '\n';
	}

}

signed main(){

	#ifdef KABRANEEL
	freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto start = chrono::high_resolution_clock::now();

	int t=1;
	int zcount = 1;
	// cin>>t;

	while(t--){
		//cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}