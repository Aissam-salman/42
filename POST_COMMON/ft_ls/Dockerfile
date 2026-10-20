FROM fedora:latest

RUN dnf install -y gcc make valgrind gdb man-pages \
	&& dnf clean all

WORKDIR /ft_ls
