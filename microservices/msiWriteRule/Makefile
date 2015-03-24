GCC = g++

INC=-I/usr/include/irods/ -I/usr/include/irods/boost/

all: libmsiWriteRule

libmsiWriteRule:
	${GCC} ${INC} -DRODS_SERVER -fPIC -shared -g -Wno-deprecated -o $@.so $@.cpp /usr/lib/irods/libirods_client.a

clean:
	@rm -f ./*.so
