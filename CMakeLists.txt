cmake_minimum_required(VERSION 3.15)
project(fuzzy VERSION 0.1)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(core)
include_directories(fuzzy)

add_library(
    fuzzy STATIC
    core/BinaryExpression.h
    core/BinaryExpressionModel.h
    core/BinaryShadowExpression.h
    core/Expression.h
    core/ExpressionFactory.h
    core/NaryExpression.h
    core/NaryExpressionModel.h
    core/NaryShadowExpression.h
    core/UnaryExpression.h
    core/UnaryExpressionModel.h
    core/UnaryShadowExpression.h
    core/ValueModel.h
    fuzzy/FuzzyFactory
    fuzzy/Operator.h
    main.cpp
)

add_executable(fuzzy_test
        core/BinaryExpression.h
        core/Expression.h
        core/UnaryExpression.h
        core/ValueModel.h
        fuzzy/Operator.h
        core/UnaryExpressionModel.h
        core/BinaryExpressionModel.h
        main.cpp core/UnaryShadowExpression.h core/BinaryShadowExpression.h core/ExpressionFactory.h fuzzy/FuzzyFactory.h core/NaryExpression.h core/NaryExpressionModel.h
)

target_link_libraries(fuzzy PRIVATE)
target_include_directories(fuzzy PRIVATE .)
set_target_properties(fuzzy PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)
#    PUBLIC_HEADER "core/BinaryExpression.h;core/BinaryExpressionModel.h;core/BinaryShadowExpression.h;core/Expression.h;core/ExpressionFactory.h;core/NaryExpression.h;core/NaryExpressionModel.h;core/NaryShadowExpression.h;core/UnaryExpression.h;core/UnaryExpressionModel.h;core/UnaryShadowExpression.h;core/ValueModel.h;fuzzy/FuzzyFactory.h;fuzzy/Operator.h;")
configure_file(fuzzy.pc.in fuzzy.pc @ONLY)
install(TARGETS fuzzy
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(
    DIRECTORY fuzzy DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
    DIRECTORY core DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${CMAKE_BINARY_DIR}/fuzzy.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
