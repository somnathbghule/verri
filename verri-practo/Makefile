files=$(shell find . -name '*.cpp')
headers=$(shell find . -name '*.h')
objs=$(files:%.cpp=%.o)
CXX=g++ -I. -g
LDFLAGS=-lpthread
all:verri-practo
verri-practo:${objs} ${headers}
	${CXX} $^ -o verri-practo ${LDFLAGS}
%.o:%.c ${headers}
clean: 
	rm -rf verri-practo 
