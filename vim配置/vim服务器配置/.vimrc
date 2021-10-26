set number
syntax on
" 打开文件类型侦测
filetype on

" 根据不同的文件类型加载不同的插件
filetype plugin on

" 快速跳转
nmap J 3j
nmap K 3k
set term=screen-256color

" 让vim配置保存后立马生效
autocmd BufWritePost $MYVIMRC source $MYVIMRC


" 开启实时搜索并且对大小写不敏感
set incsearch
set ignorecase
" 关闭兼容模式
set nocompatible
" 开启vim自身命令行模式智能补全
set wildmenu

set background=dark
set laststatus=2
let g:airline#extensions#tabline#enabled=1
"let g:airline#extensions#tabline#enabled = 1

" Vim 在与屏幕/键盘交互时使用的编码(取决于实际的终端的设定)
set encoding=utf-8
set langmenu=zh_CN.UTF-8
" 设置打开文件的编码格式 
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1 
set fileencoding=utf-8




let g:lightline = { 'colorscheme': 'papercolor', }
set t_Co=256 
let g:airline_powerline_fonts = 1



" 格式化
set formatoptions=tcrqn " 根据要求格式化
set autoindent     " 继承缩紧
set smartindent    " 为C语言提供自动缩紧
set cindent        " 使用C样式缩紧
set smarttab       " 在行和段开始处使用制表符
" 设置文件编码
"set fileencoding=UTF-8
" 搜索设置
set showmatch      " 匹配成队符号
set matchtime=5    " 匹配括号高亮的时间
" 行数控制
set scrolloff=20  " 光标始终保持在距离上下顶点20行的位置
call plug#begin('~/.vim/plugged')
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
" vim欢迎界面
Plug 'mhinz/vim-startify'
Plug 'ryanoasis/vim-devicons'
" 文件树
Plug 'scrooloose/nerdtree'
"Plug 'ryanoasis/vim-devicons'

" vim配色方案
Plug 'flazz/vim-colorschemes'

" 文件数图标
" 图标美化
"Plug 'tiagofumo/vim-nerdtree-syntax-highlight'

" 中文帮助文档
Plug 'yianwillis/vimcdoc'
"Initialize plugin system
call plug#end()

" startify
" 设置欢迎词
let g:startify_custom_header = [
      \'+--------------------------------------------------+',
      \'|     袁菊珍呀！！徐玉全。                          |',
      \'|                                                  |',
      \'|                       https://www.zhiyuquan.com  |',
      \'+--------------------------------------------------+',
      \]
" 设置END
" END


" nerdtree设置
map <leader>n :NERDTreeMirror<CR>
map <leader>n :NERDTreeToggle<CR>




let g:airline_powerline_fonts = 1


set guifont=Powerline_Consolas:h14:cANSI


" 配色方案设置
colorscheme gruvbox
let g:airline_theme = 'papercolor'
" 设置缓冲区
set hidden
" 如果超过这个时间没有输入，将内容写入到磁盘
set updatetime=3

