#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string input = "";
	getline(cin, input);
	string newinput = "";
	for(int i = 0; i < input.size(); i++){
		char character = input[i];
		if(character == 'A' || character == 'B' || character == 'C' || character == 'a' || character == 'b' || character == 'c'){
			char newchar = character + 23;
			newinput += newchar;
		} else if(character >= 65 && character <= 90 || character >= 97 && character <= 122) {
			char newchar = character - 3;
			newinput += newchar;
		} else {
			newinput += character;
		}
	}
	cout << newinput << "\n";
}