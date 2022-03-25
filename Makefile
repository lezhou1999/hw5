all:
	
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests
	g++  --std=c++14 BetterPriorityQueue.cpp BPQTests.cpp Graph.cpp -o bpq-tests
	

	



