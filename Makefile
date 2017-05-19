all: build/DataGen build/Murmur build/Tabulation build/Stat 

build/DataGen: src/DataGen.cpp src/Common.h
	g++ src/DataGen.cpp -g -o build/DataGen

build/Murmur: src/Murmur.cpp src/Common.h
	g++ src/Murmur.cpp -g -o build/Murmur

build/Tabulation: src/Tabulation.cpp src/Common.h
	g++ src/Tabulation.cpp -g -o build/Tabulation

build/Stat: src/Stat.cpp src/Common.h
	g++ src/Stat.cpp -g -o build/Stat

DataGen: build/DataGen
	rm -rf ./data/*.key; cd ./build; ./DataGen

murHash: build/Murmur
	rm -rf ./data/*_Mur.hash; cd ./build; time ./Murmur

tabHash:
	rm -rf ./data/*_Tab.hash; cd ./build; time ./Tabulation

stat: build/Stat
	cd ./build; ./Stat

clean:
	rm -rf ./build/*
