#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 256

static char buffer[BUFFER_SIZE];

static ssize_t read_file(struct file *file, char *buf, size_t count, loff_t *ppos) {
    ssize_t bytes_read = 0;

    // Copy data from kernel space buffer into user space buffer
    bytes_read = simple_read_from_buffer(buf, count, ppos, buffer, BUFFER_SIZE);

    if (bytes_read < 0) {
        pr_err("Failed to read data from buffer\n");
        return bytes_read;
    }

    pr_info("Read %zd bytes from buffer\n", bytes_read);
    return bytes_read;
}

static const struct file_operations file_ops = {
    .owner = THIS_MODULE,
    .read = read_file,
};

static struct dentry *file_dentry;

static int __init file_reader_init(void) {
    file_dentry = debugfs_create_file("file_reader", 0444, NULL, NULL, &file_ops);
    if (!file_dentry) {
        pr_err("Failed to create debugfs file entry\n");
        return -ENOMEM;
    }

    pr_info("File reader module loaded\n");
    return 0;
}

static void __exit file_reader_exit(void) {
    debugfs_remove(file_dentry);
    pr_info("File reader module unloaded\n");
}

module_init(file_reader_init);
module_exit(file_reader_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("File reader module");
