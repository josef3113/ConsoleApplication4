// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class MaxAndArr
{
public:
	int m_Max;
	vector<int> m_ArrSmaller;
};
MaxAndArr Max(int x, int y)
{
	MaxAndArr toReturn;
	if (x > y)
	{
		MaxAndArr toReturn;
		toReturn.m_Max = x;
		toReturn.m_ArrSmaller.push_back(y);
		return toReturn;
	}
	toReturn.m_Max = y;
	toReturn.m_ArrSmaller.push_back(x);
	return toReturn;
	
}

MaxAndArr RecursivTwoMax(int* i_arr, int i_size)
{

	if (i_size < 3)
	{
		MaxAndArr toReturn;
		toReturn = Max(i_arr[0], i_arr[1]);
		return toReturn;
	}

	else
	{
		MaxAndArr team1 = RecursivTwoMax( (i_arr + i_size / 2), i_size / 2);
		MaxAndArr team2 = RecursivTwoMax(i_arr, i_size / 2);

		if (team1.m_Max > team2.m_Max)
		{
			team1.m_ArrSmaller.insert(team1.m_ArrSmaller.begin(), team2.m_Max);
			return team1;
		}
		else
		{
			team2.m_ArrSmaller.insert(team2.m_ArrSmaller.begin(), team1.m_Max);
			return team2;

		}


	}

}

int* VectorToArry(vector<int> i_vecToConvert)
{
	int * arrToReturn = new int[i_vecToConvert.size()];
	for (int i = 0; i < i_vecToConvert.size(); i++)
	{
		arrToReturn[i] = i_vecToConvert[i];
	}
	return arrToReturn;
}


int main()
{
	int arr[8] = { 4,7,9,2,8,11,45,34 };
	MaxAndArr check = RecursivTwoMax(arr, 8);
	int* arrsmall = VectorToArry(check.m_ArrSmaller);
	MaxAndArr max2 = RecursivTwoMax(arrsmall, check.m_ArrSmaller.size());
	cout << check.m_Max << endl;
	cout << max2.m_Max << endl;
    return 0;
}

