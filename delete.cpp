#include <cstdio>

#include <string.h>

#include <cstdlib>

#include <iostream>

#include <string>

using namespace std;

bool delete_all()
{
  system("clear");
  cout<<"你真的要离开我而去吗？\n\n";
  while(true){
    cout<<"如果是请输入 yes 或者 y 如果是不小心的请就输入 no 或者 n \n\n";
    string select;
    cin>>select;
    if(select == "yes" || select == "y" )
    {
      cout<<"你真的要离开我嘛?哭了,嘤嘤嘤≥﹏≤!给你最后一次机会\n";
      cout<<"yes or no\n";
      string n;
      cin>>n;
      if(n=="no"||n=="n")
      {
        system("clear");
        cout<<"我就知道!你不会这样做\n";
        cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860 ✧٩(ˊωˋ*)و✧\n";
        return true;
      }
      else{
        cout<<"你真绝情!嘤嘤嘤≥﹏≤\n";
        cout<<"开始删除\n";
        system("rm -rf /bin/clc /bin/msc /bin/rc /bin/cnpc* /bin/delete && rm -rf ~/.SpaceVim ~/.SpaceVim.d ~/.compile ~/linux_nv_config ~/prc-folder ~/prcx-folder /home/.Nod");
        system("apt autoremove git python3 python2 nodejs gcc-11 g++-11 npm neovim cmake clangd clang-12 llvm-12 python3-pip libboost-all-dev");
        system("clear");
        cout<<"删除成功\n";
        cout<<"再见了!后会有期\n";
        cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860 ✧٩(ˊωˋ*)و✧\n";
        return true;
      }
    }
    else if(select == "no" ||select == "n")
    {
      system("clear");
      cout<<"你果然不会离开我!贴贴~mua!\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860 ✧٩(ˊωˋ*)و✧\n";
      return true;
    }
    else
    {
      cout<<"请重新输入 参数错误 只允许yes y no n的说喵٩(๑òωó๑)۶\n";
      system("clear");
      return false;
    }
  }
}

bool delete_binary(string str)
{
  system("clear");
  cout<<"是否要删除 "<<str<<"文件呢 ٩(๑′0`๑)۶\n";
  while(true)
  {
    cout<<"如果是请输入yes或者y\n不是则输入no 或者 n\n";
    string n;
    cin>>n;
    if(n=="yes" || n=="y")
    {
      string cmd= "rm -rf /root/.compile/";
      cmd += str;
      system(cmd.c_str());
      system("clear");
      cout<<""<<str<<" 文件删除成功 "<<" 喵٩(๑òωó๑)۶~\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860\n";
      return true;
    }
    else if(n=="no"||n=="n")
    {
      system("clear");
      cout<<"你果然不会离开我的喵٩(๑òωó๑)۶!贴贴~mua!\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860 ✧٩(ˊωˋ*)و✧\n";
      return true;
    }
    else
    {
      cout<<"请重新输入 参数错误 只允许yes y no n的说喵٩(๑òωó๑)۶\n";
      system("clear");
      return false;
    }
  }
}
bool delete_folder(string str)
{
  system("clear");
  cout<<"是否要删除 "<<str<<"项目呢 ٩(๑′0`๑)۶\n";
  while(true)
  {
    cout<<"如果是请输入yes或者y\n不是则输入no 或者 n\n";
    string n;
    cin>>n;
    if(n=="yes" || n=="y")
    {
      string cmd="rm -rf /root/prc-folder/";
      cmd += str;
      system(cmd.c_str());
      system("clear");

      cout<<""<<str<<" 项目删除成功喵٩(๑òωó๑)۶!\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860\n";
      return true;
    }
    else if(n=="no"||n=="n")
    {
      system("clear");
      cout<<"你果然不会离开我的喵٩(๑òωó๑)۶!贴贴~mua!\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860 ✧٩(ˊωˋ*)و✧\n";

      return true;
    }
    else
    {
      cout<<"请重新输入 参数错误 只允许yes y no n的说喵٩(๑òωó๑)۶\n";
      system("clear");
      return false;
    }
  }
}
bool delete_folderx(string str)
{
  system("clear");
  cout<<"是否要删除 "<<str<<"项目呢 ٩(๑′0`๑)۶\n";
  while(true)
  {
    cout<<"如果是请输入yes或者y\n不是则输入no 或者 n\n";
    string n;
    cin>>n;
    if(n=="yes" || n=="y")
    {
      string cmd="rm -rf /root/prcx-folder/";
      cmd += str;
      system(cmd.c_str());
      system("clear");

      cout<<""<<str<<" 项目删除成功喵٩(๑òωó๑)۶!\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860\n";
      return true;
    }
    else if(n=="no"||n=="n")
    {
      system("clear");
      cout<<"你果然不会离开我的喵٩(๑òωó๑)۶!贴贴~mua!\n";
      cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860 ✧٩(ˊωˋ*)و✧\n";

      return true;
    }
    else
    {
      cout<<"请重新输入 参数错误 只允许yes y no n的说喵٩(๑òωó๑)۶\n";
      system("clear");
      return false;
    }
  }
}

