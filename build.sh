#!/bin/bash

defines="-DENGINE"
warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations -Wno-switch"
includes="-Ithird_party -Ithirdparty/Include"

timestamp=$(date +%s)

if [[ "$(uname)" == "Linux" ]]; then
    echo "Running on Linux"
    libs="-lX11 -lGL -lfreetype"
    outputFile=schnitzel

    # fPIC position independent code https://stackoverflow.com/questions/5311515/gcc-fpic-option
    rm -f game* # Remove old game* files
    clang++ -g "src/game.cpp" -shared -fPIC -o game$timestamp.so $warnings $defines
    mv game_$timestamp.so game.so

elif [[ "$(uname)" == "Darwin" ]]; then
    echo "Mac is not supported yet!"

else
    echo "Running on Windows"
    libs="-luser32 -lopengl32 -lgdi32 -lole32 -Lthirdparty/lib -lfreetype.lib"
    outputFile=schnitzel.exe

    rm -f game* # Remove old game* files
    clang++ -g "src/game.cpp" -shared -o game$timestamp.dll $warnings $defines
    mv game_$timestamp.dll game.dll
fi


clang++ $includes -g src/main.cpp -o$outputFile $libs $warnings $defines