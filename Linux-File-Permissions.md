# Linux file system permissions - Recap: 
	
Linux verwendet standardmäßig DAC (Discressionary-Access-Control):  
D.h.: Benutzerbestimmbare Zugriffskontrolle - Zugriffskontrolle aufgrund der Identität des Users

## Aufbau der Berechtigungen: 
	
	-rwxrw-r-- 1 				chris5011 chris5011    0 Jan 18 21:53 test
	  u  g  o  lnks	     own		   grp		 				size		   date			name

**u**: user / owner of the file  
**g**: group / users in this group  
**o**: others / users which are not the owner or in a group this file belongs to  
**lnks**: Anzahl der (Hard-)Links auf dieses Objekt  
**own**: Besitzer des Objekts  
**grp**: Gruppenzugehörigkeit des Objekts  
**size**: Objektgröße  
**date**: Zeitpunkt der letzen Änderung  
**name**: Dateiname  

## Linux Berechtigungen: 

| **Permission / File System Object** | **File** | **Directory** |
|---|---|---|
| **r** | Allows the user to read the contents of the file | Allows the user to see the files in the directory, but no metadata (will yield some permission-denied) |
| **w** | Allows the user to write into the file, but not read it | Allows the user to manipulate directories in the directory, this bit was set |
| **x** | Does not do anything without r; When r-x is set, the file is executeable | Allows the user to cd into the directory and see the contained file-metadata |

Dateien können auch ausgeführt werden, wenn das x-bit nicht gesetzt ist: durch interpretieren des files mit `bash ./file`

## UID vs EUID:

In Linux Programmen existiert ein Unterschied zwischen der UID (User-ID) und der EUID (Effective User-ID)
Dabei ist der Unterschied beim gesetzten SUID-Bit ersichtlich - Wird eine Applikation mit dem SUID-Bit aufgerufen, dann wird die EUID auf die des Owners gesetzt, die UID selbst ist allerdings die des aufrufenden Users

## Spezial-Bits: 
Das Berechtigungssystem unter Linux kennt auch einige spezielle Bits: SUID, SGID und das Sticky-Bit

### SUID:
Das SUID-Bit wird verwendet um ausführbare Dateien als Owner der Datei auszuführen.
	--> EUID = UID des Besitzers  
Achtung: Nicht bei bash-scripts  
**Auf Directories hat dieses Bit keien Auswirkung!**	

	
### SGID:
Das SGID-Bit ist ähnlich zum SUID-Bit, nur das hier nicht die UID, sondern die GID (Group-ID) der besitzenden Gruppe verwendet wird  
**Auf Directories:** bewirkt dieses Bit, dass beim anlegen neuer Files die Gruppenzugehörigkeit die des übergeordneten Directories bekommt


### Sticky-Bit:
Das Sticky-Bit wirkt sich heutzutage nicht mehr auf Files aus, sondern nur mehr auf Directories. 
Dabei hat es den Nutzen, dass nur der Besitzer des Files (sowie root) eine Datei wieder löschen kann.

Damals unter UNIX: Verhinderte, dass eine Applikation aus dem Speicher entfernt wurde, und somit wieder schneller geladen wird.
	

