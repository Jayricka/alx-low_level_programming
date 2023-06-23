#include <stdio.h>

/* Function definitions with descriptions here */

/**
* add - Adds two integers.
* @a: The first integer.
* @b: The second integer.
*
* Return: The sum of the two integers.
*/
int add(int a, int b)
{
return (a + b);
}

/**
* sub - Subtracts two integers.
* @a: The first integer.
* @b: The second integer.
*
* Return: The difference between the two integers.
*/
int sub(int a, int b)
{
return (a - b);
}

/**
* mul - Multiplies two integers.
* @a: The first integer.
* @b: The second integer.
*
* Return: The product of the two integers.
*/
int mul(int a, int b)
{
return (a * b);
}

/**
* div - Divides two integers.
* @a: The numerator.
* @b: The denominator.
*
* Return: The quotient of the division.
*         If the denominator is zero, returns 0.
*/
int div(int a, int b)
{
if (b != 0)
{
return (a / b);
}
else
{
/* Handle division by zero error */
return (0);
}
}

/**
* mod - Computes the modulo of two integers.
* @a: The dividend.
* @b: The divisor.
*
* Return: The modulo of the division.
*         If the divisor is zero, returns 0.
*/
int mod(int a, int b)
{
if (b != 0)
{
return (a % b);
}
else
{
/* Handle division by zero error */
return (0);
}
}
