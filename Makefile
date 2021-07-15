CC = cc
LDSHARED = $(CC) -shared
SRCS = libfromfile.c
TARGET_SO = libfromfile.so

$(TARGET_SO): $(SRCS)
	$(LDSHARED) -o $@ $^ -fPIC -lm -I. -O3

main: main.c
	$(CC) -o $@ $^ -fPIC -L. -lfromfile -I. -O3