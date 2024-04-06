#!/bin/sh

function compile_and_run_c_program() {
  local FNAME=$1
  echo "===> compiling and running ${FNAME}\n\n"
  clang -o ${FNAME} "${FNAME}.c" && chmod +x ${FNAME} && ./${FNAME}  
}

compile_and_run_c_program $1 

exit 0
