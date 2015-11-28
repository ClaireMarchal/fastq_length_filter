
NAME = fastq_length_filter

CC = gcc

FLAGS = -Werror -Wall -Wextra

SRC = fastq_length_filter.c

all: $(NAME)

$(NAME):	
	@ (cd src/ && $(CC) $(FLAGS) $(SRC) -o ../$(NAME))

fclean:	
	@ /bin/rm -f $(NAME)

re:	fclean all

.PHONY: all fastq_length_filter fclean re

