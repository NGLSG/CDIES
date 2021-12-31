echo "配置文件 如果速度太慢请挂梯子后运行"

echo "配置基础ing"
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple

python3 -m pip install --upgrade pip

npm install -g neovim

pip install pynvim pythonx pyx neovim

pip install --user isort

pip install --user coverage

pip install --user autoflake

pip install --user yapf

pip install --user flake8

pip install Pillow

echo "安装插件ing"

sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'



curl -sLf https://spacevim.org/cn/install.sh | bash

cd ~

rm -rf .SpaceVim.d

sudo ln -s ~/CDIES/.SpaceVim.d/ ~

sudo chmod +x ~/CDIES/git_s ~/CDIES/git_r

sudo ln -s ~/CDIES/git_s  ~/CDIES/git_r /bin

sudo g++ -Og -g -w ~/CDIES/crc.cc -o /bin/crc
sudo g++ -Og -g -w ~/CDIES/delete.cpp -o /bin/delete
sudo g++ -Og -g -w ~/CDIES/cm.cc -o /bin/cm
sudo crc -w ~/CDIES/cnp.cc -d /bin/cnp


cd 
sudo rm -rf ~/.SpaceVim/init.vim
sudo ln -s  ~/CDIES/init.vim ~/.SpaceVim/

cd
echo "配置默认开发语言(c++/c,python)ing"
cat>>~/.SpaceVim.d/init.toml<<EOF

#coc 配置 c++
[[layers]]
  name="lang#c"
  [[layers]]
  name='lang#c'
  enable_clang_syntax_highlight = true
  [[layers]]
  name = "lsp"
  [[layers]]
  name = "lsp"
  filetypes = [
    "c",
    "cpp"
  ]
  [layers.override_cmd]
  c = ["clangd"]
  [[layers]]
  name ="format"
  [[layers]]
  name ="lang#c"
  [layer.clang_std]

  #python
  [[layers]]
  name = "lang#python"
  [[layers]]
  name = "lang#python"
  format_on_save = 1
  [[layers]]
  name = "lang#python"
  python_file_head = [
      '#!/usr/bin/ecdie python',
      '# -*- coding: utf-8 -*-',
      '',
      ''
  ]
  [[layers]]
  name = "lang#python"
  enable_typeinfo = true
  [[layers]]
    name = 'lang#python'
    format_on_save = true
    [[layers]]
  name = 'lang#python'
  enabled_linters = ['python', 'pylint']
  [[layers]]
  name = "format"
  [[layers]]
   name = "debug"

EOF

sudo g++ -w -Og -g ~/CDIES/extensions_install.cc -o /bin/extensions_install

cd ~

clear
cdie .SpaceVim.d/init.toml # 打开vim 将会自动安装所有的插件
echo "配置完成,你可以使用cdie来打开文件"
echo "交流群:616872860"
