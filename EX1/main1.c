#include <stdio.h>
void print_space(int r){
	for(int j=r;j>=1;j--){
		printf(" ");
	}
}
void print_numbers(int r){
	for(int j=1; j<=r; j++){
	printf("%d ",r);
}
}
int main(){
	int rows=6;
	int space=rows;
	for(int i=0; i<=rows; i++){
		print_space(space);
		print_numbers(i);
		printf("\n");
		space--;
	}
}
