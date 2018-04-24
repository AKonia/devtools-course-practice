// Copyright 2018 Lalykin Oleg

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_

#include <string>
class Elasticity {
public:
	Elasticity(double Q1, double Q2, double P1, double P2);


	double PriceElasticity(double Q1,double Q2,double P1,double P2);
	double IncomeElasticity(double Q1, double Q2, double P1, double P2);
	double CrossElasticity(double Q1, double Q2, double P1, double P2);
	double coeff;
	std::string answer();

	double GetQ1();
	double GetQ2();
	double GetP1();
	double GetP2();

	void SetQ1(const double _Q1);
	void SetQ2(const double _Q2);
	void SetP1(const double _P1);
	void SetP2(const double _P2);
private:
	//�������������� � ������� ����� ������
	//�D� > 1 � ����� ���������; ��� ���� ���� ����������, ��� ���������� �����. 
	//���� �D� < 1 � ����� �����������. 
	//�����D� = 1, ����� ����� ����� � ��������� �������������, �. �. �������� ���� �� 1 % �������� � ����� ������ ������ ���� �� 1 %.
	// �������������� � ������� ����
	//std::string unit elasticity
	//std::string demand is elastic
	//std::string demand is inelastic
	 double Q1; 
	 double Q2; 
	 double P1; 
	 double P2;
};

#endif  //  MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
