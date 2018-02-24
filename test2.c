#include <stdio.h>
#include <stdint.h>
typedef union{
	unsigned char c[8];
	float f;
	double d;
} df_union;


void prt(df_union *v){
	int i;
	for(i = 0; i < 8; i++)
		printf("%.2x ", v->c[i]);
	printf("\n");
}

int main(int argc, char* argv[]){
	df_union u;
	u.f = 0.2f;
	printf("var %g == 0x", u.f);
	prt(&u);
	u.d = 0.2f;
	printf("var %g == 0x", u.d);
	prt(&u);
}