// Темы:
// Перегрузка операторов.
// Встроенные объекты 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
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



	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

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
	//2.Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   
	
	//2b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора
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
	//Задание 2c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
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

		pt3 = 2 + pt1;			//нельзя перегрузить методом класса

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

	//Задание 2d. Перегрузите унарный оператор +/- 
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

	//Задание 2e. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"
	{
		stop
		std::cout << "\nTask #2e\n";

		MyString s("QWERTY");
		std::cout << std::endl << s << std::endl;

	

	//Задание 2f*. Перегрузите операторы + и += для класса MyString таким образом,
	 //чтобы происходила конкатенация строк

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
	//Задание 3. Разработать "базу данных" о сотрудниках посредством ассоциативного
	//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
	//в базе быть не может), а данными: пол, возраст, должность, зарплата...
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках
	//Например:
/*
		BD bd;	//создание пустой базы
		bd["Ivanov"] = Data(30,MALE,<остальные данные>);	//если Ivanov-а в базе еще нет, то
						//добавление, если уже есть, то замена его реквизитов
		std::cout<<bd;	//вывод информации обо всех сотрудниках

*/

	
	return 0;
}//endmain

