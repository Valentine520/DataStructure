//
// Created by 龙舌兰 on 2021/9/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"
#include "QUEUE.h"


static void Delete(Node*Btree);//用于清空二叉树


//构造二叉树
//使用递归的方法构造 在构造结束时其头指针方向不变
//由于此处的递归构造引起的是节点指针的分配 因而要使用二级指针
//或者使用带返回值的形式 使用返回值进行节点内容的分配
void CreateBtree(Node**Btree){
    int num;
    //使用judge判断用户是否输入 即是否需要创建节点
    int judge=scanf("%d",&num);
    while(getchar()!='\n'){
        continue;
    }
    //未输入值 则表示没有节点
    if(judge!=1){
        *Btree=NULL;//节点为空
    }
    else{
        *Btree=(Node*)malloc(sizeof(Node));//创建节点
        (*Btree)->data=num;
        CreateBtree(&(*Btree)->Lchild);//创建左节点
        CreateBtree(&(*Btree)->Rchild);//创建右节点
    }
}


//先序遍历法
int FTraverseBtree(Node*Btree){
   static int count=0;
   if(Btree==NULL){
       return count;
   }
   else{
        //使用静态变量count在递归中对访问的节点数目进行计数
       printf("%d\n",Btree->data);
       count++;
       FTraverseBtree(Btree->Lchild);
       FTraverseBtree(Btree->Rchild);//前序遍历
   }
   return count;
}


//中序遍历法
void MTraverseBtree(Node*Btree){
    if(Btree==NULL){
        return;
    }
    else{
        FTraverseBtree(Btree->Lchild);
        printf("%d\n",Btree->data);
        FTraverseBtree(Btree->Rchild);
    }
}

//后序遍历法
void LTraverseBtree(Node*Btree){
    if(Btree==NULL){
        return;
    }
    else{
        FTraverseBtree(Btree->Lchild);
        FTraverseBtree(Btree->Rchild);
        printf("%d\n",Btree->data);
    }
}

int BtreeDepth(Node*Btree){
    static int max=0;//临时高度
    static int MAX=0;//总体最大高度
    if(Btree!=NULL){
        //使用max在回退和前进中的增量计算 实现高度的计算
        max++;//更新长度 进入一个节点则max++
        if(MAX<max){
            MAX=max;
        }
        BtreeDepth(Btree->Lchild);
        BtreeDepth(Btree->Rchild);
        max--;//无法继续深入 意味着回到开头 则max--
        
    }
    return MAX;
}


bool BtreeEmpty(Node*Btree){
    int flag=0;
    //一个节点都没有
    if(Btree==NULL){
        flag=1;
    }
    static int MAX=0;
    return flag;
}

//使用后续遍历删除节点 保证节点从底层至顶层层层删除 free
//后序遍历法
void ClearTree(Node**Btree){
    if(*Btree==NULL){
        return;
    }
    else{
        //后序遍历清空节点
        ClearTree(&(*Btree)->Lchild);
        ClearTree(&(*Btree)->Rchild);
        free(*Btree);
        *Btree=NULL;//释放掉 指向为空
    }
}

//判断值是否在树中
bool SearchBtreeParent(Node*Btree,Item data,Node **result,int flag){
    //遍历搜索树 直到其匹配位置
    //利用flag作为标签 防止不必要的循环 递归不易通信
    if(Btree!=NULL&&flag!=1){
        if((Btree->Lchild->data==data&&Btree->Lchild!=NULL)||(Btree->Rchild!=NULL&&Btree->Rchild->data==data)){
            *result=Btree;//返回其parent
            flag=1;
        }
        SearchBtree(Btree->Lchild,data,result,flag);
        SearchBtree(Btree->Rchild,data,result,flag);
    }
    return flag;
}


bool SearchBtree(Node*Btree,Item data,Node **result,int flag){
    //遍历搜索树 直到其匹配位置
    //利用flag作为标签 防止不必要的循环
    if(Btree!=NULL&&flag!=1){
        if(Btree->data==data){
            *result=Btree;//返回节点
            flag=1;
        }
        SearchBtree(Btree->Lchild,data,result,flag);
        SearchBtree(Btree->Rchild,data,result,flag);
    }
    return flag;
}

