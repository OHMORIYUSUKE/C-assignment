FROM debian

COPY ./scripts /

RUN apt-get update && apt-get install -y -q sudo 

# Cの環境構築
RUN sudo apt-get install -y -q gcc
# Javaの環境構築
RUN sudo apt-get install -y -q default-jre
RUN sudo apt install -y -q default-jdk
# Pythonの環境構築
RUN sudo apt-get install -y -q python3

# コンテナ内に作業ディレクトリを作成
RUN mkdir -p /c/src/work
# コンテナログイン時のディレクトリ指定
WORKDIR /c/src/work
# ホストのファイルをコンテナの作業ディレクトリに移行
ADD ./scripts /c/src/work