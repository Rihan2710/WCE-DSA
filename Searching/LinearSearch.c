#include <stdio.h>
int search(int array[], int element, int size);
int main()
{
    int array[] = {4, 6, 2, 5, 1};
    int size = sizeof(array) / sizeof(array[0]);

    int x = 2;

    int result = search(array, x, size);

    if (result != -1)
        printf("Element found at index: %d", result);
    else
        printf("Not found");
}
int search(int *array, int element, int size)
{
    for (int i = 0; i < size; i++)
        if (array[i] == element)
            return i;
    return -1;
}