# C 言語を Docker で実行したい人へ

## 実行手順

このプロジェクトをクローン(ダウンロード)してください。

コンテナを作成してください。

```sh
docker compose build
```

Docker コンテナを起動してください。

```sh
docker compose up -d
```

### C を実行できるようになりました!!!

`hello.c`を実行してみる。

`hello.c`をコンパイルします。

```sh
docker compose exec app gcc hello.c
```

`hello.c`を実行します。

```sh
docker compose exec app ./a.out
```

---

## 面倒な人向け

`c.sh`を使ってコンパイルと実行をまとめてできます。

```sh
docker compose exec app ./c.sh hello.c
```

※math.h をインクルードするときはコマンドに`-lm`を付ける。

```sh
docker compose exec app ./c.sh sin.c -lm
```

---

## メモ(コンテナ内で作業するとき)

docker-compose exec app bash

## メモ(言語のインストール)

```sh
# C インストール
sudo apt-get install gcc

# Java インストール
sudo apt-get install default-jre

sudo apt install default-jdk

# Python インストール
sudo apt-get install python3
```
