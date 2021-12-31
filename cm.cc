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

class CMake
{
public:
    CMake(){
        if(!checkExist(home(CPATH))){
            string cmd="mkdir -p ";
            cmd+= home(CPATH);
            system(cmd.c_str());
        }
    }
    map<string, string> ret;

    bool INSTALL(string name, vector<string> cmd1);

    bool CUST(string flag, string cmd);

    bool SAVE_CMAKE(vector<string> file, string name);

    vector<string> LOAD_CMAKE(string name);

    bool SAVE_CMD();

    map<string, string> LOAD_CMD();

    bool RUN(string name, vector<string> cmd);

    vector<string> LOAD_NAME();

    vector<string> CATCH_OUT(const string &strCmd);

    bool RUN_CUST(string flag, string name);

    bool DELC(string flag);

    bool UNINSTALL(string name);
};


int main(int argc, char *argv[])
{

    vector<string> cmd;
    for (int i = 0; i < argc; i++)
    {
        cmd.push_back(argv[i]);
    }
    cmd.erase(cmd.begin());
    argc = argc - 1;
    CMake cmake;
    if (argc >= 1)
    {
        for (auto &it: cmd)
        {
            if (it == "-r")
            {
                cmd.erase(cmd.begin());
                for (auto &it2: cmd)
                {
                    cmake.UNINSTALL(it2);
                }
            } else if (it == "-d")
            {
                cmd.erase(cmd.begin());
                vector<string> cmd2;
                cmd2.emplace_back("mkdir build");
                cmd2.emplace_back("cd build");
                cmd2.emplace_back("cmake ..");
                cmd2.emplace_back("make -j8");
                cmd2.emplace_back("make install");
                cmake.INSTALL(cmd.front(), cmd2);
            } else if (it == "-c")
            {
                string cmd2;
                cmd.erase(cmd.begin());

                string flag = cmd.front();

                cmd.erase(cmd.begin());
                for (auto &it: cmd)
                {
                    cmd2 += it + " ";
                }
                cmake.CUST(flag, cmd2);
            } else if (it == "-s")
            {
                cmd.erase(cmd.begin());
                string name = cmd.front();
                cmd.erase(cmd.begin());
                cmake.RUN(name, cmd);
            } else if (it == "-l")
            {
                auto nload = cmake.LOAD_NAME();
                for (auto &it: nload)
                {
                    cout << it << ": " << endl;
                    auto load = cmake.LOAD_CMAKE(it);
                    for (auto &it2: load)
                    {
                        auto size = filesystem::file_size(it2);
                        if (size < 1024 * 1024)
                        {
                            auto size2 = size / 1024;
                            cout << it2 << ":\t\033[32m" << size2 << "kb\033[0m " << endl;
                        } else if (size >= 1024 * 1024 && size < 1024 * 1024 * 1024)
                        {
                            auto tmp = 1024 * 1024;
                            auto size2 = size / tmp;
                            cout << it2 << ":\t\033[34m" << size2 << "MB\033[0m " << endl;
                        } else if (size >= 1024 * 1024 * 1024)
                        {
                            auto tmp = 1024 * 1024 * 1024;
                            auto size2 = size / tmp;
                            cout << it2 << ":\t\033[31m" << size2 << "GB\033[0m " << endl;
                        }
                    }
                }
            } else if (it == "-rc")
            {
                cmd.erase(cmd.begin());
                string flag = cmd.front();
                cmd.erase(cmd.begin());
                cmake.RUN_CUST(flag, cmd.front());

            } else if (it == "-dc")
            {
                cmd.erase(cmd.begin());
                for (auto &it2: cmd)
                    cmake.DELC(it2);
            } else if (it == "-ini")
            {
                string path= home(CPATH);
                string cmd="rm -rf "+path;
                system(cmd.c_str());
                cout<<"ini success\n";
            } else if (it == "-h")
            {
                cout
                        << "\033[34m def opt:\n-ini ini\n-h\tget help\n-c \tadd custom cmd\n-dc \tdel custom cmd\n-d \tthe name of the project \n-r \tremove the file\n-s \trun shell cmd\n-l \tshow files size\n-rc \trun custom cmd\033[31m\n";
                cout << "\033[31mthe custom cmd:\n" << endl;
                auto load = cmake.LOAD_CMD();
                for (auto &it: load)
                {
                    cout << "\033[32m" << it.first << "\tcmd is: " << it.second << "\033[31m\n";
                }
            } else
            {
                cout << "cmd cannot found\n";
                return 0;
            }
        }
    }

    return 0;

}

string get_path()
{
    string res;
    char path[PATH_SIZE];
    if (!getcwd(path, PATH_SIZE))
    {
        cout << "error,未知路径" << endl;
        return 0;
    }
    res = path;
    res += "/";
    return res;
}

string home(string dpath)
{
    string path = getenv("HOME");
    path += dpath;
    return path;
}

