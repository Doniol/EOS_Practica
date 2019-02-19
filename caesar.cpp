#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string caesar(int charnum, string input){
	string newinput = "";
	for(int i = 0; i < input.size(); i++){
		char character = input[i];
		if(character >= 65 && character <= (65 + charnum) || character >= 97 && character <= (97 + charnum)){
			char newchar = character + (26 - charnum);
			if(newchar == 123){
				newchar = 97;
			} else if(newchar == 91){
				newchar = 65;
			}
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

int main(int argc,char* argv[]){
	string input = " ";
	string line = "";
	while(input != ""){
		getline(cin, input);
		line += input;
		line += "\n";
	}
	int charnum = atoi(argv[1]);
	string output = caesar(charnum, line);
	cout << output;
}