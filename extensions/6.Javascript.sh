echo "javascript 依赖文件安装,请先安装JavaScript"
###javascript
npm install -g eslint-cli
npm install -g js-beautify
###javascript
if [ $? -eq 0 ]; then
cat >>.SpaceVim.d/init.toml<<eof

###javascript
[[layers]]
  name = "lang#javascript"
[[layers]]
  name = "format"
  
eof
echo "配置完成"
else
  echo "出现未知错误请重试"
fi

