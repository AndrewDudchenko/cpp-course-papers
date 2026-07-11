#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct InputData {
    double T;
    double dt;
    double w;
    double Sc;
    double i0;
    double k0;
    double l0;
    double m;
    double n;
};

double find_k(double k0, double m, double t, double T) {
	if (t >= 0 && t < T / 2.0) {
		return k0 * (1.0 - exp(-m * t));
	}
	else {
		return k0 * (1.0 - exp(-m * (T / 2.0)));
	}
}

double find_I(double i0, double T, double t, double k) {
	if (t >= 0 && t < T / 8.0) {
		return i0 * (1.0 + k * t);
	}
	else if (t >= T / 8.0 && t < (3.0 * T) / 8.0) {
		return i0 * (1.0 + k * (T / 8.0));
	}
	else if (t >= (3.0 * T) / 8.0 && t < (5.0 * T) / 8.0) {
		return i0 * (1.0 + k * (T / 8.0) - k * (t - (3.0 * T) / 8.0));
	}
	else if (t >= (5.0 * T) / 8.0 && t < (7.0 * T) / 8.0) {
		return i0 * (1.0 - k * (T / 8.0));
	}
	else if (t >= (7.0 * T) / 8.0 && t <= T + 1e-9) {
		return i0 * (1.0 - k * (T / 8.0) + k * (t - (7.0 * T) / 8.0));
	}
	return 0;
}

double find_l(double l0, double n, double t, double T) {
	if (t >= 0 && t < T / 4.0) {
		return l0 * (1.0 + n * t);
	}
	else {
		return l0 * (1.0 + n * (T / 4.0));
	}
}

double find_F(double I, double w, double Sc, double lb) {
	const double PI = 3.14159265358979323846;
	double numerator = 0.00001 * (0.4 * PI * I * w) * (0.4 * PI * I * w) * Sc;
	double denominator = 8 * PI * lb * lb;
	if (denominator < 1e-15) {
		printf("Error: denominator = 0");
		return 0;
	}
	return numerator / denominator;
}

int main() {
	int count = 3;
	int i;
	
	
	struct InputData* x;
	x = (struct InputData*)malloc(count * sizeof(struct InputData));
	if (x == NULL) {
		printf("Error: memory");
		return 1;
	}

	FILE* fin;
	fin = fopen("InputData.txt", "r");
	if (fin == NULL) {
		printf("Error: cannot open InputData.txt");
		return 1;
	}

	for (i = 0; i < count; i++) {
		if (fscanf(fin, "%lf %lf %lf %lf %lf %lf %lf %lf %lf",
			&x[i].T, &x[i].dt, &x[i].w, &x[i].Sc, &x[i].i0, &x[i].k0, &x[i].l0, &x[i].m, &x[i].n) != 9) {
		printf("Error: you need 9 values in %d variant\n", i + 1);
		fclose(fin);
		free(x);
		return 1;
		}
	}
	fclose(fin);
	
	FILE* p1;
	p1 = fopen("OutputData.txt", "w");
	if (p1 == NULL) {
		printf("Error: cannot create OutputData.txt");
		free(x);
		return 1;
	}

	for (i = 0; i < count; i++) {
		fprintf(p1, "Variant %d:\n", i + 1);
		printf("Variant %d:\n", i + 1);
		for (double t = 0; t <= x[i].T + (x[i].dt / 2.0); t += x[i].dt) {
			double k = find_k(x[i].k0, x[i].m, t, x[i].T);
			double I = find_I(x[i].i0, x[i].T, t, k);
			double l = find_l(x[i].l0, x[i].n, t, x[i].T);
			double F = find_F(I, x[i].w, x[i].Sc, l);

			fprintf(p1, "t = %lf  I = %lf   k = %lf   l = %lf   F = %lf\n", t, I, k, l, F);
			printf("t = %lf  I = %lf   k = %lf   l = %lf   F = %lf\n", t, I, k, l, F);
		}
		fprintf(p1, "\n");
	}
	fclose(p1);
	free(x);
	return 0;
}
