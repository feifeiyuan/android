#include <linux/init.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>

static struct kobject *k_obj = NULL;
static char clusert0_power[20] = {0};
static char clusert1_power[20] = {0};
static char clusert2_power[20] = {0};
static char fcm_power[20] = {0};

static ssize_t cluster0_power_show(struct kobject *kobj, struct kobj_attribute *attr, char * buf){
    return sprintf(buf, "%s", clusert0_power);
}

static ssize_t cluster0_power_store(struct kobject *kobj, struct kobj_attribute *attr, const char * buf, size_t count){
    sprintf(clusert0_power, "%s", buf);
    return count;
}

static ssize_t cluster1_power_show(struct kobject *kobj, struct kobj_attribute *attr, char * buf){
    return sprintf(buf, "%s", clusert1_power);
}

static ssize_t cluster1_power_store(struct kobject *kobj, struct kobj_attribute *attr, const char * buf, size_t count){
    sprintf(clusert1_power, "%s", buf);
    return count;
}

static ssize_t cluster2_power_show(struct kobject *kobj, struct kobj_attribute *attr, char * buf){
    return sprintf(buf, "%s", clusert2_power);
}

static ssize_t cluster2_power_store(struct kobject *kobj, struct kobj_attribute *attr, const char * buf, size_t count){
    sprintf(clusert2_power, "%s", buf);
    return count;
}

static ssize_t fcm_power_show(struct kobject *kobj, struct kobj_attribute *attr, char * buf){
    return sprintf(buf, "%s", fcm_power);
}

static ssize_t fcm_power_store(struct kobject *kobj, struct kobj_attribute *attr, const char * buf, size_t count){
    sprintf(fcm_power, "%s", buf);
    return count;
}

static struct kobj_attribute  cluster0_power_attribute=__ATTR(cluster0_power, S_IWUSR|S_IRUGO, cluster0_power_show, cluster0_power_store);
static struct kobj_attribute  cluster1_power_attribute=__ATTR(cluster1_power, S_IWUSR|S_IRUGO, cluster1_power_show, cluster1_power_store);
static struct kobj_attribute  cluster2_power_attribute=__ATTR(cluster2_power, S_IWUSR|S_IRUGO, cluster2_power_show, cluster2_power_store);
static struct kobj_attribute  fcm_power_attribute=__ATTR(fcm_power, S_IWUSR|S_IRUGO, fcm_power_show, fcm_power_store);

static struct attribute *cpu_power_attributes[] = {
    &cluster0_power_attribute.attr,
    &cluster1_power_attribute.attr,
    &cluster2_power_attribute.attr,
    &fcm_power_attribute.attr,
    NULL
};

static const struct attribute_group cpu_power_attr_group = {
    .attrs = cpu_power_attributes,
};   

static int __init cpu_power_init(void){
    if ((k_obj = kobject_create_and_add("cpu_power", NULL)) == NULL ) {
        printk("cpu_power sys node create error \n");
        goto out;
    }

    if(sysfs_create_group(k_obj, &cpu_power_attr_group) ) {
        printk("sysfs_create_group failed\n");
        goto out2;
    }

    return 0;
out2:
    kobject_put(k_obj);
out:
    return -1;
}

static void __exit cpu_power_exit(void){
    if (k_obj) {
        sysfs_remove_group(k_obj, &cpu_power_attr_group);
        kobject_put(k_obj);
    }
    return;
}

module_init(cpu_power_init);
module_exit(cpu_power_exit);

MODULE_LICENSE("GPL");
