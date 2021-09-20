#import <iostream>
#import <unistd.h>
#import <vector>
#import <fstream>
#import <map>
#import <string>
#import <algorithm>
#import <sys/types.h>
#import <sys/stat.h>
using namespace std;

#define T_F "/home/Template/"//模板文件夹
#define M_S "/home/Template/flags.txt"//flags存储位置
#define D_P "/home/Template/DefaultCx/"//默认模板
#define C_P "/home/Template/CMake/"//cmake模板
#define S_P "/home/Template/SDL2/"//SDL2模板
#define D_C "/home/Template/DefaultC"
#define P_P "/home/Template/path.txt"//项目文件存储
#define PATH_SIZE 255
#define VERSION 1.0

bool rep=false;

map<string,string>pro;//全局map

bool checkExist(string name);//检查文件是否存在

map<string,string> loadMap();//加载Map

void saveMap();//保存Map

void creat_project(string flags,string name,string direct);//指定项目名和目录

void add_project(string flags,string dir);//添加模板项目

void add_projects(map<string,string>m);//批量添加

void del_project(string flags);//删除模板

void del_projects(vector<string>flags);//批量删除

void rep_project(string flags,string rdir);//替换

void rep_projects(map<string,string>m);//批量替换

void save_pro(string name,string dir);//保存项目路径

void option_exp();//选项详解

string get_path();//获取目录

template<class T>
void remove_element(vector<T>&v,T t);//删除元素

template<class T>
void remove_element(map<T,T>&m,T t);//删除元素

//main
int main(int argc,char*argv[]){
  pro=loadMap();
  vector<string>pro_fla;
  for(int i=0;i<argc;i++){
    pro_fla.push_back(argv[i]);
  }
  vector<string>pro2=pro_fla;
  if(argc<4){
    for(int i=0;i<2;i++){
      pro_fla.push_back("");
    }
  }
  if(!pro2.empty()){
    pro2.erase(pro2.begin());
  }
  if(!pro_fla.empty()){
    remove_element<string>(pro_fla,".");
    remove_element<string>(pro_fla," ");
    remove_element<string>(pro_fla,"./");
    pro_fla.erase(pro_fla.begin());//删除无用数据
  }
  auto tmp=pro_fla.begin();
  try {
    int judge=0;
    for(auto&it:pro_fla){
      if("-add"==it){
        judge=1;
      }
      else if("-del"==it){
        judge=2;
      }
      else if("-rep"==it){
        judge=3;
      }
      else if("-help"==it||"h"==it||"-h"==it||"help"==it){
        judge=4;
      }
      else if("-version"==it||"v"==it||"-v"==it||"version"==it){
        judge=5;
      }

    }
    map<string,string>m;
    if(judge==1){
      pro_fla.erase(pro_fla.begin());
      for(;tmp<pro_fla.end();tmp++){
        m.insert(make_pair(*tmp,*(tmp+1)));
        tmp++;
      }
      add_projects(m);
    }
    else if(judge==2){
      pro2.erase(pro2.begin());
      vector<string>v;
      for(auto&it:pro2){
        v.push_back(it);
      }
      del_projects(v);
    }
    else if(judge==3){
      pro_fla.erase(pro_fla.begin());
      for(;tmp<pro_fla.end();tmp++){
        m.insert(make_pair(*tmp,*(tmp+1)));
        tmp++;
      }
      rep_projects(m);
    }
    else if(judge==4){
      option_exp(); 
    }
    else if(judge==5){
      cout<<"作者nglsg,联系QQ：927039685,交流群:1023190045\n仓库地址https://github.com/NGLSG/\n当前版本为:"<<
        VERSION;
    }
    else{
      creat_project(*tmp,*(tmp+1),*(tmp+2));
    }
  } catch (...) {

  }
  return 0;
}

//main

void option_exp(){
  map<string,string>m;
  m.insert(make_pair("选项","用法解释"));
  m.insert(make_pair("-add","[目标选项] [模板位置] 新建模板项目"));
  m.insert(make_pair("-del","[目标选项] 删除模板文件"));
  m.insert(make_pair("-rep","[目标选项] [模板位置] 替换选项"));
  m.insert(make_pair("-s","[项目名] [地址](可为空) 创建sdl2项目"));
  m.insert(make_pair("-dx","[项目名] [地址](可为空) 创建C++默认项目"));
  m.insert(make_pair("-dc","[项目名] [地址](可为空) 创建C默认项目"));
  m.insert(make_pair("-c","[项目名] [地址](可为空) 创建CMake项目"));
  for(auto&it:pro){
    string path=it.second;
    path+="/description.txt";
    string s;
    ifstream ifs2(path,ios::in);
    while(ifs2>>s){
      m.insert(make_pair(it.first,s));
    }
  }
  for(map<string,string>::reverse_iterator rit=m.rbegin();rit!=m.rend();rit++) {
    cout<<"\t"<<(*rit).first<<"\t"<<(*rit).second<<endl;
  }
}

void rep_projects(map<string,string>m){
  for(auto&it:m){
    rep_project(it.first,it.second);
  }
}


void del_projects(vector<string>v){
  for(auto&it:v){
    del_project(it);
  }
}

