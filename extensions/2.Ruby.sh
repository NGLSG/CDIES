echo "配置RUBY中,请先安装ruby"
gem install rubocop
gem install rufo
if [ $? -eq 0 ]; then
cat >>.SpaceVim.d/init.toml<<eof

###Ruby
[[layers]]
  name = "lang#ruby"
[[layers]]
  name = "lsp"
[[layers]]
  name = "lsp"
    filetypes = [
    "ruby"
      ]
  [layers.override_cmd]
    ruby = ["solargraph",  "stdio"]
[[layers]]
  name = "format"
eof
echo "配置完成"
else
  echo "出现未知错误请重试"
fi
