all: build/DataGen build/Murmur build/Tabulation

build/DataGen: src/DataGen.cpp src/Common.h
	g++ src/DataGen.cpp -g -o build/DataGen

build/Murmur: src/Murmur.cpp src/Common.h
	g++ src/Murmur.cpp -g -o build/Murmur

build/Tabulation: src/Tabulation.cpp src/Common.h
	g++ src/Tabulation.cpp -g -o build/Tabulation

DataGen:
	rm -rf ./data/*.key; cd ./build; ./DataGen

murHash:
	rm -rf ./data/*_Mur.hash; cd ./build; time ./Murmur

tabHash:
	rm -rf ./data/*_Tab.hash; cd ./build; time ./Tabulation

clean:
	rm -rf ./build/*
