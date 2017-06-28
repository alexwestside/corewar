cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

include_directories(includes libft) # headers

link_directories(libft) # libraries

set(SOURCE_FILES main.c ft_name_comment.c ft_command.c valid.c open_read.c op.c hash.c ft_error.c collision.c)
add_executable(corewar ${SOURCE_FILES})

target_link_libraries(corewar libft.a) # linkage