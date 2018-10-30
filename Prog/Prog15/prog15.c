#include <stdio.h>
#include <stdlib.h>

void progname()
{
	printf("\n\n\n");
	printf("DANIYAL ABBASI\n");
	printf("17BCS069\n");
	printf("CS SEM 3\n");
}

int main()
{	

	int i =0,r;
	
	int arr[53];
	for ( i = 0; i < 52; ++i)
	{
		arr[i]=i;
	}

	printf("\n\n52 Unique Random Number \n\n ");
	int tempadd,last=52;

	for(i=0;i<52;i++)
	{
		tempadd=rand()%(last);

		printf("%d  ",arr[tempadd]);

		if (i%10==9)
			printf("\n");

		if (i==51)
			break;

		arr[tempadd]=arr[last-1];
		arr[last-1]='\0';
		last--;

	}
	progname();
	return 0;
}