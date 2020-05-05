#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
}*start;

void insert(int val)
{
    struct node *cur = (struct node*) malloc(sizeof(struct node)), *temp;
    cur->val = val;
    cur->next = NULL;
    if(start==NULL)
    {
        start = cur;
        return;
    }
    temp = start;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = cur;
}

void deleteStart()
{
    if(start==NULL)
    {
        puts("Underflow!");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
}

void insertAtPos(int val, int pos){
	struct node *cur = (struct node*) malloc(sizeof(struct node)), *temp = start;
    cur->val = val;
    cur->next = NULL;
    if(pos==0){
    	cur->next = start;
    	start = cur;
    	return;
    }
    pos--;
    while(pos-- && temp->next != NULL) temp = temp->next;
    cur->next = temp->next;
    temp->next = cur;
};
void deleteAtPos(int pos);
void deleteVal(int val);

void print()
{
    struct node *temp;
    if(start==NULL)
    {
        puts("List Empty!");
        return;
    }
    temp = start;
    printf("List: ");
    do
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    while(temp!=NULL);
    puts("");
}

int main()
{
    start=NULL;
    int n, i, x;

    scanf("%d", &n);
    print();
    for (i=0; i<n; i++)
    {
        scanf("%d", &x);
        insert(x);
        print();
    }
    insertAtPos(7,2);
    print();
    deleteStart();
    print();

    return 0;
}