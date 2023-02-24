#include <linux/fsnotify.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static void my_callback(struct fsnotify_group *group, struct inode *inode,
                        struct fsnotify_mark *mark, u32 mask, const void *data,
                        int data_type)
{
    if (mask & FS_OPEN) {
        printk(KERN_INFO "Opened file: %s\n", inode->i_sb->s_id->name);
    }
}

static struct fsnotify_ops my_fsnotify_ops = {
    .handle_event = my_callback,
};

static struct fsnotify_group *my_fsnotify_group;

static int __init my_module_init(void)
{
    int ret;

    my_fsnotify_group = fsnotify_alloc_group(&my_fsnotify_ops, NULL);
    if (!my_fsnotify_group) {
        printk(KERN_ERR "Failed to allocate fsnotify group\n");
        return -ENOMEM;
    }

    ret = fsnotify_add_mark(my_fsnotify_group, FSNOTIFY_MARK_TYPE_INODE,
                            FS_OPEN, NULL, NULL);
    if (ret < 0) {
        printk(KERN_ERR "Failed to add fsnotify mark\n");
        fsnotify_put_group(my_fsnotify_group);
        return ret;
    }

    printk(KERN_INFO "Loaded module\n");

    return 0;
}

static void __exit my_module_exit(void)
{
    fsnotify_remove_mark(my_fsnotify_group, FSNOTIFY_MARK_TYPE_INODE, FS_OPEN, NULL, NULL);
    fsnotify_put_group(my_fsnotify_group);

    printk(KERN_INFO "Unloaded module\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");
