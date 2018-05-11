CC:=clang++
CFLAGS:=-Wall -std=c++17
OUTPUTDIR:=./out
OBJDIR:=${OUTPUTDIR}/obj
BINDIR:=${OUTPUTDIR}/bin
SRCS:=$(wildcard *.cpp)
OBJS:=$(SRCS:.cpp=.o)
OBJS:=$(addprefix ${OBJDIR}/,${OBJS})
ALL_TARGET:=$(basename ${SRCS})
ALL_TARGET:=$(addprefix ${BINDIR}/,${ALL_TARGET})

.PHONY:all
all:${ALL_TARGET}

${OBJS}:|${OBJDIR}
${OBJDIR}:
	mkdir -p ${OBJDIR}
${ALL_TARGET}:|${BINDIR}
${BINDIR}:
	mkdir -p ${BINDIR}

${ALL_TARGET}:${BINDIR}/%:${OBJDIR}/%.o
	${CC} ${CFLAGS} $< -o $@
${OBJDIR}/%.o:%.cpp
	${CC} ${CFLAGS} -c $< -o $@

.PHONY:clean
clean:
	rm -rf ${ALL_TARGET} ${OBJS} ${OBJDIR} ${BINDIR}

