FROM ubuntu:16.04
RUN apt-get update && apt-get install -y gcc make
ADD src /apl/src
RUN mkdir /apl/bin
RUN cd /apl/src; make
CMD ["tail", "-f","/dev/null"]

