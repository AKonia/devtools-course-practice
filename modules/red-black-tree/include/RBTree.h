// Copyright 2018 Chernenko Valery
#ifndef MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_
#define MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_

typedef int T;
typedef enum { BLACK, RED } nColor;    //��������� ����� ����� ������
struct Node {
    Node* left;           //��������� �� "������" �������
    Node* right;          //��������� �� "�������" �������
    Node* parent;         //��������� �� "������"
    nColor color;      //���� ����
    T data;               //���������� � ���� ������

    Node(Node* _l, Node* _r, Node* _p, nColor _c, T _d) {
        left = _l; right = _r, parent = _p, color = _c, data = _d;
    }
};

class RBTree {
 private:
    void deleteTree(Node* x);  /*�������� ������*/
 protected:
    Node* root;  /*��������� �� ������ ������*/
    void rotateLeft(Node* x);   /*"����� �������"*/
    void rotateRight(Node* x);  /*"������ �������"*/
    void insertFixup(Node* x);  /*������� ���� � �������������*/
    void deleteFixup(Node* x);  /*�������� ���� � �������������*/
 public:
    static Node* NIL;
    RBTree();
    explicit RBTree(T data);
    RBTree(T datas[], int count);
    ~RBTree();
    Node* insertNode(T data);  /*������� ���� �� ��������*/
    Node* findNode(T data);  /*����� ���� �� ��������*/
    void deleteNode(T data);  /*�������� ���� �� ��������*/
};

#endif  // MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_
