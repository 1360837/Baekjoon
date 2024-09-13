#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int cnt[26] = { 0 };
	char input[1000000];
	int input_num;
	int maxidx = 0;

	gets(input);

	for (int i = 0; input[i] != NULL; i++)
	{
		input_num = toupper(input[i]) - 'A';
		cnt[input_num]++;
		if (cnt[maxidx] < cnt[input_num])
			maxidx = input_num;
	}

	for (int i = 0; i < 26; i++)
	{
		if (i == maxidx) continue;
		if (cnt[i] == cnt[maxidx])
		{
			printf("?");
			return 0;
		}
	}

	printf("%c", maxidx + 'A');

	return 0;
}