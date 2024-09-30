#include <math_util.h>

int e_clamp(int n, int min, int max)
{
	return (n < min) ? min : ((n > max) ? max : n );
}

int e_max(int a, int b)
{
	return (a > b) ? a : b;
}

int e_min(int a, int b) 
{
	return (a < b) ? a : b;
}

int e_round (float f)
{
	return (int)((f > 0) ? f - 0.5 : f + 0.5 );
}

int e_floor (float f)
{
	return (int)f;
}

int e_ceil(float f) 
{
	return (int)(f + 1.0);
}
