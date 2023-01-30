libmsg: matrix.o msg_solver.o
	ar rvs libmsg.a $^
matrix.o: matrix.c matrix.h
msg_solver.o: msg_solver.c msg_solver.h matrix.h
	 $(CC) -c msg_solver.c -lm

.PHONY: clean

clean:
	-rm *.o libmsg.a
