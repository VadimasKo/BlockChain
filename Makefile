CPPcompiler=g++
ObjectFiles=Main.o


main: $(ObjectFiles)
	$(CPPcompiler) -o blockchain.exe $(ObjectFiles)

%.o: %.cpp
	$(CPPcompiler) -c  $< -o $@

clear:
	rm *.o

