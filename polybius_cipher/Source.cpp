#include <fstream>
#include <string>
using namespace std;

char polybius_table[5][5] = { {'a','b','c','d','e'},
{'f','g','h','i','j'},
{'k','l','m','n','o'},
{'p','q','r','s','t'},
{'u','v','w','x','y'} };

int main() {
	ifstream in("D:\\test_text.txt");
	string msg;
	int i, j;
	while ((j = in.get())>0) {
		if ((i = in.get())>0)
			msg += polybius_table[i-'0'-1][j-'0'-1];
	}
	in.close();
	ofstream out; 
	out.open("D:\\khan_quest\\hint_44.txt");
	out << msg;
	out.close();
	return 0;
}