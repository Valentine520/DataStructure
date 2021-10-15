//
// Created by 龙舌兰 on 2021/10/6.
//
#include <stdio.h>
#include "AdjacencyMatrix.h"
#include <stdlib.h>

void CreateGraph(AdjacencyGraph *Graph){
    int VertexLength;
    int EdgeLength;
    printf("Please enter the number of the vertexes you want create.\n");
    while(scanf("%d",&VertexLength)!=1&&VertexLength>MAXVEX){
        printf("Invalid input,please enter the correct number of vertexes\n");
        while(getchar()!='\n'){
            continue;
        }
    }
    while(getchar()!='\n'){
        continue;
    }
    Graph->VertexesSize=VertexLength;
    printf("Please enter the number of the edges you want to create.\n");
    while(scanf("%d",&EdgeLength)!=1&&VertexLength>MAXVEX){
        printf("Invalid input,please enter the correct number of edges\n");
        while(getchar()!='\n'){
            continue;
        }
    }
    while(getchar()!='\n'){
        continue;
    }
    Graph->EdgesSize=EdgeLength;
    //创建顶点
    for(int i=0;i<VertexLength;i++){
        printf("Please enter the name of vertex.\n");
        char temp;
        while(scanf("%c",&temp)!=1){
            printf("Invalid input,Please enter again.\n");
            while(getchar()!='\n'){
                continue;
            }
        };
        while(getchar()!='\n'){
            continue;
        }
        Graph->Vertex[i]=temp;
    }
    //边的初始化 不可达则为Infinity
    for(int i=0;i<VertexLength;i++){
        for(int j=0;j<VertexLength;j++){
            Graph->Edge[i][j]=INFINITY;//未达的边设置为INF
        }
    }
    //给特定的边赋值
    for(int i=0;i<EdgeLength;i++){
        int site_u,site_v;
        printf("Please enter the edgesite such as u,v\n");
        scanf("%d %d",&site_u,&site_v);
        printf("Please enter the edgeweight .\n");
        int weight;
        scanf("%d",&weight);
        //无向图对称
        Graph->Edge[site_v][site_u]=weight;
        Graph->Edge[site_u][site_v]=weight;
        while(getchar()!='\n'){
            continue;
        }
    }
}


void Dijkstra(AdjacencyGraph*Graph,int NodeIndex,int *Path){
    int Visit[Graph->VertexesSize];
    int Weight[Graph->VertexesSize];
    //创建Path数组 以及 Weight 数组
    for(int i=0;i<Graph->VertexesSize;i++){
        Visit[i]=-1;
        Path[i]=NodeIndex;//初始点
        Weight[i]=Graph->Edge[NodeIndex][i];//初始化权值 到NodeIndex 的路径长度
    }

    //原节点不加入
    Path[NodeIndex]=-1;
    Visit[NodeIndex]=1;

    for(int i=0;i<Graph->VertexesSize-1;i++){
        int min=INFINITY;
        int min_index;
        for(int j=0;j<Graph->VertexesSize;j++){
            //针对所有未加入的节点
            if(Visit[j]==-1){
                if(Weight[j]<min){
                    min=Weight[j];
                    min_index=j;//保存最路径的节点
                }
            }
        }
        Visit[min_index]=1;//访问
        //更新剩余节点
        for(int k=0;k<Graph->VertexesSize;k++){
            if(Visit[k]==-1){
                //weight是否有更好的选择 如果有则更新
                if(Graph->Edge[min_index][k]+min_index<Weight[k]){
                    Weight[k]=Graph->Edge[min_index][k]+min_index;
                    //更新路径下标
                    Path[k]=min_index;//上标
                }
            }
        }
    }
}


void ShowPath(const int *Path,int index){
    if(index==-1){
        return;
    }
    else{
        ShowPath(Path,Path[index]);
        printf("%d",index);//从底到头
    }
}


void Floyd(AdjacencyGraph*Graph,int (*Path)[MAXVEX]){
    //初始化矩阵
    int size=Graph->VertexesSize;
    int Weight[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            Weight[i][j]=Graph->Edge[i][j];
            Path[i][j]=j;//初始化Path数组 初始化为12345 便于其找到对应的节点
        }
    }

    for(int v=0;v<size;v++){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i!=j&&i!=v&&j!=v){
                    if(Weight[i][j]>Weight[i][v]+Weight[v][j]){
                        Weight[i][j]=Weight[i][v]+Weight[v][j];//更新最小值
                        Path[i][j]=Path[i][v];//记录中间值(为什么需要使用i v 进行记录?)
                    }
                }
            }
        }
    }
}
void ShowPathFloyd(int (*Path)[MAXVEX],int u,int v){
    printf("%d ",u);
    PathFloyd(Path,u,v);
    printf("%d\n",v);
}

void PathFloyd(int (*Path)[MAXVEX],int u,int v){
    if(Path[u][v]==v){
        return;
    }
    else{
        int mid=Path[u][v];
        printf("%d ",mid);
        PathFloyd(Path,mid,v);
    }
}


//基于adjacency matrix实现的Prim
void Prim(AdjacencyGraph*Graph){
    int min,k,j;

    //存储最小生成树相对的路径 保存pre
    int adjavex[Graph->VertexesSize];

    //存储图中的最短的路径 除开已经被访问的节点进行继续访问 避免形成圈
    int lowcost[Graph->VertexesSize];

    adjavex[0]=lowcost[0]=0;//初始化首个节点
    for(int i=1;i<Graph->VertexesSize;i++){
        adjavex[i]=0;
        lowcost[i]=Graph->Edge[0][i];
    }
    for (int m = 0; m < Graph->VertexesSize; m++) {
        j = 1;k=0;
        min = INFINITY;//每次都寻找lowcost中最小的
            while (j < Graph->VertexesSize) {
                if (lowcost[j] != 0) {
                    if (lowcost[j] < min) {
                        min = lowcost[j];
                        k = j;//保存最短的路径的节点
                    }
                }
                j++;
            }
            //表明结束
            if(k==0){
                return;
            }
            lowcost[k]=0;//表示已被访问过 不再访问
            printf("%d -> %d\n", adjavex[k], k);
            for (int i = 0; i < Graph->VertexesSize; i++) {
                if (lowcost[i] != 0 && Graph->Edge[k][i] < lowcost[i]) {
                    adjavex[i] = k;//保存节点位置
                    lowcost[i] = Graph->Edge[k][i];//更新最短的边
                }
            }
        }
    }

