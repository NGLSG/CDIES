#include "share.h"

//编译 自定义flag default flags 默认为空
void compile(string file, string flags);

//编译 自定义flag 多个源文件
void compile(vector <string> files, string flags);

//编译 自定义flag 结果
void compile(string file, string flags, string res);

//编译 自定义flag 多个源文件 结果
void compile(vector <string> files, string flags, string res);

//检测多个文件是否存在
void check_empty(vector <string> files);

void check_empty(string file);

// sdl2的编译
void f_sdl2(int argc, char *argv[], string &flags);

//删除指定元素
template<class T>
void remove_element(vector <T> &v, T t);

//flags 扩展
template<class U>
void f_o_e(string &flags, string e, string o, vector <U> &v);

//保存地址
void save(string path);

//读取
map <string, string> load();

//获取文件
vector <string> get_all_files(string path, string suffix, vector <string> &res);

//保存地址
#define save_path "/home/Template/bin.txt"

//SDL2 flags
#define F_SDL2 "`sdl2-config --cflags --libs`"

//GTK4 flags
#define F_GTK4 "` pkg-config --libs gtk4 --cflags gtk4`"

//Sdl2 选项
#define O_SDL2 "-S"

//GTK4 选项
#define O_GTK4 "-G"

#define PATH_SIZE 255

//argc 默认为1

int main(int argc, char *argv[]) {
    system("ulimit -c unlimited");//生成core
    string regular = "[\\s\\w]+\\.(c|cpp|cxx|cc)$";//\s\w匹配任意字符包括空格
    regex r(regular, regex::icase);
    smatch res;
    string flags = " ";
    vector <string> tmp;
    for (int i = 0; i < argc; i++) {
        tmp.push_back(argv[i]);
    }
    f_o_e(flags, F_SDL2, O_SDL2, tmp);
    f_o_e(flags, F_GTK4, O_GTK4, tmp);
    if (!tmp.empty()) {
        remove_element<string>(tmp, ".");
        remove_element<string>(tmp, " ");
        remove_element<string>(tmp, "./");
        tmp.erase(tmp.begin());//删除无用数据

        if (argc == 2) {
            if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "v") == 0 ||
                strcmp(argv[1], "version") == 0) {
                cout << "目前版本为:0.3beta\n作者:尼古拉斯鸽\n交流群:1023190045\n帮助:使用-h或--help获取帮助\n";

            } else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 ||
                       strcmp(argv[1], "h") == 0) {
                cout << "\n";
                cout << "选项详解\n";
                cout << "-h 获取帮助\n";
                cout << "-v 获取版本\n";
                cout << "-d 指定编译结果\n";
                cout << "-S 编译SDL2程序(需要安装桌面)\n";
                cout << "-G 编译GTK4程序(需要安装桌面)\n";
                cout << "后续正在研发中\n";
                cout << "交流群:1023190045\n";
            } else {
                string file;
                for (auto &it: tmp) {
                    if (regex_search(it, res, r)) {
                        file = res.str();
                        remove_element<string>(tmp, file);
                    } else {
                        flags += it;
                        flags += " ";
                    }
                }
                if (file.empty()) {
                    vector <string> res2;
                    vector <string> files;
                    get_all_files(".", regular, res2);//.代表当前目录
                    for (auto &it: res2) {
                        files.push_back(it);
                    }

                    compile(files, flags);
                } else {
                    compile(file, flags);
                }
            }
        } else if (argc == 1) {
            vector <string> result;
            get_all_files(".", regular, result);//.代表当前目录
            compile(result, "");
        } else {
            //＞=2个选项
            vector <string> file;
            string d;
            for (auto &it: tmp) {
                if (regex_search(it, res, r)) {
                    file.push_back(res.str());
                }
            }
            if (!file.empty()) {
                for (auto &it: file) {
                    tmp.erase(find(tmp.begin(), tmp.end(), it));
                }
            }
            auto vit = find(tmp.begin(), tmp.end(), "-d");
            if (vit != tmp.end()) {
                try {
                    if (vit != tmp.end()) {
                        d = *(vit + 1);
                        tmp.erase(vit);//指定的目标
                        tmp.erase(vit);//-d关键字
                        try {
                            if (!d.empty()) {

                            } else {
                                throw "error!";
                            }
                        }
                        catch (...) {
                            cerr << "\033[31m错误: -d选项后面要求必须有一个参数,且不为特殊符号,请仔细检查!\033[0m" << endl;
                            exit(1);
                        }

                    } else {
                        throw "key is empty so nothing will happen";
                    }
                }
                catch (...) {}
            }
            for (auto &it: tmp) {
                flags += it;
                flags += " ";
            }
            if (!d.empty() && !file.empty()) {
                compile(file, flags, d);
            } else if (!d.empty() && file.empty()) {
                vector <string> res;
                vector <string> files;
                get_all_files(".", regular, res);//.代表当前目录
                for (auto &it: res) {
                    files.push_back(it);
                }
                compile(files, flags, d);
            } else if (file.empty()) {
                vector <string> res;
                vector <string> files;
                get_all_files(".", regular, res);//.代表当前目录
                for (auto &it: res) {
                    files.push_back(it);
                }
                compile(files, flags);
            } else {
                compile(file, flags);
            }
        }
    }
    return 0;
}

void compile(vector <string> files, string flags, string res) {
    check_empty(files);
    string file;
    for (auto &it: files) {
        file += it;
        file += " ";
    }
    compile(file, flags, res);
}

