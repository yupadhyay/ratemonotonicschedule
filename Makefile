                                                       
                                                                     
PROJECT = Assignment3

TARGET = eval

#Human generated files (should be submitted).
SRC_FILES = \
  testCase1.c \
  testCase2.c \
  testCase3.c \
  testCase4.c \
  README.txt \
  sched.c    \
  sched_periodic.c \
  sched.h \
  Makefile

#Object files.
OBJS = \
  testCase1.o \
  testCase2.o \
  testCase3.o \
  testCase4.o \

CC = gcc
CFLAGS = -g
LIBS = -lrt

#This target builds the main executable for the project.
all:		$(TARGET)

$(TARGET):  	$(OBJS)
		$(CC) $(OBJS) $(LIBS) -o $@

testCase1:	testCase1.c
		$(CC) $(CFLAG) testCase1.c -o $@
testCase2:	testCase2.c
		$(CC) $(CFLAG) testCase2.c -o $@
testCase3:	testCase3.c
		$(CC) $(CFLAG) testCase3.c -o $@
testCase4:	testCase4.c
		$(CC) $(CFLAG) testCase4.c -o $@



#Removes all objects and executables.
clean:
		rm -f $(OBJS) $(TARGET) testCase1 *~
		rm -f $(OBJS) $(TARGET) testCase2 *~
		rm -f $(OBJS) $(TARGET) testCase3 *~
		rm -f $(OBJS) $(TARGET) testCase4 *~
		

#This target makes a archive containing all the project source files,
#suitable for submission.
submit:		$(SRC_FILES)
		tar -cvf $(PROJECT).tar $(SRC_FILES)
		gzip $(PROJECT).tar

#This target outputs dependencies of all C files on stdout.  The output can
#then be cut-and-pasted into this Makefile.
DEPEND:
		$(CC) -MM *.c

#Automatically produced dependencies pasted in from output of 'make DEPEND'.
testCase1.o: testCase1.c
testCase2.o: testCase2.c
testCase3.o: testCase3.c
testCase4.o: testCase4.c




