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


// C++ implementation of the approach
// #include <bits/stdc++.h>
// using namespace std;

// Function to find the farthest
// smaller number in the right side
vector<int> farthest_min_right(vector<int> &a, int n)
{
	// To store minimum element
	// in the range i to n
	int suffix_min[n];
	suffix_min[n - 1] = a[n - 1];
	vector<int> temp;
	for (int i = n - 2; i >= 0; i--) {
		suffix_min[i] = min(suffix_min[i + 1], a[i]);
	}

	for (int i = 0; i < n; i++) {
		int low = i + 1, high = n - 1, ans = -1;

		while (low <= high) {
			int mid = (low + high) / 2;

			// If current element in the suffix_min
			// is less than a[i] then move right
			if (suffix_min[mid] < a[i]) {
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}

		// Print the required answer
		temp.PB(ans);
		// cout << ans << " ";
	}

	return temp;
}


vector<int> farthest_min_left(vector<int> &a, int n)
{
	// To store minimum element
	// in the range i to n
	int suffix_min[n];
	suffix_min[0] = a[0];
	vector<int> temp;
	for (int i = 1; i < n; i++) {
		suffix_min[i] = min(suffix_min[i - 1], a[i]);
	}

	// for(int i = 0; i<n; i++){
	// 	cout<<suffix_min[i]<<" ";
	// }
	// cout<<"\n\n";

	for (int i = 0; i < n; i++) {
		int low = 0, high = i, ans = -1;

		while (low <= high) {
			int mid = (low + high) / 2;

			// If current element in the suffix_min
			// is less than a[i] then move right
			if (suffix_min[mid] < a[i]) {
				ans = mid;
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}

		// Print the required answer
		temp.PB(ans);
		// cout << ans << " ";
	}
	// reverse(all(temp));
	return temp;
}



void solve(){
		
	int n; cin>>n;
	int k; cin>>k;

	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	
	k = min(n-1, k);

	sort(all(arr));

	cout<<arr[k]<<'\n';


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