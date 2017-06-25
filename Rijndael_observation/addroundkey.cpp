#include "addroundkey.h"

void addroundkey(word8 state[4][Nb], word8 keywords[4][kw_size], int round) {
	for (int c = 0; c < Nb; c++) {
		for (int r = 0; r < 4; ++r)
			state[r][c] ^= keywords[r][c+4*round];
	}
}