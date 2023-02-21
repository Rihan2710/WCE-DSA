#include <stdio.h>

int gcd(int a, int b);
int main() 
{
    int n1, n2;
    printf("Enter two positive integers : ");
    scanf("%d %d", &n1, &n2);
    printf("GCD of %d and %d is : %d.", n1, n2, gcd(n1, n2));
    return 0;
}

int gcd(int a, int b)
{
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}