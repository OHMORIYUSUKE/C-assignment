FROM debian

COPY ./scripts /

RUN apt-get update && apt-get install -y -q sudo 

RUN sudo apt-get install -y -q gcc

# コンテナ内に作業ディレクトリを作成
RUN mkdir -p /c/src/work
# コンテナログイン時のディレクトリ指定
WORKDIR /c/src/work
# ホストのファイルをコンテナの作業ディレクトリに移行
ADD ./scripts /c/src/work