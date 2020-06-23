#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void GetArrayFromInput(int *arr, int n);

void SortArray(int *arr, int n);

bool BubbleSort(int *arr, int n);

void Swap(int *a, int *b);

void PrintTheSorted(int *arr, int n);

bool FindSum(int* arr, int n, int sum);

void PrintLength();

void PrintArray();

void PrintSum();

void PrintExist();

void PrintDoNotExist();

int main() {
    PrintLength();
    int n = 0;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    if (!arr) {
        // Allocation error
        return 0;
    }

    PrintArray();
    GetArrayFromInput(arr, n);
    SortArray(arr, n);
    //PrintTheSorted(arr, n);
    PrintSum();
    int sum = 0;
    scanf("%d", &sum);
    bool sum_exists = false;
    sum_exists = FindSum(arr, n, sum);
    if (sum_exists) {
        PrintExist();
    } else {
        PrintDoNotExist();
    }

    free(arr);

    return 0;
}

/**
 * Checks if an input sum is available from 3 different elements in the array
 * @param arr The array
 * @param n The array length
 * @param sum The sum to check
 * @return True if the sum exists, false otherwise
 */
bool FindSum(int* arr, int n, int sum) {
    int left;
    int right;
    for (int i = 0; i < n - 2; ++i) {
        left = i+1;
        right = n-1;
        while (left < right) {
            if (arr[i] + arr[left] + arr[right] == sum) {
                return true;
            } else if (arr[i] + arr[left] + arr[right] > sum) {
                right = right - 1;
            } else {
                left = left + 1;
            }
        }
    }
    return false;
}

/**
 * Fills an array with given length with values from stdin
 * @param arr The array to fill
 * @param n The length of the array
 */
void GetArrayFromInput(int *arr, int n) {
    int i = 0;
    int current = 0;
    while (i < n) {
        scanf("%d", &current);
        arr[i] = current;
        i++;
    }
}

/**
 * Performs a bubble sort on an input array
 * @param arr The array to sort
 * @param n The size of the array
 */
void SortArray(int *arr, int n) {
    bool not_sorted = true;
    while (n > 1 && not_sorted) {
        not_sorted = BubbleSort(arr, n--);
    }
}

/**
 * Performs a bubble sort iteration on the input array
 * @param arr The array to sort
 * @param n The size of the current portion of the array to sort
 * @return True if sorting was performed in this iteration, false otherwise
 */
bool BubbleSort(int *arr, int n) {
    int swap_performed = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) {
            Swap(&arr[i], &arr[i - 1]);
            swap_performed = 1;
        }
    }

    return swap_performed;
}

/**
 * Swaps two integer values between pointers
 * @param a The first value
 * @param b The second value
 */
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Prints an array
 * @param arr The array to print
 * @param n The size of the array
 */
void PrintTheSorted(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void PrintLength() {
    printf("Please enter length:\n");
}

void PrintArray() {
    printf("Please enter array:\n");
}

void PrintSum() {
    printf("Please enter sum:\n");
}

void PrintExist() {
    printf("Such elements do exist.");
}

void PrintDoNotExist() {
    printf("Such elements do not exist.");
}