void add_projects(map<string,string>m){
  for(auto &it:m){
    add_project(it.first,it.second);
  }
}

bool checkExist(string file){
  int pos=file.find("~");
  if(pos!=string::npos){
    file.erase(file.begin());
    file.insert(0,getenv("HOME"));
  }
  struct stat info;
  if (stat(file.c_str(), &info) != 0) {  // does not exist
    return false;
  }
  else{
    return true;
  }
}
void saveMap(){
  fstream save(M_S,ios::out);
  if(!checkExist(M_S)){
    system("mkdir -p /home/Template/");
    system("touch /home/Template/flags.txt");

  }
  for(auto&it:pro)
  {
    save<<it.first<<' '<<it.second<<endl;
  }
  save.close();
}
map<string,string> loadMap()
{
  fstream load(M_S,ios::in);
  if(!checkExist(M_S)){
    system("mkdir -p /home/Template/");
    system("touch /home/Template/flags.txt");
    add_project("-dx","~/CDIES/template/DefaultCx");
    add_project("-dc","~/CDIES/template/DefaultC");
    add_project("-s","~/CDIES/template/SDL2");
    add_project("-c","~/CDIES/template/CMake");
  }
  else{
    string f;
    string s;
    while(load>>f>>s) {
      pro.insert(make_pair(f,s));
    }
    if(load.eof()){
      pro.insert(make_pair("-dx",D_P));
      pro.insert(make_pair("-dc",D_C));
      pro.insert(make_pair("-s",S_P));
      pro.insert(make_pair("-c",C_P)); 
      saveMap();

    }
  }
  load.close();
  return pro;
}

void creat_project(string flags,string name,string dir){
  if(dir.empty()){
    dir=" ./";
  }
  if(dir.back()=='/'){
    dir.pop_back();
  }
  dir+="/";
  bool judge=false;
  try{
    for(auto&it:pro){
      if(it.first==flags){
        string cmd="cp -rf ";
        if(name.empty()){
          string tmp=it.second;
          if(tmp.back()=='/'){
            tmp.pop_back();
          } 
          int pos=tmp.find_last_of("/");
          name=tmp.substr(pos+1);
        }
        dir+=name;
        cmd+=it.second;
        cmd+=" ";
        cmd+=dir;
        judge=true;
        system(cmd.c_str());
      }
    }
    if(!judge){
      throw "error";
    }
  }
  catch (...) {
    cerr<<flags<<" 选择未找到,请尝试添加或使用help获取帮助"<<endl;
  }
  try {
    if(checkExist(dir)){
      throw "pass";
    }
  } 
  catch (...) {
    cout<<name<<" 项目成功创建在 "<<dir<<" 目录\n";
    save_pro(name,dir);
  }
}

void save_pro(string name,string dir){
  ofstream save(P_P,ios::out|ios::app);
  string path;
  path=get_path();
  auto pos=dir.find("./");
  if(pos!=string::npos){
    dir=dir.substr(pos+2);
    path+=dir;
  }
  else{
    path=dir;
  }
  path+="\n";
  save<<path<<endl;
  save.close();
}

string get_path(){
  string res;
  char path[PATH_SIZE];
  if(!getcwd(path,PATH_SIZE)){
    cout<<"error,未知路径"<<endl;
    return 0;
  }
  res=path;
  res+="/";
  return res;
}

void add_project(string flags,string dir){
  if(flags.size()==0||!checkExist(dir)){
    cerr<<"错误:标识符 "<<flags<<" 和路径 "<<dir<<" 不能为空或不存在\n";
    return;
  }
  else{
    int pos=dir.find("./");
    string path;
    path=get_path();
    if(pos!=string::npos){
      dir=dir.substr(pos+2);
      path+=dir;
    }
    else if(dir.at(0)!='/'){
      path+=dir;
    }
    else{
      path=dir;
    }
    string cmd="cp -rf ";
    cmd+=path;
    cmd+=" ";
    cmd+=T_F;
    system(cmd.c_str());
    if(path.back()=='/'){
      path.pop_back();
    }
    pos=path.find_last_of("/");
    dir=path.substr(pos+1);
    path=T_F;
    path+=dir;
    if(!rep){
      pro.insert(make_pair(flags,path));
    }
    else{
      for(auto&it:pro){
        if(it.first==flags){
          it.second=path;
        }
      }
    }
    cout<<"提交成功\n";
    saveMap();
  }
}

void del_project(string flags){
  bool judge=false;
  for(auto&it:pro){
    if(flags==it.first){
      judge=true;
      string cmd="rm -rf ";
      cmd+=it.second;
      system(cmd.c_str());
    }
  }
  if(!judge){
    cout<<flags<<" 标识符不存在\n";
    return;
  }
  else{
    remove_element<string>(pro,flags);
    cout<<flags<<" 删除成功\n";
    saveMap();
  }
}

void rep_project(string flags,string rdir){
  rep=true;
  add_project(flags,rdir);
}

template<class T>
void remove_element(vector<T>&v,T t){
  auto vit=find(v.begin(),v.end(),t);
  if(vit!=v.end()){
    for(auto&it:v){
      if(it==*vit){
        v.erase(vit);
      }
    }
  }
}

template<class T>
void remove_element(map<T,T>&m,T t){
  m.erase(t);
}


