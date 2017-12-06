# 编译时拷贝至目标目录
PRODUCT_COPY_FILES += \
		       device/sprd/xxx/common/myshell.sh:system/bin/myshell.sh
原始文件位置：device/sprd/xxx/common/myshell.sh
目标文件位置：system/bin/myshell.sh
备注：拷贝文件一般放在device下，且需要编译systemimage
