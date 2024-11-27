# Быстрая сборка
```bash
g++ -v compilation.cpp
./a.out
```

# Препроцессинг
В файл исходного кода добавляем заголовочные файлы и раскрываем макросы
```bash
cpp compilation.cpp > compilation.i
```
Листаем в конец файла `compilation.i` и изучаем результат препроцессинга.

# Компиляция
Единица трансляции преобразуется в код языке ассемблера
```bash
g++ -fno-use-cxa-atexit -S compilation.i
```

При сборке нужно использовать ключ (-fno-use-cxa-atexit)[https://stackoverflow.com/questions/34308720/where-is-dso-handle-defined]

Момент в исходниках https://github.com/gcc-mirror/gcc/blob/9693459e030977d6e906ea7eb587ed09ee4fddbd/libgcc/config/vxcrtstuff.c#L73

Ознакомимся с содержимым файла `compilation.s`

# Ассемблирование
Команды на языке ассемблера преобразуются в машинный код.
Добавляеся информацию о символах - имена функций, которые мы используем в программе
ДОбавляется информация о внешних библиотечных функциях
```bash
as -o compilation.o compilation.s
```
Ознакомимся с содержимым файла `compilation.o` с помощью программы (radare2)[https://ru.wikipedia.org/wiki/Radare2]
```bash
radare2 compilation.o
aa
pdf
q
```

# Линковка
Добавляется информация о внешних зависимостях (где и как их взять)
```bash
# exit(0);
ld -e main -o compilation compilation.o /usr/lib/x86_64-linux-gnu/libstdc++.so.6 -lc -I /lib64/ld-linux-x86-64.so.2
# return 0;
ld -o compilation compilation.o /usr/lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/12/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/12 -L/usr/lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/12/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/12/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/crtn.o -I /lib64/ld-linux-x86-64.so.2
./compilation
```
