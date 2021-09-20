echo "安装必备软件 至少需要2g内存"
sudo apt-get install -y git 
apt install python3 
apt install python2 
apt install nodejs 
apt install gcc-11 
apt install g++-11 
apt install npm 
apt install neovim 
apt install cmake 
apt install clangd
apt install clang 
apt install llvm 
apt install python3-pip 
apt install libboost-all-dev
apt install openjdk-18-jdk
apt install gdb
apt install curl unzip wget
apt install ccache
if [ $? -eq 0 ]; then
  ln -s /bin/nvim /bin/cdie
  rm -rf /bin/gcc /bin/g++ #stable用户请删除此条
  ln -s /bin/gcc-11 /bin/gcc #同上
  rm -rf /usr/include/c++/10 #同上
  ln -s /bin/g++-11 /bin/g++ #同上
  echo "\n"
  echo "\n"
  echo "安装完成,你可以继续使用configure.sh来完成配置"
  echo "QQ交流群:616872860"
else
  echo "出现未知错误,请重试"
fi
