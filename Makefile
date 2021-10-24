NAME                =   primemodule

BINARY				=	${NAME}
LIBRARY				=   lib${NAME}.so

COMPILER            =   g++
COMPILER_FLAGS      =   -Wall -std=c++11 -fpic -finline-functions -ffast-math -O3 -o

RM                  =   rm -f
CP                  =   cp
MKDIR               =   mkdir -p

DESTDIR				?= "/usr"

all:                    ${BINARY} ${LIBRARY}

${BINARY}:	src/main.cpp src/${NAME}.hpp
			${COMPILER} ${COMPILER_FLAGS} $@ src/main.cpp

${LIBRARY}:	src/${NAME}.cpp src/${NAME}.hpp
			${COMPILER} -shared ${COMPILER_FLAGS} $@ src/${NAME}.cpp

install:	${BINARY} ${LIBRARY} src/${NAME}.hpp src/${NAME}.h
			${MKDIR} ${DESTDIR}/bin ${DESTDIR}/lib ${DESTDIR}/include
			${CP} ${BINARY} ${DESTDIR}/bin
			${CP} ${LIBRARY} ${DESTDIR}/lib
			${CP} src/primemodule.hpp src/primemodule.h src/primemodule-ffi.h ${DESTDIR}/include

clean:
			${RM} ${BINARY} ${LIBRARY}

