#include<stdio.h>
#include<string.h>
#define MAX 1000
int main(){
  char s[MAX];
  int charcount[26],i;
  for(i=0;i<26;++i){
    charcount[i]=0;
  }
  printf("Nhap chuoi:\n");
  gets(s);
  for(i=0;s[i]!='\0';++i){
    if(s[i]>='a' && s[i]<= 'z') charcount[s[i]-'a']++;
    if(s[i]>='A' && s[i]<= 'Z') charcount[s[i]-'A']++;
  }
  for(i=0;i<26;++i){
    if(charcount[i]>0){
      printf("Chu cai %c xuat hien %d lan\n",i+'a',charcount[i]);
    }
  }
  return 0;
}

