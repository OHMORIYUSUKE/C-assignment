#!/bin/bash

echo 'ファイル名：' "$1" ',コマンド' "$2"

gcc $1 $2

./a.out
