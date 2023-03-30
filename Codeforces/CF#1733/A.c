#include <stdio.h>

struct x{
	int b:6;
	char c;
}y;

int main(){
	printf("%d\n", sizeof(y));
}