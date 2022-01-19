//
// Created by nglsg on 2022/1/19.
//

#ifndef CM_SHARE_H
#define CM_SHARE_H

#endif //CM_SHARE_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>
#include <regex>
#include <filesystem>
#include <dirent.h>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define CPATH "/CDIES/.CMake/SAVE/"
#define NPATH "/CDIES/.CMake/SAVE/name.csv"
#define SPATH "/CDIES/.CMake/SAVE/flag.csv"
#define PATH_SIZE 255

string get_path() {
    string res;
    char path[PATH_SIZE];
    if (!getcwd(path, PATH_SIZE)) {
        cout << "error,未知路径" << endl;

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
