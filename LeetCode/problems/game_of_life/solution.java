 class Solution {
 	public void gameOfLife(int[][] board) {
 		if(board == null || board.length == 0 || board[0].length == 0) return;
 		int height = board.length, width = board[0].length;
 		for(int i = 0; i < height; i++){
 			for(int j = 0; j < width; j++){
 				//center is (i, j)
 				int count = 0;
 				for(int p = Math.max(0, i - 1); p <= Math.min(height - 1, i + 1); p++){
 					for(int q = Math.max(0, j - 1); q <= Math.min(width - 1, j + 1); q++){
 						count += board[p][q] & 1;
 					}
 				}
 				if(count == 3 || count - board[i][j] == 3) board[i][j] |= 0B10;
 			}
 		}
 		for(int i = 0; i < height; i++){
 			for(int j = 0; j < width; j++){
 				board[i][j] >>= 1;
 			}
 		}
 	}
 }