SRC_DIR = ./src


main:
	$(foreach file, $(wildcard $(SRC_DIR)/*), g++ -c $(file)/*.cpp;)
	mv *.o ./objectFiles
	make -C ./objectFiles

run: 
	make
	echo "\n\n"
	./blockchain.exe 

clear:
	rm objectFiles/*.o
