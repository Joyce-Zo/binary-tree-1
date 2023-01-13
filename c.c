#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#define DataType char
struct treeNode
{
	DataType data; // �洢����������
	struct treeNode* LChild; // ������
	struct treeNode* RChild; // ������
};

// 1. ������
struct treeNode* createNode(DataType data)
{
	struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
	newNode->data = data;
	newNode->LChild = newNode->RChild = NULL;
	return newNode;
}

// 2. ����ڵ�/���ӽڵ�
void insertNode(struct treeNode* curNode, struct treeNode* LchildNode, struct treeNode* RchildNode)
{
	curNode->LChild = LchildNode;
	curNode->RChild = RchildNode;
}

// 3. ��ӡ�ڵ�����
void printData(struct treeNode* curNode)
{
	printf("%c ", curNode->data);
}

// 4.1 ǰ����� ����
void preOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{	
		printData(tree);
		preOrder(tree->LChild);
		preOrder(tree->RChild);
	}
}
// 4.2 ������� ����
void midOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{
		midOrder(tree->LChild);
		printData(tree);
		midOrder(tree->RChild);
	}
}
// 4.3 ������� ����
void postOrder(struct treeNode* tree)
{
	if (tree != NULL)
	{
		postOrder(tree->LChild);
		postOrder(tree->RChild);
		printData(tree);
	}
}

// 5 ջ �ķ���
void midOrderByStack(struct treeNode* tree)
{
	//	��Ϊ��
	if (tree == NULL)
	{
		return;
	}
	else
	{
		// ��ʼ��һ��ջ��������С10
		struct treeNode* stack[10];
		int stackTop = -1; // ջ��-1�������һ�����ݳ�0���պ�ջ�±�0��ʼ
		
		struct treeNode* curNode = tree;
		while (stackTop != -1 || curNode)
		{
			// �����е�������
			while (curNode)
			{
				stackTop++; // ջ��+1
				stack[stackTop] = curNode;// ����ÿ���ڵ㵽ջ��
				curNode = curNode->LChild;// ������һ����������curNode��Ա�ѭ��������һ��������
			}
			if (stackTop != -1)
			{
				curNode = stack[stackTop];// �����һ���ڵ��ջ
				printf("%c ", curNode->data);
				stackTop--; // ջ��-1
				curNode = curNode->RChild;
			}
		}
	}
}

int main()
{
	// �ֶ��������нڵ�
	struct treeNode* A = createNode('A');
	struct treeNode* B = createNode('B');
	struct treeNode* C = createNode('C');
	struct treeNode* D = createNode('D');
	struct treeNode* E = createNode('E');
	struct treeNode* F = createNode('F');
	struct treeNode* G = createNode('G');
	struct treeNode* K = createNode('K');
	
	// ���ӽڵ�
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(C, F, G);
	insertNode(F, NULL, K);

	// ����ÿ���ڵ㣬��ӡ 
	midOrder(A);
	printf("\n");
	midOrderByStack(A);

	return 0;
}