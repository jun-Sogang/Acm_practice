#include <cstdio>
void func(int a,int b){
    int temp=a%b;
    if(a!=0)
    {
        func(a/b,b); 
        if(temp>=0 && temp<=9)
            printf("%d",temp);
        else
            printf("%c",temp+55);
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    func(a,b);
    puts("");
}
