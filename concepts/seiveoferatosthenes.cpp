/*

  This concept is used to find all the prime numbers in the range [1,n]
  The concept is very simple, you basically create a VISTED array
  Use the fact that if all primes less than a number does not divide the number, then it is a prime

*/

vector<bool> Seive(int n){

  vector<bool> visited(n,true);

  visied[0] = false;
  visited[1] = false;

  for(int i=2; i<n; i++){
    if(visited[i]){
      for(int j = i^2; j<(long long) n; j = j+i){
        visited[j] = false;
      }
    }
  }

  return visited;
}



#include <bits/stdc++.h>

int main(){

  int n = 100;
  vector<bool> visited(n,true);

  visited[0] = true;
  visited[1] = true;

  //now we take each number and make all multiples of the number and mark it not prime

  FOR(i,0,n){
    if(visited[i] == true){
      for(int j = i*i; j<n; j = j+i){
        visited[j] = true;
      }
    }
  }

}
