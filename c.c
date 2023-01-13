#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#define DataType char
struct treeNode
{
	DataType data; // 存储的数据类型
	struct treeNode* LChild; // 左子树
	struct treeNode* RChild; // 右子树
};

// 1. 创建树
struct treeNode* createNode(DataType data)
{
	struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
	newNode->data = data;
	newNode->LChild = newNode->RChild = NULL;
	return newNode;
}

// 2. 插入节点/连接节点
void insertNode(struct treeNode* curNode, struct treeNode* LchildNode, struct treeNode* RchildNode)
{
	curNode->LChild = LchildNode;
	curNode->RChild = RchildNode;
}

// 3. 打印节点数据
void printData(struct treeNode* curNode)
{
	printf("%c ", curNode->data);
}

// 4.1 前序遍历 函数
void preOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{	
		printData(tree);
		preOrder(tree->LChild);
		preOrder(tree->RChild);
	}
}
// 4.2 中序遍历 函数
void midOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{
		midOrder(tree->LChild);
		printData(tree);
		midOrder(tree->RChild);
	}
}
// 4.3 后序遍历 函数
void postOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{
		postOrder(tree->LChild);
		postOrder(tree->RChild);
		printData(tree);
	}
}

// 5 栈 的方法
void midOrderByStack(struct treeNode* tree)
{
	//	树为空
	if (tree == NULL)
	{
		return;
	}
	else
	{
		// 初始化一个栈，给定大小10
		struct treeNode* stack[10];
		int stackTop = -1; // 栈顶-1，入完第一个数据成0，刚好栈下标0开始
		
		struct treeNode* curNode = tree;
		while (stackTop != -1 || curNode)
		{
			// 走所有的左子树
			while (curNode)
			{
				stackTop++; // 栈顶+1
				stack[stackTop] = curNode;// 保存每个节点到栈里
				curNode = curNode->LChild;// 保存下一个左子树到curNode里，以便循环进入下一个左子树
			}
			if (stackTop != -1)
			{
				curNode = stack[stackTop];// 将最后一个节点出栈
				printf("%c ", curNode->data);
				stackTop--; // 栈顶-1
				curNode = curNode->RChild;
			}
		}
	}
}

int main()
{
	// 手动创建所有节点
	struct treeNode* A = createNode('A');
	struct treeNode* B = createNode('B');
	struct treeNode* C = createNode('C');
	struct treeNode* D = createNode('D');
	struct treeNode* E = createNode('E');
	struct treeNode* F = createNode('F');
	struct treeNode* G = createNode('G');
	struct treeNode* K = createNode('K');
	
	// 连接节点
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(C, F, G);
	insertNode(F, NULL, K);

	// 遍历每个节点，打印 
	midOrder(A);
	printf("\n");
	midOrderByStack(A);

	return 0;
}