/*
	triangle.c -- Stephen Kelly CS2303-a03
*/

#include <math.h>
#include <stdio.h>

int main(void){
	//declare variables
	double A[2],B[2],C[2];
	double lenAB, lenBC, lenCA;
	double circ, s, area;
	
	//get coordinates
	printf("Enter the x- and y-coordinates of point A:");
	scanf("%lf%lf", &A[0], &A[1]);
	printf("Enter the x- and y-coordinates of point B:");
	scanf("%lf%lf", &B[0], &B[1]);
	printf("Enter the x- and y-coordinates of point C:");
	scanf("%lf%lf", &C[0], &C[1]);

	//do math
	lenAB = sqrt(pow((A[0]-B[0]),2)+pow((A[1]-B[1]),2));
	lenBC = sqrt(pow((B[0]-C[0]),2)+pow((B[1]-C[1]),2));
	lenCA = sqrt(pow((C[0]-A[0]),2)+pow((C[1]-A[1]),2));
	circ = lenAB + lenBC + lenCA;
	s = circ / 2;
	area = sqrt(s*(s-lenAB)*(s-lenBC)*(s-lenCA));
	
	//print values
	printf("\nLength of AB is %.3f\n", lenAB);
	printf("Length of BC is %.3f\n", lenBC);
	printf("Length of CA is %.3f\n", lenCA);
	printf("Circumference is %.3f\n", circ);
	printf("Area is %.3f\n", area);

	return 0;	
}
