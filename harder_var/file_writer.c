#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 256

static char buffer[BUFFER_SIZE];

static ssize_t write_file(struct file *file, const char *buf, size_t count, loff_t *ppos) {
    ssize_t bytes_written = 0;

    // Copy data from user space into kernel space buffer
    bytes_written = simple_write_to_buffer(buffer, BUFFER_SIZE, ppos, buf, count);

    if (bytes_written < 0) {
        pr_err("Failed to write data to buffer\n");
        return bytes_written;
    }

    pr_info("Wrote %zd bytes to buffer\n", bytes_written);
    return bytes_written;
}

static const struct file_operations file_ops = {
    .owner = THIS_MODULE,
    .write = write_file,
};

static struct dentry *file_dentry;

static int __init file_writer_init(void) {
    file_dentry = debugfs_create_file("file_writer", 0644, NULL, NULL, &file_ops);
    if (!file_dentry) {
        pr_err("Failed to create debugfs file entry\n");
        return -ENOMEM;
    }

    pr_info("File writer module loaded\n");
    return 0;
}

static void __exit file_writer_exit(void) {
    debugfs_remove(file_dentry);
    pr_info("File writer module unloaded\n");
}

module_init(file_writer_init);
module_exit(file_writer_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("File writer module");
