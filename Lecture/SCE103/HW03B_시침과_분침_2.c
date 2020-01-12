#include <stdio.h>
#include <math.h>

int addH(int h, int m, int s);
int addM(int h, int m, int s);
int addS(int h, int m, int s);
double degree(int h, int m, int s);

int main() {
	int h, m, s = 0;
	scanf("%d %d", &h, &m);

	while (1) {
		double temp = fabs(degree(h, m, s) - 180.0);
		if (temp <= 0.04999)
			break;
		h = addH(h, m, s);
		m = addM(h, m, s);
		s = addS(h, m, s);
	}
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}

int addH(int h, int m, int s) {
	s++;
	if (s == 60) { s = 0; m++; }
	if (m == 60) { m = 0; h++; }
	if (h == 12) h = 0;
	return h;
}

int addM(int h, int m, int s) {
	s++;
	if (s == 60) { s = 0; m++; }
	if (m == 60) m = 0;
	return m;
}

int addS(int h, int m, int s) {
	s++;
	if (s == 60) s = 0;
	return s;
}

double degree(int h, int m, int s) {
	double hd = h * 30.0 + m / 2.0 + s / 120.0;
	double md = m * 6.0 + s / 10.0;
	return hd < md ? md - hd : hd - md;
}