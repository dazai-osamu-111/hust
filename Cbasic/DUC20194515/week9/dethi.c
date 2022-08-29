#include<stdio.h>
#include<string.h>
typedef struct{
  char name[30];
  char year[10];
  char price[10];
  int times;
} book;
typedef struct{
  book a;
  int amount;
}booklist;


int main(){
  FILE *fptr, *f2;
  booklist a[5];
  int i,j,max;
  strcpy(a[0].a.name,"book1");
  strcpy(a[0].a.year,"2000");
  strcpy(a[0].a.price,"100000");
  a[0].a.times=5;

  strcpy(a[1].a.name,"book2");
  strcpy(a[1].a.year,"2001");
  strcpy(a[1].a.price,"200000");
  a[1].a.times=4;

  strcpy(a[2].a.name,"book3");
  strcpy(a[2].a.year,"2002");
  strcpy(a[2].a.price,"300000");
  a[2].a.times=5;

  strcpy(a[3].a.name,"book4");
  strcpy(a[3].a.year,"2003");
  strcpy(a[3].a.price,"400000");
  a[3].a.times=15;

  strcpy(a[4].a.name,"book5");
  strcpy(a[4].a.year,"2005");
  strcpy(a[4].a.price,"500000");
  a[4].a.times=0;

  if((fptr=fopen("library","w+")) == NULL){
    printf("Cannot open file %s\n", "library"); if((fptr=fopen("library","w+")) == NULL){
    printf("Cannot open file %s\n", "library");
    return 1;
  }
    return 1;
  }



C-k kills the contents of the lineC-k kills the contents of the line
  for(i=0;i<5;i++){
    fprintf(fptr,"%-15s%-20s%-10s%-10d\n",a[i].a.name,a[i].a.year,a[i].a.price,a[i].a.times);
  }
  max=a[0].a.times;
  for(i=0;i<4;i++){
    for(j=0;j<5;j++){
      if(a[j].a.times>a[i].a.times){
	max=a[j].a.times;
      }
    }
  }
  printf("Quyen sach co so lan muon nhieu nhat la:\n");
  for(i=0;i<5;i++){
    if(a[i].a.times==max){
      printf("%-15s%-20s%-10s%-10s\n", "Ten"," Nam xuat ban","Gia", "So lan muon");
      printf("%-15s%-20s%-10s%-10d\n",a[i].a.name,a[i].a.year,a[i].a.price,a[i].a.times );
    }
  }
  int n=5;
  printf("Cuon sach ko co ai muon la\n");
  printf("%-15s%-20s%-10s%-10s\n", "Ten"," Nam xuat ban","Gia", "So lan muon");
  for(i=0;i<n;i++){
    if(a[i].a.times==0){
      printf("%-15s%-20s%-10s%-10d\n",a[i].a.name,a[i].a.year,a[i].a.price,a[i].a.times );
      if(i==n-1){
	n=n-1;
      }else{
	for(j=i;j<n-1;j++){
	  strcpy(a[j].a.name,a[j+1].a.name);
	  strcpy(a[j].a.year,a[j+1].a.year);
	  strcpy(a[j].a.price,a[j+1].a.price);
	  a[j].a.times=a[j+1].a.times;
	  n=n-1;
	}
      }
    }
  }
  printf("Danh sach moi:\n");
  for(i=0;i<n;i++){
    printf("%-15s%-20s%-10s%-10d\n",a[i].a.name,a[i].a.year,a[i].a.price,a[i].a.times );
  }
  if((f2=fopen("library2", "w+")) == NULL){
    printf("Cannot creat file\n");
    return 1;
  }
  for(i=0;i<n;i++){
     fprintf(f2,"%-15s%-20s%-10s%-10d\n",a[i].a.name,a[i].a.year,a[i].a.price,a[i].a.times);
  }
  return 0;
}
