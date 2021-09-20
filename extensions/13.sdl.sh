#/bin/bash
apt install libsdl2*
if [ $? -eq 0 ]; then
  echo "sdl2全家桶安装完成包括ttf image mixer...."
else
  echo "安装失败请重试"
fi
