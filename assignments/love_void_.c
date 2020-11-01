 #include<stdio.h>
int main()
{
int a,b,c;
scanf("%d",&a);
for(b=a/2; b<=a; b+=2)
{
for(c=1; c<a-b; c+=2) printf(" ");
for(c=1; c<=b; c++) printf("*");
for(c=1; c<=a-b; c++) printf(" ");
for(c=1; c<=b; c++) printf("*");
puts("");
}
for(b=a; b>0; b--)
{
for(c=b; c<a; c++) printf(" ");
for(c=1; c<2*b; c++) printf("*");
puts("");
}
return 0;
}