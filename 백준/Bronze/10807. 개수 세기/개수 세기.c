#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, data;
	int cnt[201] = { 0 };

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		cnt[data+100] += 1;
	}

	scanf("%d", &data);
	printf("%d", cnt[data+100]);

	return 0;
}