echo "配置文件 如果速度太慢请挂梯子后运行"

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

python3 RI

sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'

g++ -pthread -Og -Wall -w direct.cpp -o /bin/delete

rm -rf ./out.bmp ./direct.cpp ./RI
mkdir -p ~/.Nod
  mv -f .Makefilex .Makefile ~/.Nod
  curl -sLf https://spacevim.org/cn/install.sh | bash

  mkdir ~/.compile

  chmod 777 ./rc ./clc ./cnpc ./cnpcx ./clp ./msc

  mv -f ./rc ./clc ./cnpc ./msc ./cnpcx ./clp /bin
  

  
  cd # 保证在根目录
  
  rm -rf .SpaceVim.d # 将原来的配置删除
  
  git clone https://github.com/martins3/My-Linux-config .SpaceVim.d 
  
  mv -f ~/CDIES/init.vim ~/.SpaceVim/

  cd
  
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
[[custom_plugins]]
name = "skywind3000/asynctasks.vim"
name ="skywind3000/asyncrun.vim"
EOF

mv -f ~/CDIES/tasks.toml ~/.SpaceVim.d/

rm -rf ./conf
clear
cdie .SpaceVim.d/init.toml # 打开vim 将会自动安装所有的插件
echo "安装完成,你可以使用cdie来打开文件"
echo "交流群:616872860"
