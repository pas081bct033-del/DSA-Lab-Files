#include <stdio.h>
//binary search function
int SEARCH(int ARR[], int LB, int UB, int ITEM) {
    int BEG = LB, END = UB, MID, LOC = -1;

    MID = (BEG + END) / 2;

    while (BEG <= END && ARR[MID] != ITEM) {
        if (ITEM < ARR[MID])
            END = MID - 1;
        else
            BEG = MID + 1;

        MID = (BEG + END) / 2;
    }

    if (ARR[MID] == ITEM)
        LOC = MID;
    else
        LOC = -1;

    return LOC;
}

int main() {
    int ARR[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(ARR)/sizeof(ARR[0]);
    int ITEM = 10;

    int pos = SEARCH(ARR, 0, n-1, ITEM);

    if (pos != -1)
        printf("Item found at index %d\n", pos);
    else
        printf("Item not found\n");

    return 0;
}
