### CDIES

一个在Linux命令行运行的IDE

支持的系统:

系统 | 版本
---- | ----
Android | 7.1以上(安装Termux)
MacOs | All
Windows |All
Linux | All
---- | ----


演示图:
![Alt text](/path/demonstration.jpg)
![Alt_text](/path/demonstration.gif)
### 命令解析

crc 编译运行C/C++命令  
用法:crc [编译选项] [目标文件] #默认模式

    crc:默认编译当前目录(包含子目录)下的所有源文件 #无任何输入

    crc [编译选项] [目标文件] -d [指定编译后的文件] #指定编译后的文件`

    crc [编译选项] [NULL] -d [指定编译后的文件] #不输入文件 指定编译后的文件(不推荐)

    crc [目标文件] #原生crc

选项 | 意义
---- | ----- 
-v   | 版本信息
-h   | 获取帮助
-d   | 指定编译结果
-S   | 编译SDL2文件
-G   | 编译GTK4文件
---- | ----- 

clc 清除所有编译的二进制文件  
用法:`clc`

cdie 编写文件  
用法:`cdie 文件/目录`

cnp 创建新项目
用法 `cnp [选项] `

选项 | 意义
---  | ---
-add | [目标选项] [模板位置] 新建模板项目
-rep | [目标选项] [模板位置] 替换选项
-del | [目标选项] 删除模板文件
-s   | [项目名] [地址](可为空) 创建sdl2项目
-dc  | [项目名] [地址](可为空) 创建C默认项目
-dx  | [项目名] [地址](可为空) 创建C++默认项目
-c   | [项目名] [地址](可为空) 创建CMake项
---  | ---

delete 删除所有配置文件  
用法:`delete`  
delete [选项][文件名,二进制文件名,项目]  

选项 | 意义
---- | ----- 
-f   | 删除文件
-p   | 删除c项目
-px  | 删除c++项目
-h --help | 查看帮助
-v --verison | 查看版本
-all | 删除所有配置文件
---- | ----- 

clp 删除所有项目文件  
用法:`clp`

git_r **请本地仓库上传至git仓库,需要提前git init**  
用法:`git_r [仓库地址]`

cm  makefile与cmake的管理
选项 | 意义
---- | ----- 
-c   | 添加自定义命令[自定义选项][命令]
-h   | 查看帮助
-rc  | 运行自定义命令[自定义选项][命名]
-dc  | 删除自定义命令[自定义选项]
-ini | 初始化
-r   | 删除make install产生的程序[命名]
-d   | 执行makefile或cmake[命名]
-l   | 查看make install 产生的程序及大小
-s   | 运行shell命令
---- | ----- 

快捷键(常用):
`空格+p+t+r` 异步任务(编译运行之类的)

`空格+pte` 编辑异步任务

`空格+ft` 窗口文件管理

在窗口文件管理器 N 创建新文件

在文件内 `gd` 转定义
### 安装

首先

`git clone https://github.com/NGLSG/CDIES.git`

然后

`cd ~/CDIES`

`sh cs.sh`

`sh install.sh`

`sh configure.sh`


### 注意
**可以更改本脚本,可以把不合理的部分去掉  
stable用户不要执行cs.sh！  
stable用户请仔细看install.sh里的注意事项!**

### 说明
stable和unstable用户差别并不是特别大;只是gcc和g++,neovim的版本不同而已  
unstable用户所有都是最新,stable可能会比较久(上述三个)  
所以没必要非要安装unstable版  

### 交流群
QQ:一群:1023190045  
   二群:616872860  


### Chang Log
1.1.3(stable)&&1.2.3beta(unstable)
* 配置了所有语言的server(按需配置)  
* 更新两个新命令git_r cm

1.1.4&&1.2.4beta:
* 增加git_s命令用于登录github(只需输入你绑定github的邮箱)&&gitee(公钥要自行导入)  
* 配合git_r命令使用

1.14.1&71.2.4.1beta:
* 增加了更新Linux内核的扩展(小更新)  
* 修复了点小bug

1.15&1.2.5beta:
* 增加了gcc12&g++12的编译安装  
* extensions_select更名为extensions_install且移到/bin/目录  

1.15.5 && 1.25.5beta:
* 增加c/c++项目的cmake文件

1.16 && 1.26beta:
* 各个脚本增加成功与否的判断  

1.3(stable&&unstable):

1.3.1.编译运行C/C++ 的命令重写  
特点:
* 1.3.1.1.性能更高  
* 1.3.1.2.更加人性化  
* 1.3.1.3.适配更多场合  
* 1.3.1.4.支持多文件共同编译(不建议在不是项目环境下的场合使用)  
* 1.3.1.5.支持空输入,自动编译(可加入编译选项,解放双手,但不建议使用)  
* 1.3.1.6.msc命令彻底删除  

1.3.1:
更新内容:
* 1.3.1.1.cmake命令的优化  
* 增加了异步make cmake (SPACE p t r 普通模式下)  
* 优化cnpc cnpcx  

1.5:
更新内容:
* 1.5.1.删除cnpc cnpx 由cnp代替
* 1.5.2.cnp
* * 1.5.2.1.性能更好
* * 1.5.2.2.支持扩展
* * 1.5.2.3.更加人性化
* 1.5.3.clp与clc命令的优化
* 1.5.4.crc的优化
* 使用`$HOME/CDIES/update.sh `更新

1.6:
更新内容:
* 1.6.1.删除cm用cm代替
* 1.6.2.更加高效的cmake与makefile管理
* 使用`$HOME/CDIES/update.sh `更新
