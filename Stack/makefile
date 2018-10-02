CC:=g++
exe:=main
obj:=main.o stack.o convert.o

all:$(obj)
	$(CC) -o $(exe) $(obj)
stack.o: stack.cpp stack.h
	$(CC) -c stack.cpp
convert.o: convert.cpp convert.h
	$(CC) -c convert.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm -rvf $(obj)
