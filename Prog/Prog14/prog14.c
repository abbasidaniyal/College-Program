#include <stdio.h>
#include <math.h>

void progname()
{
	printf("\n");
	printf("DANIYAL ABBASI\n");
	printf("17BCS069\n");
	printf("CS SEM 3\n");
}
int main()
{
	int num,i,j;
	printf("Enter the number of inputs you want to give: ");
	scanf("%d",&num);

	int arr[num];
	
	for(i = 0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	int max=0,temp=0,maxind=0,pos=0;
	int  cnt=0;
	int count=0;
	int MaxSum=0;
	for(i=0;i<num;i++)
	{	
		if(arr[i]>=0
)		{	
			cnt++;
			MaxSum+=arr[i];

			if (MaxSum>max)
			{
				max=MaxSum;
				pos=i;
				count=cnt;
			}
		}
		else
		{
			MaxSum=0;
			cnt=0;
		}
	}
	printf("MAX SUB ARRAY\n");
	for(i=pos-count+1;arr[i]>0;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\nMaxSum: %d ", max);
	int min=0;
	pos=0;
	int MinSum=0;
	count =0;
	cnt=0;

	for(i=0;i<num;i++)
	{	
		if(arr[i]<0)
		{	
			cnt++;
			MinSum+=arr[i];

			if (MinSum<min)
			{
				min=MinSum;
				pos=i;
				count=cnt;
			}
		}
		else
		{
			MinSum=0;
			cnt=0;
		}
	}
	printf("\n\nMIN SUB ARRAY : ");
	for(i=pos-count+1 ; i<=pos ; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n\nMinSum: %d ", min);
	progname();
	return 0;
}
