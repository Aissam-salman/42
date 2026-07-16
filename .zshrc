export PATH="$HOME/.bin:$HOME/.local/bin:$HOME/Applications:/usr/bin:$PATH"
export PATH="/home/salman/.config/herd-lite/bin:$PATH"
export PATH="$HOME/neovim/bin:$PATH"
export PATH="$HOME/goinfre/bin:$PATH"
export PHP_INI_SCAN_DIR="/home/salman/.config/herd-lite/bin:$PHP_INI_SCAN_DIR"

ZINIT_HOME="${XDG_DATA_HOME:-${HOME}/.local/share}/zinit/zinit.git"

# Download Zinit, if it's not there yet
if [ ! -d "$ZINIT_HOME" ]; then
   mkdir -p "$(dirname $ZINIT_HOME)"
   git clone https://github.com/zdharma-continuum/zinit.git "$ZINIT_HOME"
fi
# Source/Load zinit
source "${ZINIT_HOME}/zinit.zsh"
# Add in zsh plugins
zinit light zsh-users/zsh-syntax-highlighting
zinit light zsh-users/zsh-completions
zinit light zsh-users/zsh-autosuggestions
zinit light Aloxaf/fzf-tab
# sharkdp/bat
# ogham/exa, replacement for ls
zinit ice pick"async.zsh" src"pure.zsh"
zinit light sindresorhus/pure

# Load completions
autoload -Uz compinit && compinit

zinit cdreplay -q

# Keybindings
bindkey -e
bindkey '^p' history-search-backward
bindkey '^n' history-search-forward
bindkey '^[w' kill-region

# History
HISTSIZE=5000
HISTFILE=~/.zsh_history
SAVEHIST=$HISTSIZE
HISTDUP=erase
setopt appendhistory
setopt sharehistory
setopt hist_ignore_space
setopt hist_ignore_all_dups
setopt hist_save_no_dups
setopt hist_ignore_dups
setopt hist_find_no_dups

# Completion styling
zstyle ':completion:*' matcher-list 'm:{a-z}={A-Za-z}'
zstyle ':completion:*' list-colors "${(s.:.)LS_COLORS}"
zstyle ':completion:*' menu no
zstyle ':fzf-tab:complete:cd:*' fzf-preview 'ls --color $realpath'

# sets tools
export EDITOR=nvim
export VISUAL=code
export GIT_EDITOR=nvim

### ALIASES ###
# alias vi="$EDITOR"
## git
alias gc="git clone"
alias ga="git add ."
alias gm="git commit -m"
alias gp="git push"

togit(){
  git add .
  git commit -m $1
  git push
}

try(){
    local exe="a.out"
    # Compiler et afficher toutes les erreurs de cc
    if ! cc -Wall -Wextra -Werror -o "$exe" "$@"; then
        echo "❌ Compilation échouée."
        return 1
    fi
    # Si la compilation réussit, exécuter
    echo "✅ Compilation réussie, exécution :"
    ./"$exe"
}

alias comp="cc -Wall -Wextra -Werror"
mkcd(){
  mkdir -p "$@"; 
  cd "$_";
}

alias sd="cd ~ && cd \$(find * -type d | fzf)"
alias ff="fzf --preview 'bat --style=numbers --color=always {}' | xargs -n 1 $EDITOR"

#42 
alias lab="cd ~/Documents/mlab/"
alias vog="cd ~/Documents/git42/"
alias cor="cd ~/correction/"
alias dbg='~/Documents/mlab/scripts/lldbrun'
alias val="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"
alias visu="~/Documents/mlab/push_swap_visualizer/build/bin/visualizer"


# list#
## Colorize the ls output ##
alias ls='ls --color=auto'
alias ll='ls -la'
alias l='ls -lahF'
alias listdir="ls -d */ > list"


# fix obvious typos
alias cd..="cd .."
alias pdw="pwd"

## Colorize the grep command output for ease of use (good for log files)##
alias grep="grep --color=auto"
alias egrep="egrep --color=auto"
alias fgrep="fgrep --color=auto"

# Color output of ip
alias ip="ip -color"

# continue download
alias wget="wget -c"

# switch between bash, zsh and fish
alias tobash="sudo chsh $USER -s /bin/bash && echo 'Done. Now log out.'"
alias tozsh="sudo chsh $USER -s /bin/zsh && echo 'Done. Now log out.'"
alias rg="rg --sort path"

alias nnvim="$EDITOR ~/.config/nvim/init.lua"
alias nzsh="$EDITOR ~/.zshrc"
alias sz="source ~/.zshrc"
alias nbash="$EDITOR ~/.bashrc"
alias nkitty="$EDITOR ~/.config/kitty/kitty.conf"


#tmux 
alias sourcetmux="tmux source ~/.tmux.conf"

alias norme="norminette -R CheckForbiddenSourceHeader"

autoload -U promptinit; promptinit

alias francinette=/home/alamjada/francinette/tester.sh

alias paco=/home/alamjada/francinette/tester.sh

# opencode
export PATH=/home/alamjada/.opencode/bin:$PATH
