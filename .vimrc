" =============================================================================
" 1. GESTION DES PLUGINS (Vim-Plug)
" =============================================================================
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
" 2. PARAMÈTRES GÉNÉRAUX & 42 STANDARD
" =============================================================================
filetype plugin indent on
syntax on

set termguicolors     " Couleurs 24-bit pour Ghostty
set number            " Affiche les numéros de ligne
set signcolumn=yes    " Toujours afficher la colonne de gauche (évite les sauts)
set mouse=a           " Active la souris au cas où

" Configuration des tabulations (Standard C++ 42)
set tabstop=4
set shiftwidth=4
set noexpandtab       " À 42, on utilise souvent les vraies Tabs (change en expandtab si besoin)

" Variables pour le Header 42
let g:hdr42user = "alamjada"
let g:hdr42mail = "alamjada@student.42.fr"

" =============================================================================
" 3. MAPPINGS (Raccourcis clavier)
" =============================================================================
" Sortir du mode insertion rapidement
inoremap jj <esc>

" Compilation avec F5
nnoremap <F5> :!make<CR>

" Switch rapide entre .cpp et .hpp
nnoremap <F2> :e %:p:s,.cpp$,.hpp,:s,.hpp$,.cpp,<CR>

" Voir la doc ou l'erreur sous le curseur avec 'K'
nnoremap <silent> K :call ShowDocumentation()<CR>

function! ShowDocumentation()
  if CocAction('hasProvider', 'hover')
    call CocActionAsync('doHover')
  else
    call feedkeys('K', 'in')
  endif
endfunction

" =============================================================================
" 4. CONFIGURATION DES PLUGINS (CoC, FZF, etc.)
" =============================================================================
" Icônes pour CoC (nécessite une Nerd Font dans Ghostty)
let g:coc_status_error_sign = '✘'
let g:coc_status_warning_sign = '⚠'

" Configuration de Catppuccin
let g:catppuccin_options = {
    \ "transparent_background": v:true,
    \ "term_colors": v:true,
    \ "integrations": {
    \   "coc_nvim": v:true,
    \   "fzf": v:true,
    \ }
    \ }

" =============================================================================
" 5. THÈME ET CORRECTIFS GRAPHIQUES (À laisser à la fin)
" =============================================================================
colorscheme catppuccin_mocha

" Forcer la transparence sur tous les éléments
hi Normal guibg=NONE ctermbg=NONE
hi SignColumn guibg=NONE ctermbg=NONE
hi LineNr guibg=NONE ctermbg=NONE
hi CursorLineNr guibg=NONE ctermbg=NONE
hi EndOfBuffer guibg=NONE ctermbg=NONE

" Visibilité des erreurs CoC (Correction contraste sur fond transparent)
hi CocErrorHighlight ctermfg=Red
