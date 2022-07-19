/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
  return new Array(numRows-1).fill().map((_, i) => i + 1).reduce((prev, curr) => [...prev, new Array(curr+1).fill().map((_, j) => (prev[curr - 1][j-1] ?? 0) + (prev[curr-1][j] ?? 0))], [[1]]);
};