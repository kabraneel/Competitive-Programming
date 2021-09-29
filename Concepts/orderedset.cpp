#include <bits/stdc++.h>
#include <chrono>


//The next three lines are important
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

//These two lines are the ordered_set
template <typename num_t>
using ordered_set = tree<num_t, null_type,less_equal<num_t>, rb_tree_tag,   tree_order_statistics_node_update>;

/*

for pairs:
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>

*/

// how to use
int main(){

  ordered_set<int> oset1;

  int n; cin>>n;

  for(int i = 0; i<n; i++){
    int x;
    cin>>x;

    //number of elements smaller than x
    int smaller = oset1.order_of_key(x);

    //inserting x in to an ordered_set
    oset1.insert(x);


  // cout<<ans<<'\n';
}
