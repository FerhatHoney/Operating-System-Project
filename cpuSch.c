#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "input.txt"

float totalWaitTime=0,totalTurnAroundTime=0;
int n;

typedef struct node
{
	int pn;
	float at,bt,ct,tat,wt,prio;
	struct process *next;
}node;

/////////////////////////////////////////

node *get_process(float aT,float bT){ //Getting Procces for FCFS
	static int i=1;
	node *pr=(node *)malloc(sizeof(node));
	pr->at=aT,pr->bt=bT;
	pr->pn=i++;
	pr->next=NULL;
	return pr;
}

void insert(node *ptr,float aT,float bT) // insert data's for FCFS
{
	node *pro,*temp;
	pro=get_process(aT,bT);
	while(ptr->next!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
		if(ptr->at>aT){
			pro->next=ptr;
			temp->next=pro;
			return;
		}
	}
	ptr->next=pro;
}

void FCFS(node *ptr) // FCFS Function
{
    double atta,awt;
	node *temp,*t;
	temp=ptr->next;
	t=ptr;
	while(temp!=NULL)
	{

		temp->ct=t->ct+temp->bt;
		t=temp;
		temp->tat=temp->ct-temp->at;
		totalTurnAroundTime+=temp->tat;
		temp->wt=temp->tat-temp->bt;
		totalWaitTime+=temp->wt;
		printf("P[%d]\t%3.2f\t\t%3.2f\t\t%3.2f\t\t%3.2f\t\t%3.2f\n",temp->pn,temp->at,temp->bt,temp->ct,temp->wt,temp->tat);
		temp=temp->next;
	}
	awt = totalWaitTime/n;
	atta = totalTurnAroundTime/n;

	printf("Average waiting time :%3.2f ms\nAverage turn arround time :%3.2f ms\n",awt,atta);
}
////////////////////////////////////////

int main()
{
	int t,P;
	float AT,BT,priority;
	node *START=(node *)malloc(sizeof(node));
	START->next=NULL;

    FILE *fp = fopen(FILE_NAME,"r");
	if(!fp)
		return -1*printf("FILE OPEN ERROR!\n");

		while(EOF != fscanf(fp,"%f:%f:%f:",&BT,&AT,&priority)){
		//printf("%f:%f:%f:\n",AT,BT,priority);

        P=getc(fp);
        if(P=='\n'){
            n=n+1;
            }

	insert(START,AT,BT);
    }fclose(fp);
	do{
		printf("\n SIMULATION OF CPU SCHEDULING ALGORITHMS\n");
		printf("\n Options:");
		printf("\n 1. FCFS");
		printf("\n 2. SJF (Pre-emptive)");
		printf("\n 3. SJF (Non Pre-emptive)");
		printf("\n 4. Priority Scheduling (Pre-emptive)");
		printf("\n 5. Priority Scheduling (Non Pre-emptive)");
		printf("\n 6. Round Robin");
		printf("\n 7. Exit\n Select : ");
		scanf("%d",&t);
		switch(t){
			case 1:
                printf("\n\nPROC.\tA.T.\t\tB.T.\t\t   \t\tW.T\t\tT.A.T\n");
                FCFS(START);
				break;
			case 2:
//				SJF_P(P,n);
				break;
			case 3:
			//	SJF_NP(P,n);
				break;
			case 4:
			//	PRT_P(P,n);
				break;
			case 5:
				//PRT_NP(P,n);
				break;
			case 6:
			//	RR(P,n);
				break;
			case 7:exit(0);
		}
	}while(t != 7);

	return 0;
}
