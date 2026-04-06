#ifdef TASK2
#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)
#include <stdio.h>
void main(void)
{
	// Эксперимент с int
    printf("=== int ===\n");
    int mas[] = { 100, 200, 300 };
    int *ptr1, *ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);

    // Эксперимент с char
    printf("\n=== char ===\n");
    char mas_char[] = { 'a', 'b', 'c'};
    char* ptr_char1 = mas_char;
    char* ptr_char2 = &mas_char[2];
	PR(ptr_char1);
	ptr_char1++;
	PR(ptr_char1);
	PR(ptr_char2);
	++ptr_char2;
    printf("ptr_char2 - ptr_char1 = %d\n\n", ptr_char2 - ptr_char1);

    // Эксперимент с double
    printf("\n=== double ===\n");
    double mas_double[] = { 100.0, 200.0, 300.0 };
    double* ptr_double1 = mas_double;
    double* ptr_double2 = &mas_double[2];
	PR(ptr_double1);
	ptr_double1++;
	PR(ptr_double1);
	PR(ptr_double2);
	++ptr_double2;

    printf("ptr_double2 - ptr_double1 = %d\n", ptr_double2 - ptr_double1);

}
#endif
