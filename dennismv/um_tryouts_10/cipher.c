#include <stdio.h>

char buf[36];
int perm[36] =
{
	27,	 1,	33,	2,	35,	36,
	26,	 32,	3,	34,	5,	10,
	29,	 25,	4,	13,	12,	6,
	24,	 30,	31,	22,	7,	11,
	28,	 23,	16,	21,	14,	8,
	18,	 17,	20,	15,	19,	9,
}, i, j;

int main()
{
	while(1)
	{
		scanf("%s",buf);
		if(buf[0]=='0') break;
		for(i=0;i<36;i++) for(j=0;j<36;j++) if(perm[j]==i+1) printf("%c",buf[j]);
		printf("\n");
	}
	return 0;
}
