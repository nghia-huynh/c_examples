/* Examples on function pointers */

#include <stdio.h>

/* BASIC FUNCTION POINTER SYNTAX
-----------------------------------------------------------------------------*/
int a = 5;
int b = 18;

int add (int a, int b) { return a + b; }

/* 2 ways to assigne value to function pointers */
int (*f_pt1)(int, int) = add;
int (*f_pt2)(int, int) = &add;

void demo1() {
    printf("add(%d,%d) = %d\n", a, b, add(a,b));

    /* 2 ways to call a function pointer*/
    printf("f_pt1(%d,%d) = %d\n", a, b, f_pt1(a,b));
    printf("(*f_pt1)(%d,%d) = %d\n", a, b, (*f_pt1)(a,b));
    printf("f_pt2(%d,%d) = %d\n", a, b, f_pt2(a,b));
    printf("(*f_pt2)(%d,%d) = %d\n", a, b, (*f_pt2)(a,b));
}

/* CLEANER FUNCTION POINTER DECLARATION WITH TYPEDEF
-----------------------------------------------------------------------------*/
char str[] = "abcdef";
char ch = 'e';
/* return pt to a char = ch in str if exists, otherwise 0 */
char *find_char(char* str, char ch) {
    char *result = str;
    while (*result != 0 && *result != ch) { result++; }
    return result;
}

/* Declaring function ptr without and with typedef */
char *(*f_pt3) (char*, char) = find_char;

typedef char *(*f_pt_type) (char*, char);
f_pt_type f_pt4 = find_char;

void demo2() {
    printf("find_char(\"%s\",%c) = x%lx\n", str, ch, (long) find_char(str,ch));
    printf("f_pt3(\"%s\",%c) = x%lx\n", str, ch, (long) f_pt3(str,ch));
    printf("f_pt4(\"%s\",%c) = x%lx\n", str, ch, (long) f_pt4(str,ch));
}

/*---------------------------------------------------------------------------*/
int main (int argc, char* argv[]) {
    demo1();
    printf("-----\n");
    demo2();
    return 0;
}
