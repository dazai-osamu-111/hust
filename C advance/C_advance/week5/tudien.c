#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> //thu vien de dung ham thay the cho ham getch() - tren ubuntu khong co thu vien conio.h
#include <termio.h> //tuong tu tren
#include <time.h>

#include "btree.h"

#define WORD_MAX_LEN 2000
#define MEAN_MAX_LEN 40000
#define LINE_MAX_LEN 40000
#define SIZE_MEAN1 100000

typedef struct
{
    char *s;
} String;
BTA *eng_vie;
BTA *btSoundex;

void openBT();
void closeBT();
void docfile(char *filename);
void ghifile(FILE *f);
void insert();
void delete ();
int search_tab(char *word, String *output);
// void search_soundex(String string[], int n);
void search_full();
int menu();
char getch(void);

int SoundEx(char *SoundEx, char *WordString);
void soundex_insert(char *word);
void soundex_delete(char *word);
int soundex_search(char *word, String string[]);

// hai ham phu tro trong xu li chuoi
// ham chuyen chuoi s ve chu thuong het
void strLower(char *dest, const char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        dest[i] = tolower(s[i]);
    }
    dest[strlen(s)] = '\0';
}

// ham bo dau cach o dau tu va cuoi tu
void trim(char *s)
{
    char *p = s;
    int l = strlen(p);

    while (isspace(p[l - 1])) // isspace la kiem tra xem mot ki tu co phai la khoang trang hay khong
        p[--l] = 0;
    while (*p && isspace(*p))
        ++p, --l;

    memmove(s, p, l + 1); // gan giong ham memcpy()
}

int main()
{
    btinit();

   // openBT();
   // closeBT();
    //eng_vie = btcrt("tudien",0,FALSE);//tao tep B Tree
    int key;

    do
    {
        printf("\n================================================================================================\n");
        printf("CHUONG TRINH TU DIEN MAY TINH\n");
        printf("0. LOADING A DICT FILE\n");
        printf("1. ADD\n");
        printf("2. SEARCH\n");
        printf("3. DELETE\n");
        printf("4. EXIT\n");
        printf("=================================================================================================\n");
        printf("Chon chuc nang: ");
        scanf("%d%*c", &key);
        switch (key)
        {
        case 0:
        {
            docfile("anh_viet_dict.txt");
            break;
        }
        case 1:
        {
            openBT();
            insert();
            closeBT();
            break;
        }
        case 2:
        {
            openBT();
            search_full();
            closeBT();
            break;
        }
        case 3:
        {
            openBT();
            delete ();
            closeBT();
            break;
        }
        case 4:
        {
            printf("Bye\n");
            break;
        }
        }
    } while (key != 4);

    closeBT();
    return 0;
}
// ham mo file btree
void openBT()
{
    //open btree
    if ((eng_vie = btopn("dict", 0, 0)) == NULL)
    {
        // create btree file
        eng_vie = btcrt("dict", 0, 0);
    }
    //open btree
    /* if ((btSoundex = btopn("soundex.dat", 0, 0)) == NULL)
    {
        // create btree file
        btSoundex = btcrt("soundex.dat", 0, 0);
	}*/
}

