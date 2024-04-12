#include <stdio.h>
#include <math.h>
int main(){
	int R = 0;
	if(scanf("%d", &R) != 0 && R > 0){
	double V = (4.0/3.0) * M_PI * pow(R,3);
	double result = round(V * 21500);
	printf("%.0lf", result);
	} else 
		printf("n/a");
	return 0;
}
