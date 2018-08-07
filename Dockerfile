FROM ubuntu:16.04
ADD ./src /apl/src
RUN cd src; make
ADD ./bin /apl/bin
CMD ["/apl/bin/memory_eater", "300","1"]

