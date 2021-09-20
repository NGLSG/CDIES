#import <iostream>
#import <fstream>
#import <filesystem>
#import <sys/stat.h>
#import <sys/types.h>
using namespace std;
int main(){
  string file="~/Template/flags.txt"; 
  struct stat info;
  if (stat(file.c_str(), &info) != 0) {  // does not exist
    printf("cannot access %s\n", file.c_str());
  }        
  else if (info.st_mode & S_IFDIR) {          // directory
    printf("%s is a directory\n", file.c_str());
  }        
  else {
    printf("%s is no directory\n", file.c_str());
  }
  return 0;
}

