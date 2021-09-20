#import <cstdio>
#import <cstdlib>
#import <iostream>
#import <string>
using namespace std;
#define path "~/CDIES/extensions/"
class es{
  public:
    int select;
    void showmenu();
    void install_extensions();

};

void es::showmenu(){
  cout<<"注意请不要删除~/CDIES/extensions/文件!!!本脚本依赖此目录!!!\n";
  cout<<"\t\n";
  cout<<"\t\n";
  cout<<"\t\n";
  cout<<"\t\t1.PHP\n";
  cout<<"\t\t2.Ruby\n";
  cout<<"\t\t3.Rust\n";
  cout<<"\t\t4.go\n";
  cout<<"\t\t5.lua\n";
  cout<<"\t\t6.Javascript\n";
  cout<<"\t\t7.perl\n";
  cout<<"\t\t8.kotiln\n";
  cout<<"\t\t9.gradle(安装)\n";
  cout<<"\t\t10.安装最新Linux内核\n";
  cout<<"\t\t11.gcc-12&&g++12安装\n";
  cout<<"\t\t12.gtk图形库安装\n";
  cout<<"\t\t13.SDL图形库安装\n";
  cout<<"\t\t0.退出\n";
  cout<<"\t\n";
  cout<<"\t\n";
  cout<<"\t\n";
  cout<<"请输入你的选择: ";
  int s;
  cin>>s;
  this->select=s;
}
void es::install_extensions(){
  if(select!=0){
    string cmd="bash ";
    cmd+=path;
    cmd+=to_string(select);
    cmd+="*";
    system(cmd.c_str());
    cout<<"配置完成!可能没有成功(滑稽)\n";
  }
}
int main(){
  while(true){
    es es;
    es.showmenu();
    if(es.select==0){
      cout<<"感谢支持\n";
      return 0;
      break;
    }
    es.install_extensions();
  }
  return 0;
}
