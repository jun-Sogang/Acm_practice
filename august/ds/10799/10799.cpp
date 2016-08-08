//
//  main.c
//  10799
//
//  Created by Admin on 2016. 2. 16..
//  Copyright © 2016년 이성준. All rights reserved.
//

#include <stdio.h>
int main() {
    char stack[100500];
    int R_stack[100500];
    int i=0;
    int j=0;
    int count=0;
    for(int k=0 ; k<100500 ; k++)
    {
        stack[k] = '\0';
        R_stack[k] = 0;
    }
    scanf("%s",stack);
    while(stack[i] !='\0' ||stack[i] =='\n')
    {
        if(stack[i]=='(')
            R_stack[j]=i ;
        else if(stack[i] == ')')
        {
            if(i-R_stack[j-1]==1)
            {
                count += j-1;
            }
            else
                count +=1;
            j--;
            R_stack[j]=0;
            j--;
        }
        i++, j++;
    }
    printf("%d\n",count);
    
    return 0;
}
