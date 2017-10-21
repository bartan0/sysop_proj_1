cc = cc
c_opt = -Wall -Wpedantic -Werror -std=c99
l_opt = -pthread

out = x
obj = main.o

main_h =

all: $(out)

run: $(out)
	./$(out)

$(out): $(obj)
	$(cc) $(l_opt) -o $(out) $(obj)

main.o: main.c $(main_h)
	$(cc) -c $(c_opt) main.c

clean:
	rm -rf *.o

distclean: clean
	rm -rf $(out)