//Hàm đóng btree
void closeBT()
{
    if (eng_vie != NULL)
    {
        //close btree
        btcls(eng_vie);
    }
    /* if (btSoundex != NULL)
    {
        //close btree
        btcls(btSoundex);
	}*/
}
// ham doc file
void docfile(char *filename)
{
    openBT();
    int WordCount = 0; // dem so tu insert thanh cong vao B Tree file
    char *line;
    char *linePtr;
    char notify[MEAN_MAX_LEN]; // chuoi thong bao
    char *word;
    char *meaning;
    char wordLower[WORD_MAX_LEN];
    char *tmp_word = malloc(WORD_MAX_LEN * sizeof(char));
    char *tmp_meaning = malloc(MEAN_MAX_LEN * sizeof(char));

    word = malloc(WORD_MAX_LEN * sizeof(char));
    meaning = malloc(MEAN_MAX_LEN * sizeof(char));
    line = malloc(LINE_MAX_LEN * sizeof(char));

    int i;
    BTint j;
    FILE *f;

    if ((f = fopen(filename, "r")) == NULL)
    {
        printf("Loi\n");
        exit(1);
    }
    else
    {
        // Find a first word
        // Read a line int dict file
        linePtr = fgets(line, LINE_MAX_LEN, f);
        while (linePtr != NULL)
        {
            if (feof(f))
            {
                return;
            }
            if (strlen(line) == 0)
            {
                // Read a line in dict file
                linePtr = fgets(line, MEAN_MAX_LEN, f);
                continue;
            }
            // split word - tach tu
            for (i = 1; line[i] != '/' && line[i] != '\n' && line[i] != '\0'; i++)
                ;
            ;
            strncpy(tmp_word, &line[1], i - 1);
            // ham strncpy() sao chep i-1 ki tu tu mang line sang mang tmp_word => luu tru tu
            tmp_word[i - 1] = '\0'; // gan ki tu cuoi cung cua chuoi tu bang '\0'

            // Split meaning - tach nghia
            strncpy(tmp_meaning, &line[i], strlen(line) - i + 1);
            // sao chep strlen(line) - i + 1 ki tu tu line sang tmp_meaning bat dau tu vi tri line[i]
            // Continuously read lines containing meaning => tiep tuc doc cac dong chua nghia
            // Read a line in dict file => doc mot dong o trong file dict
            linePtr = fgets(line, LINE_MAX_LEN, f);
            while (linePtr != NULL && line[0] != '@')
            {
                if (strlen(tmp_meaning) + strlen(line) > MEAN_MAX_LEN)
                {
                    sprintf(notify, "Meaning exceeded the maximum length. Word: %s\n", tmp_word);
                    printf("%s\n", notify);
                    exit(1);
                }
                strcat(tmp_meaning, line);
                // Read a line in dict file
                linePtr = fgets(line, LINE_MAX_LEN, f);
            }

            strcpy(word, tmp_word);       // copy tu tmp_word sang word
            strcpy(meaning, tmp_meaning); // copy tu tmp_meaning sang meaning
            strLower(wordLower, word);    // convert word to lower => chuyen sang chu thuong
            trim(wordLower);              // trim wordLower => loai bo dau cach o dau va cuoi

            if (bfndky(eng_vie, wordLower, &j) != 0) // ham bfndky la ham tim kiem khoa trong btree file
            {
                int result = btins(eng_vie, wordLower, meaning, strlen(meaning) * sizeof(char)); // Insert word to Btree => them tu vao B tree
                if (result == 0)
                {
		  //soundex_insert(word);
                    WordCount++; // Increase wordCount => tang bien dem
                }
            }
        }
    }
    fclose(f);
    // Ham sprintf() gan giong voi cac ham printf , fprintf nhung no khong in ra stdout , file ma no "in" vao chuoi
    sprintf(notify, "Loading done. %d words was loaded.", WordCount);
    printf("%s\n", notify);
    //free used memory => giai phong bo nho da su dung
    free(word);
    free(meaning);
    free(tmp_word);
    free(tmp_meaning);
    free(line);
    closeBT();
}
// ham getch( ) dung de nhan mot ki tu tu ban phim ma khong in ra man hinh
// trong ubuntu khong co thu vien conio.h nen ta dung ham ben duoi de thay the
char getch(void)
{
    char ch;
    int fd = fileno(stdin);
    struct termio old_tty, new_tty;
    ioctl(fd, TCGETA, &old_tty);
    new_tty = old_tty;
    new_tty.c_lflag &= ~(ICANON | ECHO | ISIG);
    ioctl(fd, TCSETA, &new_tty);
    fread(&ch, 1, sizeof(ch), stdin);
    ioctl(fd, TCSETA, &old_tty);

    return ch;
}

/*int SoundEx(char *strResult, char *chAlphaName)
{
    int i;
    int j = 0;
    char SCode = '0';
    char PrevCode = '0';
    char CharTemp = '0';

    for (i = 0; i < strlen(chAlphaName); i++)
    {
        chAlphaName[i] = tolower(chAlphaName[i]);
    }

    for (i = 0; (i < strlen(chAlphaName) && j < 4); i++)
    {
        CharTemp = chAlphaName[i];

        switch (CharTemp)
        {
        case 'r':
            SCode = '6';
            break;
        case 'm':
        case 'n':
            SCode = '5';
            break;
        case 'l':
            SCode = '4';
            break;
        case 'd':
        case 't':
            SCode = '3';
            break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            SCode = '2';
            break;
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            SCode = '1';
            break;
        default:
            SCode = '0';
            break;
        }

        if (SCode > '0' || j == 0)
        {
            //SCode la chu cai dau tien
            if (j == 0)
            {
                strResult[j] = chAlphaName[j];
                // strResult[j+1] = '\0';

                j++;
            }
            else if (SCode != PrevCode)
            {
                strResult[j] = SCode;
                //     strResult[j+1] = '\0';

                j++;
            }
        }

        if (CharTemp == 'h' || CharTemp == 'w')
        {
            SCode = PrevCode;
        }

        PrevCode = SCode;
        SCode = '0';
    }

    for (i = j; i < 4; i++)
    {
        strResult[i] = '0';
    }

    strResult[i] = '\0';
    return 4;
    }*/

