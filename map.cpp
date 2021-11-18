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
    //cout << input[1] << endl;
    //cout << input[0] << endl;
    //cout << "--------------------" << endl;
    int price = 0;
    for(std::map<string,int>::iterator iter = mapping.begin(); iter != mapping.end(); ++iter) {
        //cout << iter->first << " " << iter->second << endl;
        price = iter->second;
    }
    //cout << "--------------------" << endl;


    //stringvec dir_vec = read_directory(input[0]);

    // for (int i = 0; i < dir_vec.size(); i++){
    //     create_process(input[0] + "/" + dir_vec[i],input[1]+to_string(i)+ "-",input[2],"./province.out");
    // }
    
    // int price = get_maxOrmin_between_childs(input[2],dir_vec,input[1]);
    write_to_fifo(price, input[1]);

    return 0;
}