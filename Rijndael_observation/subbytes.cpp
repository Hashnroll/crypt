#include "settings.h"

void subbytes(word8 state[4][Nb]) {
	for (int c = 0; c < Nb; ++c)
		for (int r = 0; r < 4; ++r) {
			int n = state[r][c];
			state[r][c] = S[n];
		}
}

void invsubbytes(word8 state[4][Nb]) {
	for (int c = 0; c < Nb; ++c)
		for (int r = 0; r < 4; ++r) {
			int n = state[r][c];
			state[r][c] = Si[n];
		}
}

