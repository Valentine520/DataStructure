//
// Created by 龙舌兰 on 2021/10/4.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H
typedef char Item;//数据类型 此处的Huffman树中存储的为字符 A B C D 等

//使用静态链表存储Huffman Tree
//一共n个节点 则放在前n个位置 而后的位置全用来存放联结节点的空节点 易于访问
//因为不具有二叉树等其他树的性质 因而对数据结构的要求不是特别高
//相反 使用标准的树形结构可能会导致对节点的内容进行判断 无法知道从哪里开始 也不知道需要解码的节点在何处

typedef struct huff{
    int weight;//权重
    int parent;//双亲 便于编码
    int Lchild;//左孩子 用于解码 左0 右1
    int Rchild;//右孩子
    int flag;//表示节点是否已经被整合
    Item data;
}Huff;

//使用数组存储huffman树
typedef char ** HuffmanTable;//huffman编码表


//根据权重创建Huffman树 以及进行编码
//其中HT为赫夫曼树 使用结构体数组进行创建
//Table为赫夫编码表 使用二级指针维护的字符串进行维护 用于根据不同编码长度动态创建属于该长度的编码方式
//w为其相应的权重
//n为节点的个数
//data为相应的节点的内容
void HuffmanCreate(Huff **HT,const Item *data,const int *w,int n);

//解码
void SolveHuffmanCode(Huff *HT,HuffmanTable Table,Item **SolveTable,int n);

//编码
void HuffmanCode(Huff*HT,HuffmanTable*Table,int n);

#endif //HUFFMANTREE_HUFFMANTREE_H
