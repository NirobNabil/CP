#include <stdio.h>
#include <string.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int c[20];

char* sort(char*, int);
// int main(){
// }
char* sort(char *a, int sz) {
    const int mx=100;
    static char b[mx] = {0};
    int cmx = 0;
    for(int i=0; i<sz; i++) {
        for(int ix=0; ix<sz; ix++) {
            if(b[i]<a[ix]) b[i] = a[ix], cmx=ix;
        }
        a[cmx] *= -1;
    } 
    for(int i=0; i<sz; i++) {
        a[i] *= -1;
    } 
    return b;   
}

int main(){
    int g=32;
    printBits(sizeof(g), &g);
    // unsigned int x = 97 | 97<<8 | 97<<16 | 97<<24;
    // char b[20] = "wowcse19wow";
    // for(int i=0; i<11; i++) {
    //     c[i/4] += b[i] << (i%4)*8;
    //     printf("%d\n", b[i]);
    //     // printBits(sizeof(b[i]), &b[i]);
    // } 
    // for(int i=0; i<4; i++) {
    //     printf("%d\n", c[i]);
    //     // printBits(sizeof c[i], &c[i]);
    // } 
    // char* a = "Blice";
    // char b[20] = "yABob";
    // a = b+1;
    // printf("%s & %s\n", a,&b[2]);
    // char a[50] = "andarbiriyani";
    // printf("%s -> %s", a, sort(a,strlen(a)));
}