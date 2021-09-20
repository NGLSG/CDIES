#/bin/bash
sudo apt-get install libgtk-4-dev gtk-4-examples geany
if [ $? -eq 0 ]; then
  echo "安装完成"
else
  echo "安装失败"
fi
