//
// Created by 龙舌兰 on 2021/9/25.
//

//基于定长线性数组的String
#ifndef SSTRING_SSTRING_H
#define SSTRING_SSTRING_H
#define MAXSIZE 250
#include <stdlib.h>
//首行元素用于存放数组的大小 无需遍历则可以获取其长度
typedef unsigned char SString[MAXSIZE+1];

typedef _Bool bool;

//字符串的通用ADT


//串的初始化
/*
 * 初始条件：chars是字符串常量
 * 操作结果：生成一个值等于chars的串T
 */
bool StrAssign(unsigned char *T,const unsigned char *chars);


//串的拷贝
/*
 * 初始条件：串S存在
 * 操作结果：由串S复制得到串T
 */
void StrCopy(unsigned char *T,const unsigned char *S);


//串是否空
/*
 * 初始条件:串S存在
 * 操作结果：若S为空串，则返回True 否则返回false
 */
bool StrEmpty(const unsigned char *S);


//打印串的内容
/*
 * 初始条件：串S存在
 * 操作结果：打印S中的内容
 */
void TraverseString(const unsigned char *S);



//串的长度
/*
 * 初始条件：串S存在
 * 操作结果：返回串S的长度
 */
size_t StrLength(const char *S);



//清空串
/*
 * 初始条件：串S存在
 * 操作结果：将S清空为空串
 */
void ClearString(unsigned char *S);



//拼接串 (strncpy)
/*
 * 初始条件：串S1 串S2均存在
 * 操作结果：用T返回由S1和S2联结而成的新串 如果发生了截断 返回0 否则返回1
 */
bool Concat(unsigned char *T,const unsigned char *S1,const unsigned char *S2);


//返回子串
/*
 * 初始条件：串S存在 （1<=pos<=StrLength(S) and 0<=len<=StrLength(S)-pos+1 (合法索引)
 * 操作结果：用SubStr返回串S的第pos个字符起长度为len的子串
 */
bool SubString(unsigned const char *S,unsigned char *SubStr,int pos,int len);



//查找子串 KMP字符串模式匹配算法
/*
 * 初始条件：串S和SubStr存在
 * 操作结果：若SubStr在S中存在 则返回其首次出现的首元素位置 若不存在 则返回-1
 */
int Index_SubStr(char *S,char *Substr);


//串的替换
/*
 * 初始条件：串S T V均存在 S T非空
 * 操作结果：用V替换主串S中出现的所有与T相等的不重叠的子串
 * 借口尚未实现
 */
bool Replace(char *S,char *T,char *V);



//串的插入
/*
 * 初始条件：串S和T存在，1<=pos<=StrLength(S)+1
 * 操作结果：在串的第pos个字符之前插入串T 插入成功 True 失败 false
 */
bool StrInset(unsigned char *S,unsigned const char *T,int pos);



//串的删除
/*
 * 初始条件：串S存在
 * 操作结果：从串S中删除第pos个字符起长度为len的子串
 */
bool StrDelete(unsigned char *S,int pos,int len);



//串的销毁
/*
 * 初始条件：串S存在
 * 操作结果：串S被销毁
 */

//并非malloc 无法销毁 如果使用动态内存则可以
void DestroyString(char *S);



#endif //SSTRING_SSTRING_H
