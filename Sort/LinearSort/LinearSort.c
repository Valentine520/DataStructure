//
// Created by ���� on 2021/11/30.
//

#include "LinearSort.h"

//��ӡ�����Ԫ��
void ShowArray(int *array,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    putc('\n',stdout);
}

//Ѱ�������е����ֵ
int MaxNum(const int *array,int size){
    int max = array[0];
    for(int i=1;i<size;i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
}
//��������
void CountSort(int *array,int size){
    int k = MaxNum(array, size);
    printf("%d\n",k);
    Count(array,size,k);
}

void Count(int *array,int size,int k){
    //����k��С�Ŀռ��¼array��������ͬ�Ĵ���
    int buf[k+1];
    int B[size];
    //ע��Ա߽��������ж� �ô�buf�е�iӦ�������ȡ��k ���������е����Ԫ��
    for(int i=0;i<=k;i++){
        buf[i] = 0;
    }
    //����Ԫ���е���ͬԪ��
    for(int i=0;i<size;i++){
        buf[array[i]]++;//��ͬԪ������
    }
    //Less and Equal ����
    for(int i=1;i<=k;i++){
        buf[i]+=buf[i-1];
    }
    //��size-1��ʼ��֤ԭ�����ģ�count���ں��� ����֤�㷨���ȶ���
    for(int i=size-1;i>=0;i--){
        B[buf[array[i]]-1]=array[i];//���ռ���ȥ����Ԫ�ص�λ��
        buf[array[i]]--;//������ͬԪ��
    }
    //��Ԫ�ؿ�����ԭ����
    for(int i=0;i<size;i++){
        array[i] = B[i];
    }
}

//��������
void RadixSort(int *array,int size){
    //ͬ���������Ԫ��k ��k��Ԫ�ع�ģȷ���������
    int k = MaxNum(array,size);
    int i=1;
    //�߽�����Ҫ��׼ ����kΪ0���ֹͣ k���Ϊ��λ����ʾ�����Խ������λ�ıȽ�
    while(k>=1){
        Mysort(array,i,size);//��Ҫʹ���ȶ����� ���ÿ�εĻ�����������
        i*=10;
        k/=10;//ÿ����k/10 �������е����λ��/10
    }
}


//��iָ���ķ����ָ�λ�� iΪ1 n/i%10 ����
//�Բ�ͬ��λ���м������� �Դﵽ���������������ݵ�Ч��
void Mysort(int *array,int m,int size){
    int k=10;//�����������������Ϊ9
    //����k��С�Ŀռ��¼array��������ͬ�Ĵ���
    int buf[k+1];
    int *B = (int*)malloc(sizeof(int)*size);
    //ע��Ա߽��������ж� �ô�buf�е�iӦ�������ȡ��k ���������е����Ԫ��
    for(int i=0;i<=k;i++){
        buf[i] = 0;
    }
    for(int i=0;i<size;i++){
        buf[array[i]/m%10]++;//Ԫ������
    }
    //Less and Equal ����
    for(int i=1;i<=k;i++){
        buf[i]+=buf[i-1];
    }
    for(int i=size-1;i>=0;i--){
        B[buf[(array[i]/m%10)]-1]=array[i];//���ռ���ȥ����Ԫ�ص�λ��
        buf[array[i]/m%10]--;//������ͬԪ��
    }
    for(int i=0;i<size;i++){
        array[i] = B[i];
    }
    free(B);
}




//Ͱ����
void BucketSort(int *array,int size){
    //��������Ԫ�ص�Ͱ
    //��Ȼ����K���н�Ͱ
    int k = MaxNum(array,size);
    Link Bucket = (Link) malloc(sizeof (Node)*k);//������ģΪk��Ͱ
    for(int i=0;i<k;i++){
        Bucket[i].data=0;//��¼�Ƿ���Ԫ��
        Bucket[i].next=NULL;
        Bucket[i].pre=NULL;
    }
    for(int i=0;i<size;i++){
        InsertBucket(&Bucket[array[i]%10],array[i]);//��Ͱ�в���Ԫ��
    }
    //Ͱ��Ԫ�������ȡ��
    //����ͬͰ��Ԫ�ؽ��в�������
    for(int i=0;i<size;i++){
        BucketInsertSort(Bucket[i].next);
    }
    int site = 0;
    for(int i=0;i<k,site<size;i++){
        Link node = Bucket[i].next;
        while(node != NULL){
            array[site++] = node->data;
            node = node->next;
        }
    }
}



//��Ͱ�в�������
void InsertBucket(Link node,int data){
    //ֱ��ͷ�� �ڲ����ʵ������
    Link NewNode = (Link) malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->next = node->next;
    //�Ƿ�Ϊ�� ������ݿ�ָ��
    if(node->next!=NULL){
        node->next->pre=NewNode;
    }
    node->next = NewNode;
    NewNode->pre=node;
}


void BucketInsertSort(Link L){
    if(L==NULL||L->next==NULL){
        return;//ֻ��һ��Ԫ����������
    }
    Link head = L->pre;//ͷ�ڵ�
    Link node = L->next;//��������׸�����
    Link pre ;
    while(node!=NULL){
        pre = node->pre;
        Link temp=NULL;
        while(pre!=head){
            if(pre->data > node->data){
                pre=pre->pre;//��ǰ
            }
            else{
                break;
            }
        }
        temp = node->next;
        node->pre->next=node->next;
        if(node->next!=NULL){
            node->next->pre=node->pre;
        }
        node->next=pre->next;//������node
        if(pre->next!=NULL){
            pre->next->pre=node;
        }
        pre->next = node;
        node->pre = pre;
        node = temp;
    }
}