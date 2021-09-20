
###gradle
echo "尽管说我不是lsp,也还是在这,也不知道为啥"
echo "安装gradle中"
wget https://downloads.gradle-dn.com/distributions/gradle-7.1.1-all.zip
sudo unzip -d /opt/gradle gradle-7.1.1-all.zip
if [ $? -eq 0 ]; then
cat >>/etc/profile<<eof
export GRADLE_HOME=/opt/gradle/gradle-7.1.1
export PATH=$GRADLE_HOME/bin:$PATH
eof
echo "安装完成"
###gradle
else
  echo "出现未知错误请重试"
fi
