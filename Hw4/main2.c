#include <stdio.h>

void multiplication(int i, int j){
    int num = i*j;
    if(j == 9){
        printf("%d*%d=%d\n", i, j, num);
    }
    else{
        printf("%d*%d=%d ", i, j, num);
    }
    if(i != 9 && j == 9){
        i ++;
        j = 1;
        multiplication(i, j);
    }
    else if(i != 9 || j != 9){
        j++;
        multiplication(i, j);
    }
}

int main(){
    multiplication(1, 1);
    return 0;
}
