#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void){
    int width, height, numCuts;

    scanf("%d %d", &width, &height);
    scanf("%d", &numCuts);

    int *horizontalCuts = (int *)calloc(numCuts, sizeof(int));
    int *verticalCuts = (int *)calloc(numCuts, sizeof(int));
    int hcnt = 0, vcnt = 0;

    for(int i=0; i<numCuts; i++){
        int type, pos;
        scanf("%d %d", &type, &pos);

        if(type==0) horizontalCuts[hcnt++]=pos;
        else if(type==1) verticalCuts[vcnt++]=pos;
    }

    sort(horizontalCuts, hcnt);
    sort(verticalCuts, vcnt);

    int *horizontalSizes = (int *)malloc((hcnt + 1)*sizeof(int));
    int *verticalSizes = (int *)malloc((vcnt + 1)*sizeof(int));

    int prev=0, idx=0;
    
    for(int i=0; i<hcnt; i++){
        horizontalSizes[idx++] =horizontalCuts[i]-prev;
        prev = horizontalCuts[i];
    }
    horizontalSizes[idx++]=height-prev;

    prev = 0;
    idx = 0;
    for (int i = 0; i < vcnt; i++) {
        verticalSizes[idx++] = verticalCuts[i] - prev;
        prev = verticalCuts[i];
    }
    verticalSizes[idx++] = width - prev; 

    sort(horizontalSizes, hcnt + 1);
    sort(verticalSizes, vcnt + 1);

    int maxHorizontal = horizontalSizes[hcnt];
    int maxVertical = verticalSizes[vcnt];

    printf("%d\n", maxHorizontal * maxVertical);

    free(horizontalCuts);
    free(verticalCuts);
    free(horizontalSizes);
    free(verticalSizes);

    return 0;
}