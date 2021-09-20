rm -rf ~/prc-folder/
rm -rf ~/prcx-folder/
if [ $? -eq 0 ]; then
echo "删除成功"
else
echo "删除失败"
fi
