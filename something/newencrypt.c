#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/syscalls.h>
#include <linux/vmalloc.h>
SYSCALL_DEFINE2(s2_encrypt, char __user *, original, int, key){
int i = 0;
char *s1;
long copy;
int len = strnlen_user(original, 256);
if(key < 1 || key > 5){
	return -EINVAL;
}
s1 = vmalloc(len);
copy = copy_from_user(s1, original, len);
if(copy < 0){
return -1;
}
else{
while(s1[i] != '\0'){
s1[i] = s1[i] + key;
i++;
}
}
printk("Result : %s\n", s1);
vfree(s1);
return 0;
}
