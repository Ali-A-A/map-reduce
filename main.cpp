#include"utils.hpp"
#include<vector>


using namespace std;

int main(int argc, char **argv){
    vector<string> files;
    for (int i = 1; i < argc; i++) {
        files.push_back(argv[i]);
    }
    // string dir,commands_file;
    // if (argc == 3){
    //     commands_file = argv[1];
    //     dir = argv[2];
    // }

    // stringvec commands = read_csv(commands_file);

    // for (int i = 0; i < commands.size(); ++i){
    //     string pipe_address = "./pipes/f-" + to_string(i) + "-";
    //     create_process(dir,pipe_address,commands[i],"./assets.out");
    //     cout << to_string(read_from_fifo(pipe_address)) << endl;
    // }

    for (int i = 0; i < files.size(); i++) {
        string pipe_address = "./pipes/f-" + to_string(i) + "-";
        create_process(files[i], pipe_address);
    }


    return 0;
}