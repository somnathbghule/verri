files=$(shell find . -name '*.cpp')
headers=$(shell find . -name '*.h')
objs=$(files:%.cpp=%.o)
CXX=g++ -I. -g
all:verri-practo
verri-practo:${objs} 
	${CXX} $^ -o verri-practo
%.o:%.c ${headers}
clean: 
	rm -rf verri-practo ${objs}
