#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void new_file(string filename, string text){
	
}

vector<string> ls(){
	string path = "";
	cout << "Enter path: ";
	cin >> path;
	string command = "./ls.ps";
	command = command  + " " + path;
	cout << command;
	system(command);
}

string find(string name){
	
}

void python(string command){
	
}

int main(){
	string command = "";
	cin >> command;
	if(command == "new_file"){
		string filename = "";
		cout << "Enter filename: ";
		getline(cin, filename);
		string text = "";
		cout << "\nEnter text: ";
		getline(cin, text);
		new_file(filename, text);
	} else if(command == "ls"){
		ls();
	} else if(command == "find"){
		string name = "";
		cout << "Enter filename: ";
		getline(cin, name);
		find(name);
	} else if(command == "python"){
		string pythoncommand = "";
		cout << "Enter python command: ";
		getline(cin, pythoncommand);
		python(pythoncommand);
	}
}