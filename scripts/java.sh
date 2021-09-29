#!/bin/bash

echo 'ファイル名：' "$1"

javac $1

java ${1%.*}