#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>
#include <regex>
#include <filesystem>

using namespace std;
#define CPATH "/CDIES/.CMake/SAVE/"
#define NPATH "/CDIES/.CMake/SAVE/name.csv"
#define SPATH "/CDIES/.CMake/SAVE/flag.csv"
#define PATH_SIZE 255

string home(string dpath);

bool checkExist(string file);

class CMake {
public:
    CMake() {
        if (!checkExist(home(CPATH))) {
            string cmd = "mkdir -p ";
            cmd += home(CPATH);
            system(cmd.c_str());
        }
    }

    bool INSTALL(string name, string cmd1);

    bool SAVE_CMAKE(vector<string> file, string name);

    vector<string> LOAD_CMAKE(string name);

    vector<string> LOAD_NAME();

    vector<string> CATCH_OUT(const string &strCmd);

    bool DELC(string flag);

    bool UNINSTALL(string name);
};

void cout_size(unsigned long size) {
    if (size < 1024 * 1024) {
        auto size2 = size / 1024;
        cout << " :\t\033[32m" << size2 << "kb\033[0m " << endl;
    } else if (size >= 1024 * 1024 && size < 1024 * 1024 * 1024) {
        auto tmp = 1024 * 1024;
        auto size2 = size / tmp;
        cout << " :\t\033[34m" << size2 << "MB\033[0m " << endl;
    } else if (size >= 1024 * 1024 * 1024) {
        auto tmp = 1024 * 1024 * 1024;
        auto size2 = size / tmp;
        cout << " :\t\033[31m" << size2 << "GB\033[0m " << endl;
    }
}

int main(int argc, char *argv[]) {

    vector<string> cmd;
    for (int i = 0; i < argc; i++) {
        cmd.push_back(argv[i]);
    }
    cmd.erase(cmd.begin());
    argc = argc - 1;
    CMake cmake;
    if (argc >= 1) {
        for (auto &it: cmd) {
            if (it == "-r") {
                cmd.erase(cmd.begin());
                for (auto &it2: cmd) {
                    cmake.UNINSTALL(it2);
                }
                break;
            } else if (it == "-d") {
                cmd.erase(cmd.begin());
                vector<string> cmd2;
                cmd2.emplace_back("make -j8");
                cmd2.emplace_back("make install");
                string cmd3;
                for (auto &it2: cmd2) {
                    cmd3 += it2 + "\n";
                }
                cmake.INSTALL(cmd.front(), cmd3);
                break;
            } else if (it == "-l") {
                auto nload = cmake.LOAD_NAME();
                for (auto &it3: nload) {
                    auto load = cmake.LOAD_CMAKE(it3);
                    cout << it3;
                    unsigned long all_size = 0;
                    for (auto &it2: load) {
                        auto size = filesystem::file_size(it2);
                        all_size += size;
                    }
                    cout_size(all_size);
                }
                break;
            } else if (it == "-dl") {
                cout << cmd.back() << ": " << endl;
                auto nload = cmake.LOAD_CMAKE(cmd.back());
                for (auto &it3: nload) {
                    auto size = filesystem::file_size(it3);
                    cout << it3;
                    cout_size(size);
                }
                break;
            } else if (it == "-ini") {
                string path = home(CPATH);
                string cmd2 = "rm -rf " + path;
                system(cmd2.c_str());
                cout << "初始化成功\n";
                break;
            } else if (it == "-h") {
                cout
                        << "\033[34m选项:\n-ini \t初始化\n-h\t获取帮助\n-d \t指定的项目名 \n-r \t删除指定的项目所有文件\n-l \t显示所有文件的大小\n-dl \t显示指定项目详细信息\033[0m\n";
                break;
            } else {
                cout << "\033[31m错误:选项未找到\033[31m\n";
                break;
            }
        }
    }

    return 0;

}

string get_path() {
    string res;
    char path[PATH_SIZE];
    if (!getcwd(path, PATH_SIZE)) {
        cout << "错误: 未知路径" << endl;

    }
    res = path;
    res += "/";
    return res;
}

string home(string dpath) {
    string path = getenv("HOME");
    path += dpath;
    return path;
}

