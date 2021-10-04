sudo rm -rf $(cat /home/Template/path.txt)
if [ $? -eq 0 ]; then
  sudo rm -rf /home/Template/path.txt
  echo "删除成功"
else
  echo "删除失败"
fi