// ham them tu vao cay thuat toan soundex
/*void soundex_insert(char *word)
{ //khai bao 1 BTA la soundex va create o bien toan cuc.
    char s[SIZE_MEAN1], soundEx[10];
    int i, k, h, l, rsize;
    //soundEx=(char*)malloc(10*sizeof(char));
    l = SoundEx(soundEx, word); //soudex tra ve do dai tu
    soundEx[l] = '\0';
    //s=(char*)malloc(SIZE_MEAN*sizeof(char));
    i = btsel(btSoundex, soundEx, s, SIZE_MEAN1, &rsize); //tim kem
    if (i != 0)
    {
        if (btins(btSoundex, soundEx, word, WORD_MAX_LEN) != 0)
            printf("Nhap soundex that bai!");
    }
    else // Tu y bo doan code else nay.
      {
        strcat(s, "\n");
        strcat(s, word);
        s[strlen(s)] = '\0';
        btupd(btSoundex, soundEx, s, SIZE_MEAN1);
      }
      }*/
// ham xoa theo thuat toan soundex
/*void soundex_delete(char *word)
{ //ham can dau vao tu tieng anh va jbr
    char s[SIZE_MEAN1], soundEx[10], *ptr;
    int l, i, rsize, j;
    l = SoundEx(soundEx, word);
    soundEx[l] = '\0';
    i = btsel(btSoundex, soundEx, s, SIZE_MEAN1, &rsize);
    if (i != 0)
    {
        printf("Da xoa tu va khong tim thay soundex!\n");
    }
    else
    {

        if (strcmp(s, word) == 0)
        {
            btdel(btSoundex, soundEx); //printf("Da xoa thanh cong!\n");
        }

        else
        {
            //s1=(char*)malloc(SIZE_MEAN*sizeof(char));
            ptr = strtok(s, "\n");
            //j=0;
            btdel(btSoundex, soundEx);
            while (ptr)
            {
                //printf("%s\n",ptr);
                if (strcmp(ptr, word) != 0)
                {
                    //printf("%s\t",ptr);
                    soundex_insert(ptr);
                }
                ptr = strtok(NULL, "\n");
            }
            free(ptr);
        }
    }
}
// ham tim kiem theo thuat toan soundex
int soundex_search(char *word, String string[])
{
    int l, bn, rsize, i;
    char en[SIZE_MEAN1], soundEx[10], *ptr;
    //soundEx=(char*)malloc(10*sizeof(char));
    l = SoundEx(soundEx, word);
    soundEx[l] = '\0';
    //en=(char*)malloc(SIZE_MEAN *sizeof(char));
    bn = btsel(btSoundex, soundEx, en, SIZE_MEAN1, &rsize);
    if (bn == 0)
    {
        printf("Y cua ban co phai la:\n");
        printf("%s\n", en);
        if (strcmp(en, word) == 0)
        {
            string[0].s = strdup(word);
            return 1;
        }
        else
        {
            ptr = strtok(en, "\n");
            i = 0;
            while (ptr)
            {
                string[i++].s = strdup(ptr);
                ptr = strtok(NULL, "\n");
            }
            free(ptr);
            return i;
        }
    }
    //free(soundEx);//free(en);
    return 0;
    }*/
