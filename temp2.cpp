#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int arr[100], links[100][2];
queue<int> mem_pool;
int s=-1, e=-1;
bool Empty=1;

int get(int i) {
    int it=s;
    if(it==-1) return -1;
    // printf("%d ", i);
    while(i-- && it!=e) it=links[it][1];
    // printf("%d %d\n", i, it);
    if(i>0) return -1;
    else return it;
}

int insert(int i, int x) {
    int it = get(i);
    if(it==-1 && s!=-1) return 0;
    int ci=mem_pool.front();
    mem_pool.pop();
    arr[ci] = x;
    if(s==-1) { s=ci; e=ci; return 0; }
    if(it==e) e = ci, links[ci][0]=it;
    else links[links[it][1]][0] = ci;
    links[it][1]=ci;
    return 1;
}

int erase(int i) {
    int it = get(i);
    if(it==-1) return 0;
    mem_pool.push(it);
    if(it==s) s=links[it][1];
    else {
        // printf("y- %d %d %d\n", it, links[it][0], links[it][1]);
        links[links[it][0]][1] = links[it][1];
        links[links[it][1]][0] = links[it][0];
        // printf("x- %d %d\n", links[links[it][0]][1], links[links[it][1]][0]);
    }
    return 1;
}


int main(){
    int n=5,t;
    memset(links, -1, sizeof(links));
    for(int i=0; i<100; i++) {
        mem_pool.push(i);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        insert(i, t);
    }
    // printf("links\n");
    // for(int i=0; i<n; i++) printf("%d ", links[i][0]);
    // printf("\n");
    // for(int i=0; i<n; i++) printf("%d ", i);
    // printf("\n");
    // for(int i=0; i<n; i++) printf("%d ", links[i][1]);
    // printf("\n");
    insert(5,6);
    if(!erase(2)) printf("gg\n");;
    for(int i=0; i<n; i++) {
        printf("%d %d\n", get(i), arr[get(i)]);
    }
}