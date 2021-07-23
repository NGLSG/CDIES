"=============================================================================
" init.vim --- Entry file for neovim
" Copyright (c) 2016-2020 Wang Shidong & Contributors
" Author: Wang Shidong < wsdjeg@outlook.com >
" URL: https://spacevim.org
" License: GPLv3
"=============================================================================
"插件安装区
call plug#begin('~/.config/nvim/plugged')
Plug 'dense-analysis/ale'
"Plug 'thinca/vim-quickrun'
call plug#end()
"插件安装区}
execute 'source' fnamemodify(expand('<sfile>'), ':h').'/main.vim'
"ale
""始终开启标志列
let g:ale_sign_column_always = 1
let g:ale_set_highlights = 0
"自定义error和warning图标
"let g:ale_sign_error = '✗'
"let g:ale_sign_warning = '⚡'
""在vim自带的状态栏中整合ale
let g:ale_statusline_format = ['✗ %d', '⚡ %d', '✔ OK']
"显示Linter名称,出错或警告等相关信息
"let g:ale_echo_msg_error_str = 'E'
"let g:ale_echo_msg_warning_str = 'W'
"let g:ale_echo_msg_format = 
"'[%linter%] %s [%severity%]'
""普通模式下，sp前往上一个错误或警告，sn前往下一个错误或警告
nmap sp <Plug>(ale_previous_wrap)
nmap sn <Plug>(ale_next_wrap)
"<Leader>s触发/关闭语法检查
"nmap <Leader>s :ALEToggle<CR>
""<Leader>d查看错误或警告的详细信息
nmap <Leader>d :ALEDetail<CR>
let g:ale_linters = {
      \   'c++': ['g++'],
      \   'c': ['gcc'],
      \   'python': ['pylint'],
      \}
"设置状态栏显示的内容
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\%{strftime(\"%d/%m/%y\ -\ %H:%M\")}\ %{ALEGetStatusLine()})}}
"显示缩进
"set listchars+=tab:>-,space:_
set list
set smartindent  
set cindent
set autoindent   
set ai!      
set tabstop=4   
"quickrun
let g:quickrun_default_flags = {
      \ 'cpp': {
        \ 'compiler': 'g\++', 
        \ 'compileFlags': '-std=c++2a -I. -I${workspaceFolder}include -o ${exeFile} ${thisFile}',
        \ 'debugCompileFlags': '-Og -g3 -fno-inline -std=c++2a -I. -I${workspaceFolder}include -o ${exeFile} ${thisFile}', 
        \ 'extRegex': [ 
          \ '^\#include\s*<future>',
          \ '^\#include\s*<mysql++\/mysql++.h>'
          \ ],
          \ 'extFlags': [
            \ '-lpthread',
            \ '-I/usr/include/mysql -lmysqlpp'
            \ ],
            \ 'cmd': '${exeFile}',
            \ 'cmdArgs': '',
            \ 'cmdRedir': '', 
            \ 'debugCmd': '!tmux new-window "cgdb ${exeFile}"'
            \ },
            \ 'python': {
              \ 'cmd': '/bin/python ${file}',
              \ 'debugCmd': '!tmux new-window "pudb3 ${exeFile}"'
              \}
              \ }
" 特殊变量：
" ${thisFile}           当前文件名
" ${exeFile}            QuickRun自动选择的编译后的可执行文件位置，脚本无需编译则应该用${thisFile}
" ${workspaceFolder}    项目根目录
