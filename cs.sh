cd ~
echo "正在换源"
sudo apt autoremove neovim

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:neovim-ppa/unstable

sudo apt update&& sudo apt upgrade

