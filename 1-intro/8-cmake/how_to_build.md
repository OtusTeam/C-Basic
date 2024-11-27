# example0_gnu_make
Сборка проекта:
```bash
cd example0_gnu_make
make
```

Удаление результатов сборки:
```bash
make clean
```

# example1, example2, example3

Сборка с системой сборки по умолчанию:
```bash
cd example1
mkdir build; cd build
cmake ..
cmake --build .
```

Сборка с системой сборки `ninja`:
```bash
cd example1
mkdir build; cd build
cmake .. -G "Ninja"
cmake --build .
```

# example4

Собираем `sumLib` и устанавливаем в директорию `install`:
```bash
cd example4
mkdir /tmp/install
cd sumLib
mkdir build; cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/tmp/install
cmake --build . --target install
```

Собираем исполняемый модуль. Передаем путь к установленным библиотекам через `CMAKE_PREFIX_PATH`:
```bash
cd ../..
mkdir build; cd build
cmake .. -DCMAKE_PREFIX_PATH=/tmp/install
cmake --build .
```

# example5
`example5/cmake/FindsumLib.cmake` используем переменные окружения, чтобы найти требуемые библиотеки.

Задаем переменную окружения:
```bash
export SUMLIBDIR=/tmp/install
```

`find_package` найдет библиотеки и установит пути до них. Соберем пример:
```bash
cd example5
mkdir build; cd build
cmake ..
cmake --build .
```

# example6
```bash
cd example6
mkdir build; cd build
```

Используйте параметр `-DBUILD_EXAMPLES=ON` чтобы собрать примеры, и `-DBUILD_EXAMPLES=OFF` чтобы не собирать их:
```bash
cmake .. -DBUILD_EXAMPLES=ON
cmake --build .
```

# example7

```bash
cd example7
mkdir build; cd build
cmake ..
cmake --build .
```
