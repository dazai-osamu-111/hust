#include <stdio.h> 
#include <conio.h> 
#include <string.h>

void tachten(char s[], char ten[], char lot[]) {
  int i, j, n;
  n = strlen(s);
  for (i = n - 1; i > 0; i--)
    if (s[i] == ' ')
      break;
  for (j = 0; j < i; j++)
    lot[j] = s[j];
    lot[i] = '\0';
  for (j = i + 1; j < n; j++)
    ten[j - i - 1] = s[j];
  ten[n - i - 1] = '\0';
}
void main(void) {
  char s[30], ten[20], lot[20];
  printf(" nhap ho va ten \n");
  gets(s);
  tachten(s, ten, lot);
  printf(" \n ho va chu lot: \n");
  puts(lot);
  printf(" ten: \n");
  puts(ten);
  getch();
}#include<stdio.h>
#include<string.h>

int main() {
  char  hoten[100];
  int i;
  char s[100];
  printf("nhap ho va ten");
  fgets(hoten,sizeof(hoten),stdin);
  for(i=strlen(hoten)-1;hoten[i]!=' ';i--){
    strcpy(s,&hoten[i]);
    }
  puts(s);
  return 0;
}
