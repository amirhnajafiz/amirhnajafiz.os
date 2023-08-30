export NVM_DIR=~/.nvm

source $(brew --prefix nvm)/nvm.sh

export PATH="$HOME/.composer/vendor/bin:$PATH"
. "$HOME/.cargo/env"
___MY_VMOPTIONS_SHELL_FILE="${HOME}/.jetbrains.vmoptions.sh"; if [ -f "${___MY_VMOPTIONS_SHELL_FILE}" ]; then . "${___MY_VMOPTIONS_SHELL_FILE}"; fi
