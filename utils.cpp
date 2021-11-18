#include"utils.hpp"

using namespace std;

void create_process(string province_name,string pipe_name, const char* argv){
        int fd[2]; // 0 for read, 1 for write
        
        if (pipe(fd) < 0 ){
            cout << "error occured in opening pipe" << endl;
        }

        int pid = fork();

        if (pid < 0){
           cout << "error occured in creating new thread" << endl;
        }
        
        if (pid == 0){
            //child
            close(fd[1]);
            string fd_char = to_string(fd[0]);
            char *pchar = &fd_char[0];
            char*  arg[] = {pchar,NULL};
            execv(argv,arg);
        }
        else{
            //parrent
            close(fd[0]);
            string buf = "#" + province_name + "#" + pipe_name;
            char x[SIZE];
            strcpy(x,&buf[0]);
            mkfifo(pipe_name.c_str(), 0666); 
            write(fd[1],&x, SIZE);
        }  
}
stringvec parse_input(char buf[SIZE]){
    char dir_name_c[SIZE],pipe_name_c[SIZE],command_c[SIZE];

    sscanf(buf,"#%[^#]#%[^#]#%[^#]#",dir_name_c,pipe_name_c,command_c);
    string dir_name(dir_name_c);
    string pipe_name(pipe_name_c);
    string command(command_c);

    stringvec vec;
    vec.push_back(dir_name);
    vec.push_back(pipe_name);
    vec.push_back(command);

    return vec;
}

map<string, int> map_words(stringvec words) {
    map<string, int> result;
    for (int i = 0; i < words.size(); i++) {
        if (result.find(words[i]) == result.end()) {
            result[words[i]] = 1;
        } else {
            result[words[i]] = result[words[i]] + 1;
        }
    }
    return result;
}

stringvec read_csv(string filename){

    stringvec result;
    ifstream myFile(filename);
    if(!myFile.is_open()) throw runtime_error("Could not open file");

    std::string line;

    while(getline(myFile, line)){
        std::stringstream test(line);
        std::string segment;
        while(std::getline(test, segment, ','))
        {
            result.push_back(segment);
        }
    }
    myFile.close();

    return result;
}

int return_max(vector<int> vec){
    int price = -1;
    for (int i = 0; i < vec.size(); i++){
        price = max(price,vec[i]);
    }
    return price;
}

int return_min(vector<int> vec){
    int price = std::numeric_limits<int>::max();
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] != -1){
            price = min(price,vec[i]);
        }
    }
    
    return (price == std::numeric_limits<int>::max())? -1:price;
}

int read_from_fifo(string fifo_path){

    int fifo;
    const char *pchar = fifo_path.c_str();
    if ((fifo = open(pchar, O_RDONLY)) < 0){
        printf("error in opening read fifo ");
        return 0;
    }
    
    char price_c[SIZE];

    int flag;
    if((flag = read(fifo, price_c, SIZE) )< 0){
        printf("error in reading fifo ");
        exit(1);
    }

    close(fifo);
    unlink(pchar);
    int price = stoi(price_c);
    return price;
}


void write_to_fifo(int price_i, string fifo_path){
    int fifo;
    const char *fifochar = fifo_path.c_str();
    if ((fifo = open(fifochar,O_WRONLY)) < 0){
        printf("error in opening write fifo\n");
        return;
    }
    string s = to_string(price_i);
    const char *pchar = s.c_str();
    char kh[100];
    strcpy(kh, pchar);

    int flag;
    if ((flag = write(fifo, kh, SIZE)) < 0){
        printf("error in writing to pipe\n");
        exit(1);
    }
    close(fifo);
}

stringvec read_directory(const std::string& name){
    stringvec v;
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name,".") != 0 & strcmp(dp->d_name,"..") != 0)
            v.push_back(dp->d_name);
    }
    closedir(dirp);
    return v;
}