src =get_next_line.c\
	 get_next_line_utils.c


flag = -Wall -Wextra -Werror
name = lib.a
obj= $(src:.c=.o)

all : $(name)

$(name): $(obj)
	ar rcs $(name) $(obj)


clean : 
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re : fclean all

compile: 
	rm -f a.out 
	cc $(flag) main.c lib.a
	@echo "*******************************************"
	./a.out | cat -e

run: fclean all clean compile
	
