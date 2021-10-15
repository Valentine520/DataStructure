#ifndef GRAPH_ADJACENCYMATRIX_H
#define GRAPH_ADJACENCYMATRIX_H
#define INFINITY 65535
#define MAXVEX 100//节点的最大数量

typedef char VertexType;

typedef int EdgeType;

typedef struct adjacencyGraph{
    int VertexesSize;//节点长度
    int EdgesSize;//边长度
    VertexType Vertex[MAXVEX];//节点表
    EdgeType Edge[MAXVEX][MAXVEX];//边表
}AdjacencyGraph;

//利用双表创建Graph类型
void CreateGraph(AdjacencyGraph *Graph);
