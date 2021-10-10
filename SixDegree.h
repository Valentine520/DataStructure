//
// Created by 龙舌兰 on 2021/10/6.
//

#ifndef ADJACENCYLIST_ADJACENCYLIST_H
#define ADJACENCYLIST_ADJACENCYLIST_H
#define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;



typedef struct edgenode{
    int adjvex;//邻接的节点位置
    EdgeType weight;//权重
    struct edgenode *Next;//下一个邻接点
}EdgeNode;

//顶点表节点
typedef struct VertexNode{
    VertexType data;//储存顶点表的内容
    EdgeNode *FirstNode;//边表头指针
    int Level;//记录其层数
}VertexNode,AdjList[MAXSIZE];

typedef struct {
    AdjList adjlist;//边集 结构体数组
    int NumEdge;//边数
    int NumVertex;//顶点数
}GraphAdjList;



//创建一个基于邻接表的图
void CreateALGraph(GraphAdjList*ADJList);

//广度优先遍历
int BreadFirstTraverse(GraphAdjList*Graph,int index);


#endif //ADJACENCYLIST_ADJACENCYLIST_H
