class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Vertical rotate
        for (int i = 0; i < n / 2; i++) {
            vector<int> tmp = matrix[i];
            matrix[i] = matrix[n-i-1];
            matrix[n-i-1] = tmp;
        }

        // Matrix transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
