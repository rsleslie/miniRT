#include "../../miniRT/includes/miniRT.h"
#include <stdio.h>

int isVectorOrPoint(t_tuple tuple)
{
	if (tuple.w == 1.0)
	{
		printf("is a point\n");
		printf("is not a vector\n");
	}
	else if (tuple.w == 0.0)
	{
		printf("is not a point\n");
		printf("is a vector\n");
	}
	return (0);
}
int isTuple(t_tuple tupleTeste)
{
	if (!equal(tupleTeste.x, 4.3))
		return (FALSE);
	if (!equal(tupleTeste.y ,-4.2))
		return (FALSE);
	if (!equal(tupleTeste.z,3.1))
		return (FALSE);
	if (!equal(tupleTeste.w, 1.0) && !equal(tupleTeste.w, 0.0))
		return (FALSE);
	isVectorOrPoint(tupleTeste);
	return (TRUE);
}

int testTuple()
{
	printf("pointer\n");
	if (!isTuple(tuples(4.3, -4.2, 3.1, 1.0)))
	{
		printf("error in tuple value\n");
		return (FALSE);
	}
	printf("\nVector\n");
	if (!isTuple(tuples(4.3, -4.2, 3.1, 0.0)))
	{
		printf("error return if tuple\n");
		return (FALSE);
	}
	return (TRUE);
}

int testePointer()
{
	isTuple(point(4.3, -4.2, 3.1));
	return (0);
}

int testeVector()
{
	isTuple(vector(4.3, -4.2, 3.1));
	return (0);
}

int testeAddingTuple()
{
	t_tuple adding;

	adding = addingTuple(tuples(3, -2, 5, 1), tuples(-2, 3, 1, 0));
	printf("resperado tuple(1, 1, 6, 1)\nresultado(%f, %f, %f, %f)\n", adding.x,adding.y, adding.z, adding.w);
	isVectorOrPoint(adding);
	return (0);
}

int testeSubPoint()
{
	t_tuple adding;

	adding = subtractingPoint(point(3, 2, 1), point(5, 6, 7));
	printf("Esperado (-2, -4, -6)\nresultado (%f, %f, %f, %f)\n", adding.x,adding.y, adding.z, adding.w);
	isVectorOrPoint(adding);
	return (0);
}

int testeSubPointFromVec()
{
	t_tuple adding;

	adding = subtractingVecFromPoint(point(3, 2, 1), vector(5, 6, 7));
	printf("Esperado (-2, -4, -6)\nresultado (%f, %f, %f, %f)\n", adding.x,adding.y, adding.z, adding.w);
	isVectorOrPoint(adding);
	return (0);
}

int testeSubVector()
{
	t_tuple sub_1;
	t_tuple sub;
	sub_1 = subtractingVector(vector(3, 2, 1), vector(5, 6, 7));
	printf("Esperado (-2, -4, -6)\nresultado (%f, %f, %f, %f)\n", sub_1.x,sub_1.y, sub_1.z, sub_1.w);
	isVectorOrPoint(sub_1);
	
	sub = subtractingVector(vector(0, 0, 0), vector(1, -2, 3));
	printf("Esperado (-1, 2, -3)\nresultado (%f, %f, %f, %f)\n", sub.x,sub.y, sub.z, sub.w);
	isVectorOrPoint(sub);
	
	return (0);
}

int negateTupla()
{
	t_tuple negTuple;
	
	negTuple = negate(tuples(1, -2, 3, -4));
	printf("Esperado (-1, 2, -3, 4)\nresultado (%f, %f, %f, %f)\n", negTuple.x,negTuple.y, negTuple.z, negTuple.w);
	return (0);
}
int main()
{
	// testTuple();
	// testePointer();
	// testeVector();
	// testeAddingTuple();
	// testeSubPoint();
	// testeSubPointFromVec();
	// testeSubVector();
	negateTupla();
	return (0);
}
