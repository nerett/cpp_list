DEPENDENCIES =

CC = g++
CFLAGS = -c #-fsanitize=address #-Wall -Wextra -g
LDFLAGS = #-fsanitize=address #-Wall -Wextra -g
BUILDDIR = Build/
EXECDIR = Debug/

EXECNAME = cpp_list


#------------------------------------BUILDING-----------------------------------------------
all: mkdir main
	$(CC) $(LDFLAGS) $(BUILDDIR)main.o $(BUILDDIR)libcpp_list.o -o $(EXECDIR)$(EXECNAME)
	
mkdir:
	mkdir -p Build Debug
	
main: libcpp_list
	$(CC) $(CFLAGS) main.cpp -o $(BUILDDIR)main.o


#-------------------------------------libcpp_stack------------------------------------------------
libcpp_list:
	$(CC) $(CFLAGS) cpp_list.cpp -o $(BUILDDIR)libcpp_list.o


#-----------------------------INSTALLING DEPENDENCIES----------------------------------------
install-dependencies:
	cd .. && git clone $(DEPENDENCIES)


#------------------------------------RUNNING-------------------------------------------------
run:
	./$(EXECDIR)$(EXECNAME) $(CPUCODEPATH)

rund:
	valgrind ./$(EXECDIR)$(EXECNAME)


#-----------------------------------CLEANING-------------------------------------------------
clean:
	rm -rf $(BUILDDIR) $(EXECDIR)
