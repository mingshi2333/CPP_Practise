#include <iostream>
using namespace std;
using ElemType = char;
typedef struct node
{
	ElemType data;
	node* left, * right;

	node(ElemType val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
}node,*BiTree;

class BinaryTree
{
public:
	void Create()
	{
		m_root = create();
	}
	void PreOrder()
	{
		cout << "�������" << endl;
		preOrder(m_root);
		cout<<endl;

	}
	void InOrder()
	{
		cout << "�������" << endl;
		inOrder(m_root);
		cout << endl;
	}
	void PostOrder()
	{
		cout << "�������" << endl;
		postOrder(m_root);
		cout << endl;
		
	}
	void Destory()
	{
		cout << "ɾ����" << endl;
		distroy(m_root);
		cout << endl;
	}

private:
	BiTree create();						//�ݹ�Ĵ����������Ľڵ�
	void preOrder(BiTree root);				//ǰ�����
	void inOrder(BiTree root);				//�������
	void postOrder(BiTree root);			//�������
	void distroy(BiTree root);				//�ݻ���
	int getHeight(BiTree root);				//�ݹ�õ����ĸ߶�
	void AddNode(const ElemType key, int direction, BiTree root);         //��ӽڵ�
	BiTree m_root;      //���ڵ�
	int count;			//�ڵ�����
};

BiTree BinaryTree::create()
{
	BiTree temp = NULL;
	ElemType val;
	cin >> val;
	if(val=='#')
	{
		return NULL;
	}
	else
	{
		count++;
		temp = new node(val);
		temp->left = create();
		temp->right = create();
		return temp;
	}
}
void BinaryTree::preOrder(BiTree root)
{
	if (root == NULL)
		return;
	else
	{
		cout << root->data << "--> ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void BinaryTree::inOrder(BiTree root)
{
	if(root == NULL)
		return;
	else
	{
		inOrder(root->left);
		cout << root->data << "--> ";
		inOrder((root->right));
	}
}
void BinaryTree::distroy(BiTree root)
{
	if (root == nullptr)
		return;

		distroy(root->left);
		distroy(root->right);
		cout << root->data;
		delete(root);
}


void BinaryTree::postOrder(BiTree root)
{
	if (root == NULL)
		return;
	else
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << "--> ";
	}
}



int main()
{
	BinaryTree  tree;
	tree.Create();
	tree.PostOrder();
	tree.PreOrder();
	tree.Destory();
	
}


