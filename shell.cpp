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
#include <termios.h>
using namespace std;

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);


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
		execlp("ls", "ls", "-la", path.c_str(), NULL);
	}
	int waitnr = 2;
	wait(&waitnr);
}

void find(){
	string name = "";
	string text = "";
	cout << "Enter filename: ";
	cin >> name;
	cout << "Enter string: ";
	cin >> text;
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(pid == 0) {
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	    	execlp("find", "find", name.c_str(), NULL);
	} else {
		int pid = fork();
		if (pid == 0){
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			execlp("/bin/grep", "grep", text.c_str(), NULL);
		} else {
			close(fd[1]);
			close(fd[0]);
			int waitnr = 2;
			wait(&waitnr);
		}
	}
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
		find();
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