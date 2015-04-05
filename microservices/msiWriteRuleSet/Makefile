GCC = g++

INC=-I/usr/include/irods/ -I/usr/include/irods/boost/

all: libmsiWriteRuleSet

libmsiWriteRuleSet:
	${GCC} ${INC} -DRODS_SERVER -fPIC -shared -g -Wno-deprecated -o $@.so $@.cpp /usr/lib/irods/libirods_client.a

clean:
	@rm -f ./*.so
