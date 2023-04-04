#include <stdio.h>
#include <stdlib.h>

int N, *time, *price;

void dfs(int date, int sum, int *max)
{
    int tem;
    if (date >= N) {
        if (sum > *max) *max = sum;
        return ;
    }
    for (int i = date ; i < N ; i++) {
        tem = sum;
        if (i + time[i] <= N) tem += price[i];
        dfs(i + time[i], tem, max);
    }
}

int main(void)
{
    int max = 0;
    scanf("%d", &N);
    time = malloc(sizeof(int) * N);
    price = malloc(sizeof(int) * N);
    for (int i = 0 ; i < N ; i++) scanf("%d %d", &time[i], &price[i]);
    dfs(0, 0, &max);
    printf("%d\n", max);
    free(time);
    free(price);
}