file(GLOB hdrs "*.h*") #????????? ? ?????????? hdrs ??? ????? ? ??????????? .h
file(GLOB srcs "*.cpp") #????????? ? ?????????? srcs ??? ????? ? ??????????? .cpp

add_library(${vectorlib} STATIC ${srcs} ${hdrs}) #??????? ??????????? ?????????? ? ?????? ?? ?????????? ${vectorlib}, ??????????? ? ???????????? CMake ????? (????????? ?????????? ??????????? ? ???????????), ? ??? ??????????? ????? ?? ?????????? ${srcs} ? ${hdrs}