#include <iostream>
#include <string>
#include <vector>
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

<<<<<<< HEAD
int main(){
=======
int main(int argc, int argv[]){
>>>>>>> 3cf025587f5f65597ec8f7636250b16b7fa66697
	string input = "";
	getline(cin, input);
	int charnum = 6;
	string output = caesar(charnum, input);
	cout << output << "\n";
}