//
// Created by 周龙 on 2021/11/19.
//

#include "LinkHash.h"

//关键的是hash函数的设置 和hash大小的选取 根据length选取大小


Hash Initial(int n){
    //如何计算素数
    //该处可以更改 沿用算法导论中的3次比对假设
    int res= SimpleNumber(n/3);//素数能够极大程度使hash分布均匀
//    int res=n;
    Hash hash=(Hash)malloc(sizeof(hashtable));
    if(hash==NULL){
        fprintf(stderr,"Fail to allocate the memory.\n");
        return NULL;
    }
    hash->size=res;
    //为计算出的hash长度的hash表分配空间
    hash->data=(Link)malloc(sizeof(node)*res);
    if(hash->data==NULL){
        fprintf(stderr,"Fail to allocate the memory.\n");
        return NULL;
    }
    for(int i=0;i<res;i++){
        hash->data[i].data=0;//统计节点个数
        hash->data[i].next=NULL;//作为链表的结束 头节点不需要设置Parent
    }
    return hash;
}


void Insert(Hash T,int data){
    //计算地址
    int key= HashFunction_D(T,data);//使用乘法的形式计算
    Link Node= NewNode(data);
    if(T->data[key].data==0){
        T->data[key].data=1;
        T->data[key].next= Node;
        Node->p=&(T->data[key]);
    }
    else{
        //在头部插入
        Node->p=&(T->data[key]);//指向头节点
        T->data[key].next->p=Node;
        Node->next=T->data[key].next;
        T->data[key].next=Node;
        T->data[key].data++;//节点个数+1
    }
}


Link Search(Hash T,int data){
    int key= HashFunction_D(T,data);//要和Insert等使用同一个Hash函数 否则会失败
    if(T->data[key].data==0){
        return NULL;//查找失败
    }
    Link temp=T->data[key].next;//首个节点
    while(temp!=NULL){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;//查找失败
}

bool Delete(Hash T,int data){
    Link Node= Search(T,data);
    //查找失败
    if(Node==NULL){
        printf("The node is not exist\n");
        return 0;
    }
    //删除该节点
    Node->p->next=Node->next;
    if(Node->next!=NULL){
        Node->next->p=Node->p;
    }
    free(Node);//删除该节点
    return 1;//删除成功
}

Link NewNode(int data){
    Link L=(Link)malloc(sizeof(node));
    L->data=data;
    L->next=NULL;
    return L;
}


//查找接近n的最大素数
int SimpleNumber(int n){
    int res=1;
    for(int i=n;i>=1;i--){
        if(IsSimpleNumber(i)){
            res=i;
            return res;
        }
    }
    return res;
}


//辅助判断是否为素数
int IsSimpleNumber(int N){
    int flag=1;
    if(N<=1){
        flag=0;
        return flag;
    }
    if(N==2||N==3){
        flag=1;
        return flag;
    }
    //要排除小于6的基础特殊数 1 2 3
    if(N%6!=1&&N%6!=5){
        flag=0;
        return flag;
    }
    /*
     * 因式分解的原理
     * 前面一轮的取余判断已经证明了该数必为6x+1或者6x-1(即6x+5)
     * 下面循环判断存不存在6x+1或者6x-1的因子 如果不存在则表示为素数
     * 如果存在因子则表示不可能为素数
     */
    for(int i=5;i<= sqrt(N);i+=6){
        //只存在两种组合的可能
        if(N%i==0||N%(i+2)==0) {
            flag = 0;
            return flag;
        }
    }
    return flag;
}

//哈希函数 用于计算散列的地址
int HashFunction_D(Hash T,int key){
    return key%T->size;
}

int HashFunction_M(Hash T,int key){
    //A为既定参数 取小数后再取整数 乘法构造思想 见算法导论
    double A=0.618;
    double Decimal=key*A-floor(A*key);
    return floor((T->size*Decimal));
}


void Traverse(Hash T){
    for(int i=0;i<T->size;i++){
        printf("Node%d: ",i);
        if(T->data[i].data==0){
            printf("NULL\n");
        }
        else{
            Link temp=T->data[i].next;
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
            }
            putchar('\n');
        }
    }
}



