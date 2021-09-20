cat >>.SpaceVim.d/init.toml<<eof

###go###
[[layers]]
  name = "lang#go"
[[layers]]
  name = "format"
eof
if [ $? -eq 0 ]; then
  echo "配置完成"
else
  echo "出现未知错误请重试"
fi
