src =get_next_line.c\
	#get_next_utils.c

name = lib.a
obj= $(src:.c=.o)

all : $(name)

$(name): $(obj)
	ar rcs $(name) $(obj)

clean : 
	rm -r $(obj)

fclean: clean
	rm -r lib.a

re : fclean all

