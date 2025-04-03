const int N = 1003;
vector<vector<int>> a;
int n, m;
bool vis[N][N];
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int i, int j) {
    
    vis[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] != 0) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}



void solve() {
    cin >> n >> m;
    a.assign(n, vector<int>(m, 0));
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((a[i][j] != 0 ) && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }
}
