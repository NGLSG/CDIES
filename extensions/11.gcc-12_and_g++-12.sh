echo "你确定要编译安装gcc-12,安装须知:"
echo "1.耗时巨大,要1+小时,看情况"
echo "2.内存占用极大,8g内存空余需要" 
echo "3.删除不易,最快的方法就是重置系统,不然得手动删除"
echo "4.gcc-12对于gcc-11只是修复一些bug,详情见官网https://gcc.gnu.org/"
read -p "如果你可以接受上述情况,可以继续安装,请输入你的选择yes or no(默认yes): " select

if [[ -z "$select" ]] || [[ ${select} -eq "yes" ]] || [[ ${select} -eq "y" ]]
then
  git clone https://mirrors.tuna.tsinghua.edu.cn/git/gcc.git /usr/local/share/gcc
  apt-get install flex
  cd /usr/local/share/gcc
  ./contrib/download_prerequisites
  mkdir build
  cd build
  ./../configure --enable-checking=release --enable-languages=c,c++,go,d,fortran,objc,obj-c++ --disable-multilib --disable-boost --disable-rtti --disable-bootstrap --disable-nls --disable-werror --disable-libstdcxx-verbose --with-gxx-libcxx-include-dir=/usr/local/include/c++/12/
  make -j8
  make install
  if [ $? -eq 0 ]; then
    echo "安装成功,重启系统已生效!"
    make clean
    rm -rf /usr/local/share/gcc/
  else
    echo "发生了未知错误呢!这绝对不是我的问题(哼~)请检查报错～"
  fi
else
  echo "我们下次再见!"
fi

