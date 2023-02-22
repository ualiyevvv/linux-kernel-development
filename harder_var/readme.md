# Kernel Module Project - File Writer and File Reader

This is a sample project that includes two kernel modules, `file_writer` and `file_reader`, which communicate with each other via debugfs. The `file_writer` module allows data to be written to a buffer, which can then be read by the `file_reader` module.

## Prerequisites

To build and use these kernel modules, you will need a Linux system with kernel headers installed.

## Building the Modules

To build the kernel modules, navigate to the module directories and run the following command:

```
make
```

This will generate the kernel modules `file_writer.ko` and `file_reader.ko`.

## Installing the Modules

To install the kernel modules, run the following commands:

```
sudo insmod file_writer.ko
```
```
sudo insmod file_reader.ko
```


This will insert the `file_writer` and `file_reader` modules into the kernel.

## Using the Modules

Once the modules are installed, you can interact with them using the files in the debugfs filesystem. The `file_writer` module exposes a file named `file_writer` in the debugfs filesystem, which can be used to write data to the buffer. The `file_reader` module exposes a file named `file_reader` in the debugfs filesystem, which can be used to read data from the buffer.

To write data to the buffer using the `file_writer` module, simply write the data to the `file_writer` file in the debugfs filesystem:

```
echo "Hello, world!" > /sys/kernel/debug/file_writer
```

To read the data from the buffer using the `file_reader` module, simply read the `file_reader` file in the debugfs filesystem:

```
cat /sys/kernel/debug/file_reader
```

## Removing the Modules

To remove the kernel modules, run the following commands:

```
sudo rmmod file_reader
```
```
sudo rmmod file_writer
```

This will remove the `file_reader` and `file_writer` modules from the kernel.

## Team 
```
 ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄   ▄▄ 
█       █  ▄    █       █  █       █       █      █  █▄█  █ 
█   ▄   █ █▄█   █    ▄  █  █▄     ▄█    ▄▄▄█  ▄   █       █ 
█  █▄█  █       █   █▄█ █    █   █ █   █▄▄▄█ █▄█  █       █ 
█       █  ▄   ██    ▄▄▄█    █   █ █    ▄▄▄█      █       █ 
█   ▄   █ █▄█   █   █        █   █ █   █▄▄▄█  ▄   █ ██▄██ █ 
█▄▄█ █▄▄█▄▄▄▄▄▄▄█▄▄▄█        █▄▄▄█ █▄▄▄▄▄▄▄█▄█ █▄▄█▄█   █▄█ 
```





