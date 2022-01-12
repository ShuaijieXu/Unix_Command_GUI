/*
Author: Shuaijie Xu
Student ID: 251187747
Date: 2021-09-31
Description: Command class including three private memebers
A constuction and a deconstruction
setter and getter functions are also included 
*/
#ifndef COMMAND_H
#define COMMAND_H
class Command{
	private:
		std::string command_text;
		std::string result;
		int return_code;
	public:
		Command(std::string Command_Text);
		~Command();
		int execute();
		void set_command_text(std::string Command_Text);
		std::string get_command_text();
		std::string get_result();
		int get_return_code();
};
#endif

