bool adj[9][9];
int visit[9];
int low[9]; // 記錄自身與子孫們
            // 用back edge連到的最高祖先（的遍歷時刻）。
            // 由於遍歷時刻要盡量小，故大家習慣取名為low。
int t = 0;
 
void DFS(int p, int i)
{
    visit[i] = low[i] = ++t;
 
    int child = 0;
    bool ap = false;
 
    for (int j=0; j<9; ++j)
        if (adj[i][j] && j != p)
            if (visit[j])   // back edge
            {
                // 遍歷時刻較小者，即是較高祖先。
                low[i] = min(low[i], visit[j]);
            }
            else            // tree edge
            {
                child++;
                DFS(i, j);
 
                // 遍歷時刻較小者，即是較高祖先。
                low[i] = min(low[i], low[j]);
                if (low[j] >= visit[i]) ap = true;
            }
 
    if ((i == p && child > 1) || (i != p && ap))
        cout << "第" << i << "點是關節點";
}
