CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS = Game.o HealRoom.o Item.o NormalRoom.o Player.o Source.o Space.o TrapRoom.o WinningRoom.o
SRCS = Game.cpp HealRoom.cpp Item.cpp NormalRoom.cpp Player.cpp Source.cpp Space.cpp TrapRoom.cpp WinningRoom.cpp
HEADERS = Game.hpp HealRoom.hpp Item.hpp NormalRoom.hpp Player.hpp Space.hpp TrapRoom.hpp WinningRoom.hpp


finalProject: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o finalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f ${OBJS}
	rm -f finalProject
