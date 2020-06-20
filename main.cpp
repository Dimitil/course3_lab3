// ����:
// ���������� ����������.
// ���������� ������� 

//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������
#include <iostream>
#include <tchar.h>
#include "myString.h"
#include "Point.h"
#include "MyData.h"
#include "base.h"
#include "Pair.h"
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////



	//������� 1.���������� ����������.

	//���������� � ������� ����� MyString.cpp � MyString.h
	//������ MyString, �������������� ���� �� ���������� �������
	//9a. ����������� �������� ������������ ��� ������ MyString
	//��������� ������������ ������ �������������� ���������

	{
		std::cout << "\nTask #1\n";
		
		MyString s1("AAA"), s2;
		s2 = s1;

		if (!strcmp(s2.GetString(), s1.GetString()))
		{
			std::cout << "\nCorrect\n";
		}
		else 	std::cout << "\nUncorrect\n";
	
		s1="CCC";

		if (!strcmp(s1.GetString(), "CCC"))
		{
			std::cout << "\nCorrect\n";
		}
		else 	std::cout << "\nUncorrect\n";

		stop

		s2= MyString("tmp");

		if (!strcmp(s2.GetString(), "tmp"))
		{
			std::cout << "\nCorrect\n";
		}
		else 	std::cout << "\nUncorrect\n";

		s1=s1;

		if (!strcmp(s1.GetString(), s1.GetString()))
		{
			std::cout << "\nCorrect\n";
		}
		else 	std::cout << "\nUncorrect\n";

		stop 
	}
		stop
	//2.�������� ����� Point, ������� ����� ��������� ����������
	//"�����". �������� ����������� (������������) ������   
	
	//2b. "�����������" �������� += ���, ����� ��� ����������
	//�������� ���� pt2+=pt1; ������������
	//����������� ���������� �������� pt1 � pt2, � �����
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2+=1; ��� ���������� ������� pt2 ������������� ��
	// ��������� ��������
	//a) � ������� ������ ������ (�������� +=)
	//�) � ������� ���������� ������� (�������� -=)
	//��������� ������������ ������ �������������� ���������
	{
		std::cout << "\nTask #2b\n";

		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 += pt1;

		if (pt2.GetY() == 3 && pt2.GetX() == 3)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt2 += 1;

		if (pt2.GetY() == 4 && pt2.GetX() == 4)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		Point pt3(3, 3);
		pt2 += pt1 += pt3;

		if (pt2.GetY() == 8 && pt2.GetX() == 8)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt2 -= pt1;

		if (pt2.GetY() == 4 && pt2.GetX() == 4)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt2 -= 1;

		if (pt2.GetY() == 3 && pt2.GetX() == 3)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		stop
	}
	//������� 2c. ����������� �������� +/- 
	//a)� ������� ������� ������ (�������� +)
	//�) � �������  ���������� ������� (�������� -)
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������
	{
		std::cout << "\nTask #2c\n";

		Point pt1(1, 1);
		Point pt2(2, 2);
		Point pt3;

		pt3 = pt1 + 5;

		if (pt3.GetY() == 6 && pt3.GetX() == 6)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt3 = 2 + pt1;			//������ ����������� ������� ������

		if (pt3.GetY() == 3 && pt3.GetX() == 3)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt3 = pt1 + pt2;

		if (pt3.GetY() == 3 && pt3.GetX() == 3)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";


		pt3 = pt1 - 5;

		if (pt3.GetY() == -4 && pt3.GetX() == -4)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt3 = pt1 - pt2;

		if (pt3.GetY() == -1 && pt3.GetX() == -1)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		stop

	//������� 2d. ����������� ������� �������� +/- 
		std::cout << "\nTask #2d\n";

		pt3 = -pt1;

		if (pt3.GetY() == -1 && pt3.GetX() == -1)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";

		pt3 = +pt1;

		if (pt3.GetY() == 1 && pt3.GetX() == 1)
		{
			std::cout << "\nCorrect\n";
		}
		else std::cout << "\nUncorrect\n";
		
		stop

	}

	//������� 2e. ����������� �������� << (������ � �����) ���
	//������ MyString ����� �������, ����� ��� ���������� ����������� ������
	//�� ����� ���� ��������:
	//contents:  "QWERTY"
	{
		stop
		std::cout << "\nTask #2e\n";

		MyString s("QWERTY");
		std::cout << std::endl << s << std::endl;

	

	//������� 2f*. ����������� ��������� + � += ��� ������ MyString ����� �������,
	 //����� ����������� ������������ �����

	std::cout << "\nTask #2f*\n";

	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1 + s2;

	std::cout << "\n" << s3 << "\n";

	s4 += s1; 
	std::cout << "\n" << s4 << "\n";

	stop
	}

	
	{
		stop
		
		//MyData D(MyData::UNDEF, 20, "Rabotyaga", 350);
		
		//Pair P("Stepanof", D);
		
		stop
	}

	stop
	//������� 3. ����������� "���� ������" � ����������� ����������� ��������������
	//�������. ������ �������� ������� (���� � ������� ��������, ������� ���������� ��������
	//� ���� ���� �� �����), � �������: ���, �������, ���������, ��������...
	//����������:
	//���������� ����������� � ����
	//����������
	//����� ���������� � ���������� ����������
	//����� ���� (��� ������������) ���������� � ���� �����������
	//��������:
/*
		BD bd;	//�������� ������ ����
		bd["Ivanov"] = Data(30,MALE,<��������� ������>);	//���� Ivanov-� � ���� ��� ���, ��
						//����������, ���� ��� ����, �� ������ ��� ����������
		std::cout<<bd;	//����� ���������� ��� ���� �����������

*/

	
	return 0;
}//endmain

