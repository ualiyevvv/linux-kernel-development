# Загрузить модуль file_writer.c
$ sudo insmod file_writer.ko

# Загрузить модуль file_reader.c
$ sudo insmod file_reader.ko

# Записать строку в буфер
$ echo "Hello, kernel!" | sudo tee /sys/kernel/debug/file_writer

# Проверить содержимое буфера
$ cat /sys/kernel/debug/file_reader
