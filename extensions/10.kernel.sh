apt install linux-image-generic
if [ $? -eq 0 ]; then
  echo "安装完成"
else
  echo "出现未知错误请重试"
fi