bool checkExist(string file)
{
    int pos = file.find("~");
    int pos2 = file.find("./");
    if (pos != string::npos)
    {
        file.erase(file.begin());
        file.insert(0, getenv("HOME"));
    }
    if (pos2 != string::npos)
    {
        file = file.substr(pos2, file.back());
        string tmp = get_path();
        tmp += file;
        file = tmp;
    }
    struct stat info;
    if (stat(file.c_str(), &info) != 0)
    {  // does not exist
        return false;
    } else
    {
        return true;
    }
}

bool CMake::INSTALL(string name, vector<string> cmd1)
{
    string cmd;
    for (auto &it: cmd1)
    {
        cmd += it + "\n";
    }
    string file = name;
    auto res = CATCH_OUT(cmd);
    string regular = "^(-- Up-to-date: |-- Installing: )";
    regex r(regular);
    smatch sres;
    vector<string> callback;
    for (auto &it: res)
    {
        if (regex_search(it, sres, r))
        {
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

bool CMake::SAVE_CMAKE(vector<string> files, string name)
{
    string path = home(CPATH);
    path += name + "/";
    if (!checkExist(path))
    {
        string cmd = "mkdir -p " + path;
        system(cmd.c_str());
    }
    string csv = path;
    csv += name + ".csv";
    ofstream ofs(csv, ios::out | ios::app);
    for (auto &it: files)
    {
        ofs << it;
    }
    ofs.close();
    return true;
}

vector<string> CMake::LOAD_CMAKE(string file)
{
    string path = home(CPATH);
    path += file + "/";
    path += file + ".csv";
    ifstream ifs(path, ios::in);
    string s = "";
    vector<string> res;
    while (getline(ifs, s))
    {
        res.push_back(s);
    }
    ifs.close();
    return res;
}

/// 执行cmd指令并返回结果
vector<string> CMake::CATCH_OUT(const string &strCmd)
{
    vector<string> res;
    char buf[10240] = {0};
    FILE *pf = nullptr;

    if ((pf = popen(strCmd.c_str(), "r")) == nullptr)
    {
    }

    string strResult;
    while (fgets(buf, sizeof buf, pf))
    {
        cout << buf << endl;
        res.emplace_back(buf);
    }

    pclose(pf);

//    unsigned int iSize = strResult.size();
//    if (iSize > 0 && strResult[iSize - 1] == '\n')  // linux
//    {
//        strResult = strResult.substr(0, iSize - 1);
//    }

    return res;
}

bool CMake::UNINSTALL(string name)
{
    auto load = LOAD_CMAKE(name);
    string cmd;
    vector<string> deal;
    bool ret = false;
    for (auto &it: load)
    {
        cmd = "rm -rf ";
        cmd += it;
        CATCH_OUT(cmd);
        if (!checkExist(it))
        {
            ret = true;
        } else
        {
            cout << it << "del error\n";
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
    while (getline(ifs, tmp))
    {
        if (tmp != name)
        {
            ofs2 << tmp << endl;
        }
    }
    cout << "del " << tmp << " success\n";
    SAVE_CMAKE(deal, name);
    return ret;
}

bool CMake::CUST(string flag, string cmd)
{
    ret.insert(make_pair(flag, cmd));
    SAVE_CMD();
    return false;
}

bool CMake::SAVE_CMD()
{
    string path = home(SPATH);
    ofstream ofs(path, ios::out | ios::app);
    for (auto &it: ret)
    {
        ofs << it.first << " " << "," << " " << it.second << " " << "," << endl;
    }
    cout << "save success\n";
    ofs.close();
    return false;
}

map<string, string> CMake::LOAD_CMD()
{
    string path = home(SPATH);
    ifstream ifs(path, ios::in);
    string f, s;
    vector<string> f1;
    while (ifs >> f >> s)
    {
        if (f != ",")
        {
            f1.push_back(f);
        }
    }
    for (int i = 0; i < f1.size(); ++i)
    {
        string s2 = f1.at(i + 1);
        string f2 = f1.at(i);
        ret.insert(make_pair(f2, s2));
        ++i;
    }
    return ret;
}

bool CMake::RUN(string name, vector<string> cmd)
{
    INSTALL(std::move(name), std::move(cmd));
    return false;
}

vector<string> CMake::LOAD_NAME()
{
    ifstream ifs(home(NPATH), ios::in);
    string line;
    vector<string> ret;
    while (getline(ifs, line))
    {
        ret.push_back(line);
    }
    return ret;
}

bool CMake::RUN_CUST(string flag, string name)
{
    if (name.empty())
    {
        name = flag;
    }
    LOAD_CMD();
    for (auto &it: ret)
    {
        if (flag == it.first)
        {
            cout << it.first << endl;
            vector<string> cmd;
            cmd.push_back(it.second);
            INSTALL(name, cmd);
        }
    }
    return false;
}

bool CMake::DELC(string flag)
{
    LOAD_CMD();
    for (auto &it: ret)
    {
        if (flag == it.first)
        {
            ret.erase(it.first);
            cout << it.first << " del success\n";
        }
    }
    return false;
}

