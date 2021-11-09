#include "TireTree.h"

int main(void){
	TireTree *node=(TireTree*)malloc(sizeof(TireTree));
	Initial(node);
	Insert("cat", node);
	Insert("dog", node);
	Insert("fuckyou", node);
	printf("%d\n",Search("dog", node));
	printf("%d\n",Search("dof", node));
	printf("%d\n",Search("fuckyou", node));
	//模糊检索
	printf("%d\n",SearchWith("fuck", node));
}