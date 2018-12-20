#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int m, n, k;
	int i, j, l, f;
	
	int p = 0;
	
	FILE *we;
	FILE *wy;
	
	we = fopen("we.txt", "r");
	wy = fopen("wy.txt", "w");


	fscanf(we, "%d", &m);
	fscanf(we, "%d", &n);
	fscanf(we, "%d", &k);

	int **A = (int**)malloc(m * sizeof(*A));
	int **B = (int**)malloc(n * sizeof(*B));
	int **C = (int**)malloc(m * sizeof(*C));
	
	//A
	for(i = 0; i < m; i++)
	{
		A[i] = (int*)malloc(n * sizeof(**A));
	}
	
	//B
	for(i = 0; i < n; i++)
	{
		B[i] = (int*)malloc(k * sizeof(**B));
	}
	
	//C
	for(i = 0; i < m; i++)
	{
		C[i] = (int*)malloc(k * sizeof(**C));
	}
	
	
	//Wstawianie danych do A
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			//printf("Podaj A[%d][%d] = ", i, j);
			
			fscanf(we, "%d", &A[i][j]);
		}
	}
	
	//Wstawianie danych do B
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < k; j++)
		{
			//printf("Podaj B[%d][%d] = ", i, j);
			
			fscanf(we, "%d", &B[i][j]);
		}
	}
	//Mno¿enie
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < k; j++)
		{
			p = 0;
			for(l = 0; l < n; l++)
			{
				p = p + (A[i][l] * B[l][j]);
			}
			C[i][j] = p;
		}
	}

	
	printf("\n");
	
	fprintf(wy, "%dx", m);
	fprintf(wy, "%d\n", k);
	
	//Wyœwietl C
	for(i = 0; i < m; i++)
	{
		for (j = 0; j < k; j++)
		{
			fprintf(wy, "%d\n", C[i][j]);
		}
	}
	
	
	//A C free
	for(i = 0; i < m; i++)
	{
		free(A[i]);
		free(C[i]);
	}
	
	//B free
	for(i = 0; i < n; i++)
	{
		free(B[i]);
	}
	
	free(A); free(B); free(C);
	
	A = NULL; B = NULL; C = NULL;
	
	fclose(we);
	
	return 0;
}
