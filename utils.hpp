#ifndef TOOLS_H
#define TOOLS_H
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<sys/types.h>
#include<dirent.h>
#include<vector>
#include<map>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include<sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include <utility> 
#include <stdexcept>
#include <sstream> 
#include <limits> 


using namespace std;

#define MAX 1
#define MIN 0
#define SIZE 512

typedef std::vector<std::string> stringvec;
stringvec read_csv(std::string filename);
stringvec read_directory(const std::string& name);
int read_from_fifo(string fifo_path);
void write_to_fifo(int price, string fifo_path);
int return_max(vector<int> vec);
int return_min(vector<int> vec);
std::map<string, int> map_words(stringvec words);
stringvec parse_input(char buf[SIZE]);
void create_process(string province_name,string pipe_name, const char* argv);

#endif