bool checkExist(string file) {
    int pos = file.find("~");
    int pos2 = file.find("./");
    if (pos != string::npos) {
        file.erase(file.begin());
        file.insert(0, getenv("HOME"));
    }
    if (pos2 != string::npos) {
        file = file.substr(pos2, file.back());
        string tmp = get_path();
        tmp += file;
        file = tmp;
    }
    struct stat info;
    if (stat(file.c_str(), &info) != 0) {  // does not exist
        return false;
    } else {
        return true;
    }
}

bool CMake::INSTALL(string name, string cmd1) {
    string cmd;
    cmd = cmd1;
    string file = name;
    auto res = CATCH_OUT(cmd);
    string regular = "^(-- Up-to-date: |-- Installing: )";
    regex r(regular);
    smatch sres;
    vector<string> callback;
    for (auto &it: res) {
        if (regex_search(it, sres, r)) {
            string tmp = sres.str();
            int pos = it.find(tmp);
            it = it.erase(pos, tmp.size());
            callback.push_back(it);
        }
    }
    ofstream ofs2(home(NPATH), ios::out | ios::app);
    ofs2 << file << endl;
    name = name.erase(0, name.find_last_of("/") + 1);
    SAVE_CMAKE(callback, name);
    ofs2.close();
    return true;
}

bool CMake::SAVE_CMAKE(vector<string> files, string name) {
    string path = home(CPATH);
    path += name + "/";
    if (!checkExist(path)) {
        string cmd = "mkdir -p " + path;
        system(cmd.c_str());
    }
    string csv = path;
    csv += name + ".csv";
    ofstream ofs(csv, ios::out | ios::app);
    for (auto &it: files) {
        ofs << it;
    }
    ofs.close();
    return true;
}

vector<string> CMake::LOAD_CMAKE(string file) {
    string path = home(CPATH);
    path += file + "/";
    path += file + ".csv";
    vector<string> res;
    ifstream ifs(path, ios::in);
    if (ifs.is_open()) {
        string s = "";
        while (getline(ifs, s)) {
            res.push_back(s);
        }
        return res;
    } else {
        cout << "\033[33m警告: 无法找到 " << file <<"\033[0m"<< endl;
    }
    ifs.close();
}

/// 执行cmd指令并返回结果
vector<string> CMake::CATCH_OUT(const string &strCmd) {
    vector<string> res;
    char buf[10240] = {0};
    FILE *pf = nullptr;

    if ((pf = popen(strCmd.c_str(), "r")) == nullptr) {
    }

    string strResult;
    while (fgets(buf, sizeof buf, pf)) {
        cout << buf << endl;
        res.emplace_back(buf);
    }

    pclose(pf);

    return res;
}

bool CMake::UNINSTALL(string name) {
    auto load = LOAD_CMAKE(name);
    if (!load.empty()) {
        string cmd;
        vector<string> deal;
        bool ret = false;
        for (auto &it: load) {
            cmd = "rm -rf ";
            cmd += it;
            CATCH_OUT(cmd);
            if (!checkExist(it)) {
                ret = true;
            } else {
                cout << it << "删除失败\n";
                deal.push_back(it);
                ret = false;
            }
        }
        cmd = "rm -rf ";
        string path = home(CPATH);
        path += name + "/";
        path += name + ".csv";
        cmd += path;
        system(cmd.c_str());
        string path2 = home(NPATH);
        ifstream ifs(path2, ios::in | ios::trunc);
        vector<string> v;
        string tmp;
        ofstream ofs2(home(NPATH), ios::out);
        while (getline(ifs, tmp)) {
            if (tmp != name) {
                ofs2 << tmp << endl;
            }
        }
        cout << "删除 " << name << " 成功\n";
        SAVE_CMAKE(deal, name);
        return ret;
    } else{
        cout << "\033[33m警告: 删除失败 \033[0m" << endl;
    }
}


vector<string> CMake::LOAD_NAME() {
    ifstream ifs(home(NPATH), ios::in);
    string line;
    vector<string> ret;
    while (getline(ifs, line)) {
        ret.push_back(line);
    }
    return ret;
}
