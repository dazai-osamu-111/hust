#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
typedef struct phonedb_t{
  phonedb phone;
  struct phonedb_t *next;
} phonedb_node;
phonedb_node *root=NULL,*cur=NULL,*prev=NULL,*k;
phonedb_node *makenewnode(phonedb phone){
  phonedb_node *new=(phonedb_node*)malloc(sizeof(phonedb_node));
  new->phone=phone;
  new->next= NULL;
  return new;
}
void insertathead(phonedb phone){
  phonedb_node *new=makenewnode(phone);
  if(root == NULL){
    root = new;
    cur = root;
  } else{
    new->next = root;
    root=new;
    cur=root;
  }
  return;
}
void displaynode(phonedb_node *p){
  if(p==NULL){
    printf("Null pointer error\n");
    return;
  }
  printf("%-30s%-10s%-10s%s\n",p->phone.model,p->phone.space,p->phone.ssize,p->phone.price);
}
phonedb readtext(FILE *fptr){
    phonedb a;
    fscanf(fptr,"%s%s%s%s",a.model,a.space,a.ssize,a.price);
      
    printf("%-30s%-10s%-10s%s\n",a.model,a.space,a.ssize,a.price);
  
return a;
}
/*phonedb readdat(FILE *fptr){
  phonedb a;
  if(fread(a, sizeof(phonedb),1,fptr) != 0){
    printf("%-30s%-10s%-10s%s\n",a.model,a.space,a.ssize,a.price);
  return a;
  }*/
void insertaftercurrentpos(phonedb a){
  phonedb_node *new=makenewnode(a);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  } else{
    new->next=cur->next;
    cur->next=new;
    cur=cur->next;
  }
  return;
}
void insertbeforecurrent(phonedb a){
  phonedb_node *new=makenewnode(a);
  if(root==NULL){
    root = new;
    cur = root;
    prev = NULL;
  } else {
    new->next=cur;
    if(cur == root){
      root = new;
    }
    else prev->next=new;
    cur = new;
  }
}
void traversinglist(){
  phonedb_node *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}
phonedb inputnode(){
  phonedb a;
  printf("Enter model: ");
  scanf("%s",a.model);
  printf("Enter space: ");
  scanf("%s",a.space);
  printf("Enter screen size:");
  scanf("%s",a.ssize);
  printf("Enter price");
  scanf("%s",a.price);
  return a;
}
int main(){
  FILE *f1,*f2;
  int x,n,i,x1,x2=1,x3;
  phonedb tmp,a;
  char s[100];
  f1=fopen("PhoneDB.txt","r");
  f2=fopen("PhoneDB.dat","r+b");
  if(f1==NULL){
    printf("Cannot open %s\n","PhoneDB.txt");
    return 1;
  }
  if(f2==NULL){
    printf("Cannot open %s\n","PhoneDB.dat");
    return 1;
  }
  
  do{
    printf("************MENU**************\n");
    printf("1.Import from text\n2.Import from Dat\n3.Display list\n\
4.Search phone by Model\n5.Search phone of which the price is under the value inputted\n\
6.Export to Dat\n7.Manual Insertion\n8.quit\n");
    printf("Enter your choose: ");
    scanf("%d",&x);
    switch(x){
    case 1:
       root=NULL;cur=NULL;prev=NULL;
      while(fscanf(f1,"%s%s%s%s",a.model,a.space,a.ssize,a.price)!=EOF){
	insertathead(a);
      }
      if(fseek(f1,0,SEEK_SET) != 0){
	printf("fseek failed!\n");
      }
      printf("Successfully\n");
      break;
    case 2:
      root=NULL;
	while(fread(&a,sizeof(phonedb),1,f2)!=0){
	  insertaftercurrentpos(a);
	}
	printf("successfully\n");
	break;
	
    case 3:
      traversinglist();
      break;
    case 4:
      while(strcmp(s,"0") != 0) {
	printf("Enter model:(0 to exit) ");
	__fpurge(stdin);
	scanf("%s",s);
	int count =0;
	for(k=root;k!=NULL;k=k->next){
	  if(strcmp(k->phone.model,s) == 0){
	    displaynode(k);
	    count++;
	  }
	}
	if(count == 0){
	  printf("Cannot find model\n");
	}
      }
      break;
    case 5:
      while(x1!=0){
	printf("Enter the price:(0 to exit) ");
	scanf("%d",&x1);
	for(k=root;k!=NULL;k=k->next){
	  x3=atoi(k->phone.price);
	  if(x3 < x1){
	    displaynode(k);
	  }
	}
      }
      x1=1;
      break;
      /*case 7:
      while(x2!=0){
	printf("Choose the way to imput one new model\n");
	printf("choose 1 to imput before current possition\n");
	printf("choose 2 to input after current position\n");
	printf("choose 0 to exit\n");
	printf("Enter your choice: ");
	scanf("%d",&x2);
	switch(x2){
	case 2:
	  insertaftercurrentpos(inputnode());
	  break;
	case 1:
	  insertbeforecurrent(inputnode());
	  break;
	}
      }
    case 6:
      if(fseek(f2, 0, SEEK_END) != 0){
	printf("fseek failed!\n");
      }
      for(k=root;k!=NULL;k=k->next){
	fwrite(&k->phone,sizeof(phonedb),1,f2);
      }
      break;*/
    default: break;
    }
  }

while(x!=8);
fclose(f1);
fclose(f2);
return 0;
}
