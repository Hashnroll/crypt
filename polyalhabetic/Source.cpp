#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	fstream in("D:\\khan_quest\\hint_4.txt");
	string cipher, key = "kkuullllss", msg;
	getline(in, cipher);
	ofstream out;
	out.open("D:\\khan_quest\\hint_44.txt");
	int l=key.length();
	for (int j = 0; j < cipher.length(); ++j) {
		int ch = cipher.at(j) - (key.at(j%l) - 'a');
		if (ch < 'a')
			ch += 26;
		msg += ch;
	}
	out << msg << endl << endl;
	in.close();
	out.close();
	return 0;
}