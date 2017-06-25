#include <iostream>
#include "subbytes.h"
#include "shiftrows.h"
#include "mixcolumns.h"
#include "addroundkey.h"
#include "keyexpansion.h"

using namespace std;
void showstate(word8 state[4][Nb]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << hex << (int)state[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

char* encrypt(char* input, word8 keywords[4][kw_size]) {
	word8 state[4][Nb];
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			state[r][c] = input[r + 4 * c];
	//////////////////////////////////
	addroundkey(state, keywords, 0);
	for (int round = 1; round < Nr; ++round) {	
		subbytes(state);
		shiftrows(state);
		mixcolumns(state);
		addroundkey(state, keywords,round);
	}
	subbytes(state);
	shiftrows(state);
	addroundkey(state, keywords, Nr);
	//////////////////////////////////
  char* output = new char[4*Nb];
	for (int c = 0; c < Nb; c++)
			for (int r = 0; r < 4; r++)
				output[r + 4 * c] = state[r][c];
	return output;
}

char* decrypt(char* input, word8 keywords[4][kw_size]) {
	word8 state[4][Nb];
	for (int c = 0; c < Nb; c++)
		for (int r = 0; r < 4; r++)
			state[r][c] = input[r + 4 * c];
	//////////////////////////////////
	addroundkey(state, keywords, Nr);
	for (int round = Nr-1; round > 0; --round) {
		invshiftrows(state);
		invsubbytes(state);
		addroundkey(state, keywords, round);
		invmixcolumns(state);
	}
	invshiftrows(state);
	invsubbytes(state);
	addroundkey(state, keywords, 0);
	//////////////////////////////////
	char* output=new char[4*Nb];
	for (int c = 0; c < Nb; c++)
		for (int r = 0; r < 4; r++)
			output[r + 4 * c] = state[r][c];
	output[4 * Nb] = '\0';
	return output;
}

int main() {	
	word8 keywords[4][kw_size];
	unsigned char key[4*Nk]={ 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	keyexpansion(key, keywords);
	char msg[16] = { 'i','t','\'','s', 'j','u','s','t','o','n','e','b','l','o','c','k'};
	cout << decrypt(encrypt(msg, keywords), keywords) << endl;
	system("pause");
	return 0;
}