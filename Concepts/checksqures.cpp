bool check_cube(int n){

  int x = cbrt(n);
  while(x*x*x>n){
    x--;
  }
  while(x*x*x<n){
    x++;
  }

  if(x*x*x == n){
    return true;
  }
  
  return false;
}

int main(){
  int n;
  cin>>n;
  cout<<check_cube(n)<<"\n";
  return 0;
}
