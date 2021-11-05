//
// Created by 龙舌兰 on 2021/9/25.
//
#include "SString.h"
#include <string.h>
#include <stdio.h>

//初始化 末尾可以不用'\0'作结束标记
bool StrAssign(unsigned char *T, const unsigned char *chars) {
    bool flag = 1;
    int index = 1;
    T[0] = 0;
    while (*chars != '\0') {
        if (index > MAXSIZE) {
            flag = 0;
            fprintf(stderr, "The str is full.\n");
            return flag;
        }
        T[index++] = *chars++;
        T[0]++;//表示字符串的长度
    }
    return flag;
}

void TraverseString(const unsigned char *S) {
    for (int i = 1; i <= S[0]; i++) {
        putchar(S[i]);
    }
    putc('\n', stdout);
}


void StrCopy(unsigned char *T, const unsigned char *S) {
    //拷贝和字符串自身的容量有关 但在同样的字符串类型中 容量是一致的
    for (int i = 0; i <= S[0]; i++) {
        T[i] = S[i];
    }
}

bool StrEmpty(const unsigned char *S) {
    int flag = 0;
    //表示字符串为空
    if (S[0] <= 0) {
        flag = 1;
    }
    return flag;
}

size_t StrLength(const char *S) {
    size_t length = (size_t) S[0];//返回字符串的长度
    return length;
}

void ClearString(unsigned char *S) {
    //从尾部开始置0
    size_t length = StrLength(S);
    for (int i = (int) length; i >= 0; i--) {
        S[i] = 0;
    }
    //直至头部都为0
}

bool Concat(unsigned char *T, const unsigned char *S1, const unsigned char *S2) {
    int flag = 0;
    if (S1[0] + S2[0] <= MAXSIZE) {
        T[0] = S1[0] + S2[0];
        for (int i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        for (int i = 1; i <= S2[0]; i++) {
            T[S1[0] + i] = S2[i];
        }
    } else {
        flag = 1;//发生了截断
        //判断在何处发生了截断
        //1.S1处
        if (S1[0] == MAXSIZE) {
            StrCopy(T, S1);
        }
            //2.S2处
        else {
            StrCopy(T, S1);
            //计算剩余长度
            for (int i = 1; i <= MAXSIZE - S1[0]; i++) {
                T[S1[0] + i] = S2[i];
            }
        }
    }
    return flag;
}


bool SubString(unsigned const char *S, unsigned char *SubStr, int pos, int len) {
    bool flag = 1;
    //非法索引
    if (pos <= 0 || pos > S[0] - len) {
        flag = 0;
        fprintf(stderr, "Invalid index for substr.\n");
        return flag;
    }
    for (int i = pos; i < pos + len; i++) {
        SubStr[i - pos + 1] = S[pos];
    }
    SubStr[0] = (unsigned char) len;
    return flag;
}


//KMP字符串匹配算法
int Index_SubStr(char *S, char *Substr) {
    int Sub_length = (int) strlen(Substr);
    int S_length = (int) strlen(S);
    //创建next数组
    int next[strlen(Substr)];
    next[0] = -1;//特殊节点 表示不匹配
    next[1] = 0;//表示1不匹配后访问0节点
    //初始化next数组
    for (int i = 2; i < Sub_length; i++) {
        next[i] = 0;
    }
    for (int i = 2; i < Sub_length; i++) {
        //每次都从头开始匹配
        int index = 0;
        //匹配字符串
        while (Substr[index] == Substr[i + index - 1]) {
            index++;
            //最长跨度的重复子串
            if (next[i + index - 1] < index) {
                next[i + index - 1] = index;
            }
        }
    }
    for (int i = 0; i < Sub_length; i++) {
        printf("%d ", next[i]);
    }
    putchar('\n');
    //改进next数组 看其索引下标中是否有相同的元素
    for (int i = 1; i < Sub_length; i++) {
        if (Substr[next[i]] == Substr[i]) {
            next[i] = next[next[i]];//如果有则表示该处不匹配 直接令其等于不匹配后的index
        }
    }
    int i=0,index;
    while(i<=S_length-Sub_length){
        index = 0;
        while(1) {
            //主串的自增条件
            while (S[i] == Substr[index]) {
                i++;//可以匹配 i自增
                index++;
                //Success compare
                if (index == Sub_length) {
                    index=i-Sub_length;
                    return index;
                }
            }
            //不匹配 则去向下一次匹配的内容
            index=next[index];
            if(index==-1){
                i++;//头无法匹配 i自增
                break;
            }
        }
    }
    index=-1;
    return index;
}


//串的插入
bool StrInset(unsigned char *S, unsigned const char *T, int pos) {
    int flag = 1;
    if (pos > S[0]) {
        flag = 0;
        fprintf(stderr, "Invalid index.\n");
        return flag;
    }
    if (S[0] + T[0] > MAXSIZE) {
        flag = 0;
        fprintf(stderr, "The string is full.\n");
        return flag;
    }
    //移动S的内容
    for (int i = S[0]; i >= pos; i--) {
        S[i + T[0]] = S[i];
    }
    for (int i = pos; i < T[0] + pos; i++) {
        S[i] = T[i - pos + 1];
    }
    S[0] += T[0];//更新S的长度
    return flag;
}

bool StrDelete(unsigned char *S, int pos, int len) {
    bool flag = 1;
    if (pos + len > S[0]) {
        flag = 0;
        fprintf(stderr, "Invalid Delete.\n");
        return flag;
    }
    //先置为0
    for (int i = pos; i < pos + len; i++) {
        S[i] = 0;
    }
    //元素向前移
    for (int i = pos; i < S[0] + 1 - len; i++) {
        S[i] = S[i + len];
    }
    S[0] -= len;
    return flag;
}



