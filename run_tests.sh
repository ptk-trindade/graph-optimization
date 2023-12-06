#!/bin/bash

export -f run_main

run_main() {
    i=$1
    j=$2
    ./main $i $j >> output_${i}.txt
}

export -f run_main

parallel -j 4 ::: \
    "run_main 500 {1..10}" \
    "run_main 700 {1..10}" \
    "run_main 800 {1..10}" \
    "run_main 1000 {1..10}"
