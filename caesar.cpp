#include <iostream>
#include <string>
#include <vector>
using namespace std;

string caesar(int charnum, string input){
	string newinput = "";
	for(int i = 0; i < input.size(); i++){
		char character = input[i];
		if(character == 'A' || character == 'B' || character == 'C' || character == 'a' || character == 'b' || character == 'c'){
			char newchar = character + (26 - charnum);
			newinput += newchar;
		} else if(character >= 65 && character <= 90 || character >= 97 && character <= 122) {
			char newchar = character - charnum;
			newinput += newchar;
		} else {
			newinput += character;
		}
	}
	return newinput;
}

int main(int argc, char argv[]){
	string input = "";
	getline(cin, input);
	int charnum = argv[1];
	string output = caesar(charnum, input);
	cout << output << "\n";
}