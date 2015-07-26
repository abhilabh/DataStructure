#include<stdio.h>
#include<conio.h>

struct node
{
    int info;
    int balance;
    struct node *lchild;
    struct node *rchild;
};
struct node *insert(int,struct node*);
int ht_inc;

main()
{
    int info;
    int choice;
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root=NULL;

    while(1)
    {
        printf("1.insert\n");
        printf("2.display\n");
        printf("3.exit\n");
        printf("enter ur choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            ht_inc=1;
            printf("enter the no to  be inserted:");
            scanf("%d",&info);
            root=insert(info,root);
            break;
            case 2:
            display(root,0);
            break;
            case 3:
            exit(1);
        }
    }
}

struct node *insert(int info,struct node *pptr)
{
    if(pptr==NULL)
    {
        pptr=(struct node*)malloc(sizeof(struct node));
        pptr->info=info;
        pptr->lchild=NULL;
        pptr->rchild=NULL;
        pptr->balance=0;
        return(pptr);

    }
    if(info<pptr->info)
    {

        pptr->lchild=insert(info,pptr->lchild);
        if(ht_inc==1)
        {
            if(pptr->balance==-1)
            ht_inc=0;
            pptr->balance=pptr->balance+1;

        }

    }
    if(info>pptr->info)
    {

        pptr->rchild=insert(info,pptr->rchild);
        if(ht_inc==1)
        {
            if(pptr->balance==1)
            ht_inc=0;
              pptr->balance=pptr->balance-1;
        }
    }
    return pptr;
}
display(struct node *ptr,int level)
{
     int i;
    if(ptr!=NULL)
    {


        display(ptr->rchild,level+1);
        printf("\n");
        for(i=0;i<level;i++)
        printf("  ");
        printf("%d\t",ptr->balance);
        display(ptr->lchild,level+1);

    }
}

