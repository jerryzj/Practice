#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCSIZE 108
typedef char VertexType;

//邻接表中表对应的链表的顶点
typedef struct _Enode
{
    int adjvex;                 //该边所指向的顶点的位置
    struct _Enode *next_edge;   //指向下一条弧
} Enode;

//邻接表中表的顶点
typedef struct _Vnode
{
    int indegree;               //顶点入度
    VertexType data[MAXCSIZE];  //顶点信息
    Enode *first_edge;          //指向第一条依附该顶点的弧
} Vnode;

//邻接表
typedef struct _LGraph
{
    int vexnum;         //顶点数
    int edgenum;        //边数
    Vnode *Vexs;        //顶点
}LGraph;

void CreateLGraph(LGraph *G);
int VexLocate(LGraph *G, VertexType e[]);
void Topo_Sort(LGraph *G);
void PrintLgraph(LGraph *G);

int main(){
    LGraph G;
    
    CreateLGraph(&G);
	Topo_Sort(&G);
	getchar();
    return 0;
}


void CreateLGraph(LGraph *G)
{
    FILE *file = fopen("player.txt", "r");
    fscanf(file, "%d", &G->vexnum);     //读取顶点数

    G->Vexs = (Vnode*)malloc(sizeof(Vnode)*(G->vexnum));
	printf("---读取顶点---\n\n");
	for (int i = 0; i < G->vexnum; i++)
    {
        fscanf(file, "%s", G->Vexs[i].data);
        printf("第%d个顶点的信息：", i+1);
        printf("%s\n", G->Vexs[i].data);
        G->Vexs[i].indegree = 0;
        G->Vexs[i].first_edge = NULL;
    }
	printf("\n---共读取到%d个顶点---\n\n", G->vexnum);
	fclose(file);
	printf("---读取边---\n\n");
	file = fopen("tour1.txt","r");
	fscanf(file,"%d",&G->edgenum);
	for (int k = 0; k < G->edgenum; k++)
    {
        VertexType vi[MAXCSIZE], vj[MAXCSIZE];
        fscanf(file, "%s > %s", vi, vj);
        //printf("第%d条边的信息：", k+1);
        //printf("%s->%s\n", vi, vj);
        int pi = VexLocate(G, vi);
        int pj = VexLocate(G, vj);
        Enode *E = (Enode*)malloc(sizeof(Enode));
        E->adjvex = pj;
        E->next_edge = G->Vexs[pi].first_edge;
        G->Vexs[pi].first_edge = E;
        G->Vexs[pj].indegree++;
    }
	fclose(file);
	file = fopen("tour2.txt","r");
	fscanf(file,"%d",&G->edgenum);
	for (int k = 0; k < G->edgenum; k++)
    {
        VertexType vi[MAXCSIZE], vj[MAXCSIZE];
        fscanf(file, "%s > %s", vi, vj);
        //printf("第%d条边的信息：", k+1);
        //printf("%s->%s\n", vi, vj);
        int pi = VexLocate(G, vi);
        int pj = VexLocate(G, vj);
        Enode *E = (Enode*)malloc(sizeof(Enode));
        E->adjvex = pj;
        E->next_edge = G->Vexs[pi].first_edge;
        G->Vexs[pi].first_edge = E;
        G->Vexs[pj].indegree++;
    }
	fclose(file);
	file = fopen("tour3.txt","r");
	fscanf(file,"%d",&G->edgenum);
	for (int k = 0; k < G->edgenum; k++)
    {
        VertexType vi[MAXCSIZE], vj[MAXCSIZE];
        fscanf(file, "%s > %s", vi, vj);
        //printf("第%d条边的信息：", k+1);
        //printf("%s->%s\n", vi, vj);
        int pi = VexLocate(G, vi);
        int pj = VexLocate(G, vj);
        Enode *E = (Enode*)malloc(sizeof(Enode));
        E->adjvex = pj;
        E->next_edge = G->Vexs[pi].first_edge;
        G->Vexs[pi].first_edge = E;
        G->Vexs[pj].indegree++;
    }
	fclose(file);
	file = fopen("tour4.txt","r");
	fscanf(file,"%d",&G->edgenum);
	for (int k = 0; k < G->edgenum; k++)
    {
        VertexType vi[MAXCSIZE], vj[MAXCSIZE];
        fscanf(file, "%s > %s", vi, vj);
        //printf("第%d条边的信息：", k+1);
        //printf("%s->%s\n", vi, vj);
        int pi = VexLocate(G, vi);
        int pj = VexLocate(G, vj);
        Enode *E = (Enode*)malloc(sizeof(Enode));
        E->adjvex = pj;
        E->next_edge = G->Vexs[pi].first_edge;
        G->Vexs[pi].first_edge = E;
        G->Vexs[pj].indegree++;
    }
	fclose(file);
	file = fopen("tour5.txt","r");
	fscanf(file,"%d",&G->edgenum);
	for (int k = 0; k < G->edgenum; k++)
    {
        VertexType vi[MAXCSIZE], vj[MAXCSIZE];
        fscanf(file, "%s > %s", vi, vj);
        //printf("第%d条边的信息：", k+1);
        //printf("%s->%s\n", vi, vj);
        int pi = VexLocate(G, vi);
        int pj = VexLocate(G, vj);
        Enode *E = (Enode*)malloc(sizeof(Enode));
        E->adjvex = pj;
        E->next_edge = G->Vexs[pi].first_edge;
        G->Vexs[pi].first_edge = E;
        G->Vexs[pj].indegree++;
    }
	fclose(file);
	printf("\n---共读取到%d条边---\n\n", G->edgenum);
	printf("---邻接表建立完成---\n\n");
	PrintLgraph(G);
	printf("\n");
}

int VexLocate(LGraph *G, VertexType e[])
{
    int pos;
    for (pos=0; pos<G->vexnum; pos++)
    {
        if (strcmp(e, G->Vexs[pos].data) == 0)
            return pos;
    }
    return -1;
}

void Topo_Sort(LGraph *G)
{
	Vnode *queue[128];		//辅助队列
	int top = 0;
	for (int k = 0; k < G->vexnum; k++)
    {
		for (int i = 0; i < G->vexnum; i++)
			if (G->Vexs[i].indegree == 0)
			{
				G->Vexs[i].indegree = -1;
				queue[top++] = &G->Vexs[i];		//将入度为0的顶点存入队列
				Vnode *p = &G->Vexs[i];
				Enode *e = p->first_edge;
				p->indegree--;
				for (; e != NULL; e = e->next_edge)
				{
					p = &G->Vexs[e->adjvex];
					p->indegree--;
				}
				free(G->Vexs[i].first_edge);
			}
    }
	if (top != G->vexnum)
	{
		printf("拓扑排序失败！此图有闭环\n\n");
		return;
	}
	printf("拓扑排序完成：\n");
	for (int i = 0; i < top-1; i++)
		printf("%s->", queue[i]->data);
	printf("%s\n\n", queue[top - 1]->data);
}

void PrintLgraph(LGraph * G)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		Vnode *p = &G->Vexs[i];
		Enode *e = p->first_edge;
		printf("%16s", p->data);
		for (; e != NULL; e = e->next_edge)
		{
			p = &G->Vexs[e->adjvex];
			printf("==%s", p->data);
		}
		printf("\n");
	}
}
