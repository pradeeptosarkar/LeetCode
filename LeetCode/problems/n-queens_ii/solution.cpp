class Solution {
public:
void blockPlaces(int mat[][10], int n, int x, int y)
{
	int i = x+1, j = y+1, k=y;

	while (i < n)
		mat[i++][y] += 1;

	while (j < n)
		mat[x][j++] += 1;

	i = x+1, k = y-1;

	while (i < n && k >= 0)
		mat[i++][k--] += 1;

	i = x+1, j = y+1;

	while (i < n && j < n )
		mat[i++][j++] += 1;
}

void unblockPlaces(int mat[][10], int n, int x, int y)
{
	int i = x + 1, j = y + 1, k = y;

	while (i < n)
		mat[i++][y] -= 1;

	while (j < n)
		mat[x][j++] -= 1;

	i = x + 1, k = y - 1;

	while (i < n && k >= 0)
		mat[i++][k--] -= 1;

	i = x + 1, j = y + 1;

	while (i < n && j < n)
		mat[i++][j++] -= 1;
}

bool N_Queen(int mat[][10],int n,int i, int &count){

	//base case
	if(i==n){
        count++;

		return true;
	}

	for(int j=0;j<n;j++){
		if (mat[i][j] == 0)
		{
			mat[i][j] = -1;
			blockPlaces(mat, n, i, j);

			N_Queen(mat, n, i + 1, count);
			mat[i][j] = 0;
			unblockPlaces(mat, n, i, j);
		}
	}
	return false;
}
    int totalNQueens(int n) {
        int mat[10][10] = {0};
        int count =0;
        N_Queen(mat,n,0,count);
        return count;
    }
};