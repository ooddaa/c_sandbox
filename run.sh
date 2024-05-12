#!/bin/sh

function compile_and_run_c_program() {
  local FILENAME=$1
  local PATH_TO_BIN=$(echo $FILENAME | awk 'gsub("/", "-") gsub("\.c$", "") {print "./bin/"$1}')
  clang -o $PATH_TO_BIN $FILENAME && chmod +x $PATH_TO_BIN && $PATH_TO_BIN   
}

compile_and_run_c_program $1 

exit 0
