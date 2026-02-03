# Customised Virtual File System

- This project is used to emulate all functionalities provided by File systems.

### Platform required
    Windows NT platform OR Linux Distributions

### Architectural requirement
    Intel 32 bit processor

### User Interface
    Command User Interface

### SDK used
    None

### Technology used
    System Programming using C

### About Virtual File System

• In this project we emulate all data structures which are used by operating system to manage File system oriented tasks.

• As the name suggest its virtual because we maintain all records in Primary storage.

• In this project we create all data structures which required for File Subsystems as Inode Inode Table, File Table, UAREA, User File Descriptor Table, Super block, Disk Inode List Block, Data Block, Boot Block etc.

• We provide all implementations of necessary system calls and commands of File subsystem as Open, Close, Read, Write, Lseek, Create, RM, LS, Stat, Fstat etc.

• While providing the implementations of all above functionality we use our own data structures by referring Algorithms of UNIX operating system.

• By using this project we can get overview of UFS (UNIX File System) on any platform.

## Flow Diagram  :



|     Boot Block     |
|--------------------|
| Information[]      |



|    Super Block     |
|--------------------|
| TotalInodes        |
| FreeInodes         |


|                    UAREA                         |
|--------------------------------------------------|
| ProcessName                                      |
| UFDT[0] | UFDT[1] | UFDT[2] | ... | UFDT[19]     |
    |
    |  (File Descriptor)
    v
                
|      File Table       |
|-----------------------|
| ReadOffset            |
| WriteOffset           |
| Mode                  |
| ptrinode -------------+-------------------+|        
                                         |
                                         |
                                         v
|             Inode (DILB Linked List)          
|-------------------------------------------------|
| FileName                                        |
| InodeNumber                                     |
| FileSize                                        |
| ActualFileSize                                  |
| FileType                                        |
| ReferenceCount                                  |
| Permission                                      |
| Buffer ---------------> Actual File Data        |
| next  --------------------------------> Next Inode

## How to Run this project

#### “The system should have MinGW pre-installed to run this program.”

#### “Open the Command Prompt and go to the correct directory path.”
### Type command :
#### 1] gcc CVFS.cpp -o Myexe
#### 2] Myexe.exe

After that run below commands

### Help  :
#### Ashwini CVSF : > help

### Information of Specific Command  :
#### Ashwini CVSF : > man ls
(ls is a command name)

### Create  :
#### Ashwini CVSF : > creat Ganesh.txt 3 
(Ganesh.txt - file name, 3 is a permission for file operations : read - 1, write - 2, Execute - 4)

### View Created Files :
#### Ashwini CVSF : > ls

### Write :
#### Ashwini CVFS : > write 2 
(2 is a fd visible when file is created )

### Read  :
#### Ashwini CVFS : > read 3 10 
(here 3 is a fd and 10 is number of bytes that you want to read)

### Delete  :
#### Ashwini CVSF : > unlink Demo.txt

### To clear the Shell :
#### Ashwini CVSF : > clear

### For Exit from Project  :
#### Ashwini CVSF : > exit

