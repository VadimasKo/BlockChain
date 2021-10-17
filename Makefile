SRC_DIR = ./src

main:
	$(foreach file, $(wildcard $(SRC_DIR)/*), g++ -c $(file)/*.cpp;)
	mv *.o ./objectFiles
	make -C ./objectFiles

%.o: %.cpp
	$(CPPcompiler) -c  $< -o $@

clear:
	rm objectFiles/*.o
