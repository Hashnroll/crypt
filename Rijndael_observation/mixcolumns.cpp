#include "settings.h"
#include "lame_math.h"

int mult_galois(int a, int b) {
	return mod_bin(mult_bin(a, b), 283);
}

void mixcolumns(word8 state[4][Nb]) {
	char newstate[4][Nb];	
	for (int c = 0; c < Nb; c++) {
		newstate[0][c] = mult_galois(2, state[0][c]) ^ mult_galois(3, state[1][c]) ^ state[2][c] ^ state[3][c];
		newstate[1][c] = state[0][c] ^ mult_galois(2, state[1][c]) ^ mult_galois(3, state[2][c]) ^ state[3][c];
		newstate[2][c] = state[0][c] ^ state[1][c] ^ mult_galois(2, state[2][c]) ^ mult_galois(3, state[3][c]);
		newstate[3][c] = mult_galois(3, state[0][c]) ^ state[1][c] ^ state[2][c] ^ mult_galois(2, state[3][c]);
	}
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < Nb; c++)
			state[r][c] = newstate[r][c];
}

void invmixcolumns(word8 state[4][Nb]) {
	char newstate[4][Nb];
	for (int c = 0; c < Nb; c++) {
		newstate[0][c] = mult_galois(0x0e, state[0][c]) ^ mult_galois(0x0b, state[1][c]) ^ mult_galois(0x0d, state[2][c]) ^ mult_galois(0x09, state[3][c]);
		newstate[1][c] = mult_galois(0x09, state[0][c]) ^ mult_galois(0x0e, state[1][c]) ^ mult_galois(0x0b, state[2][c]) ^ mult_galois(0x0d, state[3][c]);
		newstate[2][c] = mult_galois(0x0d, state[0][c]) ^ mult_galois(0x09, state[1][c]) ^ mult_galois(0x0e, state[2][c]) ^ mult_galois(0x0b, state[3][c]);
		newstate[3][c] = mult_galois(0x0b, state[0][c]) ^ mult_galois(0x0d, state[1][c]) ^ mult_galois(0x09, state[2][c]) ^ mult_galois(0x0e, state[3][c]);
	}
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < Nb; c++)
			state[r][c] = newstate[r][c];
}