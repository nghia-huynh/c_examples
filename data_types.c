/* data types in C */
#include <stdio.h>
#include <stdint.h>

/* Basic data types */
void print_basic_size() {
    printf("Size of basic C datatypes in unit of byte(s):\n");
    printf(" - char\t\t= %ld\n", sizeof(char));
    printf(" - short\t= %ld\n", sizeof(short));
    printf(" - int\t\t= %ld\n", sizeof(int));
    printf(" - long\t\t= %ld\n", sizeof(long));
    printf(" - float\t= %ld\n", sizeof(float));
    printf(" - double\t= %ld\n", sizeof(double));
    printf(" - pointer\t= %ld\n", sizeof(void*));
}

/* Type casting */
void type_cast() {
    int a = 42;
    printf("Type cast:\n");
    printf(" - sizeof(a) = %ld\n - sizeof((long) a) = %ld\n",
           sizeof(a),sizeof((long) a));
}

/* stdint.h */
#define size(N)  sizeof(int##N##_t) /* ## : concat */
#define usize(N) sizeof(uint##N##_t)
#define max(N)   INT##N##_MAX
#define min(N)   INT##N##_MIN
#define umax(N)  UINT##N##_MAX

void stdint_summary() {
    printf("Summary of types in stdint.h\n");
    printf("|  Types   |Size(B)|    MAX   |    MIN    |\n");
    printf("----------------------------------------\n");
    printf("|%9s |%6ld |%9d |%10d |\n","int8_t",size(8),max(8),min(8));
    printf("|%9s |%6ld |%9d |%10d |\n","uint8_t",usize(8),umax(8),0);
    printf("|%9s |%6ld |%9d |%10d |\n","int16_t",size(16),max(16),min(16));
    printf("|%9s |%6ld |%9d |%10d |\n","uint16_t",usize(16),umax(16),0);
    printf("|%9s |%6ld | %.2e | %.2e |\n","int32_t",size(32),(double)max(32),(double)min(32));
    printf("|%9s |%6ld | %.2e | %9.2e |\n","uint32_t",usize(32),(double)umax(32),(double)0);
    printf("|%9s |%6ld | %.2e | %.2e |\n","int64_t",size(64),(double)max(64),(double)min(64));
    printf("|%9s |%6ld | %.2e | %9.2e |\n","uint64_t",usize(64),(double)umax(64),(double)0);
    
}


int main (int argc, char* argv[]) {
    print_basic_size();
    printf("-----\n");
    type_cast();
    printf("-----\n");
    stdint_summary();
    return 0;
}
