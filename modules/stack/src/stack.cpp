// Copyright 2018 Gladyshev Alexey
#ifndef abc
#define abc
#include "include\stack.h"

//�����������-�������������
template <class ValType>
TStack<ValType>::TStack(int _size)
{
    sp = 0;
    if (_size > 0)    size = _size;
    else              size = 1;

    Arr = new ValType[size];
    
    if (Arr == NULL)    throw(Arr);
}

//����������
template <class ValType>
TStack<ValType>::~TStack(void)
{
    delete[]Arr;
    Arr = NULL;
}

//����������� �����������
template <class ValType>
TStack<ValType>::TStack(const TStack<ValType> &S)
{
    size = S.size;
    sp = S.sp;
    
    Arr = new ValType[size];
    if (Arr == NULL)
        throw(Arr);
    
    //����������� ��������� �����
    for (int i = 0; i < S.sp; i++)
        Arr[i] = S.Arr[i];
}

#endif
