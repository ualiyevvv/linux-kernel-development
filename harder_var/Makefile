# Имя модуля
MODULE = debugfs_example

# Общие флаги компиляции
EXTRA_CFLAGS += -Werror

# Исходные файлы
SRC_WRITER = file_writer.c
SRC_READER = file_reader.c

# Объектные файлы
OBJ_WRITER = $(SRC_WRITER:.c=.o)
OBJ_READER = $(SRC_READER:.c=.o)

# Конфигурация ядра
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Цели по умолчанию
default: all

# Сборка модулей
all: writer reader

writer: $(OBJ_WRITER)
    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

reader: $(OBJ_READER)
    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

# Очистка
clean:
    $(MAKE) -C $(KERNELDIR) M=$(PWD) clean

# Зависимости
$(OBJ_WRITER): $(SRC_WRITER)
$(OBJ_READER): $(SRC_READER)

# Установка
install:
    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

# Вызов из оболочки
.PHONY: all clean writer reader install
