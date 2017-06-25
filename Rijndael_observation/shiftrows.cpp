#include "shiftrows.h"

void shiftrows(word8 state[4][Nb]) {
	for (int r = 1; r < 4; ++r)
		for (int k = 0; k < r; ++k) {
			char l = state[r][0];
			for (int c = 0; c < Nb-1; ++c) {
				state[r][c] = state[r][c + 1];
			}
			state[r][Nb-1] = l;
		}
}

void invshiftrows(word8 state[4][Nb]) {
	for (int r = 1; r < 4; ++r)
		for (int k = 0; k < (4-r); ++k) {
			char l = state[r][0];
			for (int c = 0; c < Nb-1; ++c) {
				state[r][c] = state[r][c + 1];
			}
			state[r][Nb-1] = l;
		}
}