void ShowTargetNode(Node*Btree,Item data){
    Node *copy=Btree;
    Node *temp=NULL;
    int flag=SearchBtree(Btree,data,&temp,0);
    if(flag){
        Node *copy_temp=temp;
        //小的先进行
        int depth= -BtreeDepth(copy_temp)+BtreeDepth(Btree);
        printf("The Btree Depth is %d\n", BtreeDepth(copy));
        printf("The node is %d\n", BtreeDepth(copy_temp));


        printf("The depth of the node is %da\n",depth);
        printf("The value of it is %d\n",temp->data);
        if(temp->Lchild!=NULL){
            printf("The value of its Lchild is %d\n",temp->Lchild->data);
        }
        if(temp->Rchild!=NULL){
            printf("The value of its Rchild is %d\n",temp->Rchild->data);
        }
    }
    else{
        fprintf(stderr,"The data is not exist in the tree.\n");
        return ;
    }
    flag=SearchBtreeParent(copy,data,&temp,0);
    if(flag){
        printf("The value of its parent is  %d\n",temp->data);
    }
    else{
        fprintf(stderr,"The data is not exist in the tree.\n");
        return ;
    }
    if(temp->Lchild!=NULL&&temp->Lchild->data!=data){
        printf("The sibling of the node is %d\n",temp->Lchild->data);
    }
    if(temp->Rchild!=NULL&&temp->Rchild->data!=data){
        printf("The sibling of the node is %d\n",temp->Rchild->data);
    }

}


bool AssignValue(Node*Btree,Item data,Item new_value){
    Node *temp=NULL;
    //利用temp存储查找的节点
    bool flag= SearchBtree(Btree,data,&temp,0);
    //是否查找成功
    if(flag==1){
        temp->data=new_value;
    }
    return flag;
}


//层序遍历
void StepTraverse(Node *Btree){
    Node *temp=Btree;
    Queue queue;
    Initial(&queue);
    //对树根进行特殊操作
    //若不空 则push树根进 push的是节点的值 并未push指针 
    if(!BtreeEmpty(Btree)){
        AddElem(&queue,Btree->data);
    }
    //若队列不空 则继续
    while(!QueueEmpty(&queue)){
        Item data;
        DeleteElem(&queue,&data);
        //利用search定位弹出值的位置
        SearchBtree(Btree,data,&temp,0);
        printf("%d\n",data);
        if(temp->Lchild!=NULL){
            AddElem(&queue,temp->Lchild->data);
        }
        if(temp->Rchild!=NULL){
            AddElem(&queue,temp->Rchild->data);
        }
    }
}

//利用层序遍历的思想进行
void Insert(Node *Btree,Item my_data){
    Node *temp=(Btree);
    Node *temp2;
    Queue queue;
    Item data;
    Initial(&queue);
    //若不空 则push树根进
    if(!BtreeEmpty(Btree)){
        AddElem(&queue,(Btree)->data);
        //若队列不空 则继续
        while(!QueueEmpty(&queue)){
            DeleteElem(&queue,&data);
            SearchBtree(temp,data,&temp2,0);//弹出的位置
            if(temp2->Lchild==NULL){
                 temp2->Lchild=(Node*) malloc(sizeof(Node));
                 temp2->Lchild->data=my_data;
                 temp2->Lchild->Lchild=NULL;
                 temp2->Lchild->Rchild=NULL;
                 break;
            }
            else{
                AddElem(&queue,temp2->Lchild->data);//压入左节点进行层序遍历式地插入
            }
            if(temp2->Rchild==NULL){
                temp2->Rchild=(Node*) malloc(sizeof(Node));
                temp2->Rchild->data=my_data;
                temp2->Rchild->Lchild=NULL;
                temp2->Rchild->Rchild=NULL;
                break;
            }
            else{
                AddElem(&queue,temp2->Rchild->data);
            }
        }
    }
}

