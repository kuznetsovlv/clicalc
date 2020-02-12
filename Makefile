#Makefile
srcDir = ./src
testDir = ./test/support
#tests = 

#.PHONY: tests $(tests) clean
#test: $(tests)

test/support:
	mkdir -p $(testDir)

clean:
	cd $(srcDir) && make clean
