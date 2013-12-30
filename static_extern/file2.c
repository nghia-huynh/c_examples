#include <stdio.h>
#include "file1.h"

static int x = 20;

void f2_printx() { printf("f2.x = %d\n", x); }
void f2_printy() { printf("f2.y = %d\n", y); }

int main(int argc, char* argv[]) {
    printf("static int x;\n");
    printf("extern int y;\n");

    printf("Inside f2\n");
    f1_printx();
    f2_printx();

    f1_printy();
    f2_printy();
    printf("assign y = 40;\n");
    y = 40;
    f1_printy();
    f2_printy();

    return 0;
}