//为保证每次删除都尽可能少地破坏树结构 分为三种情况进行删除
bool DeleteNode(Node*Btree,Item data){
    bool flag=1;
    Node *PreNode=NULL;
    //找到该节点的前驱
    if(!SearchBtreeParent(Btree,data,&PreNode,0)){
        flag=0;
        return flag;//不存在该节点
    };
    //三种情况
    Node*CurNode;//待删除的节点
    int opt=0;
    //记录前驱节点和待删除节点的关系 左、右
    if(PreNode->Lchild->data==data){
        opt=1;
        CurNode=PreNode->Lchild;
    }
    else{
        opt=2;
        CurNode=PreNode->Rchild;
    }
    //叶节点
    if(CurNode->Lchild==NULL&&CurNode->Rchild==NULL){
        free(CurNode);
        //为右子树
        if(opt==2){
            PreNode->Rchild=NULL;
        }
        //为左子树
        else{
            PreNode->Lchild=NULL;
        }
    }
    //仅有一个子节点
    else if(CurNode->Lchild==NULL||CurNode->Rchild==NULL){
        //左为空
        if(CurNode->Lchild==NULL){
            //链接其右侧
            if(opt==1){
                PreNode->Lchild=CurNode->Rchild;
            }
            if(opt==2){
                PreNode->Rchild=CurNode->Rchild;
            }
            free(CurNode);
        }
        else {
                if (opt == 1) {
                    PreNode->Lchild = CurNode->Lchild;
                }
                if (opt == 2) {
                    PreNode->Rchild = CurNode->Lchild;
                }
                free(CurNode);
        }
    }
    //最复杂的就在此 先查找其最长的部分 最长的部分作为链接
    else{
        Node *origin_temp=(CurNode);//当前待删除的节点
        Node *cur_temp;//用作游标
        Queue queue;//层序遍历的辅助结构
        Item temp_data;
        Initial(&queue);
        //若不空 则push树根进
        //查找待删除的子树中的空节点
        if(!BtreeEmpty(origin_temp)){
            AddElem(&queue,(origin_temp)->data);
            //若队列不空 则继续
            while(!QueueEmpty(&queue)){
                DeleteElem(&queue,&data);
                SearchBtree(origin_temp,data,&cur_temp,0);//弹出的位置
                //查找空闲节点 而后判断空闲节点属于哪边 左边则将删除节点右边的数据插入 右边同理
                if(cur_temp->Lchild==NULL||cur_temp->Rchild==NULL){
                    //有剩余空间 查找该节点是哪个的节点
                    
                    //如果查找成功 则说明在左半部分 cur_temp代表有空余子节点的位置
                    if(SearchBtree(origin_temp->Lchild,data,&cur_temp,0)){
                        //看在cur_temp节点的哪个部分插入 待删除节点的右子树
                        if(cur_temp->Lchild==NULL){
                            cur_temp->Lchild=CurNode->Rchild;
                        }
                        else{
                            cur_temp->Rchild=CurNode->Rchild;
                        }
                        //看前驱的左侧链接还是右侧链接
                        if(opt==1){
                            PreNode->Lchild=CurNode->Lchild;
                        }
                        if(opt==2){
                            PreNode->Rchild=CurNode->Lchild;
                        }
                    }
                    //在右半部分 其中操作通上述
                    else{
                        if(cur_temp->Lchild==NULL){
                            cur_temp->Lchild=CurNode->Lchild;
                        }
                        else{
                            cur_temp->Rchild=CurNode->Lchild;
                        }
                        //删除节点和亲本节点的关系不同 则链接上的方式也不同
                        if(opt==1){
                            PreNode->Lchild=CurNode->Rchild;
                        }
                        if(opt==2){
                            PreNode->Rchild=CurNode->Rchild;
                        }
                    }
                    free(CurNode);//释放待删除的节点
                    break;
                }
                //添加元素进队列 层序遍历法
                AddElem(&queue,cur_temp->Lchild->data);
                AddElem(&queue,cur_temp->Rchild->data);
            }
        }
    }
    return flag;
}


//其实进行删除的时候 没有必要将真正的节点断开 直接将末尾的值拷贝到头即可 然后删除末尾 尽可能少地破坏该树状结构
//在VAL树以及Heap堆中都是采用该方法进行节点的删除以及调整








