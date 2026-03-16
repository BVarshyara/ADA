#include <stdio.h>
int gcd(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int a, b, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    result = gcd(a, b);
    printf("GCD of %d and %d is %d\n", a, b, result);
    return 0;
}
