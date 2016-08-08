#include<stdio.h>
#include<stdlib.h>

typedef struct _QUEUE{
    int value;
    struct _QUEUE *link;
}QUEUE;

void push(QUEUE *);
void pop(QUEUE *);
void size(QUEUE *);
void empty(QUEUE *);
void front(QUEUE *);
void back(QUEUE *);
void run(QUEUE *);
int main()
{
    QUEUE *head;
    head=(QUEUE *)malloc(sizeof(QUEUE));
    head->link = NULL;
    int count;
    
    scanf("%d",&count);
    while(count--)
        run(head);
    return 0;
}
void run(QUEUE *head)
{
    char a[50];
    scanf("%s",a);
    if(!strcmp(a,"push"))
        return push(head);
    if(!strcmp(a,"pop"))
        return pop(head);
    if(!strcmp(a,"size"))
        return size(head);
    if(!strcmp(a,"empty"))
        return empty(head);
    if(!strcmp(a,"front"))
        return front(head);
    if(!strcmp(a,"back"))
        return back(head);
}
void push(QUEUE *head)
{
    int temp;
    scanf("%d",&temp);

    QUEUE *new;
    QUEUE *p;
    new=(QUEUE *)malloc(sizeof(QUEUE));
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
void pop(QUEUE *head)
{
    QUEUE *reset;
    reset=(QUEUE *)malloc(sizeof(QUEUE));
    if(head->link == NULL)
        printf("-1\n");
    else
    {
        printf("%d\n",head->link->value);
        head->link=head->link->link;
    }
}
void size(QUEUE *head)
{
    QUEUE *p;
    int count=0;
    for(p=head ; p->link != NULL; p=p->link)
        count++;
    printf("%d\n",count);
}
void empty(QUEUE *head)
{
    if(head->link == NULL)
        printf("1\n");
    else
        printf("0\n");
}
void front(QUEUE *head)
{
    if(head->link == NULL)
        printf("-1\n");
    else
        printf("%d\n",head->link->value);
}
void back(QUEUE *head)
{
    if(head->link == NULL)
        printf("-1\n");
    else
    {
        QUEUE *p;
        for(p=head->link ; p->link != NULL ; p=p->link);
        printf("%d\n",p->value);
    }
}