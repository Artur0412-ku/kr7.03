#include <stdio.h>
#include <stdlib.h>

void sort_odd_positions_desc(int *arr, int size) {
    int *odd_arr = malloc((size / 2) * sizeof(int));
    int odd_index = 0;

    // Copy odd elements into a new array
    for (int i = 1; i < size; i += 2) {
        odd_arr[odd_index++] = arr[i];
    }

    // Sort odd elements in descending order
    for (int i = 0; i < odd_index - 1; i++) {
        for (int j = i + 1; j < odd_index; j++) {
            if (odd_arr[i] < odd_arr[j]) {
                int temp = odd_arr[i];
                odd_arr[i] = odd_arr[j];
                odd_arr[j] = temp;
            }
        }
    }

    // Copy sorted odd elements back into the original array
    odd_index = 0;
    for (int i = 1; i < size; i += 2) {
        arr[i] = odd_arr[odd_index++];
    }

    free(odd_arr);
}

int main() {
    int arr[] = {4, 3, 6, 7, 1, 8, 2, 5};
    int size = sizeof(arr) / sizeof(int);

    sort_odd_positions_desc(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
