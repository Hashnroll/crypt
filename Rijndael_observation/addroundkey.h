#pragma once
#include "keyexpansion.h"

void addroundkey(word8 state[4][Nb], word8 keywords[4][kw_size], int round);