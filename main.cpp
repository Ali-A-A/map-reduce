#include"utils.hpp"
#include<vector>


using namespace std;

int main(int argc, char **argv){
    vector<string> files;
    for (int i = 1; i < argc; i++) {
        files.push_back(argv[i]);
    }
    
    for (int i = 0; i < files.size(); i++) {
        string pipe_address = "./pipes/f-" + to_string(i) + "-";
        create_process(files[i], pipe_address, "./map.out");
        cout << read_from_fifo(pipe_address) << endl;
    }

    cout << "Bye" << endl;


    return 0;
}