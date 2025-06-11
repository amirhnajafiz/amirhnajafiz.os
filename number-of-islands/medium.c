// Stack to hold row and column pairs
typedef struct {
    int x, y;
} Point;

int dx[] = {0, 0, 1, -1}; // Directions: right, left, down, up
int dy[] = {1, -1, 0, 0};

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int islands = 0;
    int rows = gridSize;
    int cols = *gridColSize;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != '1')
                continue;
            
            // perform DFS
            Point stack[10000];
            int top = -1;

            // push the start position
            stack[++top] = (Point){i, j};

            while(top != -1) {
                Point p = stack[top--];
                int x = p.x;
                int y = p.y;

                if (x < 0 || y < 0 || x >= rows || y >= cols)
                    continue;
                if (grid[x][y] != '1')
                    continue;
                
                grid[x][y] = '2';
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    stack[++top] = (Point){nx, ny};
                }
            }

            islands++;
        }
    }

    return islands;
}
