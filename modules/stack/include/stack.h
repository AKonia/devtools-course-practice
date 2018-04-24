#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

template <class ValType>
class TStack {
private:
    ValType* Arr;							//������ ��� �������� ������
    int size;								//������ �����
    int sp;									//��������� �� ������� �����
public:
    TStack(int _size = 1);					//�����������-�������������
    TStack(const TStack& S);				//����������� �����������
    ~TStack(void);							//����������

    int IsEmpty(void);						//�������� �������
    int IsFull(void);						//�������� ������������
    void Push(ValType var);					//�������� �������� � ����
    ValType Pop(void);						//������� �������� �� �����

    TStack& operator = (const TStack& S);	//������������
    int operator == (const TStack& S);		//���������
};

#endif
