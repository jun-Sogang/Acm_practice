//
//  main.c
//  10866
//
//  Created by Admin on 2016. 2. 17..
//  Copyright © 2016년 이성준. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct _DEQUE{
    int value;
    struct _DEQUE *link;
}DEQUE;

void push_front(DEQUE *);
void push_back(DEQUE *);
void pop_front(DEQUE *);
void pop_back(DEQUE *);
void size(DEQUE *);
void empty(DEQUE *);
void front(DEQUE *);
void back(DEQUE *);
void run(DEQUE *);
int main()
{
    DEQUE *head;
    head=(DEQUE *)malloc(sizeof(DEQUE));
    head->link = NULL;
    int count;
    
    scanf("%d",&count);
    while(count--)
        run(head);
    return 0;
}
void run(DEQUE *head)
{
    char a[50];
    scanf("%s",a);
    if(!strcmp(a,"push_front"))
        return push_front(head);
    if(!strcmp(a,"push_back"))
        return push_back(head);
    if(!strcmp(a,"pop_front"))
        return pop_front(head);
    if(!strcmp(a,"pop_back"))
        return pop_back(head);
    if(!strcmp(a,"size"))
        return size(head);
    if(!strcmp(a,"empty"))
        return empty(head);
    if(!strcmp(a,"front"))
        return front(head);
    if(!strcmp(a,"back"))
        return back(head);
}
void push_front(DEQUE *head)
{
    int temp;
    scanf("%d",&temp);
    
    DEQUE *new;
    DEQUE *p;
    new=(DEQUE *)malloc(sizeof(DEQUE));
    new->value = temp;
    
    if(head->link == NULL)
        head->link = new;
    else
    {
        p=head->link;
        new->link = p;
        head->link = new;
    }
}

void push_back(DEQUE *head)
{
    int temp;
    scanf("%d",&temp);
    
    DEQUE *new;
    DEQUE *p;
    new=(DEQUE *)malloc(sizeof(DEQUE));
    new->link = NULL;
    new->value = temp;
    
    if(head->link == NULL)
    {
        head->link = new;
    }
    else
    {
        for(p=head ; p->link != NULL; p=p->link);
        p->link = new;
    }
}
void pop_front(DEQUE *head)
{
    if(head->link == NULL)
        printf("-1\n");
    else
    {
        printf("%d\n",head->link->value);
        head->link=head->link->link;
    }
}
void pop_back(DEQUE *head)
{
    DEQUE *p;
    if(head->link == NULL)
        printf("-1\n");
    else
    {
        if(head->link->link ==NULL)
        {
            printf("%d\n",head->link->value);
            head->link = NULL;
        }
        else
        {
            for(p=head->link ; p->link->link != NULL ; p=p->link);
            printf("%d\n",p->link->value);
            p->link = NULL;
        }
    }
}
void size(DEQUE *head)
{
    DEQUE *p;
    int count=0;
    for(p=head ; p->link != NULL; p=p->link)
        count++;
    printf("%d\n",count);
}
void empty(DEQUE *head)
{
    if(head->link == NULL)
        printf("1\n");
    else
        printf("0\n");
}
void front(DEQUE *head)
{
    if(head->link == NULL)
        printf("-1\n");
    else
        printf("%d\n",head->link->value);
}
void back(DEQUE *head)
{
    if(head->link == NULL)
        printf("-1\n");
    else
    {
        DEQUE *p;
        for(p=head->link ; p->link != NULL ; p=p->link);
        printf("%d\n",p->value);
    }
}