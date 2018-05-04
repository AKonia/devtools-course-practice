#pragma once
class Graph
{
protected:
    int n;
    double** graph_matrix;
public:
    Graph(); //��������� �� ���������
    Graph(int count_vertex, double** matrix); //����������� � �����������
    ~Graph(); //����������
    int GetCount(); //�������� ����� ������
    double GetWeight(int first, int last); //�������� ��� �����
    void AddVertex(); //�������� �������
    void AddEdge(int first, int last, double weight); //�������� �����
    void DeleteEdge(int first, int last); //������� �����
    void DeleteVertex(int vertex); //������� �������
    double FindDistance(int start, int finish); //����� ���������� �� start �� finish
};

