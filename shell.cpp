#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
using namespace std;


void new_file(){
	string filename = "";
	cout << "Enter filename: ";
	cin >> filename;
	string path = "/home/hu/" + filename;
	creat(path.c_str(), S_IRWXO | S_IRWXU);
	string text = "";
	cout << "\nEnter text: ";
	cin.ignore();
	getline(cin, text);
	text += "\n";
	int fd  = open(path.c_str(), O_RDWR | O_EXCL);
	const void * input = text.c_str();
	write(fd, input, strlen(text.c_str()));
	close(fd);
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
		new_file();
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