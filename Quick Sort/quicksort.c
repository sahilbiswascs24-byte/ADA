#include <stdio.h>

int partition(int a[], int low, int high);
void Quick_Sort(int a[], int low, int high);

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[20];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Quick_Sort(a, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void Quick_Sort(int a[], int low, int high) {
    int p;
    if (low < high) {
        p = partition(a, low, high);
        Quick_Sort(a, low, p - 1);
        Quick_Sort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int i, j, temp, pivot;

    pivot = a[low];
    i = low + 1;
    j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
