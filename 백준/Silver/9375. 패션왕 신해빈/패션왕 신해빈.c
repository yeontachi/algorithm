#include <stdio.h>
#include <string.h>

#define MAX 31

typedef struct {
    char type[21];
    int count;
} Clothing;

int main() {
    int t;
    scanf("%d", &t); // 테스트 케이스 수 입력

    while (t--) {
        int n;
        scanf("%d", &n); // 의상의 수 입력

        Clothing clothes[MAX];
        int types = 0; // 의상 종류의 개수

        for (int i = 0; i < n; i++) {
            char name[21], type[21];
            scanf("%s %s", name, type);

            // 의상 종류 찾기
            int found = 0;
            for (int j = 0; j < types; j++) {
                if (strcmp(clothes[j].type, type) == 0) {
                    clothes[j].count++;
                    found = 1;
                    break;
                }
            }

            // 새로운 의상 종류라면 추가
            if (!found) {
                strcpy(clothes[types].type, type);
                clothes[types].count = 1;
                types++;
            }
        }

        // 경우의 수 계산
        int result = 1;
        for (int i = 0; i < types; i++) {
            result *= (clothes[i].count + 1); // 의상을 입지 않는 경우 포함
        }
        result -= 1; // 알몸인 경우 제외

        printf("%d\n", result);
    }

    return 0;
}