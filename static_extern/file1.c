/* file1.c */

#include <stdio.h>
#include "file1.h"

static int x = 10;
int y = 30;

void f1_printx() { printf("f1.x = %d\n", x); }
void f1_printy() { printf("f1.y = %d\n", y); }

