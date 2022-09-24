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
		cout << "先序遍历" << endl;
		preOrder(m_root);
		cout<<endl;

	}
	void InOrder()
	{
		cout << "中序遍历" << endl;
		inOrder(m_root);
		cout << endl;
	}
	void PostOrder()
	{
		cout << "中序遍历" << endl;
		postOrder(m_root);
		cout << endl;
		
	}
	void Destory()
	{
		cout << "删除树" << endl;
		distroy(m_root);
		cout << endl;
	}

private:
	BiTree create();						//递归的创建二叉树的节点
	void preOrder(BiTree root);				//前序遍历
	void inOrder(BiTree root);				//中序遍历
	void postOrder(BiTree root);			//后序遍历
	void distroy(BiTree root);				//摧毁树
	int getHeight(BiTree root);				//递归得到树的高度
	void AddNode(const ElemType key, int direction, BiTree root);         //添加节点
	BiTree m_root;      //根节点
	int count;			//节点总数
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


