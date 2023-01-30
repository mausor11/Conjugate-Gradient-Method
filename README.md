# Conjugate gradient method

### Jak odpalić program?
1. Wchodzimy do folderu "gaus" oraz "msg" 
  i wpisujemy komende "make"
2. W folderze /lmp10 mamy do wyboru dwie opcje:
	a) metoda gaus -> komenda "make aproxgaus"
	b) metoda gradientu - > komenda "make aproxgradient"
3. Po dokonaniu kompilacji wpisujemy "./aprox"
4. Wybieramy potrzebne opcje:
	przykładowo: ./aprox -s spl -p test/dane.1 -g myplot -f 5.1 -t 5.7 -n 300
5. Odpalamy Gnuplot komendą "gnuplot"
6. Do wywołania wpisujemy komendę "plot 'test/dane.1','myplot' "

#### Przydatne informacje:
1. Wykresy porównujące metody znajdują się w folderze "Wykresy"
2. Dane do kompilacji znajdują się w folderze "test"


### How to run the program?
1. Go to the "gaus" and "msg" folders
  and enter the command "make"
2. In the /lmp10 folder, we have two options:
	a) gaus method -> "make aproxgaus" command
	b) gradient method - > "make aproxgradient" command
3. After compiling, enter command "./aprox" 
4. Select the required options:
	for example: ./aprox -s spl -p test/data.1 -g myplot -f 5.1 -t 5.7 -n 300
5. Launch Gnuplot with the command "gnuplot"
6. Enter the command "plot 'test/data.1','myplot' "

#### Useful information:
1. Graphs comparing the methods are in the "Wykresy" folder
2. Compilation data is in the "test" folder
