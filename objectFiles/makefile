ObjectFiles = Main.o GenerateRandom.o GenerateHash.o MerkelTree.o User.o Transactions.o Block.o


main: $(ObjectFiles)
	g++ -o blockchain.exe $(ObjectFiles)
	mv blockchain.exe ../
	