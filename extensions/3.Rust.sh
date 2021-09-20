echo "正在安装rust,出现选项就输入1"
curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh
rustup component add rls rust-analysis rust-src
rustup component add rustfmt
if [ $? -eq 0 ]; then
  cat >>.SpaceVim.d/init.toml<<eof
###rust###
[[layers]]
name = "lang#rust"
[[layers]]
name = "lsp"
[[layers]]
name = "lsp"
filetypes = [
    "rust"
  ]
  [layers.override_cmd]
    rust = ["rls"]
[[layers]]
  name = "format"
eof
echo "配置完成"
else
  echo "出现未知错误,请重试"
fi
