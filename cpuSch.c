#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "input.txt"

typedef struct node {
    int no;
    int at,bt,pc,tat,wt,rt,rd;
    struct node *next;
}NODE;

void createInsert(NODE **p,int no,int arrival_time,int burst_time,int *first_response){
    NODE *q,*r = *p;
    q = (NODE*)malloc(sizeof(NODE));
    q -> no = no;
    q -> at = arrival_time;
    q -> bt = burst_time;
    q -> rt = *first_response - arrival_time;
    q -> pc = *first_response + burst_time;
    q -> tat = q ->pc - arrival_time;
    q -> wt = q ->tat - burst_time;
    q -> rd = q ->tat / burst_time;
    *first_response = *first_response + burst_time;

    //inserting node at the end
    q->next=NULL;
    if(*p==NULL) *p =q;
    else {
    while(r->next != NULL){
            r = r -> next;
        }
        r -> next = q;
    }

}
void displayResults(NODE *p,int process){
    double totalTimeArroundTime,totalWaitingTime,totalRelativeDelay,totalResponseTime,totalBurstTime;
    totalTimeArroundTime = totalWaitingTime = totalRelativeDelay = totalResponseTime = totalBurstTime=0;

    while(p!=NULL){

        totalTimeArroundTime += p -> tat;
        totalWaitingTime += p -> wt;
        totalRelativeDelay += p ->rd;
        totalResponseTime += p ->rt;
        totalBurstTime += p ->bt;

        printf("P%d: %d ms\n",p->no,p->wt);
        p = p -> next;

    }
    double twp = totalWaitingTime/process;

     printf("Average Waiting Time: %f ms\n",twp);

}

int main () {
    NODE *q,*head = NULL;
    char P;//line number
    int i,k=0;
    int BT,AT;
    int arrival_time,burst_time,priority,first_response;

    FILE *fp = fopen(FILE_NAME,"r");

	if(!fp)
		return -1*printf("FILE OPEN ERROR!\n");

    while(EOF != fscanf(fp,"%d:%d:%d:",&burst_time,&arrival_time,&priority)){

        P=getc(fp);
        if(P=='\n'){
            k=k+1;
            }
    	//printf("%d:%d:%d\n",burst_time,arrival_time,priority);

    	BT=burst_time;
    	AT=arrival_time;
    	//printf("%d %d\n",BT,AT);
    	//head -> bt = BT;
    	//head -> at = AT;

    	if (head!=NULL){
    	//q -> at = arrival_time;
    	//head -> bt = burst_time;


        }
       // head = (NODE*)malloc(sizeof(NODE));
    	if(k>=1){

            first_response = AT;
            createInsert(&head,k,AT,BT,&first_response);


        }



    }
    displayResults(head,k);
    fclose(fp);

 printf("\n\n%d\n",k);
 return 0;
}