int main(int argc, const char *argv[]) {
  if(argv[1] == NULL){
    int select;
    cout<<"请输入,您的选择喵~\n\n"<<"1:删除所有东西的喵٩(๑òωó๑)۶~\n\n"<<"2:删除二进制文件的喵٩(๑òωó๑)۶\n\n"<<"3:删除c项目喵٩(๑òωó๑)۶\n\n"<<"4:删除c++项目喵٩(๑òωó๑)۶\n\n"<<"0:退出,什么也不干\n\n";
    cin>>select;
    switch(select)
    {
      case 1:
        delete_all();
        break;
      case 2:
        {
          cout<<"请输入想要删除的二进制文件\n\n";
          string str;
          cin>>str;
          int pos = str.find(".");
          string bn=str.substr(0,pos);
          delete_binary(bn);
          break;
        }
      case 3:
        {
          cout<<"请输入想要删除的项目名字\n\n";
          string str;
          cin>>str;
          int pos = str.find(".");
          string fpn=str.substr(0,pos);
          delete_folder(fpn);
          break;
        }
      case 4:
        {
          cout<<"请输入想要删除的项目名字\n\n";
          string str;
          cin>>str;
          int pos = str.find(".");
          string fpn=str.substr(0,pos);
          delete_folderx(fpn);
          break;
        }
      default:{
                system("clear");
                cout<<"欢迎加入交流群٩(๑^o^๑)۶:616872860\n";
                break;
              }
    }
  }
  else if(strcmp(argv[1],"-f")==0 || strcmp(argv[1],"f")==0)
  {
    string str=argv[2];
    int pos = str.find(".");
    string bn=str.substr(0,pos);
    delete_binary(bn);
    return 0;
  }
  else if(strcmp(argv[1],"-p")==0 || strcmp(argv[1],"p")==0)
  {
    string str =argv[2];
    delete_folder(str);
  }
  else if(strcmp(argv[1],"-px")==0 || strcmp(argv[1],"px")==0)
  {
    string str =argv[2];
    delete_folderx(str);
  }
  else if(strcmp(argv[1],"-v")==0 || strcmp(argv[1],"--version")==0 || strcmp(argv[1],"v")==0|| strcmp(argv[1],"version")==0)
  {
  cout<<"作者:by一首快乐的鸽\n"<<"版本:1.0.5beta\n"<<"功能:你可以使用本命令删除项目或编译产生的二进制文件或所有配置\n最后编译于2021/7/23";
  }
  else if(strcmp(argv[1],"help")==0 || strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0 || strcmp(argv[1],"h")==0 )
  {
  cout<<"选项详解:\n\n"<<"-all 删除所有配置文件\n\n"<<"-f 删除二进制文件\n\n"<<"-p 删除c项目\n\n"<<"-px 删除c++项目\n\n"<<"-h 查看帮助\n\n"<<"-v 查看版本\n\n"<<"TIP:-可以去掉\n\n";
  }
  else if(strcmp(argv[1],"-all")==0 || strcmp(argv[1],"all")==0)
  {
  delete_all();
  }
  
  else
  {
  cout<<"命令未找到,请使用help获取帮助\n";
  }
}
