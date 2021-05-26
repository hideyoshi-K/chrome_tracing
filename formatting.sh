#!/bin/bash

DIR=$1

cat ${DIR}/*.yaml | sed 's/,*$//' | sed -e 's/^/[/' | sed -e 's/$/]/'
