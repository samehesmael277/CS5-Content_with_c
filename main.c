#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// /********** phonebook cs50 week 3 phonebook **********\

typedef struct {
    char* name;
    char* number;
}emp;

int phonebook(void) {
    emp Employee[2];
    Employee[0].name = "sameh";
    Employee[0].number = "011155";
    Employee[1].name = "ahmed";
    Employee[1].number = "01224";

    for(int i = 0; i < 2; i++) {
        if(strcmp(Employee[i].name, "sameh") == 0) {
            printf("found : %s ", Employee[i].number);
            return 0;
        }
    }
    printf("Not founded\n");
    return 1;
}

// /********** [week3 recursion 1 **********\

void rec(int x) {
    if(x == 0)
        return;
    printf("Sameh\n");
    rec(x-1);
}

void draw(int n) {
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            printf("#");
        }
        printf("\n");
    }
}

void draw2(int n) {
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < i + 1; y++) {
            printf("#");
        }
        printf("\n");
    }
}

void rec2(int x) {
    if (x <= 0)
        return;
    rec(x - 1);
    for (int i = 0; i < x; i++) {
        printf("#");
    }
    printf("\n");
}

// /********** [week4 | string **********\

typedef char * string;
void strFun() {
    int x = 50;
    int *p = &x;
    printf("%i \n", x);
    printf("%p \n", p);
    printf("%i \n", *p);
    printf("%i \n", *&x);

    string s = "sameh";   // = char *s = "sameh";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
}

// /********** week4 | Pointer Arithmetic **********\

// typedef char * string;

void pa() {
    string s = "sameh";   // = char *s = "sameh";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("%c\n", *(s+3));
    printf("%c\n", *(s+4));
}

// /********** week4 | malloc & free & valgrind **********\

void malloc_free_valgrind() {
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);
    if(t == NULL)
        return 1;

    /*
        for(int i = 0; i < (strlen(s) + 1); i++) {
        t[i] = s[i];
    }
    */

    strcpy(t,s);

    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}

// /********** week4 | swap **********\

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void call_swap() {
    int x = 10;
    int y = 20;
    swap(&x,&y);

    printf("x = %i\n", x);
    printf("y = %i\n", y);
}

// /********** week4 | file in c **********\

void files() {
    FILE *myFile = fopen("text.csv","a");
    char* a = get_string("name: ");
    char* b = get_string("number: ");

    fprintf(myFile, "%s, %s\n", a, b);
    fclose(myFile);
}

// /********** week4 | jpegcheck if photo is jpeg **********\

void checkjpeg(int argc, char* argv[]) {
    if (argc != 2) {
        return;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }
    unsigned char c [3];
    fread(c, 1, 3, file);
    if (c[0] == 0xff && c[1] == 0xd8 && c[2] == 0xff) {
        printf("Yes, maybe jpeg\n");
    }
    else {
        printf("No, jpeg\n");
    }
    fclose(file);
}

int main() {

}
