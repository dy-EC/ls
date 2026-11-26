/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int* successfulPairs(int* spells,
                     int spellsSize,
                     int* potions,
                     int potionsSize,
                     long long success,
                     int* returnSize) {
    // //排序
    // for(int i=0;i<potionsSize;i++)
    // {
    //     for(int j=i+1;j<potionsSize;j++)
    //     {
    //         if(potions[i]>potions[j])
    //         {
    //             int t=potions[i];
    //             potions[i]=potions[j];
    //             potions[j]=t;
    //         }
    //     }
    // }

    qsort(potions, potionsSize, sizeof(int), cmp);

    int* arr = (int*)malloc(spellsSize * sizeof(int));
    *returnSize = spellsSize;

    for (int i = 0; i < spellsSize; i++) {
        // long long axx[100000]={0};
        // for(int j=0;j<potionsSize;j++)
        // {
        //     axx[j]=potions[j]*spells[i];
        // }
        if (success % spells[i]) {
            long long xxxsuccess = success / spells[i] + 1;
            int left = 0;
            int right = potionsSize - 1;
            while (left <= right) {
                int n = left + (right - left) / 2;
                if (potions[n] < xxxsuccess) {
                    left = n + 1;
                } else {
                    right = n - 1;
                }
            }
            arr[i] = potionsSize - left;
        } else {
            long long xxxsuccess = success / spells[i];
            int left = 0;
            int right = potionsSize - 1;
            while (left <= right) {
                int n = left + (right - left) / 2;
                if (potions[n] < xxxsuccess) {
                    left = n + 1;
                } else {
                    right = n - 1;
                }
            }
            arr[i] = potionsSize - left;
        }
    }
    return arr;
}