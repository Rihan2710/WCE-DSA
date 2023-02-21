#include <stdio.h>

void twoh(int n, char source, char destination, char auxillary)
{
    if(n==1)
    {
        printf("Moved %d from %c to %c \n",n,source,destination);
    }
    else
    {
        twoh(n-1,source,auxillary,destination);
        printf("Moved %d from %c to %c \n",n,source,destination);
        twoh(n-1,auxillary,destination,source);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    twoh(n,'A','B','C');
    return 0;
}