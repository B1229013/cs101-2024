#include <stdio.h>
typedef struct{
    int *g_mms;
}my_mm_t;

int g_mm[10] = {0};
int num = 1;
my_mm_t mms;

void print_calloc_array(int flag){
    int g_mms_p;
    for(int i = 0; i < 10; i++){
        g_mms_p = *(mms.g_mms+i);
        if(g_mms_p == 0){
            printf("0");
        }
        else{
            printf("1");
        }
    }
    if(flag == 1){//記憶體滿了
        printf(" <- Out of space\n");
    }
    else{
        printf("\n");
    }
}

int *my_calloc(int n, int size){//儲存資料
    int k = 1;
    int flag = 0;//有沒有足夠的空間
    for(int i = 0; i < 10; i++){
        if(g_mm[i] == 0){
            flag++;
        }
        else{
            flag = 0;
        }
        if(flag == size){//空間夠儲存資料
            for(int j = i-size+1; j <= i+size; j++){
                g_mm[j] = num;k++;
                if(k > size){
                    break;
                }
            }
            num++;
            print_calloc_array(0);
            return &g_mm[i-size+1];
        }
    }
    if(flag < size){
        num++;
        print_calloc_array(1);//空間不夠
    }
}

void my_free(int *p){//刪除資料
    int free_time = *p;
    for(int i = 0; i < free_time; i++){
        *(p+i) = 0;
    }
    print_calloc_array(0);
}

int main(){
    mms.g_mms = g_mm;
    int *np1 = my_calloc(1, 1);
    int *np2 = my_calloc(1, 2);
    int *np3 = my_calloc(1, 3);
    int *np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int *np5 = my_calloc(1, 5);
    int *np6 = my_calloc(1, 1);
    return 0;
}