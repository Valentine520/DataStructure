//防止头文件重复包含
#ifndef TIRETREE
#define TIRETREE

#include <stdio.h>
#include <stdlib.h>
typedef _Bool bool;
typedef struct TireTree{
	char ch;
	struct TireTree *child[26];//存储26个可能节点 26个可能字母
	bool isComplete;//记录该单词树是否已经终结
}TireTree;
//初始化
void Initial(TireTree *node);


//插入单词
void Insert(char *str,TireTree *node);

//查找单词
bool Search(char *str,TireTree *node);

//查找前缀
bool SearchWith(char *str,TireTree *node);

#endif