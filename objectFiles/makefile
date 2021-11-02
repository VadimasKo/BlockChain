ObjectFiles = Main.o GenerateRandom.o GenerateHash.o MerkelTree.o User.o Transactions.o TransactionPool.o


main: $(ObjectFiles)
	g++ -o blockchain.exe $(ObjectFiles)
	mv blockchain.exe ../
	