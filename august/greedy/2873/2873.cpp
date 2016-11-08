#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int r,c;
  char R = 'R';
  char L = 'L';
  char D = 'D';
  char U = 'U';
  cin >> r >> c;
  if(r%2==1){
    //go down right
    for(int i=0; i<c; i++){
      for(int j=0; j<r-1; j++){
        printf("%c",D );
        if(i==c-1 && j == r-2)
          return 0;
      }
      printf("%c",R );
      swap(D,U);
    }
  }
  else if(c%2==1){
    //go right down
    for(int i=0; i<r; i++){
      for(int j=0; j<c-1; j++){
        printf("%c",R );
        if(i == r-1  &&j == c-2)
          return 0;
      }

      printf("%c",D );
      swap(R,L);
    }
  }
  else{
    //find even * even

  }
}
