echo "kotlin配置ing,kotlin请自行安装"
npm install --save-dev --save-exact prettier
###kotlin
if [ $? -eq 0 ]; then
cat >>.SpaceVim.d/init.toml<<eof

###kotlin
[[layers]]
  name = "lang#kotlin"
[[layers]]
  name = 'lsp'
    filetypes = [
    'kotlin',
      ]
[[layers]]
  name = 'lsp'
    filetypes = [
    'kotlin',
      ]
  [layers.override_cmd]
    kotlin = 'path/to/kotlin-language-server'
[[layers]]
  name = "format"
eof
  ###kotlin
echo "配置完成"
else
  echo "出现未知错误请重试"
fi
