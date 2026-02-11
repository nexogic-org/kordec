cmake_minimum_required(VERSION 4.1)
project(kordec C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(kordec src/main.c
        src/lexer/lexer.c
        src/lexer/lexer.h
        src/lexer/test.c
        src/parser/parser.c
        src/parser/parser.h
        src/parser/ast.c
        src/parser/ast.h
        src/semantic/semantic.c
        src/semantic/semantic.h
        src/semantic/test.c
        src/parser/test.c
        src/ir/ir.c
        src/ir/ir.h
        src/ir/test.c
        src/cli/cli.c
        src/cli/cli.h
        src/const.h
        src/runtime/stdlib/console.c
        src/runtime/stdlib/console.h
        src/runtime/stdlib/math.c
        src/runtime/stdlib/math.h
        src/runtime/stdlib/net.c
        src/runtime/stdlib/net.h
        src/runtime/stdlib/json.c
        src/runtime/stdlib/json.h
        src/runtime/gc/gc.c
        src/runtime/gc/gc.h
        src/codegen/codegen.c
        src/codegen/codegen.h
        src/optimizer/optimizer.c
        src/optimizer/optimizer.h
        include/koredec.h
        src/runtime/stdlib/string.c
        src/runtime/stdlib/string.h
        src/runtime/stdlib/io.c
        src/runtime/stdlib/io.h
        src/runtime/stdlib/util.c
        src/runtime/stdlib/util.h
        src/runtime/stdlib/time.c
        src/runtime/stdlib/time.h
        src/runtime/stdlib/dynlib.c
        src/runtime/stdlib/dynlib.h
        src/api/api.c
        src/api/api.h
        src/preprocessing/package.c
        src/preprocessing/package.h)
