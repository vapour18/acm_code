struct Edge{
	int u,v,next,w;
}edge[400000];
int head[160000],en;
int gap[160000],h[160000];

void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w,edge[en].u=u;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0,edge[en].u=u;
	edge[en].next=head[u];
	head[u]=en++;
}
void bfs(int s,int t,int n)
{
	queue<int> q;
    memset(h, -1, sizeof(h));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    h[t] = 0;
    q.push(t);
    int u, v;
    while (!q.empty())
    {
        u = q.front();
		q.pop();
        for (int i=head[u]; i!=-1; i=edge[i].next)
        {
            v = edge[i].v;
            if (edge[i].w != 0 || h[v] != -1)
                continue;
            q.push(v);

            gap[h[v] = h[u] + 1]++;
        }
    }
}
int cur[VM],stack[VM];
int sap(int s,int t,int n)       //sap模板
{
    int res = 0;
    bfs(s,t,n);
    int vp = 0;
    memcpy(cur, head, sizeof(head));
    int u = s, i;
    while (h[s] < n)
    {
        if (u == t)
        {
            int temp = inf, inser = n;
            for (i=0; i!=vp; i++)
                if (temp > edge[stack[i]].w)
                {
                    temp = edge[stack[i]].w;
                    inser = i;
                }
            for (i=0; i<vp; i++)
            {
                edge[stack[i]].w -= temp;
                edge[stack[i]^1].w += temp;
            }
            res += temp;
            vp = inser;
            u = edge[stack[vp]].u;
        }

        if (u != t && gap[h[u] -1] == 0)
            break;
        for (i = cur[u]; i != -1; i = edge[i].next)
            if (edge[i].w != 0 && h[u] == h[edge[i].v] + 1)
                break;

        if (i != -1)
        {
            cur[u] = i;
            stack[vp++] = i;
            u = edge[i].v;
        }
        else
        {
            int min = n;
            for (i = head[u]; i != -1; i = edge[i].next)
            {
                if (edge[i].w == 0)
                    continue;
                if (min > h[edge[i].v])
                {
                    min = h[edge[i].v];
                    cur[u] = i;
                }
            }
            --gap[h[u]];
            ++gap[h[u] = min + 1];
            if (u != s)
                u = edge[stack[--vp]].u;
        }
    }
    return res;
}