// ham them tu vao tu dien
void insert()
{
    char word[30];
    char mean[MEAN_MAX_LEN];
    int i, rsize;
    printf("Nhap tu muon them:");
    fgets(word, MEAN_MAX_LEN, stdin); // ham nhap tu qua ham fgets() tu ban phim
    for (i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]); // ham tolower dung de bien chu hoa thanh chu thuong
    word[strlen(word) - 1] = '\0';  // bo ki tu cuoi cung va bien no thanh NULL
    if (btsel(eng_vie, word, mean, MEAN_MAX_LEN, &rsize) == 0)
    {
        // ham btsel dinh vi va tra ve ban ghi du lieu cua mot khoa hien co trong tep
        printf("Da co \'%s\' trong tu dien!\n", word);
    }
    else
    {
        printf("Nhap nghia cua tu:");
        fgets(mean, MEAN_MAX_LEN, stdin); // ham nhap nghia cua tu qua ham fgets()
        mean[strlen(mean) - 1] = '\0';
        btins(eng_vie, word, mean, MEAN_MAX_LEN); // insert tu nay vao tu dien
	// soundex_insert(word);
        printf("Da them tu \'%s\' thanh cong!\n", word);
    }
}
// ham tim kiem tong hop
void search_full()
{
    char *word, mean[MEAN_MAX_LEN];
    int i, j, k, n, rsize;
    char c;
    String *string;
    // 27 : ESC ; 127 : DEL
    word = (char *)malloc(sizeof(char) * WORD_MAX_LEN);
    //mean=(char*)malloc(sizeof(char)*SIZE_MEAN);
    string = (String *)malloc(sizeof(String) * 1000);
    printf("Nhap tu can tim: ");
    j = 0;
    i = 0;
    while (1)
    {
        c = tolower(getch()); // chuyen ve chu thuong
        if (c != '\n' && c != 127 && c != '\t' && c != 27)
        {
            word[j++] = c;
            putchar(c);
            i = 0;
        }
        if (c == '\t')
        { // neu nhap vao ki tu tab
            if (j != 0)
            {
                if (i == 0)
                {
                    word[j] = '\0';
                    free(string);
                    string = (String *)malloc(sizeof(String) * 1000);
                    n = search_tab(word, string);
                    if (n != 0)
                    {
                        for (k = 0; k < j; k++)
                        {
                            putchar('\b');       // in ra dau Backspace
                            printf("%c[0K", 27); // in ki tư ESC
                        };
                        free(word);
                        word = (char *)malloc(sizeof(char) * WORD_MAX_LEN);
                        strcpy(word, string[i].s);
                        //j=0;
                        for (k = 0; k < strlen(word); k++)
                        {
                            putchar(word[k]);
                        }
                        j = strlen(word);
                        i++;
                    }
                }
                else
                {
                    for (k = 0; k < strlen(word); k++)
                    {
                        putchar('\b');       // in ra dau Backspace
                        printf("%c[0K", 27); // ki tu ESC
                    }
                    if (i == n)
                        i = 0; //tim den tu cuoi cung
                    free(word);
                    word = (char *)malloc(sizeof(char) * WORD_MAX_LEN);
                    strcpy(word, string[i].s);
                    //j=0;
                    for (k = 0; k < strlen(word); k++)
                    {
                        //e=word[k];
                        putchar(word[k]);
                        //j++;
                    }
                    j = strlen(word);
                    i++;
                }
            }
        }
        if (c == 127)
        { // nhap ki tu del
            if (j > 0)
            {
                putchar('\b');
                printf("%c[0K", 27);
                word[j--] = '\0'; // xoa bot 1 ki tu
                i = 0;
            }
        }
        if (c == '\n')
        { // nhap ki tu xuong dong
            printf("\n");
            word[j] = '\0';
            if (btsel(eng_vie, word, mean, WORD_MAX_LEN, &rsize) == 0)
            {
                // xac dinh du lieu cua khoa co san - tra ve record(ban ghi) cua key ton tai
                printf("Nghia cua tu \'%s\' la:\n %s\n", word, mean);
            }
            else
            {
                printf("Khong co tu \'%s\' trong tu dien.\n", word);
                free(string);
                string = (String *)malloc(sizeof(String) * 1000);
		// i = soundex_search(word, string);
                //if (i != 0); //search(root,btSoundex);
                            //  search_full(root,btSoundex);
                    // search_soundex(string, i);
            }
            free(string);
            free(word);
            break;
        }
    }
}

// ham ho tro tim kiem thong qua ki tu tab
int search_tab(char *word, String *output)
{
    /*
  - cac tu do duoc luu trong output
  - ham tra ve 1 gia tri nguyen
    . -1: neu tim thay tu word trong tu dien
      total: so luong tu co phan dau trung voi word
  */
    int result, total = 0, value;
    char key[50];
    result = bfndky(eng_vie, word, &value); //tim kiem khoa
    if (result == 0)
    {                                     //neu tim thay
        output[total++].s = strdup(word); // cho tu viet hoa vao mang output
    }
    while (1)
    {
        result = bnxtky(eng_vie, key, &value); //tim kiem khoa tiep theo
        if (result != 0 || strncmp(key, word, strlen(word)) != 0)
            break;
        output[total++].s = strdup(key); //luu khoa tim thay vao output
        if (total == 1000)
            break;
    }
    return total;
}

void delete ()
{
    char word[50];
    char mean[MEAN_MAX_LEN];
    int re, i, rsize;
    printf("Nhap tu muon xoa:");
    fgets(word, WORD_MAX_LEN, stdin);
    word[strlen(word) - 1] = '\0';
    for (i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]); // chuyen tu thanh viet thuong
    re = btdel(eng_vie, word);      // xoa tu do trong btree
    if (re == 0)
    {
        printf("Da xoa \'%s\' thanh cong!\n", word);
	// soundex_delete(word);
    }
    else
        printf("Khong co \'%s\' trong tu dien!\n", word);
}
