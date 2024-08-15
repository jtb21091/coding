#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// Directions for movement: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Grid size
const int GRID_SIZE = 10;

// Function to check if a cell is within the grid and not an obstacle
bool isValid(int x, int y, const vector<vector<int> > & grid) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] != 1;
}

// Autonomous robot navigation using Breadth-First Search (BFS)
bool navigateGrid(vector<vector<int> > & grid, pair<int, int> start, pair<int, int> goal) {
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(GRID_SIZE, vector<bool>(GRID_SIZE, false));
    
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current == goal) {
            cout << "Goal reached at (" << current.first << ", " << current.second << ")\n";
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (isValid(nx, ny, grid) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << "No path to the goal found.\n";
    return false;
}

int main() {
    srand(time(0));

    vector<vector<int> > grid(GRID_SIZE, vector<int>(GRID_SIZE, 0));

    // Randomly place obstacles in the grid
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (rand() % 5 == 0) {
                grid[i][j] = 1; // Place an obstacle
            }
        }
    }

    // Define start and goal positions
    pair<int, int> start = make_pair(0, 0);
    pair<int, int> goal = make_pair(GRID_SIZE - 1, GRID_SIZE - 1);

    // Ensure start and goal positions are not obstacles
    grid[start.first][start.second] = 0;
    grid[goal.first][goal.second] = 0;

    // Display the grid
    cout << "Grid (0 = free, 1 = obstacle):\n";
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // Start navigation
    cout << "\nStarting autonomous navigation...\n";
    navigateGrid(grid, start, goal);

    return 0;
}
