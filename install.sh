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
apt install curl unzip

ln -s /bin/nvim /bin/cdie
rm -rf /bin/gcc /bin/g++
ln -s /bin/gcc-11 /bin/gcc
rm -rf /usr/include/c++/10
ln -s /bin/g++-11 /bin/g++
echo "\n"
echo "\n"
echo "安装完成,你可以继续使用configure.sh来完成配置"
echo "交流群:616872860"
