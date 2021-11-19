//
// Created by 周龙 on 2021/11/17.
//

#include "TreapTree.h"
//插入节点
Treap Insert(Treap tree,int data){
    int priority=rand()%100;//100范围内的随机数
    //先按照二叉树的规则插入
    if(tree==NULL){
        tree=(Treap)malloc(sizeof(TreapTree));
        tree->value=data;
        tree->priority=priority;
        tree->P=tree->Lchild=tree->Rchild=NULL;
        return tree;
    }
    Treap temp=tree;
    Treap pre;
    while(temp!=NULL){
        pre=temp;
        if(data==temp->value){
            return tree;//相同节点 不插入
        }
        if(data>temp->value){
            temp=temp->Rchild;
        }
        else{
            temp=temp->Lchild;
        }
    }
    Treap NewNode=(Treap)malloc(sizeof(TreapTree));
    NewNode->value=data;
    NewNode->priority=priority;
    NewNode->Lchild=NewNode->Rchild=NULL;
    NewNode->P=pre;
    //插入位置则为temp Parent则为Pre
    if(data>pre->value){
        pre->Rchild=NewNode;
    }
    else{
        pre->Lchild=NewNode;
    }
    //向上调整
    tree=PercolateUp(tree,NewNode);
    return tree;
}

Treap PercolateUp(Treap tree,Treap node){
    Treap temp;
    while(node->P!=NULL){
        //维护为最小堆
        if(node->P->priority>node->priority){
            if(node->P->Lchild==node){
                //如果temp->P不为root
                if(node->P->P!=NULL){
                    if(node->P->P->Lchild==node->P){
                        temp=node->P->P;
                        temp->Lchild=RRotate(node);

                    }
                    else{
                        temp=node->P->P;
                        temp->Rchild=RRotate(node);
                    }
                }
                else{
                    tree=RRotate(node);
                    return tree;
                }
            }
            else{
                //如果temp->P不为root
                if(node->P->P!=NULL){
                    if(node->P->P->Lchild==node->P){
                        temp=node->P->P;
                        temp->Lchild=LRotate(node);

                    }
                    else{
                        temp=node->P->P;
                        temp->Rchild= LRotate(node);
                    }
                }
                else{
                    tree=LRotate(node);
                    return tree;
                }
            }
        }
        else
            break;
    }
    return tree;
}

Treap PercolateDown(Treap Tree,Treap node){
    Treap Temp=Tree;
    if(node==Tree){
        //查找priority最高(此处最小则为最高)的节点 更新根节点的指向
        if(Tree->Lchild!=NULL&&Tree->Rchild!=NULL){
            //左侧节点的优先级更高
            if(Tree->Lchild->priority<Tree->Rchild->priority){
                //右旋
                Tree= RRotate(node->Lchild);//右旋
            }
            else{
                Tree= LRotate(node->Rchild);//左旋
            }
        }
        else if(Tree->Lchild!=NULL){
            Tree= RRotate(node->Lchild);
        }
        else{
            Tree= LRotate(node->Rchild);
        }
    }
    //为根则修改Tree的指向 同时node也已经被更新 此时直接执行非Root的删除即可
    //查找左右两侧节点的最高优先级
    int Suc= Priority(node);
    Treap pre;
    while (Suc!=-1){
        pre=node->P;
        switch (Suc) {
            case 1:
                //左优先级高 则右旋
                //使根节点和旋转后的节点相连
                if(pre->Lchild==node){
                    pre->Lchild= RRotate(node->Lchild);
                }
                else{
                    pre->Rchild= RRotate(node->Lchild);
                }
                break;
            case 2:
                if(pre->Lchild==node){
                    pre->Lchild= LRotate(node->Rchild);
                }
                else{
                    pre->Rchild= LRotate(node->Rchild);
                }
                break;
            default:
                fprintf(stderr,"error\n");
        }
        Suc= Priority(node);
    }
    pre=node->P;
    //直到node变成了叶节点
    if(pre->Lchild==node){
        pre->Lchild=NULL;
    }
    else{
        pre->Rchild=NULL;
    }
    free(node);
    return Tree;
}

int Priority(Treap node){
    int flag;
    //两侧都为NULL则直接删除
    if(node->Lchild==NULL&&node->Rchild==NULL){
        return -1;//表示为叶节点 可以直接删除
    }
    if(node->Lchild==NULL){
        flag =2;//右侧大
    }
    else if(node->Rchild==NULL){
        flag=1;//左侧大
    }
    else{
        if(node->Lchild->priority<node->Rchild->priority){
            flag=1;//左侧优先级根高
        }
        else{
            flag=2;
        }
    }
    return flag;
}

Treap Delete(Treap Tree,int data){
    Treap temp = Tree;
    Treap node= Search(temp,data);
    int flag=0;
    if(node==NULL){
        fprintf(stderr,"The node is not exist.\n");
        return NULL;
    }
    //查找到该元素 从该节点下滤
    Tree= PercolateDown(Tree,node);
    return Tree;
}



//查找 二叉树的搜索
Treap Search(Treap tree,int data){
    Treap res=NULL;
    while(tree!=NULL){
        if(tree->value==data){
            res=tree;
            return res;
        }
        else if(tree->value>data){
            tree=tree->Lchild;
        }
        else{
            tree=tree->Rchild;
        }
    }
    return res;
}

//节点右旋
Treap RRotate(Treap node){
    Treap temp=node->P;
    //修改node的左侧节点
    temp->Lchild=node->Rchild;
    //判断是否NULL
    if(node->Rchild!=NULL){
        node->Rchild->P=temp;
    }
    //修改node
    node->P=temp->P;//修改parent指针
    node->Rchild=temp;
    temp->P=node;
    return node;//返回修改后的应该和parent相链的node
}

//节点左旋
Treap LRotate(Treap node){
    Treap temp=node->P;
    //修改node的左侧节点
    temp->Rchild=node->Lchild;
    //判断是否NULL
    if(node->Lchild!=NULL){
        node->Lchild->P=temp;
    }
    //修改node
    node->P=temp->P;//修改parent指针
    node->Lchild=temp;
    temp->P=node;
    return node;//返回修改后的应该和parent相链的node
}

void Traverse(Treap tree){
    //中序遍历
    if(tree==NULL){
        return;
    }
    else{
        Traverse(tree->Lchild);
        printf("value:%d priority:%d\n",tree->value,tree->priority);
        Traverse(tree->Rchild);
    }
}

//查找节点的后继
Treap Successor(Treap node){
    Treap temp=node->Rchild;
    Treap suc=temp;
    while(temp!=NULL){
        suc=temp;
        temp=temp->Lchild;
    }
    return suc;
}


//Let v be u->parent->child
void TransPlant(Treap *Tree, Treap u,Treap v) {
    //Reverse the root
    if (u->P == NULL) {
        *Tree = v;//The v is the root of BST
    }
        //The left child
    else if (u == u->P->Lchild) {
        u->P->Lchild = v;
    } else {
        u->P->Rchild = v;
    }
    if (v) {
        v->P = u->P;
    }
}
