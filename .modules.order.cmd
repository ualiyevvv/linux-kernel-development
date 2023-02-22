cmd_/root/develop/kernel/hello-1/modules.order := {   echo /root/develop/kernel/hello-1/hello.ko; :; } | awk '!x[$$0]++' - > /root/develop/kernel/hello-1/modules.order
