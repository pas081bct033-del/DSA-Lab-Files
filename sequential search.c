#include <stdio.h>
#define max 100
// Sequential Search Function
int LSEARCH(int ARR[], int N, int ITEM) {
    int position = -1; 
    for (int index = 0; index < N; index++) {
        if (ARR[index] == ITEM) {
            position = index + 1; 
            break;                // Stop once found
        }
    }
return position;
}

int main() {
    int N, ITEM;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int ARR[max]; 
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ARR[i]);
    }
    printf("Enter item to search: ");
    scanf("%d", &ITEM);
    int LOC = LSEARCH(ARR, N, ITEM);
    if (LOC == -1)
        printf("Search Result: Item not found\n");
    else
        printf("Search Result: Item found at position %d\n", LOC);
    return 0;
}
