# Linux-Capabilties
Capabilties unter Linux haben das Ziel, Berechtigungen granularer als ein:  `if([E]UID == 0) ...` zu gestalten.  
Diese jedoch (leider) immer noch nur ein POSIX-Draft.   
Die Funktionalität ist einerseits durch das zerstückeln der Berechtigungen von root und andererseits durch das zuweisen von benötigten Berechtigungen um Syscalls im Kernel auszuführen.

Die Capabilties werden in vier Capabiltiy-Sets aufgeteilt: 
- Permitted: Capabilties die sich eine Applikation aktiv setzen darf.
- Effective: Capabilties die in einer Applikation aktiviert sind.
- Inheritable: Capabilties die an Sub-Prozesse vererbt werden dürfen. Dabei dürfen diese wiede weitervererbt werden, und können effective gesetzt werden
- Ambient: Sind etwas speziell --> Man Page oder andere Ressourcen liefen besseren Überblick

Weiters existiert ein Capabilty-Bounding-Set, welches festlegt, welche Capabilties überhaupt verwendet werden können bei einem execve (Syscall um Programme aufzurufen)

Um alle Capabilties anzuzeigen (im aktuellen Bounding-Set):  
```
chris5011@ubuntu:~/memory_protection/capabilities$ capsh --print
Current: =
Bounding set =cap_chown,cap_dac_override,cap_dac_read_search,cap_fowner,cap_fsetid,  
cap_kill,cap_setgid,cap_setuid,cap_setpcap,cap_linux_immutable,cap_net_bind_service,  
cap_net_broadcast,cap_net_admin,cap_net_raw,cap_ipc_lock,cap_ipc_owner,cap_sys_module,  
cap_sys_rawio,cap_sys_chroot,cap_sys_ptrace,cap_sys_pacct,cap_sys_admin,cap_sys_boot,  
cap_sys_nice,cap_sys_resource,cap_sys_time,cap_sys_tty_config,cap_mknod,cap_lease,  
cap_audit_write,cap_audit_control,cap_setfcap,cap_mac_override,cap_mac_admin,cap_syslog,  
cap_wake_alarm,cap_block_suspend,cap_audit_read,cap_perfmon,cap_bpf,cap_checkpoint_restore
Ambient set =
Current IAB:
Securebits: 00/0x0/1'b0
 secure-noroot: no (unlocked)
 secure-no-suid-fixup: no (unlocked)
 secure-keep-caps: no (unlocked)
 secure-no-ambient-raise: no (unlocked)
uid=1000(chris5011) euid=1000(chris5011)
gid=1000(chris5011)
groups=4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),110(lxd),1000(chris5011)
Guessed mode: UNCERTAIN (0)```







