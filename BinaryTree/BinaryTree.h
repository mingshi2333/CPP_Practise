#pragma once
#include <iostream>
using namespace std;

using ElemType = char;

typedef struct BiNode
{
	ElemType data;			//�ڵ����������
	BiNode* left;			//������
	BiNode* right;			//������
	BiNode(ElemType val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
}BiNode, * BiTree;





class BinaryTree
{
public:
	void Create();				//�ݹ�Ĵ����������Ľڵ�
	int getSize();				//�ݹ�õ����Ľڵ���Ŀ
	int getHeight();			//�ݹ�õ����ĸ߶�
	void preOrder();			//ǰ�����
	void inOrder();			//�������
	void postOrder();			//�������
	void distroy();			//ɾ��������

private:
	BiTree create();						//�ݹ�Ĵ����������Ľڵ�
	void preOrder(BiTree root);				//ǰ�����
	void inOrder(BiTree root);				//�������
	void postOrder(BiTree root);			//�������
	void distroy(BiTree root);				//�ݻ���
	int getHeight(BiTree root);				//�ݹ�õ����ĸ߶�
	void AddNode(const ElemType key, int direction, BiTree root);         //��ӽڵ�
	BiTree m_root;      //���ڵ�
	int size;			//�ڵ�����
};