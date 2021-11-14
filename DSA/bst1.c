int main(){

  char s[10];
  int n=0;

  //int t=100;

  while(feof(stdin)==0){//until input is stopped

    scanf("%s", s);

  //  printf("%s\n", s);

    if(strcmp(s, "INS")==0){
      //scanning the value to be inserted
      int x;
      scanf("%d ", &x);
      n++;
      //if there is only one node, then we create, else we insertnode
      if(n == 1){
        createtree(x);
        continue;
      }
      insertnode(x);
    }

    if(strcmp(s, "DEL")==0){
      //scanning the value to be inserted
      int x;
      scanf("%d ", &x);
      //if there is only one node, then we create, else we insertnode

      int t=deletenode(x);

      if(t==-1){
        printf("-1\n");
      }

      else{
        n--;
      }

    }

    if(strcmp(s,"MAX")==0){

  //    printf("-1\n");
      printf("%d\n", findmax(root));

    }

    if(strcmp(s,"MIN")==0){

      printf("%d\n", findmin(root));

    }

    if(strcmp(s,"PST")==0){

      if(root==NULL){
        printf("-1\n");
        continue;
      }
      postorder(root);
      printf("\n");

    }
  }
  return 1;
}
