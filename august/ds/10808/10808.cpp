//
//  main.c
//  10808
//
//  Created by Admin on 2016. 2. 17..
//  Copyright © 2016년 이성준. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    
    char a[30];
    char input[150];
    int b[30];
    int i;
    int len;
    
    scanf("%s",input);
    len=strlen(input);
    
    for(i=0;i<30;i++)
        b[i]=0;
    for(i=0;i<26;i++)
    {
        a[i]=i+97;
    }
    for(i=0;i<len; i++)
    {
        if(input[i] == '\n'||input[i] =='\0')
            break;
        for(int j=0;j<26;j++)
        {
            if(input[i] == a[j])
                b[j]++;
        }
        
    }
    for(i=0;i<25;i++)
        printf("%d ",b[i]);
    
    printf("%d\n",b[25]);
    return 0;
}
