/*
Author: Shuaijie Xu
Student ID: 251187747
Date: 2021-09-31
Description: 
-Command(string) set all the class memeber and set the command_text meaningful
-A deconstruction do nothing
-execute() function create a child process and run the command_text on linux,get the std_out and std_err to pipe_stream
copy the pipe_stream into a string and result
-and getter and setter functions
*/
#include<iostream>
#include"command.h"
#include<boost/process.hpp>
using namespace std;
using namespace boost::process;

/*function name: Command
description: constructor initializes member of Command class
*/
Command::Command(string Command_Text)
{
	command_text = Command_Text;
	return_code = 0;
	result = string();
}
Command::~Command()
{
	;
}

/*
function name: execute
description: create a child process to run the command in Linux
get the std_out and std_err and store in pipe_stream, and store pipe_strem in
a string. catch exception if there is an error
return: if it catch exception return -1, otherwise rturn 0
*/
int Command::execute()
{
	ipstream pipe_stream;
	string line;
	try{
		child c(command_text, (std_out & std_err) > pipe_stream);
		while(pipe_stream && getline(pipe_stream,line) && !line.empty())
		{
			result.append(line);
			result.append("\n");
		}	
		c.wait();
	}
	catch(process_error &ex)
	{
		result.append(ex.what());
		return_code = -1;//if error, set return code to -1
	}
	return return_code;//if no error, return the old value of return_code which is 0
}

/*
function name: set_command_text
description: it get the string and assign the value to command_txt
parameter: Command_Text is the userinput
*/
void Command::set_command_text(string Command_Text)
{
	command_text = Command_Text;
}

/*
function name: get_command_text
description: it return one of the member of Command class
*/
string Command::get_command_text()
{
	return command_text;
}

/*
function name: get_result()
description: it return one of the member of Command class
*/
string Command::get_result()
{
	return result;
}

/*
function name: get_return_code
desciption: it return one of the member of Command class
*/
int Command::get_return_code()
{
	return return_code;
}


