call plug#begin()

Plug 'tpope/vim-sensible'
Plug 'catppuccin/vim', { 'as': 'catppuccin' }
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'
Plug 'pbondoer/vim-42header'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'sheerun/vim-polyglot'
Plug 'tpope/vim-commentary'

call plug#end()

" =============================================================================
" 2. PARAMETRES GENERAUX
" =============================================================================
filetype plugin indent on
syntax on

set termguicolors
set number
set signcolumn=yes
set clipboard=unnamedplus

" Config Tabulations 42
set tabstop=4
set shiftwidth=4
set noexpandtab

let g:hdr42user = "alamjada"
let g:hdr42mail = "alamjada@student.42.fr"

" =============================================================================
" 3. MAPPINGS
" =============================================================================
let mapleader = " "
inoremap jj <esc>
nnoremap <leader>pv :Ex<CR>
nnoremap <leader>sf :Files<CR>
nnoremap <leader><esc> :nohlseach<CR>
nnoremap <F5> :!make<CR>
nnoremap <F2> :e %:p:s,.cpp$,.hpp,:s,.hpp$,.cpp,<CR>
nnoremap <silent> K :call ShowDocumentation()<CR>

function! ShowDocumentation()
  if CocAction('hasProvider', 'hover')
    call CocActionAsync('doHover')
  else
    call feedkeys('K', 'in')
  endif
endfunction

" =============================================================================
" 4. CONFIG PLUGINS & THEME
" =============================================================================
let g:coc_status_error_sign = 'x'
let g:coc_status_warning_sign = '!'

let g:catppuccin_options = {
    \ "transparent_background": v:true,
    \ "integrations": { "coc_nvim": v:true, "fzf": v:true }
    \ }

colorscheme catppuccin_mocha

" Correctifs Transparence
hi Normal guibg=NONE ctermbg=NONE
hi SignColumn guibg=NONE ctermbg=NONE
hi LineNr guibg=NONE ctermbg=NONE
hi CursorLineNr guibg=NONE ctermbg=NONE
hi EndOfBuffer guibg=NONE ctermbg=NONE

" Visibilite Erreurs
hi CocErrorHighlight ctermfg=Red guifg=#f38ba8 gui=underline
hi CocWarningHighlight ctermfg=Yellow guifg=#f9e2af gui=underline
