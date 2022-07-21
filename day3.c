#include<stdio.h>
#include<stdlib.h>
int no_vertices;
struct node
{
int data;
struct node *next;
};
void readgraph(struct node *ad[]);
void printgraph(struct node *ad[]);
void dfs(struct node *ad[],int start,int visited[]);
int main()
{
int i,j,k,ch,start;
printf("Enter the total number of vertex :");
scanf("%d",&no_vertices);
int visited[no_vertices];
struct node *adj[no_vertices];
for(i=0;i<no_vertices;i++)
{
adj[i] = NULL;
}
readgraph(adj);

do{
printf("\n Enter 1 for DFS\n Enter 2 to Print the adjacency list\nEnter 3 to Exit : ");
scanf("%d",&ch);
switch(ch)
{


case 1:
printf("Enter the vertex from which do you wanted to start :");
scanf("%d",&start);
for(int k=0;k<no_vertices;k++)
visited[k]=0;

printf("DFS : ");
dfs(adj,start,visited);
break;

case 2: printgraph(adj);break;

case 3: break;
}
}while(ch!= 3);




return 0;
}
void readgraph(struct node *ad[])
{
struct node *newnode;
int i,j,k,data;

for(i=0;i<no_vertices;i++)
{
struct node *last =NULL;
printf("\nEnter the Number of neighbours of %d  :",i);
scanf("%d",&k);

for(j=0;j<k;j++)
{
printf("Enter the value of %d neighbour of %d : ",j,i);
scanf("%d",&data);

newnode = (struct node*)malloc(sizeof(struct node*));
newnode->data = data;
newnode->next = NULL;
if(ad[i]==NULL)
{
ad[i] = newnode;
}
else
last->next = newnode;

last = newnode;
}
}
}
void printgraph(struct node *ad[])
{
struct node *ptr  = NULL;
int i,j;
for(i=0;i<no_vertices;i++)
{
ptr = ad[i];
printf("\n The neighbour of %d are :",i);
while(ptr != NULL)
{
printf("%d\t",ptr->data);
ptr = ptr->next;
}
}
}

void dfs(struct node *ad[],int start, int visited[])
{

visited[start] = 1;
printf("%d\t",start);
struct node *ptr;
ptr = ad[start];
while(ptr!=NULL)
{
if(visited[ptr->data]==0)
dfs(ad,ptr->data,visited);
ptr = ptr->next;
}
}
