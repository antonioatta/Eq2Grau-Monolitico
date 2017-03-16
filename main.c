#include <stdio.h>
#include <math.h>

struct vet_eq {
	int a, b, c;
	float x1, x2;
	// float delta;
	int raizesReais;
};

int main() {

	struct vet_eq vetEq[10];
	int delta;
	int i;
	int numEq = 3;

	vetEq[0].a=5; vetEq[0].b=6; vetEq[0].c=2;
	vetEq[1].a=4; vetEq[1].b=10; vetEq[1].c=6;
	vetEq[2].a=3; vetEq[2].b=8; vetEq[2].c=3;

	for (i=0; i<numEq; i++) {
		delta = vetEq[i].b*vetEq[i].b - 4*vetEq[i].a*vetEq[i].c;
		vetEq[i].raizesReais = (delta >= 0);
		if (vetEq[i].raizesReais) {
			vetEq[i].x1 = (-vetEq[i].b + sqrt(delta)) / (2*vetEq[i].a);
			vetEq[i].x2 = (-vetEq[i].b - sqrt(delta)) / (2*vetEq[i].a);
		}
	}

	for (i=0; i<numEq; i++) {
		printf("Para os coeficientes a=%d, b=%d e c=%d as raizes sao ", vetEq[i].a, vetEq[i].b, vetEq[i].c);
		if (vetEq[i].raizesReais) printf("%6.2f e %6.2f\n", vetEq[i].x1, vetEq[i].x2);
		else printf("imaginarias.\n");
	}
	return 0;
}
