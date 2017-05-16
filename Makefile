build/DataGen: src/DataGen.cpp
	g++ src/DataGen.cpp -o build/DataGen

genData:
	rm -rf ./data/*; cd ./build; ./DataGen

clean:
	rm -rf ./build/*
