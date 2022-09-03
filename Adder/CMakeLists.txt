add_library(add add.cpp)

install(TARGETS add DESTINATION lib)
install(FILES add.h DESTINATION include)