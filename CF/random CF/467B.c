#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	int soldiers[m+1];
	for(int i=0; i<=m; i++) scanf("%d", soldiers[i]);
	for(int i=0; i<m; i++){
		int difftypes=0;
		int diff = soldiers[i] ^ soldiers[m];

		for(int ix=0; ix<n; ix++){
			if(diff & (1<<ix)) difftypes++;
		}
		printBits(sizeof(difftypes), &difftypes);
	}	
}