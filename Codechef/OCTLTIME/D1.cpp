// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// A utility function to get the
// middle index from corner indexes
int getMid(int s, int e)
{
	return (s + (e - s) / 2);
}

// A recursive function to get the gcd of values in given range
// of the array. The following are parameters for this function

// st --> Pointer to segment tree
// si --> Index of current node in the segment tree. Initially
// 0 is passed as root is always at index 0
// ss & se --> Starting and ending indexes of the segment represented
// by current node, i.e., st[si]
// qs & qe --> Starting and ending indexes of query range
int getGcdUtil(int* st, int ss, int se, int qs, int qe, int si)
{
	// If segment of this node is a part of given range
	// then return the gcd of the segment
	if (qs <= ss && qe >= se)
		return st[si];

	// If segment of this node is outside the given range
	if (se < qs || ss > qe)
		return 0;

	// If a part of this segment overlaps with the given range
	int mid = getMid(ss, se);
	return __gcd(getGcdUtil(st, ss, mid, qs, qe, 2 * si + 1),
				getGcdUtil(st, mid + 1, se, qs, qe, 2 * si + 2));
}

// A recursive function to update the nodes which have the given
// index in their range. The following are parameters
// st, si, ss and se are same as getSumUtil()
// i --> index of the element to be updated. This index is
// in the input array.
// diff --> Value to be added to all nodes which have i in range
void updateValueUtil(int* st, int ss, int se, int i, int diff, int si)
{
	// Base Case: If the input index lies outside the range of
	// this segment
	if (i < ss || i > se)
		return;

	// If the input index is in range of this node, then update
	// the value of the node and its children
	st[si] = st[si] + diff;
	if (se != ss) {
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
		updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
	}
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int* st, int n, int i, int new_val)
{
	// Check for erroneous input index
	if (i < 0 || i > n - 1) {
		cout << "Invalid Input";
		return;
	}

	// Get the difference between new value and old value
	int diff = new_val - arr[i];

	// Update the value in array
	arr[i] = new_val;

	// Update the values of nodes in segment tree
	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

// Function to return the sum of elements in range
// from index qs (query start) to qe (query end)
// It mainly uses getSumUtil()
int getGcd(int* st, int n, int qs, int qe)
{

	// Check for erroneous input values
	if (qs < 0 || qe > n - 1 || qs > qe) {
		cout << "Invalid Input";
		return -1;
	}

	return getGcdUtil(st, 0, n - 1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructGcdUtil(int arr[], int ss, int se, int* st, int si)
{
	// If there is one element in array, store it in current node of
	// segment tree and return
	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one element then recur for left and
	// right subtrees and store the sum of values in this node
	int mid = getMid(ss, se);
	st[si] = __gcd(constructGcdUtil(arr, ss, mid, st, si * 2 + 1),
				constructGcdUtil(arr, mid + 1, se, st, si * 2 + 2));
	return st[si];
}

// Function to construct segment tree from given array. This function
// allocates memory for segment tree and calls constructSTUtil() to
// fill the allocated memory
int* constructGcd(int arr[], int n)
{
	// Allocate memory for the segment tree

	// Height of segment tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of segment tree
	int max_size = 2 * (int)pow(2, x) - 1;

	// Allocate memory
	int* st = new int[max_size];

	// Fill the allocated memory st
	constructGcdUtil(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}

// Driver code
int main()
{
	// int arr[] = { 1, 3, 6, 9, 9, 11 };
	// int n = sizeof(arr) / sizeof(arr[0]);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  freopen("/home/kabraneel/coding/error.txt","w",stderr);
  #endif

  int t; cin>>t;
  while(t--){

    int n; cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++) cin>>arr[i];

    // Build segment tree from given array
    int* st = constructGcd(arr, n);

    // Print GCD of values in array from index 1 to 3
    // cout << getGcd(st, n, 1, 3) << endl;
    //
    // // Update: set arr[1] = 10 and update corresponding
    // // segment tree nodes
    // updateValue(arr, st, n, 1, 10);
    //
    // // Find GCD after the value is updated
    // cout << getGcd(st, n, 1, 3) << endl;

    int ans = 0;

    for(int i = 0; i<n; i++){
      for(int j = i+1; j<n; j++){

        // cout<<"here\n";

        int temp1 = arr[i];
        int temp2 = arr[j];

        updateValue(arr, st, n, i, temp1*temp2);

        updateValue(arr, st, n, j, temp1*temp2);

        // for(int k = 0; k<n; k++){
        //   cout<<getGcd(st, n, k, k)<<" ";
        // }
        // cout<<'\n';
        //
        // cout<<getGcd(st, n, 1, n-1)<<" ";
        // cout<<'\n';

        // ans = max(ans, s.query(0, n-1).v);
        ans =  max(ans, __gcd(getGcd(st, n, 0, 0), getGcd(st, n, 1, n-1)));
        // cout<<getGcd(st, n, 0, n-1)<<'\n';
        // for(int k = 0; k<n; k++){
          //   // cout<<arr[i]<<" ";
          //   cout<< s.query(k,k).v << " ";
          // }
          // cout<<'\n';
          //
          // cout<<s.query(0, n-1).v<<"\n";

          updateValue(arr, st, n, i, temp1);

          updateValue(arr, st, n, j, temp2);

          // s.rupd(i, i, temp1);
          // s.rupd(j,j, temp2);
        }
      }

      cout<<ans<<'\n';
  }



	return 0;
}
