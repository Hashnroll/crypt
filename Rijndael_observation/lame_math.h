#pragma once
#include <math.h>

int m = 283; //несократимый полином
int q;	//частное от деления двух полиномов

int zeronation(int x) {	//обнуление следующих за главным разрядов(maybe there's a better way)
	int shift = 0;
	while (x > 1) {
		x >>= 1;
		shift++;
	}
	int res = x << shift;
	return x << shift;
}

int mod_bin(int a, int b) {
	q = 0;
	//////
	int shift;
	while ((shift = trunc(log2(a)) - trunc(log2(b))) >= 0) {
		int shifted_b = (b << shift);
		a ^= shifted_b;
		////////////////
		q += pow(2, shift--);
	}
	return a;
}

int mult_bin(int a, int b) {
	int res = 0;
	while (b > 0) {
		res ^= a * zeronation(b);
		b -= zeronation(b);
	}
	return res;
}
