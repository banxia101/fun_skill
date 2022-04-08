/*算法相关的图片放在Photos中，命名为PK_algorithm1/2*/
#Prim algorithm
#该算法将图转换为邻接矩阵，构造最小生成树，通过找权值最小的顶点，并修改lowcost[]值，依次递归，不断更新lowcost[]数组，最终完成全局搜索
void MiniSpanTree_Prim(MGraph G)
{
    int min,i,j,k;
    int adjvex[MAXVEX];//保存相关顶点下标
    int lowcost[MAXVEX];//保存相关顶点间边的权值
    lowcost[0] = 0;
    adjvex[0] = 0;
    
    for(i = 1;i < G.numVertexes; i ++)
    {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    
    for(i = 1; i < G.numVertexes;i ++)
    {
        min = INFINITY;
        j = 1;k = 0;//j做顶点下标循环的变量，k存储最小权值的顶点
        
        while(j < G.numvertexes)
        {
            if(lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j ++;  
        }
        
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k] = 0;
        
        for(j = 1;j < G.numVertexes;j ++)
        {
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
        
    }
    
}



#Kruskal algorithm
/*假设N=(V,{E})是连通网，则令最小生成树的初始状态为只有n个顶点而无边的非连通图T={V,{}},图中每个顶点自成一个连通分量。
在E中选择代价最小的边，若该边依附的顶点落在T中不同的连通分量上，则将此边加入到T中，否则舍去此边而选择下一条代价最小的边。
依此类推，直至T中所有顶点都在同一连通分量上为止。*/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i,n,m;
	Edge edges[MAXEDGE];
	int parent[MAXVEX];
	for(i = 0;i < G.numEdges;i ++)
	{
		parent[i] = 0;
	}
	for(i = 0;i < G.numEdges;i ++)
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if(n != m)
		{
			parent[n] = m;
			printf("(%d,%d)%d",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
}
int Find(int *parent,int f)
{
	while(parent[f] > 0)
	{
		f = parent[f];
		return f;
	}
}
