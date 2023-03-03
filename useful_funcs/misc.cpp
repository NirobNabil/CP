//extract digits from integer
for(int i=1; t/i != 0; i*=10) {
	printf("%d ", (t/i)%10 );
} 