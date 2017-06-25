#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//frequency analysis of latin message

int main() {
	fstream in("D:\\khan_quest\\hint_4.txt");
	string cipher;
	getline(in, cipher);
	int data[26];
	for (int i = 0; i < 26; ++i) {
		data[i] = 0;
	}
	int max_index = 0;
	for (int i = 0; i < cipher.length(); ++i) {
		int index = cipher.at(i)-'a';
		data[index]++;
		if (data[index] > data[max_index])
			max_index = index;
	}
	string freq_scale = "etaoins";
	ofstream out;
	out.open("D:\\khan_quest\\hint_44.txt");
	for (int i = 0; i < freq_scale.length(); ++i) {
		string guess;
		int shift = freq_scale.at(i)-'a'-max_index;
		for (int j = 0; j < cipher.length(); ++j) {
			int ch = cipher.at(j) + shift;
			if (ch < 97)
				ch += 26;
			else if (ch > 122)
				ch -= 26;
			guess += ch;
		}
		out << guess << endl << endl;
	}
	in.close();
	out.close();
	system("pause");
	return 0;
}