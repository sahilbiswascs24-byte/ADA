#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print the permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Function to find the largest mobile element
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {

        // Check left direction
        if (dir[i] == LEFT && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        // Check right direction
        if (dir[i] == RIGHT && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Johnson-Trotter Algorithm
void johnsonTrotter(int n) {
    int perm[n], dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    // Print first permutation
    printPermutation(perm, n);

    while (1) {

        // Find largest mobile element
        int mobileIndex = getMobile(perm, dir, n);

        // If no mobile element, stop
        if (mobileIndex == -1)
            break;

        int swapIndex;

        // Determine swap position
        if (dir[mobileIndex] == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        // Swap permutation elements
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        // Swap directions
        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;

        // Reverse direction of all elements larger than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[mobileIndex]) {
                dir[i] = -dir[i];
            }
        }

        // Print next permutation
        printPermutation(perm, n);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
