#include <cstdio>
#include <vector>
#define maxnode 26
using namespace std;
vector < int > outdegree[maxnode];
void preorder(int start){
    if(start==-1)
        return ;
    printf("%c",start+'A');
    preorder(outdegree[start][0]);
    preorder(outdegree[start][1]);
}
void inorder(int start){
    if(start==-1)
        return ;
    inorder(outdegree[start][0]);
    printf("%c",start+'A');
    inorder(outdegree[start][1]);
}
void postorder(int start){
    if(start==-1)
        return ;
    postorder(outdegree[start][0]);
    postorder(outdegree[start][1]);
    printf("%c",start+'A');
}
int main(){
    int n;
    scanf("%d%*c",&n);
    for(int i=0; i<n; i++){
        char a,b,c;
        scanf("%c %c %c%*c",&a,&b,&c);
        if(b>='A' && b<='Z')
            outdegree[a-'A'].push_back(b-'A');
        else
            outdegree[a-'A'].push_back(-1);
        if(c>='A' && c<='Z')
            outdegree[a-'A'].push_back(c-'A');
        else
            outdegree[a-'A'].push_back(-1);
    }
    preorder(0);
    puts("");
    inorder(0);
    puts("");
    postorder(0);
    puts("");
}
