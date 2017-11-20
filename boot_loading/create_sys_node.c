#include <linux/init.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
static struct kobject *k_obj = NULL;
static char cpu_total_buf[20] = {0};

static ssize_t sysfs_demo_show_cpu_total(struct kobject *kobj, struct kobj_attribute *attr, char * buf){
	return sprintf(buf, "%s\n", cpu_total_buf);
}

static ssize_t sysfs_demo_store_cpu_total(struct kobject *kobj, struct kobj_attribute *attr, const char * buf, size_t n){
	sprintf(cpu_total_buf, "%s", buf);
	return n;
}
static struct kobj_attribute cpu_total_attribute =
    __ATTR(cpu_total, S_IWUSR|S_IRUGO, sysfs_demo_show_cpu_total, sysfs_demo_store_cpu_total);


static struct attribute *sysfs_demo_attributes[] = {
    &cpu_total_attribute.attr,
    NULL
};

static const struct attribute_group sysfs_demo_attr_group = {
    .attrs = sysfs_demo_attributes,
};   

static int __init sysfs_demo_init(void){
    if ((k_obj = kobject_create_and_add("cpu_loading", NULL)) == NULL ) {
        printk("sysfs_demo sys node create error \n");
        goto out;
    }

    if(sysfs_create_group(k_obj, &sysfs_demo_attr_group) ) {
        printk("sysfs_create_group failed\n");
        goto out2;
    }

    return 0;
out2:
    kobject_put(k_obj);
out:
    return -1;
}

static void __exit sysfs_demo_exit(void){
    if (k_obj) {
        sysfs_remove_group(k_obj, &sysfs_demo_attr_group);
        kobject_put(k_obj);
    }
    return;
}

module_init(sysfs_demo_init);
module_exit(sysfs_demo_exit);

MODULE_LICENSE("GPL");
