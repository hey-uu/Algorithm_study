#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int n, *seq, *max, i, out, *sum;
		scanf("%d", &n);
    seq = malloc(sizeof(int) * n);
    max = malloc(sizeof(int) * n);
    sum = malloc(sizeof(int) * n);
    for (i = 0 ; i < n ; i++) {
		    scanf("%d", &seq[i]);
    }
    if (seq[0] > 0) sum[0] = seq[0];
    else sum[0] = 0;
    max[0] = seq[0];
    out = seq[0];
    for (i = 1 ; i < n ; i++) {
				max[i] = seq[i];
        if (max[i-1] > 0)
		        max[i] += max[i-1];
            sum[i] = seq[i] + sum[i-1];
        if (seq[i] < 0) {
		        if (sum[i] < max[i-1])
		            sum[i] = max[i-1];
        }
        if (max[i] > out) out = max[i];
        if (sum[i] > out) out = sum[i];
    }
    printf("%d\n", out);
    free(seq);
    free(max);
    free(sum);
}