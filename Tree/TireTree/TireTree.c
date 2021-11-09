#include "TireTree.h"

void Insert(char *str,TireTree *node){
	int base=(int)'a';//计算下标
	int site;
	//对该单词进行插入
	while(*str!='\0'){
		site=(int)*str-base;
		//未分配内容 则分配
		if(node->child[site]==NULL){
			node->child[site]=(TireTree*)malloc(sizeof(TireTree));//为空节点分配内存
			node->ch=*str;
		}
		//移动指针
		str++;
		node=node->child[site];
	}
	
	node->isComplete=1;//插入完成
}

void Initial(TireTree *node){
	for(int i=0;i<26;i++){
		node->child[i]=NULL;
	}
	node->isComplete=0;
}

//查找单词内容
bool Search(char *str,TireTree *node){
	int flag=1;
	int base=(int)'a';
	int site;
	while(*str!='\0'){
		site=(int)*str-base;
		//避免恶意索引
		if(site>=0){
			//表示该字符不存在 匹配失败
			if(node->child[site]==NULL){
				flag=0;
				return flag;
			}
			//移动指针
			str++;
			node=node->child[site];
		}
	}
	if(node->isComplete!=1){
		flag=0;
	}
	return flag;
}

bool SearchWith(char *str,TireTree *node){
	int flag=1;
	int base=(int)'a';
	int site;
	while(*str!='\0'){
		site=(int)*str-base;
		//避免恶意索引
		if(site>=0){
			//表示该字符不存在 匹配失败
			if(node->child[site]==NULL){
				flag=0;
				return flag;
			}
			//移动指针
			str++;
			node=node->child[site];
		}
	}
	//查找子串则是不要求完全匹配
//	if(node->isComplete!=1){
//		flag=0;
//	}
	return flag;
}