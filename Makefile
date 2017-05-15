build/DataGen: src/DataGen.cpp
	g++ src/DataGen.cpp -o build/DataGen

genData:
	./build/DataGen

clean:
	rm -rf ./build/*
