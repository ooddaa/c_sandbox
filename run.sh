#!/bin/sh

function compile_and_run_c_program() {
  local FNAME=$1
  clang -o ${FNAME} "${FNAME}.c" && chmod +x ${FNAME} && ./${FNAME}  
}

compile_and_run_c_program $1 

exit 0
