#include <stdio.h>
#include <stdlib.h>

int ft_min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int main(void)
{
    int N, *cost, *min, res;
    scanf("%d", &N);
    cost = malloc(sizeof(int) * N * 3);
    min = malloc(sizeof(int) * N * 3);
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < 3 ; j++)
            scanf("%d", &cost[i*3+j]);
    for (int i = 0 ; i < 3 ; i++) min[i] = cost[i];
    for (int i = 1 ; i < N ; i++) {
        min[i*3] = ft_min(min[(i-1)*3+1], min[(i-1)*3+2]) + cost[i*3];
        min[i*3+1] = ft_min(min[(i-1)*3], min[(i-1)*3+2]) + cost[i*3+1];
        min[i*3+2] = ft_min(min[(i-1)*3], min[(i-1)*3+1]) + cost[i*3+2];
    }
    res = min[(N-1)*3];
    if (res > min[(N-1)*3+1]) res = min[(N-1)*3+1];
    if (res > min[(N-1)*3+2]) res = min[(N-1)*3+2];
    printf("%d\n", res);
    free(min);
    free(cost);
}