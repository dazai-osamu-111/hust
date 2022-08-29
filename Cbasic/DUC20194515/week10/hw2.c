#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
  double  memory;
  char id[15];
} process;
typedef process element;
#include "GenDLL.h"
#include "queuelist.h"
#define MAX 100
int main(){
  queue *front=NULL,*rear=NULL;
  int  number,x,i, count=0, count2=0;
  double memory, sum=0;
  process a;
  char s[MAX];
  node *p;
  printf("Enter number of parallel process: ");
  scanf("%d", &number);
  printf("Enter memory capacity: ");
  scanf("%lf", &memory);
  
  do{
    printf("1. Creat new program( with a given amount of necessary momory and ID.\n");
    printf("2. Kill a program.\n");
    printf("3. Show the status of running and waiting processes.\n");
    printf("4. Exit.\n");
    printf("Your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      
      printf("Enter size of program:");
      scanf("%lf",&a.memory);
      printf("Enter ID: ");
      scanf("%s", a.id);
      
      if(count+1>number && sum+a.memory <= memory){
	printf("-> in queue as there only %d parallel process\n",number);
	enQ(&front, &rear, a);
	count2++;
	break;
      }
      if(count<=number && sum+a.memory <= memory){
	printf("Successfully\n");
	count++;
	sum=sum+a.memory;
	insertatlast(a);
	break;
      }
      if(count<=number && sum+a.memory>memory){
	printf("-> in queue as there is not enough memory.\n");
	enQ(&front, &rear, a);
	count2++;
	break;
      }
      break;
    case 2:
      printf("Enter ID of process that you want to kill: ");
      scanf("%s",s);
      for(i=0,p=root;p!=NULL;i++,p=p->next){
	if(strcmp(p->element.id, s) ==0){
	  count--;
	  sum=sum-p->element.memory;
	  deleteatpos(i);
	  printf("Done!\n");
	}
      }
      while(!empty(front)){
	a = frontQ(front, rear);
	if((a.memory+sum) <= memory){
	  sum=sum+a.memory;
	  insertatlast(a);
	  deQ(&front, &rear);
	} else break;
      }
      break;
    case 3:
	printf("%-10s%-10s%-10s\n","ID", "Memory", "Queue");
	for(p=root;p!=NULL;p=p->next){
	  printf("%-10s%-10.2lf\n",p->element.id,p->element.memory);
	}
	for(i=0;i<count2;i++){
	  a=deQ(&front, &rear);
	  enQ(&front, &rear, a);
	  printf("%-10s%10s%-10.2lf\n",a.id," ",a.memory);
	}
	break;
    default: break;
    }
  } while(x!=4);
  return 0;
}
