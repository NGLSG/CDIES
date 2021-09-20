echo "配置PHP中,请先安装php"
composer require --dev vimeo/psalm
pear install PHP_Beautifier
if [ $? -eq 0 ]; then
  cat >>SpaceVim.d/init.toml<<eof

###PHP
[[layers]]
  name = "lang#php"
[[layers]]
  name = "lsp"
[[layers]]
  name = "lsp"
    filetypes = [
    "php"
      ]
  [layers.override_cmd]
    php = ["php-language-server"]
[[layers]]
  name = "format"
eof
echo "配置完成"
else
  echo "出现未知错误请重试"
fi
