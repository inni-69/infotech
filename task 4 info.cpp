
#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0  
#define N 9


bool yoyo(int soduuu[N][N],int& row, int& col);  bool BADHIYA(int soduuu[N][N], int row,int col, int num);

bool bahottbadhiya(int soduuu[N][N])
{
	int row, col;


	if (!yoyo(soduuu, row, col))  return true;
for (int num = 1; num <= 9; num++) 
	{   if (BADHIYA(soduuu, row, col, num)) 
		{    soduuu[row][col] = num;

		
			if (bahottbadhiya(soduuu))
				return true;

			soduuu[row][col] = UNASSIGNED;
		}
	}
	
	
	return false;
}


bool yoyo(int soduuu[N][N],
							int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (soduuu[row][col] == UNASSIGNED)
				return true;
	return false;
}


bool ro(int soduuu[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (soduuu[row][col] == num)
			return true;
	return false;
}


bool co(int soduuu[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (soduuu[row][col] == num)
			return true;
	return false;
}


bool bo(int soduuu[N][N], int bboxxxuuuu,
			int boxxxyyy, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (soduuu[row + bboxxxuuuu]
					[col + boxxxyyy] ==
									num)
				return true;
	return false;
}

bool BADHIYA(int soduuu[N][N], int row,
			int col, int num)
{
	
	return !ro(soduuu, row, num)
		&& !co(soduuu, col, num)
		&& !bo(soduuu, row - row % 3,
						col - col % 3, num)
		&& soduuu[row][col] == UNASSIGNED;
}


void dikha(int soduuu[N][N])
{
	for (int row = 0; row < N; row++) 
	{
		for (int col = 0; col < N; col++)
			cout << soduuu[row][col] << " ";
		cout << endl;
	}
}


int main()
{
	
	int soduuu[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if (bahottbadhiya(soduuu) == true)   dikha(soduuu);
	else cout<<"No solution exists";

	return 0;
}


