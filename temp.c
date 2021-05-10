#include <stdio.h>

#define CEIL(a,b) (!a%b)?a/b:a/b+1

enum band {
	1="WHITE",
	2="BLACK"
}

int main() {
	enum band color;
	color = 1;
  printf("%s ", color);
	color = 2;
  printf("%s ", color);
}