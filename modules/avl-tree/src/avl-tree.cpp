#include "include/avl-tree.h"
#include <iostream>
#include <vector>
using namespace std;

AVL::AVL()
{
	root = NULL;
}

AVLNode* AVL::getRoot()
{
	return root;
}

unsigned char AVL::height(AVLNode* p)//��������� ������ �������
{
	if (p)
		return p->height;
	else
		return 0; //������� ������ ��������� �������� : ���� ������� ���, ����� 0 ����� ������ ��������� ���� �������
}

int AVL::bFactor(AVLNode* p)//�������� ����� ����� ���������
{
	return height(p->right) - height(p->left);
}

void AVL::fixheight(AVLNode* p) // ������� ������, ���� ������������������ ��������
{
	unsigned int hl = height(p->left); // ������ ������ ����
	unsigned int hr = height(p->right); // ������ ������� ����
	if (hl > hr)
		p->height = hl + 1;
	else//hr>=hl
		p->height = hr + 1; // ������ ������� - ��� ������ ���� � ���� ������� ���� 1
}

AVLNode* AVL::rightRotate(AVLNode* p) // ������ ������� ������ p
{
	AVLNode* q = p->left;//���������� ������ ���� � 
	p->left = q->right;//�������� ������ ���� � ����, ������� ���� p � q
	q->right = p;//����������� ������� ���� q ��������� �
	if (root == p)
		root = q;
	fixheight(p);//������� ������
	fixheight(q);
	return q;
}

AVLNode* AVL::leftRotate(AVLNode* q) // ����� ������� ������ q
{
	AVLNode* p = q->right;//���������� ������� ���� q
	q->right = p->left;//�������� ������� ���� q ����, ������� ���� q � p
	p->left = q;//����������� ������ ���� p ��������� q
	if (root == q)
		root = p;
	fixheight(q);//������� ������
	fixheight(p);
	return p;
}

AVLNode* AVL::balance(AVLNode* p) // ������������ ���� p
{
	fixheight(p);
	if (bFactor(p) == 2)//���� ����� ��� ������ ������ ������� ������� ������ �������
	{
		if (bFactor(p->right) < 0)
			p->right = rightRotate(p->right);
		return leftRotate(p);
	}
	if (bFactor(p) == -2)// ���� ������ ��� ����� ������ ������ ������� ����� �������
	{
		if (bFactor(p->left) > 0)
			p->left = leftRotate(p->left);
		return rightRotate(p);
	}
	return p; // ������������ �� �����
}


AVLNode* AVL::insert(AVLNode* r, int w)
{
	if (root == NULL)//���� ������ ������, �� ������ ������� ����� ���� 
	{
		root = new AVLNode(w);
		return root;
	}
	if (r == NULL)
	{
		r = new AVLNode(w);
		return r;
	}
	else //r!=NULL
		if (w < r->key)//���� �������� ������������ ������ ����������, ���� �����
		{
			r->left = insert(r->left, w);
			r = balance(r);
		}
		else
			if (w > r->key)//���� �������� ������������ ������ ����������, ���� ������
			{
				r->right = insert(r->right, w);
				r = balance(r);
			}
			else r->key++;//���� �������� ����������� == ������������, �� ����������� ���������� ���������� �����

			return r;
}

//void AVL::Show(AVLNode *node)//����� � ������� �����������
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	Show(node->left);
//	cout << node->key << " ";
//	Show(node->right);
//}

//void AVL::toVector(AVLNode *node,vector<int> vec)//����� � ������� �����������
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	toVector(node->left,vec);
//	vec.push_back(node->key);
//	//cout << node->key << " ";
//	toVector(node->right,vec);
//}


AVLNode* AVL::findMin(AVLNode* p) // ����� ���� � ����������� ������ � ������ p 
{
	return p->left ? findMin(p->left) : p;
}

AVLNode* AVL::removeMin(AVLNode* p) // �������� ���� � ����������� ������ �� ������ p
{
	if (p->left == 0)
		return p->right;
	p->left = removeMin(p->left);
	return balance(p);
}

AVLNode* AVL::remove(AVLNode* p, int k) // �������� ����� k �� ������ p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		AVLNode* q = p->left;
		AVLNode* r = p->right;
		delete p;
		if (!r) return q;
		AVLNode* min = findMin(r);
		min->right = removeMin(r);
		min->left = q;
		return balance(min);
	}

	return balance(p);
}

AVLNode* AVL::search(AVLNode* r, int key) //like BST
{
	if (r == NULL) return NULL;

	if (key == r->key)
	{
		return r;
	}
	if (key < r->key)
	{
		return search(r->left, key);
	}
	return search(r->right, key);
}