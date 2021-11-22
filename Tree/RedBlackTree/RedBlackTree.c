//
// Created by 周龙 on 2021/11/13.
//

#include "RedBlackTree.h"

RBTreePointer Insert(RBTreePointer Tree, Item data) {
    //节点不存在
    if (!Tree) {
        Tree = (RBTreePointer) malloc(sizeof(RBTree));//Allocate the memory
        Tree->P = Tree->Lchild = Tree->Rchild = (RBTreePointer) malloc(sizeof(RBTree));//The parent of root is null
        Tree->data = data;
        Tree->color=Black;
        Tree->P->color=Black;//Set the color of nil black
        return Tree;
    } else {
        RBTreePointer Reserve = Tree;//Reserve the node of the tree
        //Find the site to insert
        RBTreePointer nil=Reserve->P;//The node of nil
        RBTreePointer Pre = Tree;//To record the predecessor of node
        while (Tree!=nil) {
            Pre = Tree;//记录前驱 用于更新
            if (data == Tree->data) {
                //存在相同的内容无需插入
                return Reserve;
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
        RBTreePointer New_node = (RBTreePointer) malloc(sizeof(RBTree));
        New_node->data = data;
        New_node->Rchild = New_node->Lchild = nil;
        New_node->color=Red;//The new insert node must be red
        New_node->P = Pre;
        //在右侧插入
        if (data > Pre->data)
            Pre->Rchild = New_node;
            //在左侧插入
        else
            Pre->Lchild = New_node;
        Tree= RB_Insert_Fixup(Reserve,New_node);
        return Tree;//Fixup the color of red black tree
    }
}

//6种情况 3种对称
RBTreePointer RB_Insert_Fixup(RBTreePointer Tree,RBTreePointer Node){
    RBTreePointer Reserve=Tree;
    RBTreePointer Nil=Tree->P;
    //The conflict of node
    while(Node->P->color==Red){
        //左侧
        if(Node->P==Node->P->P->Lchild){
            RBTreePointer Temp=Node->P->P->Rchild;
            //The uncle of the node is red
            if(Temp->color==Red){
                Node->P->color=Black;
                Temp->color=Black;
                Node=Node->P->P;
            }
            else{
                //判断是否需要左旋
                if(Node==Node->P->Rchild){
                    Node=Node->P;
                    //此处的根节点不会发生旋转
                    LeftRotate(Tree,Node);//Node left rotate
                }
                //处理右旋 判断根节点是否需要参加右旋
                //Node 为red 令node->p 为 black 保证不冲突 而后旋转 使节点node->p->p为中间节点
                Node->P->color=Black;
                Node->P->P->color=Red;
                //为根节点
                if(Node->P->P==Tree){
                    //修改根节点
                    RBTreePointer temp = RightRotate(Tree,Node->P->P);
                    Reserve=temp;
                }
                else{
                    RightRotate(Tree,Node->P->P);//Just right rotate
                }
            }
        }
        else{
            RBTreePointer Temp=Node->P->P->Lchild;
            //The uncle of the node is red
            if(Temp->color==Red){
                Node->P->color=Black;
                Temp->color=Black;
                Node=Node->P->P;
            }
            //右侧
            else{
                //判断是否需要右旋
                if(Node==Node->P->Lchild){
                    Node=Node->P;
                    //此处的根节点不会发生旋转
                    RightRotate(Tree,Node);//Node left rotate
                }
                //处理左旋 判断根节点是否需要参加左旋
                //Node 为red 令node->p 为 black 保证不冲突 而后旋转 使节点node->p->p为中间节点
                Node->P->color=Black;
                Node->P->P->color=Red;
                RBTreePointer temp=(RBTreePointer)malloc(sizeof(RBTree));
                //为根节点
                if(Node->P->P==Tree){
                    //修改根节点
                    temp = LeftRotate(Tree,Node->P->P);
                    Reserve=temp;
                }
                else{
                    LeftRotate(Tree,Node->P->P);//Just left rotate
                }
            }
        }
        //Fix the color of root
        Reserve->color=Black;
        Reserve->P=Nil;
        Reserve->P->color=Black;
    }
    return Reserve;
}






//左旋
RBTreePointer LeftRotate(RBTreePointer Tree,RBTreePointer Node){
    RBTreePointer nil = Tree->P;
    RBTreePointer temp=Node->Rchild;
    Node->Rchild=temp->Lchild;//连上child
    if(temp->Lchild!=nil){
        temp->Lchild->P=Node;//修改parent指针
    }
    //修改Node的亲节点
    temp->P=Node->P;
    //为ROOT
    if(Node->P!=nil){
        //左侧
        if(Node->P->Lchild==Node){
            Node->P->Lchild=temp;
        }
        //右侧
        else{
            Node->P->Rchild=temp;
        }
    }
    //链接node和temp
    temp->Lchild=Node;
    Node->P=temp;
    return temp;//返回旋转后的节点
}



//右旋
RBTreePointer RightRotate(RBTreePointer Tree,RBTreePointer Node){
    RBTreePointer nil = Tree->P;
    RBTreePointer temp=Node->Lchild;
    Node->Lchild=temp->Rchild;//连上child
    //是否是nil节点
    if(temp->Rchild!=nil){
        temp->Rchild->P=Node;//修改parent指针
    }
    //修改Node的亲节点
    //为ROOT
    temp->P=Node->P;
    if(Node->P!=nil){
        //左侧
        if(Node->P->Lchild==Node){
            Node->P->Lchild=temp;
        }
            //右侧
        else{
            Node->P->Rchild=temp;
        }
    }
    //链接node和temp
    temp->Rchild=Node;
    Node->P=temp;
    return temp;//返回旋转后的节点
}


//Traverse the binary search tree
void InorderTraverse(RBTreePointer Tree,RBTreePointer nil) {
    //Traverse the data of tree
    if (Tree == nil ) {
        return;
    } else {
        //The Inorder Traverse
        InorderTraverse(Tree->Lchild,nil);
        printf("Data=%d Color=%d\n", Tree->data,Tree->color);
        InorderTraverse(Tree->Rchild,nil);
    }
}

bool RBDelete(RBTreePointer *Tree,Item data){
    /*
     * 沿用z的删除方式 使用y作为带插入的节点 而使用x作为新拼接上的节点
     * y插入z并不会导致节点内容的丢失 节点内容的丢失在x点处
     * 因而需要记录y源的颜色 如果为黑
     * 则表明在x进行替代的过程中使黑色节点的个数减少了
     */
    //使用指针传入的方式以便能修改指针
    RBTreePointer *Restore=Tree;//直接保存二级指针的值
    RBTreePointer Temp=*Tree;//指向Tree
    int flag;
    RBTreePointer z = Search(Temp,data);
    if(z==(*Tree)->P){
        printf("The node is not exists\n");
        return 0;//The node is not exists
    }
    RBTreePointer y=z;
    RBTreePointer x;
    int y_original_color=y->color;//记录y的原始颜色
    //开始delete
    if (z->Lchild ==(*Tree)->P ) {
        //connect the Rchild
        x=z->Rchild;//记录拼接的位置
        TransPlant(Restore, z, z->Rchild);
    }
    else if (z->Rchild == (*Tree)->P) {
        //connect the Lchild
        x=z->Lchild;//同上
        TransPlant(Restore,x, x->Lchild);
    }
    else{
        y= Minimize(*Restore,z->Rchild);
        y_original_color=y->color;//找到y的位置 即后继节点
        x=y->Rchild;//即将拼接的节点
        
        /*
        * 这一部分是十分关键的！！！！！！
        * 并不是多余的操作
        * 本身x如果为nil那么p是随意指向的
        * 那么如果在后面进行调整的时候是无法完成的
        * 因而需要修改x的p的指向 令p就是指向的删除的节点
        */
        
        x->P=y;
        if (y!= z->Rchild) {
            TransPlant(Tree,y,x);//concat the node
            y->Rchild = z->Rchild;
            y->Rchild->P = y;
        }
        //The successor must in the right of the node
        TransPlant(Restore,z,y);//拼接y到z的位置
        y->color=z->color;//修改y的颜色
        //处理z的左节点
        y->Lchild=z->Lchild;
        y->Lchild->P = y;
    }
    if(y_original_color==Black){
        *Tree= RB_Delete_Fixup(*Tree,x);
    }
    return 1;
}




RBTreePointer RB_Delete_Fixup(RBTreePointer Tree,RBTreePointer x){
    RBTreePointer Restore = Tree;
    RBTreePointer w;
    //为了分担这个黑色的节点
    while(x!=Tree && x->color==Black){
        //在左侧
        if(x==x->P->Lchild){
            printf("The node is left.\n");
            w=x->P->Rchild;//sibling node
            //为红则以w节点作为黑节点的消解节点
            if(w->color==Red){
                //旋转时一定要随时注意根节点的位置
                w->color=Black;//消解黑色节点
                x->P->color=Red;
                //若为根节点
                if(x==Tree)
                    //修改Tree的值然后用于返回
                    Tree= LeftRotate(Restore,x->P);
                else
                    LeftRotate(Restore,x->P);
            }
            //节点颜色为黑色
            else{
                //两个都是黑色
                if(w->Lchild->color==Black&&w->Rchild->color==Black){
                    w->color=Red;
                    x=x->P;//把Black向上推 直接结束循环 在循环体结束后为x的颜色赋值为Black
                    //不管剩下的红节点了吗
                }
                //右侧为Black
                else {
                    //右侧
                    if (w->Rchild->color == Black) {
                        w->Lchild->color = Red;
                        w->color = Red;
                        //右旋w不会是根节点 则直接旋转就行
                        RightRotate(Restore, w);
                        w = x->P->Rchild;//重回原位置
                    }
                    //左侧
                    w->color=x->P->color;
                    x->P->color=Black;//旋转后不破坏prenode
                    w->Rchild->color=Black;//借助w的Rchild消解掉多余的黑色节点
                    //观察是否处理到了root
                    if(x->P==Tree){
                        Tree= LeftRotate(Restore,x->P);
                    }
                    else{
                        LeftRotate(Restore,x->P);
                    }
                    x=Tree;//x为根节点
                }
            }
        }
        //X在右侧
        else{
            printf("The node is in the right.\n");//由于不完整的删除会导致红黑树的w为nil
//            return Tree;
            //在右侧
            if(x==x->P->Rchild){
                w=x->P->Lchild;//sibling node
                //为红则以w节点作为黑节点的消解节点
                if(w->color==Red){
                    //旋转时一定要随时注意根节点的位置
                    w->color=Black;//消解黑色节点
                    x->P->color=Red;
                    //若为根节点
                    if(x==Tree)
                        //修改Tree的值然后用于返回
                        Tree= RightRotate(Restore,x->P);
                    else
                        RightRotate(Restore,x->P);
                }
                    //节点颜色为黑色
                else{
                    //两个都是黑色
                    if(w->Lchild->color==Black&&w->Rchild->color==Black){
                        w->color=Red;
                        x=x->P;//把Black向上推 直接结束循环 在循环体结束后为x的颜色赋值为Black
                        //不管剩下的红节点了吗 在节点结束后抹去颜色
                    }
                        //右侧为Black
                    else {
                        //左侧
                        if (w->Lchild->color == Black) {
                            w->Rchild->color = Red;
                            w->color = Red;
                            //左旋w不会是根节点 则直接旋转就行
                            LeftRotate(Restore, w);
                            w = x->P->Lchild;//重回原位置
                        }
                        //左侧
                        w->color=x->P->color;
                        x->P->color=Black;//旋转后不破坏prenode
                        w->Lchild->color=Black;//借助w的Lchild消解掉多余的黑色节点
                        //观察是否处理到了root
                        if(x->P==Tree){
                            Tree= RightRotate(Restore,x->P);
                        }
                        else{
                            RightRotate(Restore,x->P);
                        }
                        x=Tree;//x为根节点
                    }
                }
            }
        }
    }
    x->color=Black;
    return Tree;
}




//Let v be u->parent->child
void TransPlant(RBTreePointer *Tree, RBTreePointer u, RBTreePointer v) {
    //Reverse the root
    if (u->P ==(*Tree)->P) {
        *Tree = v;//The v is the root of BST
    }
        //The left child
    else if (u == u->P->Lchild) {
        u->P->Lchild = v;
    } else {
        u->P->Rchild = v;
    }
    //由于NULL代表一个nil节点 则无需判断 直接全指 为空也指
    v->P = u->P;//尽管是nil 它的parent已然需要往前指 改动节点为v
}



RBTreePointer Minimize(RBTreePointer Tree,RBTreePointer node) {
    RBTreePointer pre = Tree->P;
    while (node != Tree->P) {
        pre = node;
        node = node->Lchild;//Minimize data is always in the left
    }
    return pre;
}

RBTreePointer Maximum(RBTreePointer Tree,RBTreePointer node) {
    RBTreePointer pre = Tree->P;
    while (node != Tree->P) {
        pre = node;
        node = node->Rchild;//Minimize data is always in the left
    }
    return pre;
}

//Visit the successor of the assign node from binary search tree
RBTreePointer Successor(RBTreePointer Tree, Item data) {
    RBTreePointer Temp=Tree;
    RBTreePointer KeyNode = Search(Temp, data);//Find the node which will  delete
    if (KeyNode == Temp->P) {
        return Temp->P;
    }
    if (KeyNode->Rchild) {
        return Minimize(Tree,KeyNode->Rchild);
    } else {
        //Find the pre data
        RBTreePointer pre = KeyNode->P;
        while (pre && pre->Rchild == KeyNode) {
            KeyNode = KeyNode->P;
            pre = KeyNode->P;
        }
        return pre;
        //直到找到root或者node 如果是root表明没有节点为前驱 返回NULL
    }
}


//Search the item from binary search tree
RBTreePointer Search(RBTreePointer Tree, Item data) {
    RBTreePointer Temp=Tree;
    //Find the node which data equal to data
    while (Temp != Tree->P) {
        if (data == Temp->data) {
            return Temp;
        } else if (Temp->data < data) {
            Temp = Temp->Rchild;
        } else {
            Temp = Temp->Lchild;
        }
    }
    return Tree->P;//If the search is fail
}

