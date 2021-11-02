SRC_DIR = ./src


main:
	$(foreach file, $(wildcard $(SRC_DIR)/*), g++ -c $(file)/*.cpp;)
	mv *.o ./objectFiles
	make -C ./objectFiles

run: 
	make
	clear
	./blockchain.exe 

clear:
	rm objectFiles/*.o
