//This file contains codes for generation fibonacci series using three methods:
//1. Recursion
//2. Memoized Solution
//3. Tabulated Solution

//Fibonacci Series using Recursion
#include<stdio.h>
#include<time.h>
int fib(int n)
{
if (n <= 1)
	return n;
return fib(n-1) + fib(n-2);
}

//Time taken: 0.700817


/* C/C++ program for Memoized version for nth Fibonacci number */
#include<stdio.h>

#include<time.h>

#define NIL -1
#define MAX 100

int lookup[MAX];

/* Function to initialize NIL values in lookup table */
void _initialize()
{
int i;
for (i = 0; i < MAX; i++)
	lookup[i] = NIL;
}

/* function for nth Fibonacci number */
int fib(int n)
{
if (lookup[n] == NIL)
{
	if (n <= 1)
		lookup[n] = n;
	else
		lookup[n] = fib(n-1) + fib(n-2);
}

return lookup[n];
}

//Time taken: 0.000056

/* C program for Tabulated version */
#include<stdio.h>
#include<time.h>

int fib(int n)
{
int f[n+1];
int i;

double time_spent ;

f[0] = 0; f[1] = 1; 
for (i = 2; i <= n; i++)
	f[i] = f[i-1] + f[i-2];

return f[n];
}

//Time taken: 0.000071

//main function for reference


int main ()
{
int n = 40;

clock_t begin, end;

double time_spent;

begin = clock();

printf("%d\n", fib(n));

end = clock();

time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("\nTime Taken %lf ", time_spent);

getchar();
return 0;
}
