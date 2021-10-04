#!/bin/bash
rm -rf ~/.Nod/ /bin/cnpc /bin/cnpcx
g++ -Og -g -w ~/CDIES/cnp.cc -o /bin/cnp
g++ -Og -g -w ~/CDIES/crc.cc -o /bin/crc

if [ $? -eq 0 ]; then
  echo "安装成功"
else
  echo "安装失败"
fi

