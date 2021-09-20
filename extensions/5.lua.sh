###lua
echo "lua配置ing,请先安装lua"
luarocks install formatter
###lua
if [ $? -eq 0 ]; then
cat >>.SpaceVim.d/init.toml<<eof

###lua
[[layers]]
  name = "lang#lua"
[[layers]]
  name = "format"
eof

###lua
echo "配置完成"
else
  echo "出现未知错误请重试"
fi
