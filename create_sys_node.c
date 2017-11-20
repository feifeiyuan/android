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
