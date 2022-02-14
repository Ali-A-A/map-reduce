#include"utils.hpp"

using namespace std;

int main(int argc, char **argv){
    char buf[SIZE];
    int fd = stoi(argv[0]);
    read(fd,buf,SIZE);
    close(fd);
    stringvec input = parse_input(buf);
    stringvec res = read_csv(input[0]);
    map<string, int> mapping = map_words(res);
    
    int price = 0;
    for(std::map<string,int>::iterator iter = mapping.begin(); iter != mapping.end(); ++iter) {
        price = iter->second;
    }

    write_to_fifo(price, input[1]);

    return 0;
}