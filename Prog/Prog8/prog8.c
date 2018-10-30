#include <stdio.h>
#include <string.h>

void progname()
{
	printf("\n");
	printf("DANIYAL ABBASI\n");
	printf("17BCS069\n");
	printf("CS SEM 3\n");
}

int main(int argc, char const *argv[])
{
	char* a;
	FILE *fp;
 	fp=fopen("Text1.txt", "r");
 	fgets(a,100,fp);
 	int i,j;
 	printf("%s ", a );
 	for (i = 0; a[i]!=NULL ; ++i)
	{
		if(a[i]==a[i+1])
		{
			for (j= i; a[j]!=NULL; ++j)
			{
				a[j]=a[j+1];
			}
			i--;
		}
	}
	fclose(fp);
	fp=fopen("Text1.txt","w");
	fprintf(fp, "%s\n",a);
	fclose(fp);
	progname();
	return 0;
}