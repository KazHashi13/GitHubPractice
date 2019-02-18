#include <stdio.h>


int partition (int *arr, int left, int right){
    int pi;
    int pivot = arr[right];
    int i, j;
    int placeholder;

    j = left-1;

    for (i = left; i < right; i++){
        if(arr[i] <= pivot){
            j++;
            placeholder = arr[i];
            arr[i] = arr[j];
            arr[j] = placeholder;
        }
    }

    j++;
    arr[right] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(int *arr, int left, int right) {

    if(left < right) {

        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
    
    return;
}

int main(){
    int num;
    int val, i;
    int arr[0xffff];

    do {
        printf("Enter number of elements (2-10): \n");
        scanf("%d", &num);
    } while (num > 10 || num < 2);

    for (i = 0; i < num; i++){
        printf("Enter value for element number %d: ", i+1);
        scanf("%d", &val);
        arr[i] = val;
    }

    quickSort(arr, 0, num-1);

    printf("sorted array: ");
    for (i = 0; i < num-1; i++){
        printf("%d, ", arr[i]);
    }

    printf("%d", arr[num-1]);

    return 0;
}