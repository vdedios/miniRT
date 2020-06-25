let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <Plug>CocRefresh =coc#_complete()
map! <D-v> *
map  gT
map  gt
map * >
map + +
map - -
nnoremap :%y + :yy
nnoremap :w :wa
map H h
map J j
map K k
map L l
map _ <
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
map r 
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
onoremap <silent> <Plug>(coc-classobj-a) :call coc#rpc#request('selectSymbolRange', [v:false, '', ['Interface', 'Struct', 'Class']])
onoremap <silent> <Plug>(coc-classobj-i) :call coc#rpc#request('selectSymbolRange', [v:true, '', ['Interface', 'Struct', 'Class']])
vnoremap <silent> <Plug>(coc-classobj-a) :call coc#rpc#request('selectSymbolRange', [v:false, visualmode(), ['Interface', 'Struct', 'Class']])
vnoremap <silent> <Plug>(coc-classobj-i) :call coc#rpc#request('selectSymbolRange', [v:true, visualmode(), ['Interface', 'Struct', 'Class']])
onoremap <silent> <Plug>(coc-funcobj-a) :call coc#rpc#request('selectSymbolRange', [v:false, '', ['Method', 'Function']])
onoremap <silent> <Plug>(coc-funcobj-i) :call coc#rpc#request('selectSymbolRange', [v:true, '', ['Method', 'Function']])
vnoremap <silent> <Plug>(coc-funcobj-a) :call coc#rpc#request('selectSymbolRange', [v:false, visualmode(), ['Method', 'Function']])
vnoremap <silent> <Plug>(coc-funcobj-i) :call coc#rpc#request('selectSymbolRange', [v:true, visualmode(), ['Method', 'Function']])
nnoremap <silent> <Plug>(coc-cursors-position) :call coc#rpc#request('cursorsSelect', [bufnr('%'), 'position', 'n'])
nnoremap <silent> <Plug>(coc-cursors-word) :call coc#rpc#request('cursorsSelect', [bufnr('%'), 'word', 'n'])
vnoremap <silent> <Plug>(coc-cursors-range) :call coc#rpc#request('cursorsSelect', [bufnr('%'), 'range', visualmode()])
nnoremap <Plug>(coc-refactor) :call       CocActionAsync('refactor')
nnoremap <Plug>(coc-command-repeat) :call       CocAction('repeatCommand')
nnoremap <Plug>(coc-float-jump) :call       coc#util#float_jump()
nnoremap <Plug>(coc-float-hide) :call       coc#util#float_hide()
nnoremap <Plug>(coc-fix-current) :call       CocActionAsync('doQuickfix')
nnoremap <Plug>(coc-openlink) :call       CocActionAsync('openLink')
nnoremap <Plug>(coc-references) :call       CocActionAsync('jumpReferences')
nnoremap <Plug>(coc-type-definition) :call       CocActionAsync('jumpTypeDefinition')
nnoremap <Plug>(coc-implementation) :call       CocActionAsync('jumpImplementation')
nnoremap <Plug>(coc-declaration) :call       CocActionAsync('jumpDeclaration')
nnoremap <Plug>(coc-definition) :call       CocActionAsync('jumpDefinition')
nnoremap <Plug>(coc-diagnostic-prev-error) :call       CocActionAsync('diagnosticPrevious', 'error')
nnoremap <Plug>(coc-diagnostic-next-error) :call       CocActionAsync('diagnosticNext',     'error')
nnoremap <Plug>(coc-diagnostic-prev) :call       CocActionAsync('diagnosticPrevious')
nnoremap <Plug>(coc-diagnostic-next) :call       CocActionAsync('diagnosticNext')
nnoremap <Plug>(coc-diagnostic-info) :call       CocActionAsync('diagnosticInfo')
nnoremap <Plug>(coc-format) :call       CocActionAsync('format')
nnoremap <Plug>(coc-rename) :call       CocActionAsync('rename')
nnoremap <Plug>(coc-codeaction) :call       CocActionAsync('codeAction',         '')
vnoremap <Plug>(coc-codeaction-selected) :call       CocActionAsync('codeAction',         visualmode())
vnoremap <Plug>(coc-format-selected) :call       CocActionAsync('formatSelected',     visualmode())
nnoremap <Plug>(coc-codelens-action) :call       CocActionAsync('codeLensAction')
nnoremap <Plug>(coc-range-select) :call       CocAction('rangeSelect',     '', v:true)
vnoremap <Plug>(coc-range-select-backward) :call       CocAction('rangeSelect',     visualmode(), v:false)
vnoremap <Plug>(coc-range-select) :call       CocAction('rangeSelect',     visualmode(), v:true)
map <F1> :Stdheader
map <C-H> gT
map <C-L> gt
vmap <BS> "-d
vmap <D-x> "*d
vmap <D-c> "*y
vmap <D-v> "-d"*P
nmap <D-v> "*P
inoremap " ""hli
inoremap ' ''hli
inoremap ( ()hli
inoremap < <>hli
inoremap [ []hli
inoremap jj 
inoremap { {}ko
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autoread
set background=dark
set backspace=indent,eol,start
set clipboard=unnamed
set cpoptions=BceFs
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=es
set hidden
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set modelines=1
set report=10000
set runtimepath=~/.vim,~/.vim/bundle/Vundle.vim,~/.vim/bundle/lightline.vim,~/.vim/bundle/artify.vim,~/.vim/bundle/vim-gitbranch,~/.vim/bundle/lightline-gitdiff,~/.vim/bundle/lightline-ale,~/.vim/bundle/lightline-asyncrun,~/.vim/bundle/pomodoro.vim,~/.vim/bundle/vim-devicons,~/.vim/bundle/forest-night,/usr/local/share/vim/vimfiles,/usr/local/share/vim/vim82,/usr/local/share/vim/vimfiles/after,~/.vim/after,~/.vim/bundle/Vundle.vim/after,~/.vim/bundle/lightline.vim/after,~/.vim/bundle/artify.vim/after,~/.vim/bundle/vim-gitbranch/after,~/.vim/bundle/lightline-gitdiff/after,~/.vim/bundle/lightline-ale/after,~/.vim/bundle/lightline-asyncrun/after,~/.vim/bundle/pomodoro.vim/after,~/.vim/bundle/vim-devicons/after,~/.vim/bundle/forest-night/after
set scrolloff=5
set shiftwidth=4
set showmatch
set noshowmode
set showtabline=2
set smartcase
set smartindent
set smarttab
set splitbelow
set splitright
set tabline=%!lightline#tabline()
set tabstop=4
set termguicolors
set timeoutlen=500
set undodir=~/.cache/vim/undo
set undofile
set verbosefile=~/.vim/vimdebug.txt
set viminfo='1000
set visualbell
set wildmenu
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Desktop/miniRT
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
$argadd src/miniRT.c
tabnew
tabrewind
edit src/algebra/algebra_1.c
set splitbelow splitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),0],:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
set cursorline
setlocal cursorline
setlocal cursorlineopt=both
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'c'
setlocal filetype=c
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=syntax
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},0),0],:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal scrolloff=-1
setlocal shiftwidth=4
setlocal noshortname
setlocal showbreak=
setlocal sidescrolloff=-1
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_active_0#%(\ %{lightline#mode()}\ %)%{(&paste)?\"\":\"\"}%(\ %{&paste?\"PASTE\":\"\"}\ %)%#LightlineLeft_active_0_1#%#LightlineLeft_active_1#%(\ %R\ %)%{(&readonly)&&(1||(&modified||!&modifiable)||1||Devicons_Filetype()!=#\"\")?\"\":\"\"}%(\ %t\ %)%{(&modified||!&modifiable)||1||Devicons_Filetype()!=#\"\"?\"\":\"\"}%(\ %M\ %)%{(&modified||!&modifiable)&&(1||Devicons_Filetype()!=#\"\")?\"\":\"\"}%(\ %{&fenc!=#\"\"?&fenc:&enc}[%{&ff}]\ %)%{Devicons_Filetype()!=#\"\"?\"\":\"\"}%(\ %{Devicons_Filetype()}\ %)%#LightlineLeft_active_1_2#%#LightlineMiddle_active#%=%#LightlineRight_active_2_3#%#LightlineRight_active_2#%(\ %{coc#status()}\ %)%#LightlineRight_active_1_2#%#LightlineRight_active_1#%(\ %{PomodoroStatus()}\ %)%#LightlineRight_active_0_1#%#LightlineRight_active_0#%(\ %2p%%\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'c'
setlocal syntax=c
endif
setlocal tabstop=8
setlocal tagcase=
setlocal tagfunc=
setlocal tags=
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=0
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal wincolor=
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
let s:l = 16 - ((15 * winheight(0) + 17) / 35)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
16
normal! 0
lcd ~/Desktop/miniRT
tabnext
edit ~/.myvimrc
set splitbelow splitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
vnoremap <buffer> <silent> [" :exe "normal! gv"|call search('\%(^\s*".*\n\)\%(^\s*"\)\@!', "bW")
nnoremap <buffer> <silent> [" :call search('\%(^\s*".*\n\)\%(^\s*"\)\@!', "bW")
vnoremap <buffer> <silent> [] m':exe "normal! gv"|call search('^\s*endf\%[unction]\>', "bW")
nnoremap <buffer> <silent> [] m':call search('^\s*endf\%[unction]\>', "bW")
vnoremap <buffer> <silent> [[ m':exe "normal! gv"|call search('^\s*fu\%[nction]\>', "bW")
nnoremap <buffer> <silent> [[ m':call search('^\s*fu\%[nction]\>', "bW")
vnoremap <buffer> <silent> ]" :exe "normal! gv"|call search('^\(\s*".*\n\)\@<!\(\s*"\)', "W")
nnoremap <buffer> <silent> ]" :call search('^\(\s*".*\n\)\@<!\(\s*"\)', "W")
vnoremap <buffer> <silent> ][ m':exe "normal! gv"|call search('^\s*endf\%[unction]\>', "W")
nnoremap <buffer> <silent> ][ m':call search('^\s*endf\%[unction]\>', "W")
vnoremap <buffer> <silent> ]] m':exe "normal! gv"|call search('^\s*fu\%[nction]\>', "W")
nnoremap <buffer> <silent> ]] m':call search('^\s*fu\%[nction]\>', "W")
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal nocindent
setlocal cinkeys=0{,0},0),0],:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:\"\ -,mO:\"\ \ ,eO:\"\",:\"
setlocal commentstring=\"%s
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
set cursorline
setlocal cursorline
setlocal cursorlineopt=both
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'vim'
setlocal filetype=vim
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=syntax
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=GetVimIndent()
setlocal indentkeys=0{,0},0),0],:,0#,!^F,o,O,e,=end,=else,=cat,=fina,=END,0\\,0=\"\\\ 
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255,#
setlocal keywordprg=:help
setlocal nolinebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal scrolloff=-1
setlocal shiftwidth=4
setlocal noshortname
setlocal showbreak=
setlocal sidescrolloff=-1
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_active_0#%(\ %{lightline#mode()}\ %)%{(&paste)?\"\":\"\"}%(\ %{&paste?\"PASTE\":\"\"}\ %)%#LightlineLeft_active_0_1#%#LightlineLeft_active_1#%(\ %R\ %)%{(&readonly)&&(1||(&modified||!&modifiable)||1||Devicons_Filetype()!=#\"\")?\"\":\"\"}%(\ %t\ %)%{(&modified||!&modifiable)||1||Devicons_Filetype()!=#\"\"?\"\":\"\"}%(\ %M\ %)%{(&modified||!&modifiable)&&(1||Devicons_Filetype()!=#\"\")?\"\":\"\"}%(\ %{&fenc!=#\"\"?&fenc:&enc}[%{&ff}]\ %)%{Devicons_Filetype()!=#\"\"?\"\":\"\"}%(\ %{Devicons_Filetype()}\ %)%#LightlineLeft_active_1_2#%#LightlineMiddle_active#%=%#LightlineRight_active_2_3#%#LightlineRight_active_2#%(\ %{coc#status()}\ %)%#LightlineRight_active_1_2#%#LightlineRight_active_1#%(\ %{PomodoroStatus()}\ %)%#LightlineRight_active_0_1#%#LightlineRight_active_0#%(\ %2p%%\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'vim'
setlocal syntax=vim
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tagfunc=
setlocal tags=
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=78
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal wincolor=
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
let s:l = 15 - ((14 * winheight(0) + 17) / 35)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
15
normal! 0
lcd ~/Desktop/miniRT
tabnext 2
badd +0 ~/Desktop/miniRT/src/algebra/algebra_1.c
badd +30 ~/Desktop/miniRT/src/miniRT.c
badd +37 ~/Desktop/miniRT/makefile
badd +4 ~/Desktop/miniRT/src/load/load.c
badd +3 ~/Desktop/miniRT/scenes/single_geometry/sceneSphere.rt
badd +4 ~/Desktop/miniRT/src/main.c
badd +8 ~/Desktop/miniRT/src/error.c
badd +6 ~/Desktop/miniRT/includes/bmp.h
badd +79 ~/Desktop/miniRT/src/bmp.c
badd +47 ~/Desktop/miniRT/src/pipeline.c
badd +15 ~/Desktop/miniRT/includes/scene_types.h
badd +9 ~/Desktop/miniRT/scenes/bonus/sceneRainbow.rt
badd +59 ~/Desktop/miniRT/assets/help.txt
badd +62 ~/Desktop/miniRT/includes/miniRT.h
badd +15 ~/Desktop/miniRT/assets/welcome.txt
badd +10 ~/Desktop/miniRT/src/shadows.c
badd +23 ~/Desktop/miniRT/includes/error.h
badd +8 ~/Desktop/miniRT/scenes/single_geometry/sceneCylinder.rt
badd +3 ~/Desktop/miniRT/src/minirt/miniRT_utils.c
badd +34 ~/Desktop/miniRT/src/color.c
badd +9 ~/Desktop/miniRT/scenes/scenePlanesBump.rt
badd +37 ~/Desktop/miniRT/src/main_options.c
badd +24 ~/Desktop/miniRT/src/bonus/color_bonus.c
badd +22 ~/Desktop/miniRT/includes/geometry_types.h
badd +7 ~/Desktop/miniRT/scenes/scenePlanesWaves.rt
badd +11 ~/Desktop/miniRT/src/algebra/algebra_2.c
badd +19 ~/Desktop/miniRT/src/geometry/plane.c
badd +13 ~/Desktop/miniRT/includes/algebra.h
badd +63 ~/Desktop/miniRT/src/load/load_1.c
badd +13 ~/Desktop/miniRT/includes/bmp_types.h
badd +1 ~/Desktop/miniRT/src/load/load_utils2.c
badd +1 ~/Desktop/miniRT/scenes/sceneVoid.rt
badd +7 ~/Desktop/miniRT/scenes/sceneSphere2.rt
badd +18 ~/Desktop/miniRT/src/camera.c
badd +22 ~/Desktop/miniRT/src/geometry/sphere.c
badd +28 ~/Desktop/miniRT/src/load/load_2.c
badd +1 ~/Desktop/miniRT/includes/color.h
badd +8 ~/Desktop/miniRT/scenes/sceneOverlap.rt
badd +1 ~/Desktop/miniRT/src/geometry/cylinder.c
badd +31 ~/Desktop/miniRT/src/shadows/shadows.c
badd +16 ~/Desktop/miniRT/includes/shadows.h
badd +8 ~/Desktop/miniRT/scenes/sceneSpheres.rt
badd +72 ~/Desktop/miniRT/src/geometry/triangle.c
badd +4 ~/Desktop/miniRT/scenes/scene3.rt
badd +26 ~/Desktop/miniRT/src/shadows/cylinder_shadows.c
badd +11 ~/Desktop/miniRT/src/shadows/plane_shadows.c
badd +4 ~/Desktop/miniRT/scenes/scenePlanesSpheres.rt
badd +12 ~/Desktop/miniRT/includes/pipeline.h
badd +43 ~/Desktop/miniRT/src/geometry/square.c
badd +50 ~/Desktop/miniRT/includes/geometry.h
badd +1 ~/Desktop/miniRT/scenes/sceneInterferences.rt
badd +1 ~/Desktop/miniRT/scenes/scene1.rt
badd +1 ~/Desktop/miniRT/src/geometry.c
badd +23 ~/Desktop/miniRT/includes/load_utils.h
badd +10 ~/Desktop/miniRT/scenes/scene2.rt
badd +2 ~/Desktop/miniRT/scenes/scene_resolution.rt
badd +11 ~/Desktop/miniRT/includes/camera.h
badd +24 ~/Desktop/miniRT/includes/load.h
badd +1 ~/Desktop/miniRT/src
badd +1 ~/Desktop/miniRT/scenes/scenePlanes.rt
badd +4 ~/Desktop/miniRT/scenes/sceneFails.rt
badd +12 ~/Desktop/miniRT/src/shadows/square_shadows.c
badd +10 ~/Desktop/miniRT/src/shadows/sphere_shadows.c
badd +4 ~/Desktop/miniRT/src/shadows/triangle_shadows.c
badd +7 ~/Desktop/miniRT/scenes/sceneTriangle.rt
badd +4 ~/Desktop/miniRT/scenes/sceneCylinder.rt
badd +1 ~/Desktop/miniRT/src/load/load_utils.c
badd +1 ~/Desktop/miniRT/src/algebra
badd +3 ~/Desktop/miniRT/src/axis.c
badd +29 ~/Desktop/miniRT/src/algebra/algebra_3.c
badd +1 ~/Desktop/miniRT/includes/axis.h
badd +32 ~/Desktop/miniRT/scenes/scene42.rt
badd +3 ~/Desktop/miniRT/scenes/sceneProblems2.rt
badd +1 ~/Desktop/miniRT/art
badd +37 ~/Desktop/pruebas/minirt/src/intersect_obj.c
badd +1 ~/Desktop/miniRT/src/shadows
badd +4 ~/Desktop/miniRT/scenes/room.rt
badd +1 ~/Desktop/miniRT/src/load
badd +18 ~/Desktop/miniRT/src/geometry/cylinder_caps.c
badd +9 ~/Desktop/miniRT/scenes/scene2Planes.rt
badd +9 ~/Desktop/miniRT/scenes/alilisotiocianato.rt
badd +30 ~/Desktop/miniRT/dependencies/libft/ft_strncmp.c
badd +1 ~/Desktop/miniRT/output_scenes/output.bmp
badd +1 ~/Desktop/miniRT/dependencies/minilibx_opengl
badd +1 ~/Desktop/miniRT/dependencies/minilibx_opengl/mlx_int_str_to_wordtab.o
badd +126 ~/Desktop/miniRT/dependencies/minilibx_opengl/mlx.h
badd +56 ~/Desktop/miniRT/dependencies/minilibx_opengl/mlx_new_window.h
badd +81 ~/Desktop/miniRT/dependencies/minilibx_opengl/mlx_int.h
badd +4 ~/Desktop/miniRT/dependencies/minilibx_opengl/Makefile
badd +22 ~/Desktop/miniRT/src/load/load_utils_2.c
badd +8 ~/Desktop/miniRT/scenes/plan.rt
badd +4 ~/Desktop/miniRT/src/color_waves.c
badd +4 ~/Desktop/miniRT/README.md
badd +1 ~/Desktop/miniRT/src/main_bonus.c
badd +45 ~/Desktop/miniRT/includes/bonus/minirt_bonus.h
badd +22 ~/Desktop/miniRT/src/bonus/main_bonus.c
badd +21 ~/Desktop/miniRT/dependencies/libft/ft_strnstr.c
badd +8 ~/Desktop/miniRT/scenes/scenePlanesCheckered.rt
badd +10 ~/Desktop/miniRT/scenes/sceneRainbow.rt
badd +1 ~/Desktop/miniRT/dependencies/minilibx_opengl/mlx_png.h
badd +13 ~/Desktop/miniRT/dependencies/minilibx_opengl/mlx_png.c
badd +171 ~/Desktop/miniRT/dependencies/minilibx_opengl/libmlx.a
badd +1 ~/Desktop/42.png
badd +1 ~/Desktop/miniRT/miniRT/includes/bonus
badd +1 ~/Desktop/miniRT/scenes/scenePlanesSkybox.rt
badd +7 ~/Desktop/miniRT/scenes/sceneSphereEarth.rt
badd +5 ~/Desktop/miniRT/scenes/sceneSphereParallel.rt
badd +1 ~/Desktop/miniRT/src/geometry
badd +8 ~/Desktop/miniRT/output.txt
badd +8 ~/Desktop/miniRT/scenes/sceneCube.rt
badd +1 ~/Desktop/miniRT/scenes/scenePyramid.rt
badd +8 ~/Desktop/miniRT/scenes/sceneProblemsTriangle.rt
badd +85 ~/Desktop/miniRT/src/bonus/load_bonus.c
badd +1 ~/Desktop/miniRT/includes
badd +8 ~/Desktop/miniRT/scenes_bonus/scenePlanesBump.rt
badd +1 ~/Desktop/miniRT/scenes_bonus/sceneCylinder.rt
badd +2 ~/Desktop/miniRT/scenes_bonus/sceneCylinderCaps.rt
badd +2 ~/Desktop/miniRT/scenes_bonus/sceneSphereEarth.rt
badd +7 ~/Desktop/miniRT/scenes_bonus/scenePlanesSkybox.rt
badd +9 ~/Desktop/miniRT/scenes_bonus/sceneSphereSpace.rt
badd +9 ~/Desktop/miniRT/scenes_bonus/sceneSphereSpace2.rt
badd +8 ~/Desktop/miniRT/scenes_bonus/sceneSphereParallel.rt
badd +1 ~/Desktop/miniRT/scenes_bonus/.sceneSphereSpace.rt.swp
badd +1 ~/Desktop/miniRT/scenes_bonus/.sceneSphereParallel.rt.swp
badd +6 ~/Desktop/miniRT/scenes_bonus/scenePROBLEMS.rt
badd +8 ~/Desktop/miniRT/scenes/check/sceneMix.rt
badd +5 ~/Desktop/miniRT/scenes/sceneSphere.rt
badd +2 ~/Desktop/miniRT/scenes/check/scene42.rt
badd +8 ~/Desktop/miniRT/scenes/check/sceneRoom.rt
badd +1 ~/Desktop/miniRT/src/bonus
badd +32 ~/Desktop/miniRT/src/bonus/color_sphere_bonus.c
badd +19 ~/Desktop/miniRT/src/bonus/light_bonus.c
badd +42 ~/Desktop/miniRT/src/bonus/color_plane_bonus.c
badd +3 ~/Desktop/miniRT/src/bonus/filter_bonus.c
badd +4 ~/Desktop/miniRT/src/bonus/load_bonus2.c
badd +2 ~/Desktop/miniRT/scenes/bonus/sceneSphereSpace.rt
badd +2 ~/Desktop/miniRT/scenes/bonus/sceneSphereEarth.rt
badd +2 ~/Desktop/miniRT/scenes/bonus/sceneCylinderRainbow.rt
badd +2 ~/Desktop/miniRT/scenes/bonus/scenePlanesSkybox.rt
badd +3 ~/Desktop/miniRT/scenes/bonus/scenePlanesBump.rt
badd +6 ~/Desktop/miniRT/scenes/bonus/sceneSphereParallel.rt
badd +9 ~/Desktop/miniRT/scenes/single_geometry/sceneSquare.rt
badd +8 ~/Desktop/miniRT/scenes/single_geometry/sceneTriangle.rt
badd +75 ~/Desktop/miniRT/src/load/load_utils_3.c
badd +38 ~/Desktop/miniRT/src/minirt/miniRT.c
badd +97 ~/Desktop/miniRT/tmp.c
badd +1 ~/Desktop/miniRT/src/bonus/.load_bonus.c.swp
badd +2 ~/Desktop/miniRT/scenes/single_geometry/sceneVoid.rt
badd +7 ~/Desktop/miniRT/scenes/single_geometry/scenePlane.rt
badd +8 ~/Desktop/miniRT/scenes/bonus/scene42.rt
badd +8 ~/Desktop/miniRT/scenes/multiple_objects/scene42.rt
badd +4 ~/Desktop/miniRT/scenes/bonus/scene42Space.rt
badd +2 ~/Desktop/miniRT/scenes/multiple_objects/sceneRoom.rt
badd +1 ~/Desktop/miniRT/includes/bonus
badd +4 ~/Desktop/miniRT/src/color_utils.c
badd +7 ~/Desktop/miniRT/.gitignore
badd +7 ~/Desktop/miniRT/scenes/bonus/sceneSphereMultiple.rt
badd +7 ~/Desktop/miniRT/scenes/bonus/scenePlanesFloor.rt
badd +1 ~/Desktop/miniRT/assets
badd +1 ~/Desktop/miniRT/src/hooks/miniRT_utils.c
badd +25 ~/Desktop/miniRT/src/bonus/color_utils_bonus.c
badd +9 ~/Desktop/miniRT/scenes/bonus/sceneSphereTexture.rt
badd +8 ~/Desktop/miniRT/scenes/multiple_objects/sceneMix.rt
badd +1 ~/Desktop/miniRT/scenes/bonus/sceneCube.rt
badd +31 ~/Desktop/miniRT/src/hooks/miniRT.c
badd +1 ~/Desktop/miniRT/dependencies/get_next_line
badd +52 ~/Desktop/miniRT/dependencies/get_next_line/get_next_line.c
badd +0 ~/.myvimrc
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOS
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
