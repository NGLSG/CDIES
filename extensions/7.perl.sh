echo "配置perl中 请在安装了perl后使用此脚本"
cpanm Perl::Critic
cpanm Perl::Tidy
if [ $? -eq 0 ]; then
  cat >>.SpaceVim.d/init.toml<<eof


###perl
[[layers]]
  name = "lang#perl"
[[layers]]
  name = "format"
eof
echo "配置完成"
###perl
else
  echo "出现未知错误请重试"
fi
