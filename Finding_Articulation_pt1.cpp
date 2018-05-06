bool adj[9][9]; // 無向圖，adjacency matrix。
int parent[9];  // 記錄DFS forest
int visit[9];   // 記錄每一點的DFS遍歷時刻，以判斷祖先與子孫。
int order[9];   // 記錄DFS遍歷順序
int trace[9];   // 記錄自身與子孫們用back edge連到的最高祖先
int ap[9];      // 記錄每一點是不是關節點
 
void articulation_vertex()
{
    /* DFS。計算visit、parent、order。 */
 
    memset(visit, 0, sizeof(visit));
    int t = 0;  // 時刻
 
    stack<int> stk;
    for (int r=0; r<9; ++r)
        if (!visit[r])
        {
            stk.push(r);
            parent[r] = r;
 
            while (!stk.empty())
            {
                int i = stk.top(); stk.pop();
                if (visit[i]) continue;
 
                visit[i] = t+1;
                order[t] = i;
                t++;
 
                for (int j=0; j<9; ++j)
                    if (adj[i][j] && !visit[j])
                    {
                        stk.push(j);
                        parent[j] = i;
                    }
            }
        }
 
    /* 計算trace：自身與子孫們用back edge連到的最高祖先。 */
 
    for (int t=9-1; t>=0; --t)  // DFS逆序，先算子孫才算祖先
    {
        int i = order[t];
        trace[i] = i;
        for (int j=0; j<9; ++j)
            if (adj[i][j])
                // tree edge
                if (visit[i] < visit[j] && i == parent[j])
                {
                    if (visit[trace[j]] < visit[trace[i]])
                        trace[i] = trace[j];
                }
                // back edge
                else if (visit[i] > visit[j] && parent[i] != j)
                {
                    if (visit[j] < visit[trace[i]])
                        trace[i] = j;
                }
    }
 
    /* 計算ap：判斷關節點 */
 
    for (int i=0; i<9; ++i)
        // 樹根
        if (i == parent[i])
        {
            int child = 0;
            for (int j=0; j<9; ++j)
                if (adj[i][j] && i != j && i == parent[j])
                    child++;
            ap[i] = (child > 1);
        }
        // 其他節點
        else
        {
            ap[i] = false;
            for (int j=0; j<9; ++j)
                if (adj[i][j] && i == parent[j])
                    if (visit[trace[j]] >= visit[i])
                    {
                        ap[i] = true;
                        break;
                    }
        }
 
    for (int i=0; i<9; ++i)
        if (ap[i])
            cout << "第" << i << "點是關節點";
}
