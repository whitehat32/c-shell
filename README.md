# c-shell
使用：make后可以生成main,使用./main运行即可
目前支持的功能：
1）cd xxx 
进入某个目录（上述代码会进入xxx目录）。 
2）exit 退出 shell 程序。 
3）显示历史命令  !# 所有输入的命令都保存在一个log_t中，这个命令的作用是显示所有输入过的命令(不包括带!的命令)。
4）根据前缀查找命令 !prefix 查找是否曾经输入过包含前缀prefix的命令，如果找到（如果有多个，只找最靠近栈底的一个），则执行这条命令，如果没有，则返回No Match换行。
5）ls 跟 bash shell 的ls命令一样，列举当年目录下所有子目录和文件
6）执行外部命令 你需要使用fork()和exec()等函数来执行一个外部命令——如果执行失败，输出%s: no such command换行。
