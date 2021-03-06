// stirling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

long pow(int x, int p)
{
	long power = 1;
	for (int i = 0; i < p; i++)
		power *= x;
	return power;
}

long fact(long n)
{
	if (n == 0)
		return 1;
	else
		return (n * fact(n - 1));
}

long binom(int n, int r)
{
	int large_denom = n-r;
	int small_denom = r;
	if (r > n - r)
	{
		large_denom = r;
		small_denom = n-r;
	}

	long numerator = 1;
	for (int i = n; i > large_denom; i--)
		numerator *= i;

	long denominator = 1;
	for (int i = small_denom; i > 1; i--)
		denominator *= i;

	return numerator / denominator;
}

long s(int n, int j)
{
	long total = 0;
	for (int i = 0; i < j; i++)
		total += pow(-1, i)*binom(j,i)*pow(j-i,n);

	return total / fact(j);
}

int main()
{
	// result is stirling number for n and j
	long result = 0;
	for (int n = 1; n < 1000; n++)
		for (int j = 1; j <= n; j++)
			result = s(n, j);
	
    return 0;
}

