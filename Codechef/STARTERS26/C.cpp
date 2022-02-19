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

void solve(){
	int n; cin>>n;
	string a; string b;
	cin>>a>>b;

	sort(all(a));
	sort(all(b));
	reverse(all(b));
	// int last = n-1;
	// string ans(2*n);
	string ans;
	for(int i = 0; i<2*n; i++) ans.PB('a');

	int currf = 0;
	int currl = 2*n-1;

	int i1 = 0; int i2 = n-1;
	int j1 = 0; int j2 = n-1;

	for(int i = 0; i<n; i++){
		//Alice's turn
		//if alice has anything less than bob, then alice wants to put that in the front

		if(a[i1] < b[j1]){ //bobs largest character
			ans[currf++] = a[i1++];
			// i1++;
		}

		else if(b[j1] <= a[i1]){
			//alice is in NTL
			ans[currl--] = a[i2--];
		}

		else{
			ans[currl--] = a[i1++];
			// i1++;
		}



		// now bob's move 

		if(a[i1] < b[j1]){
			ans[currf++] = b[j1]; j1++;
		}

		else{
			ans[currl--] = b[j2]; j2--;
		}

	}

	cout<<ans<<'\n';
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
	cin>>t;
	while(t--){
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}