class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle);
};
/************************************************************************/
int Solution::minimumTotal(vector<vector<int>>& triangle) {
    /* check edge cases */
    if (triangle.size() == 1) {
        return triangle[0][0];
    }
    vector<int> aux, sumAcum;
    int nRows, nColumns, rows, columns;
    /* first case */
    aux.emplace_back(triangle[0][0]);
    sumAcum=aux;
    aux.clear();
    /* constant initialization */
    nRows = triangle.size();
    /* sumAcum fulling */
    for (rows = 1; rows < nRows; ++rows) {
        nColumns = triangle.at(rows).size();
        for (columns = 0; columns < nColumns; ++columns) {
            /* trivial case */
            if (rows == 1) {
                aux.emplace_back(sumAcum[0]+triangle[rows][columns]);
                continue;
            }
            /* test if right border of the triangle */
            if (columns+1 >= nColumns) {
                aux.emplace_back(sumAcum[columns-1]+triangle[rows][columns]);
            } else if (columns == 0) {
                aux.emplace_back(sumAcum[columns]+triangle[rows][columns]);
            } else {
                if (sumAcum[columns-1] <= sumAcum[columns]) {
                    aux.emplace_back(sumAcum[columns-1]+triangle[rows][columns]);
                } else {
                    aux.emplace_back(sumAcum[columns]+triangle[rows][columns]);
                }
            }
        } 
        /* test if there is room for one more round or not */
        if (rows+1 < nRows) {
            sumAcum=aux;
            aux.clear();
        }
    }
    /* return final value */
    return *min_element(aux.begin(), aux.end());
}