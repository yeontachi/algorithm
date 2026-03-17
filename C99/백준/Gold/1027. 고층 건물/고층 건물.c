#include <stdio.h>
#include <math.h>

double gradient(int x1, int y1, int x2, int y2){
    return (double)(y2 - y1) / (x2 - x1);
}
int main(void){
    int N;
    scanf("%d", &N);

    int building[55];

    for(int i = 0; i < N; i++){
        scanf("%d", &building[i]);
    }

    int count[55]={0, };

    for(int i=0; i<N; ++i){
        double max_slope = -9999999999.0;
        for(int j=i+1; j<N; ++j){
            double current_slope = gradient(i, building[i], j, building[j]);

            if(j == i+1 || current_slope > max_slope){
                count[i]++;
                count[j]++;
                max_slope = current_slope;
            }
        }
    }

    int max = 0;
    for(int i=0; i<N; ++i){
        if(count[i] > max){
            max = count[i];
        }
    }

    printf("%d", max);
}