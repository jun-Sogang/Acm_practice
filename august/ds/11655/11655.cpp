//
//  main.c
//  11655
//
//  Created by Admin on 2016. 3. 4..
//  Copyright © 2016년 이성준. All rights reserved.
//

#include <stdio.h>
int main() {
    
    char input;
    
    while((input=getchar()) != '\n')
    {
        if(input>=65 && input<=90)
        {
            if(input+13<=90)
                printf("%c",input+13);
            else
                printf("%c",input+13-26);
        }
        else if(input>=97 && input<=122)
        {
            if(input+13<=122)
                printf("%c",input+13);
            else
                printf("%c",input+13-26);
        }
        else
            printf("%c",input);
    }
    printf("\n");
    return 0;
}
