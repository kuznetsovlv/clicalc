#Makefile
srcDir = ./src
testDir = ./tests

.PHONY: all test build clean
all: test build

test:
	cd $(testDir) && make test

build:
	cd $(srcDir) && make all

clean:
	sh ./clean.sh $(srcDir)
	sh ./clean.sh $(testDir)
