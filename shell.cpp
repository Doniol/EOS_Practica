#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
using namespace std;


void new_file(string filename, string text){
	
}

void ls(){
	string path = "";
	cout << "Enter path: ";
	cin >> path;
	int pid = fork();
	if (pid == 0){
		execlp("/bin/ls", "ls", "-la", path.c_str(), NULL);
	}
	int waitnr = 2;
	wait(&waitnr);
}

string find(string name){
	
}

void python(string command){
	
}

void command_run(){
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

int main(){
	command_run();
}