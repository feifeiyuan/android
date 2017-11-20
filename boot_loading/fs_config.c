static const struct fs_path_config android_files[] = {
# system 只以只读的形式挂载，需要在android_files中赋予权限
	{ 00755, AID_ROOT,      AID_SHELL,     0, "system/bin/myshell.sh" },
