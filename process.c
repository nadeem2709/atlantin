#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
struct multi
{
	int arr;
	int p_id;
	int pty;
	int bst;
}*q1,*q2,*q3;
static int n,ind[3]={0,0,0};
void input()
{
	int i;
	printf("Please Enter No Of Processes\n");
	scanf("%d",&n);
	struct multi m;
	q1=(struct multi*)malloc(n*sizeof(struct multi));
	q2=(struct multi*)malloc(n*sizeof(struct multi));
	q3=(struct multi*)malloc(n*sizeof(struct multi));
	for(i=0;i<n;i++)
	{
		printf("Please Enter Process Id\n");
		scanf("%d",&m.p_id);
		printf("Please Enter Arrival Time\n");
		scanf("%d",&m.arr);
		printf("Please Enter Priority\n");
		scanf("%d",&m.pty);
		printf("Please Enter Burst time\n");
		scanf("%d",&m.bst);
		if(m.pty>=1&&m.pty<=5)
		{
			q1[ind[0]]=m;
			++ind[0];
			sleep(10);
		}
		else if(m.pty>=6&&m.pty<=12)
		{
			q2[ind[1]]=m;
			++ind[1];
			sleep(10);
		}
		else
		{
			q3[ind[2]]=m;
			++ind[2];
			sleep(10);
		}
	}
	
}
void algoFcfsUpdated(struct multi *q,int size)
{
	int i,j;
	struct multi m;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(q[j].arr>q[j+1].arr)
			{
				m=q[j];
				q[j]=q[j+1];
				q[j+1]=m;
			}	
		}
	}
}
void algoFcfs()
{
	int i,sum=0;
	int fst_bst=0;
	int *wt=(int*)malloc(ind[0]*sizeof(int));
	algoFcfsUpdated(q1,ind[0]);
	for(i=0;i<ind[0];i++)
	{
		//printf("")
		if(i==0)
		{
			printf("Process of Id    ---> %d\n",q1[i].p_id);
			printf("Turn around Time ---> %d\n",q1[i].bst);
			printf("Waiting Time     ---> 0\n");
			fst_bst+=q1[i+1].bst;
			wt[i]=0;
		}
		else
		{
			printf("Process of Id    ---> %d\n",q1[i].p_id);
			printf("Turn around Time ---> %d\n",fst_bst);
			printf("waiting Time     ---> %d\n",fst_bst-q1[i].bst);
			wt[i]=fst_bst-q1[i].bst;
			fst_bst+=q1[i+1].bst;
		}
	}
	for(i=0;i<ind[0];i++)
	{
		sum+=wt[i];
	}
	printf("Average Waiting Time      ---> %d\n",sum);
	
}
int main()
{
	input();
	algoFcfs();
return 0;
}
