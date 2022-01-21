FROM gcc

RUN apt-get update

RUN apt-get -y install astyle
RUN apt-get -y install cppcheck
RUN apt-get -y install cmake
RUN apt-get -y install dos2unix
RUN apt-get -y install doxygen
RUN apt-get -y install graphviz
RUN apt-get -y install valgrind
RUN apt-get -y install vim
RUN apt-get -y install libboost-dev
RUN apt-get -y install libboost-serialization-dev
RUN apt-get -y install libgmp-dev
RUN apt-get -y install libgtest-dev

RUN git clone https://github.com/DOMjudge/checktestdata checktestdata && \
    cd checktestdata                                                  && \
    git checkout release                                              && \
    ./bootstrap                                                       && \
    make                                                              && \
    cp checktestdata /usr/bin                                         && \
    cd -

RUN cd /usr/src/gtest                                                 && \
    cmake CMakeLists.txt                                              && \
    make                                                              && \
    cp lib/*.a /usr/lib                                               && \
    cd -

CMD bash
