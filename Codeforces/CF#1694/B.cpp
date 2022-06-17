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

// Function to merge two partitions
// such that the merged array is sorted
void merge(vector<int>& v, int left,
		int mid, int right, int& inversions)
{
	vector<int> temp(right - left + 1);

	int i = left;
	int j = mid + 1;
	int k = 0;
	int cnt = 0;

	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			temp[k++] = v[i++];
		}
		else {
			// Counting inversions
			inversions += (mid - i + 1);

			temp[k++] = v[j++];
		}
	}

	while (i <= mid)
		temp[k++] = v[i++];

	while (j <= right)
		temp[k++] = v[j++];

	k = 0;
	for (int a = left; a <= right; a++) {
		v[a] = temp[k++];
	}
}

// Function to implement merge sort
void mergeSort(vector<int>& v, int left,
			int right, int& inversions)
{
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSort(v, left, mid, inversions);
		mergeSort(v, mid + 1, right, inversions);
		merge(v, left, mid, right, inversions);
	}
}

// Function to calculate number of
// inversions in a given array
int CountInversions(vector<int>& v)
{
	int n = v.size();
	int inversions = 0;

	// Calculate the number of inversions
	mergeSort(v, 0, n - 1, inversions);

	// Return the number of inversions
	return inversions;
}

// Function to count the number of
// substrings that contains more 1s than 0s
int getSubsCount(string& input)
{
	int n = input.length();

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		nums[i] = input[i] - '0';

		if (nums[i] == 1)
			nums[i] = -1;

		else{
			nums[i] = 1;
		}
	}

	// Stores the prefix sum array
	vector<int> pref(n);

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += nums[i];
		pref[i] = sum;
	}

	int cnt = 0;

	// Stores the count of valid substrings
	for (int i = 0; i < n; i++) {
		if (pref[i] > 0)
			cnt++;
	}

	reverse(pref.begin(), pref.end());

	int inversions = CountInversions(pref);

	int ans = inversions;

	return ans;
}
/*
	111000
	
	1010

	10
	01
 	10 

	101
	010

	1010

	101001  0
	

	00
	100
	10100
	
	10
	01
	10
	01

	101
	010
	001

	1010
	1001

	01001
	101001
	counter = 

	1110001

	000111  -- 
	000
	00001
	0011001
	
	0001
	1111

	01111

	NC2 - 3C2
	10001

	4C2 - 2C2 -- 
	
	1001
	
	if(count0 < count1){
		problem
	}

*/
void solve(){
	//fix l, see number of 1 counts less than that
	// 10 0
	int n; cin>>n;

	string s;
	cin>>s;

	int bit = s[0];
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(bit != s[i]){
			ans += i;
			bit = s[i];
		}
	}

	cout<<ans + n<<'\n';

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
	cin>>t;

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