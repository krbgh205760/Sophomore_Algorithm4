#include<stdio.h>
#include<stdlib.h>

int *vcolor;//color array index by vertax
int m;//number of color
int n;//size of gragh
int **W;//graph
int check;

int promising(int i)
{
	int j;
	int sw;
	sw = 1;
	j = 1;
	while((j < i) && sw)
	{
		if(W[i][j] && (vcolor[i] == vcolor[j]))
			sw = 0;
		j++;
	}
	return sw;
}

void m_coloring(int i)
{
	int color;
	if(promising(i))
		if(i == n)
		{
			check++;
		}
		else
			for(color = 1; color <= m; color++)
			{
				vcolor[i+1] = color;
				m_coloring(i+1);
			}
}

int main(void)
{
	FILE *input;
	int i, j;

	input = fopen("input", "r");

	fscanf(input, "%d ", &n);

	W = (int **) calloc(n+1, sizeof(int*));
	for(i = 1; i <= n; i++)
		*(W + i) = (int *) calloc(n+1, sizeof(int));
	vcolor = (int *) calloc(n+1, sizeof(int));

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			fscanf(input, "%d ", &W[i][j]);

	for(m = 1; m <= n; m++)
	{
		m_coloring(0);
		if(check > 0)
			break;
	}
	printf("m : %d, check : %d\n", m, check);

	return 0;
}
