#include <stdio.h>

#define NMAX 105

/*	functie de citire a datelor unei nonograme
	se memoreaza cate 3 matrici NxM
	grid - nonograma
	grid_line/grid_row - pe fiecare linie se memoreaza numarul de grupuri si
	dimensiunile grupurilor care trebuie gasite pe o linie/coloana
*/
void read_nonogram(int grid[NMAX][NMAX], int grid_line[NMAX][NMAX],
				   int grid_row[NMAX][NMAX], int *N, int *M)
{
	scanf("%d%d", N, M);

	for (int i = 0; i < *N; i++) {
		int K;
		scanf("%d", &K);

		grid_line[i][0] = K;
		for (int j = 1; j <= K; j++)
			scanf("%d", &grid_line[i][j]);
	}

	for (int i = 0; i < *M; i++) {
		int K;
		scanf("%d", &K);

		grid_row[i][0] = K;
		for (int j = 1; j <= K; j++)
			scanf("%d", &grid_row[i][j]);
	}

	for (int i = 0; i < *N; i++) {
		for (int j = 0; j < *M; j++)
			scanf("%d", &grid[i][j]);
	}
}

/*	functie de verificare a unei singure linii
	returneaza 0 daca gaseste o eroare,
	altfel returneaza 1
*/
int check_line(int grid[NMAX][NMAX], int grid_line[NMAX][NMAX], int M, int line)
{
	// length memoreaza dimensiunea grupului curent
	// pos este pozitia curenta din grid_line[line]
	int length, pos = 1;

	for (int i = 0; i < M; i++) {
		// se trece peste secventele nule
		while (grid[line][i] == 0 && i < M)
			i++;

		length = 0;

		// se numara dimensiunea grupului curent
		while (grid[line][i] == 1 && i < M) {
			i++;
			length++;
		}

		// se verifica daca dimensiunea grupului curent este in regula
		if (length != grid_line[line][pos] && length != 0)
			return 0;

		pos++;
	}

	// se verifica daca s-a parcurs toate blocurilie de pe grid_line
	if (pos < grid_line[line][0] + 1)
		return 0;

	return 1;
}

/*	functie de verificare a unei singure coloane
	returneaza 0 daca gaseste o eroare,
	altfel returneaza 1
*/
int check_row(int grid[NMAX][NMAX], int grid_row[NMAX][NMAX], int N, int row)
{
	// length memoreaza dimensiunea grupului curent
	// pos este pozitia curenta din grid_line[line]
	int length, pos = 1;

	for (int i = 0; i < N; i++) {
		// se trece peste secventele nule
		while (!grid[i][row] && i < N)
			i++;

		length = 0;

		// se numara dimensiunea grupului curent
		while (grid[i][row] && i < N) {
			i++;
			length++;
		}

		// se verifica daca dimensiunea grupului curent este in regula
		if (length != grid_row[row][pos] && length != 0)
			return 0;

		pos++;
	}

	// se verifica daca s-a parcurs toate blocurilie de pe grid_line
	if (pos < grid_row[row][0] + 1)
		return 0;

	return 1;
}

/*	functie de verificare
	returneaza 0 daca gaseste o eroare,
	altfel returneaza 1
*/
int check_nonogram(int grid[NMAX][NMAX], int grid_line[NMAX][NMAX],
				   int grid_row[NMAX][NMAX], int N, int M)
{
	// itereaza fiecare linie
	for (int i = 0; i < N; i++) {
		if (!check_line(grid, grid_line, M, i))
			return 0;
	}

	// itereaza fiecare coloana
	for (int i = 0; i < M; i++) {
		if (!check_row(grid, grid_row, N, i))
			return 0;
	}

	return 1;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int k = 0; k < T; k++) {
		int grid[NMAX][NMAX], grid_line[NMAX][NMAX], grid_row[NMAX][NMAX], N, M;
		read_nonogram(grid, grid_line, grid_row, &N, &M);

		if (check_nonogram(grid, grid_line, grid_row, N, M))
			printf("Corect\n");
		else
			printf("Eroare\n");
	}

	return 0;
}