void compile(string file, string flags, string res) {
    try {
        string flag = " -pthread -time -g -Og ";
        flag += file;
        flag += " -o ";
        flag += res;
        flag += flags;
        int index = 0;
        string cmd = "g++";
        cmd += flag;
        cout << "输出的可执行文件为: " << res << endl;
        cout << "编译命令为: " << cmd << endl;
        auto beginTime = std::chrono::high_resolution_clock::now();
        int status = system(cmd.c_str());
        auto endTime = chrono::high_resolution_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::microseconds>(endTime - beginTime);
        double programTimes = ((double) elapsedTime.count());
        if (status == 0) {
            cout << "编译" << file << "成功!编译时间为: " << __TIME__ << "\n编译" << file << "文件总用时: " << (double) programTimes
                 << "秒" << "\n运行结果如下:\n\n";
            status = system(res.c_str());
            if (status == 0) {}
            else {
                cmd = "./";
                cmd += res;
                system(cmd.c_str());
            }
            string tmp = "./";
            tmp += res;
            save(tmp);
        } else {
            throw "error!";
        }
    }
    catch (...) {
        cerr << "\033[31m编译失败!\033[0m\n";
    }
}

void compile(vector <string> files, string flags) {
    check_empty(files);
    if (files.size() > 1) {
        cout << "根据检测,你输入的源文件大于一个\n";
        cout << "系统将会自动把输出文件命名为_run_,请检查是否有重名\n";
        cout << "现在CTRL+C退出还来得及,如果继续请按回车\n";
        cin.get();
        compile(files, flags, "_run_");
    } else {
        for (auto &it: files) {
            compile(it, flags);
        }
    }
}

void compile(string file, string flags) {
    check_empty(file);
    try {
        string flag = " -pthread -time -g -Og ";
        flag += file;
        flag += " -o ";
        int index = 0;
        auto pos = file.find_last_of('.');
        string res = file.substr(0, pos);
        flag += res;
        flag += flags;
        string cmd = "g++";
        cmd += flag;
        cout << "输出的可执行文件为: " << res << endl;
        cout << "编译命令为: " << cmd << endl;
        auto beginTime = std::chrono::high_resolution_clock::now();
        int status = system(cmd.c_str());
        auto endTime = chrono::high_resolution_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::microseconds>(endTime - beginTime);
        double programTimes = ((double) elapsedTime.count());
        if (status == 0) {
            cout << "编译" << file << "成功!编译时间为: " << __TIME__ << "\n编译" << file << "文件总用时: " << (double) programTimes
                 << "秒" << "\n运行结果如下:\n\n";
            status = system(res.c_str());
            if (status == 0) {}
            else {
                cmd = "./";
                cmd += res;
                system(cmd.c_str());
            }
            string tmp = "./";
            tmp += res;
            save(tmp);

        } else {
            throw "error!";
        }
    }
    catch (...) {
        cerr << "\033[31m错误: 编译失败!\033[0m\n";
    }
}

vector <string> get_all_files(string path, string suffix, vector <string> &res) {
    vector <string> files;
    regex reg_obj(suffix, regex::icase);

    vector <string> paths;
    paths.push_back(path);

    for (int i = 0; i < paths.size(); i++) {
        string curr_path = paths[i];
        DIR *dp;
        struct dirent *dirp;
        if ((dp = opendir(curr_path.c_str())) == NULL) {
            cerr << "没有文件!" << endl;
            continue;
        }
        while ((dirp = readdir(dp)) != NULL) {
            if ((dirp->d_name)[0] == '.') // 这里很奇怪，每个文件夹下都会有两个文件： '.'  和   '..'
                continue;
            string tmp_path = curr_path + "/" + dirp->d_name;
            paths.push_back(tmp_path);
            if (regex_match(dirp->d_name, reg_obj)) {
                string full_path = curr_path + "/" + dirp->d_name;
                files.push_back(full_path);
            }
        }
        closedir(dp);
    }
    res = files;
    return files;
}

void check_empty(vector <string> files) {
    for (auto &it: files) {
        check_empty(it);
    }
}

template<class T>
void remove_element(vector <T> &v, T t) {
    auto vit = find(v.begin(), v.end(), t);
    if (vit != v.end()) {
        for (auto &it: v) {
            if (it == *vit) {
                v.erase(vit);
            }
        }
    }
}

template<class U>
void f_o_e(string &flags, string ext, string opt, vector <U> &v) {
    string temp = opt;
    for (auto it = opt.begin(); it < opt.end(); it++) {
        if (*it == '-') {}
        else {
            opt = *it;
        }
    }
    if (!v.empty()) {
        for (auto &it: v) {
            if (it == temp || it == opt) {
                flags += ext;
                flags += " ";
                remove_element<U>(v, it);
            }
        }
    }
}

void save(string path) {
    if (checkExist(save_path)) {

        string cmd = "touch ";
        cmd += save_path;
        system(cmd.c_str());
    } else {
        ofstream ofs(save_path, ios::out | ios::app);
        ofs << path << endl;
        ofs.close();
    }
}

void check_empty(string file) {
    ifstream ifs(file, ios::in);
    if (!ifs.is_open()) {
        cerr << "\033[31m编译意外终止: 没有" << file << "这个文件\033[0m \n";
        exit(1);
    }
    ifs.close();
}


