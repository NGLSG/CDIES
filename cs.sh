cd ~
echo "正在换源"
sudo apt autoremove neovim

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:neovim-ppa/unstable

sudo rm -rf /etc/apt/sources.list.d/neovim-ppa-ubuntu-unstable-impish.list
#如果你不是20.10的Ubuntu请把上条内容注释掉

sudo echo "deb http://ppa.launchpad.net/neovim-ppa/unstable/ubuntu groovy main " >> /etc/apt/sources.list
#同上
sudo echo "deb-src http://ppa.launchpad.net/neovim-ppa/unstable/ubuntu groovy main" >>/etc/apt/sources.list
#同上
sudo apt update&& sudo apt upgrade