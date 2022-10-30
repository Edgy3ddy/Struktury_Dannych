//Tablica...
//2022-10-25
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find(int item, int *arr, int s);
void insert(int item, int pos, int **arr, int *size);
int remove_a(int pos, int **arr, int *size);
int findMax(int *arr, int size);
int findMin(int *arr, int size);
int size(int s);

int main()
{
        int *arr, i, s, item, pos, n;

        printf("eneter array size: ");

        scanf("%d", &s);

        arr = calloc(s, sizeof(int));

        for (i = 0; i < s; i++) {
                printf("enter arrays %dth element: ", i + 1);
                scanf("%d", &arr[i]);
        }

        printf("Insert number: \n");
        scanf("%d", &item);
        printf("Enter index: \n");
        scanf("%d", &pos);

        insert(item, pos, &arr, &s);

        printf("item search: enter item: \n");

        scanf("%d", &item);

        printf("found element at index; %d \n",find(item, arr, s));

        printf("enter pos to delete: \n");
        scanf("%d", &pos);

        remove_a(pos, &arr, &s);

        size(s);

        printf("largest element: %d \n", findMax(arr, s));
        printf("smallest element: %d \n", findMin(arr, s));

        for(i = 0; i < s; i++)
                printf("%d\n", arr[i]);

        return 0;
}
int find(int item, int *arr, int s)
{

        for (int i = 0; i < s; i++) {
                if (arr[i] == item) {
                        return i;
                }
        }
        return -1;

}
void insert(int item, int pos, int **arr, int *size)
{
        int i;
        *arr = realloc(*arr, (*size + 1) * sizeof(int));

        for (i = *size - 1; i >= pos - 1; i--) {
                (*arr)[i + 1] = (*arr)[i];
        }
        (*size)++;
        (*arr)[i + 1] = item;
}
int remove_a(int pos, int **arr, int *size)
{
        int i;

        for (i = pos-1; i <= *size-1; i++) {
                (*arr)[i] = (*arr)[i + 1];
        }
        *arr = realloc(*arr, (*size - 1) * sizeof(int));
        (*size)--;
}
int findMax(int *arr, int s)
{
        int max = INT_MIN;
        for(int i = 0; i < s; i++){
                if (arr[i] > max) {
                        max = arr[i];
                }
        }
                return max;
}
int findMin(int *arr, int s)
{
        int min = INT_MIN;
        for(int i = 0; i < s; i++){
                if (arr[i] < min) {
                        min = arr[i];
                }
        }
                return min;
}
int size(int size)
{ 
        return size;
}

