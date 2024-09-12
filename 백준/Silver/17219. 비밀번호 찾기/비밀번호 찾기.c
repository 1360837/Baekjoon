#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define STRING_SIZE 21
# define MAX_HASH_TABLE 100

typedef struct node * nodePointer;
typedef struct node
{
	char	site[STRING_SIZE];
	char	password[STRING_SIZE];
	nodePointer link;
}node;
nodePointer	hash_table[MAX_HASH_TABLE] = {NULL};

int	hashF(char *site);
void	insert(char *site, char *password);
char	*find(char *site);

int	hashF(char *site)
{
	unsigned int	h;

	h = 0;
	while (*site)
	{
		h += (h * 11) + (*site);
		site++;
	}
	h = h % MAX_HASH_TABLE;
	return (h);
}

void	insert(char *site, char *password)
{
	int	h;
	nodePointer	newNode;

	h = hashF(site);
	newNode = malloc(sizeof(node));
	strcpy(newNode->site, site);
	strcpy(newNode->password, password);
	newNode->link = hash_table[h];
	hash_table[h] = newNode;
}

char	*find(char *site)
{
	int	h;
	nodePointer	curr;

	h = hashF(site);
	curr = hash_table[h];
	while (curr)
	{
		if (!strcmp(site, curr->site))
			return (curr->password);
		curr = curr->link;
	}
	return (NULL);
}

int	main(void)
{
	int	N, M;
	char	site[STRING_SIZE];
	char	password[STRING_SIZE];

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s", site, password);
		insert(site, password);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", site);
		printf("%s\n", find(site));
	}
}

