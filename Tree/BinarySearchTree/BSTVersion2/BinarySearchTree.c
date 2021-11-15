//
// Created by 周龙 on 2021/11/13.
//

#include "BinarySearchTree.h"

//The help function of concat
void TransPlant(NodePointer *Tree, NodePointer u, NodePointer v);

static NodePointer Minimize(NodePointer node);

static NodePointer Maximum(NodePointer node);

//Inserting the node into binary search tree
NodePointer Insert(NodePointer Tree, Item data) {
    NodePointer Temp = Tree;//保存源节点
    //节点不存在
    if (!Tree) {
        Tree = (NodePointer) malloc(sizeof(Node));//Allocate the memory
        Tree->P = Tree->Lchild = Tree->Rchild = NULL;//The parent of root is null
        Tree->data = data;
        return Tree;
    } else {
        //Find the site to insert
        NodePointer Pre = NULL;
        while (Tree) {
            Pre = Tree;//记录前驱 用于更新
            if (data == Tree->data) {
                //存在相同的内容无需插入
                return Tree;
            }
            if (data > Tree->data) {
                //大于则在右边
                Tree = Tree->Rchild;
            } else {
                //小于则在左边
                Tree = Tree->Lchild;
            }
        }
        //找到待插入的空节点 Pre不可能不存在
        NodePointer New_node = (NodePointer) malloc(sizeof(Node));
        New_node->data = data;
        New_node->Rchild = New_node->Lchild = NULL;
        New_node->P = Pre;
        //在右侧插入
        if (data > Pre->data)
            Pre->Rchild = New_node;
            //在左侧插入
        else
            Pre->Lchild = New_node;
        return Temp;
    }
}


//Search the item from binary search tree
NodePointer Search(NodePointer Tree, Item data) {
    //Find the node which data equal to data
    while (Tree != NULL) {
        if (data == Tree->data) {
            return Tree;
        } else if (Tree->data < data) {
            Tree = Tree->Rchild;
        } else {
            Tree = Tree->Lchild;
        }
    }
    return NULL;//If the search is fail
}


//Delete the node from binary search tree
bool Delete(NodePointer *Tree, Item data) {
    NodePointer Reserve = *Tree;//Restore the root
    int flag = 0;
    //分四种情况删除 如果删除根节点会如何？？

    //Find the node wait to delete
    NodePointer KeyNode = Search(Reserve, data);
    if (KeyNode == NULL) {
        return flag;//The node is not exist
    }
    //The Left Child if null
    if (KeyNode->Lchild == NULL) {
        //connect the Rchild
        TransPlant(Tree, KeyNode, KeyNode->Rchild);
    } else if (KeyNode->Rchild == NULL) {
        //connect the Lchild
        TransPlant(Tree, KeyNode, KeyNode->Lchild);
    }
        //Both of the child are existing
    else {
        //If the successor not in the right of the node
        NodePointer Suc_Node = Successor(Reserve, data);//Find the successor of node
        if (Suc_Node != KeyNode->Rchild) {
            TransPlant(Tree, Suc_Node, Suc_Node->Rchild);//concat the node
            Suc_Node->Rchild = KeyNode->Rchild;
            KeyNode->Rchild->P = Suc_Node;
        }
        //The successor must in the right of the node
        KeyNode->Lchild->P = Suc_Node;
        Suc_Node->Lchild = KeyNode->Lchild;
        TransPlant(Tree, KeyNode, Suc_Node);//concat the node, reach the aim to delete the node named KeyNode
    }
    flag = 1;
    return flag;
}


//Visit the prenode of the assign node from  binary search tree
NodePointer Predecessor(NodePointer Tree, Item data) {
    NodePointer KeyNode = Search(Tree, data);//Find the node which will  delete
    if (KeyNode == NULL) {
        return NULL;//The node is not exists
    }
    if (KeyNode->Lchild) {
        return Maximum(KeyNode->Lchild);
    } else {
        //Find the pre data
        NodePointer pre = KeyNode->P;
        while (pre && pre->Lchild == KeyNode) {
            KeyNode = KeyNode->P;
            pre = KeyNode->P;
        }
        return pre;
        //直到找到root或者node 如果是root表明没有节点为前驱 返回NULL
    }
}

//Visit the successor of the assign node from binary search tree
NodePointer Successor(NodePointer Tree, Item data) {
    NodePointer KeyNode = Search(Tree, data);//Find the node which will  delete
    if (KeyNode == NULL) {
        return NULL;
    }
    if (KeyNode->Rchild) {
        return Minimize(KeyNode->Rchild);
    } else {
        //Find the pre data
        NodePointer pre = KeyNode->P;
        while (pre && pre->Rchild == KeyNode) {
            KeyNode = KeyNode->P;
            pre = KeyNode->P;
        }
        return pre;
        //直到找到root或者node 如果是root表明没有节点为前驱 返回NULL
    }
}

//Traverse the binary search tree
void InorderTraverse(NodePointer Tree) {
    //Traverse the data of tree
    if (Tree == NULL) {
        return;
    } else {
        //The Inorder Traverse
        InorderTraverse(Tree->Lchild);
        printf("%d ", Tree->data);
        InorderTraverse(Tree->Rchild);
    }
}


NodePointer Minimize(NodePointer node) {
    NodePointer pre = NULL;
    while (node != NULL) {
        pre = node;
        node = node->Lchild;//Minimize data is always in the left
    }
    return pre;
}

static NodePointer Maximum(NodePointer node) {
    NodePointer pre = NULL;
    while (node != NULL) {
        pre = node;
        node = node->Rchild;//Minimize data is always in the left
    }
    return pre;
}


//Let v be u->parent->child
void TransPlant(NodePointer *Tree, NodePointer u, NodePointer v) {
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
