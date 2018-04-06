# コンテナのメモリ消費プログラム

Docker環境やKubernetes環境で、メモリ制限値を超過した場合の振る舞いを調べるためのコードです。



## バイナリのビルド

~~~
$ cd src
$ make
gcc -Wall -O2 -o ../bin/memory_eater memory_eater.c
~~~



## コンテナのビルド

~~~
$ docker build -t memory_eater:0.1 .
Sending build context to Docker daemon  18.94kB
Step 1/4 : FROM ubuntu:16.04
 ---> 00fd29ccc6f1
Step 2/4 : ADD ./src /apl/src
 ---> Using cache
 ---> a25f76a56787
Step 3/4 : ADD ./bin /apl/bin
 ---> Using cache
 ---> 679c8906b68f
Step 4/4 : CMD /apl/bin/memory_eater 300 1
 ---> Using cache
 ---> 9807be5cb0d0
Successfully built 9807be5cb0d0
Successfully tagged memory_eater:0.1
~~~



## DockerHubへの登録

~~~
$ docker login
Login with your Docker ID to push and pull images from Docker Hub. If you don't have a Docker ID, head over to https://hub.docker.com to create one.
Username (maho):          
Password: 
Login Succeeded

$ docker tag memory_eater:0.1 maho/memory_eater:0.1

$ docker push maho/memory_eater:0.1
The push refers to a repository [docker.io/maho/memory_eater]
df6ee6a7a2b1: Pushed 
55355a00e5ef: Pushed 
f17fc24fb8d0: Mounted from library/ubuntu 
6458f770d435: Mounted from library/ubuntu 
5a876f8f1a3d: Mounted from library/ubuntu 
d2f8c05d353b: Mounted from library/ubuntu 
48e0baf45d4d: Mounted from library/ubuntu 
0.1: digest: sha256:8d3100d43214c6934247a6dd0bc4cd548131ac7b92a57685b606b8b6055bf46b size: 1772
~~~


