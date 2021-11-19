//
// Created by 周龙 on 2021/11/19.
//

#include "OpenHash.h"
static int IsSimpleNumber(int N);

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
static int IsSimpleNumber(int N){
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
    //??什么原理
    for(int i=5;i<= sqrt(N);i+=6){
        //只存在两种组合的可能
        if(N%i==0||N%(i+2)==0) {
            flag = 0;
            return flag;
        }
    }
    return flag;
}


Hash Initial(int n){
    //如何计算素数
    //该处可以更改 沿用算法导论中的3次比对假设
    int res= SimpleNumber(n/3);
    Hash hash=(Hash)malloc(sizeof(hashtable));
    if(hash==NULL){
        fprintf(stderr,"Fail to allocate the memory.\n");
        return NULL;
    }
    hash->size=res;
    //为计算出的hash长度的hash表分配空间
    hash->data=(int*)malloc(sizeof(int)*res);
    if(hash->data==NULL){
        fprintf(stderr,"Fail to allocate the memory.\n");
        return NULL;
    }
    for(int i=0;i<res;i++){
        hash->data[i]=MINIMIZE;
    }
    return hash;
}


int HashFunction_D(Hash T,int key){
    return key%T->size;
}

int HashFunction_M(Hash T,int key){
    //A为既定参数 取小数后再取整数 乘法构造思想 见算法导论
    double A=0.618;
    double Decimal=A-(int)floor(A*key);
    return floor((T->size*Decimal));
}

int Locate_L(Hash T,int site){
    return (site+1)%T->size;
}

int Locate_S(Hash T,int site){
    return (site*site)%T->size;
}

int Locate_M(Hash T,int site){
    int m=T->size-1;
    int res=(site+1+site%m)%T->size;
    return res;
}

//Insert Delete Search 均要满足同样的操作类型
//如hash函数相同、寻址方式相同
bool Insert(Hash T,int data){
    bool flag=0;
    int key= HashFunction_D(T,data);
    int site=key;
    while(T->data[site]!=DELETE&&T->data[site]!=MINIMIZE){
        site= Locate_M(T,site);
        //表示回到了原来的key位置 表示该hash满了
        if(site==key){
            fprintf(stderr,"The hash table is full.\n");
            return flag;
        }
    }
    T->data[site]=data;//为其赋值
    flag=1;
    return flag;
}

int Search(Hash T,int data){
    int key= HashFunction_D(T,data);
    int site=key;
    while(data!=T->data[site]){
        site= Locate_M(T,site);
        //表示回到了原来的key位置 表示该元素在hash表中不存在
        //如果元素遇到了一个空的地方 则表示也不存在 （如果为delete则跳过）
        if(site==key||T->data[site]==MINIMIZE){
            return -1;//表示未查找到
        }
    }
    return site;//返回元素在hash表中的位置
}

bool Delete(Hash T,int data){
    bool flag=0;
    int key= HashFunction_D(T,data);
    int site=key;
    while(data!=T->data[site]){
        site= Locate_M(T,site);
        //表示回到了原来的key位置 表示该元素在hash表中不存在
        //如果元素遇到了一个空的地方 则表示也不存在 （如果为delete则跳过）
        if(site==key||T->data[site]==MINIMIZE){
            return flag;
        }
    }
    T->data[site]=DELETE;//表示删除
    return site;//返回元素在hash表中的位置
}