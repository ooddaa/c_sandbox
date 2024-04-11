#!/bin/sh

function compile_and_run_c_program() {
  local FNAME=$1
  echo $PWD
  clang -o "./bin/${FNAME}" "${FNAME}.c" && chmod +x "./bin/${FNAME}" && "./bin/${FNAME}"  
}

compile_and_run_c_program $1 

exit 0
