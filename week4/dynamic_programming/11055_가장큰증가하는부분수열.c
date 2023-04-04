#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int n, *seq, *max, i, j, out = 0;
		scanf("%d", &n);
		seq = malloc(sizeof(int) * n);
		max = malloc(sizeof(int) * n);
		for (i = 0 ; i < n ; i++) scanf("%d", (seq+i));
		max[0] = seq[0];
		out = max[0];
		for (i = 1 ; i < n ; i++) {
				max[i] = seq[i];
				for (j = 0 ; j < i ; j++) {
						if (seq[j] < seq[i] && max[i] < seq[i] + max[j])
								max[i] = seq[i] + max[j];
				}
				if (out < max[i]) out = max[i];
		}
		printf("%d", out);
		free(seq);
		free(max);
}