#include <cstdio>
#include <stdlib.h>
#include <time.h>
int main(){
    srand((unsigned)time(NULL));
    int input;
    int ans=rand()%11;
    while(1){
        printf("숫자를 입력하시오");
        scanf("%d",&input);
        if(input < ans){
            printf("up\n");
        }
        else if(input == ans){
            printf("right!!\n");
            break;
        }
        else
            printf("down\n");
    }

}
