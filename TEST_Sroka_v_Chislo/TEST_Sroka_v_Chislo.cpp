// TEST_Sroka_v_Chislo.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TEST_Sroka_v_Chislo.h"


int main()
{
	int *z = new int;
	*z = 0;
	string str;
	char str2[256] ;
	char str3[256] = { "\%\." };
	cout << "Input a digit -> ";
	getline(cin, str);
	double i = StrToD(str,z);
	sprintf(str3, "%s%d%c","\%\.", *z, 'f');
	sprintf(str2, str3, i);

	cout << "\nDigit = " << str2<< '\n';

    return 0;
}

double StrToD(string s, int* z)
{
	int temp = 0; // число
	int temp2 = 0; // число после знака
	double temp3 = 0.0;
	int i = 0;
	int j = 1;
	int sign = 0; // знак числа 0- положительное, 1 — отрицательное
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] >= 0x30 && s[i] <= 0x39)
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (s[i] == '.' || s[i] == ',')
	{
		i++;
		while (s[i] >= 0x30 && s[i] <= 0x39)
		{
			temp2 = temp2 + (s[i] & 0x0F);
			temp2 = temp2 * 10;
			i++;
			j*=10;
			*z+=1;
		}
		temp2 = temp2 / 10;	
	}

	temp3 = (double)temp + (double)temp2/ j;
	if (sign == 1)
		temp3 = -temp3;
	return(temp3);
}