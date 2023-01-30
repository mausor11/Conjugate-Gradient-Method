aproxgradient: main.o splines.o points.o aproksymator_na_bazie_gradient.o msg/libmsg.a 
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie_gradient.o -L msg -l msg -lm

aproxgaus: main.o splines.o points.o aproksymator_na_bazie_gaus.o gaus/libge.a
	$(CC) -o aprox main.o splines.o points.o aproksymator_na_bazie_gaus.o -L gaus -l ge

intrp: main.o splines.o points.o interpolator.o gaus/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L gaus -l ge -lm

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie_gradient.o: makespl.h points.h msg/msg_solver.h
	$(CC) -I msg -c aproksymator_na_bazie_gradient.c

aproksymator_na_bazie_gaus.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator_na_bazie_gaus.c 

interpolator.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c interpolator.c

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta *.txt
