#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    vector<int> books;

    for(int i=0; i<n; i++){
      int temp;
      cin>>temp;
      books.push_back(temp);
    }

    vector<int> zerolen;

    int i=0;

    while(i<n){
      int count =0;
      if(books[i]==0){
        while(i<n && books[i]==0){
          i++;
          count++;
        }
        zerolen.push_back(count);
      }
      else{
        i++;
      }
    }


  }
  return 0;
}
