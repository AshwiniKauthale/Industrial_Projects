/////////////////////////////////////////////////////////////////////////////////
//
//      Header File Inclusion
//
/////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<fcntl.h>

////////////////////////////////////////////////////////////////////////////////
//
//      User defined Macros
//
///////////////////////////////////////////////////////////////////////////////

// Maximum file size that we allow in the project
#define MAXFILESIZE 50

#define MAXOPENFILES 20

#define MAXINODE 10

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

#define REGULARFILE 1
#define SPECIALFILE 2

////////////////////////////////////////////////////////////////////////////////
//
//      User defined Macros for error handling
//
///////////////////////////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER -1

#define ERR_NO_INODES -2

#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4

#define ERR_PERMISSION_DENIDE -5

#define ERR_INSUFFICIENT_SPACE -6
#define ERR_INSUFFICIANT_DATA -7

#define ERR_MAX_FILES_OPEN -8

///////////////////////////////////////////////////////////////////////////////
//
//      User defined Structures
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//      Structure Name : BootBlock
//      Description :    Hold the information to boot the OS
//
///////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

///////////////////////////////////////////////////////////////////////////////
//
//      Structure Name : SuperBlock
//      Description :    Hold the information about the File System
//
///////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

///////////////////////////////////////////////////////////////////////////////
//
//      Structure Name : Inode
//      Description :    Hold the information about the File
//
///////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char *Buffer;               // Store actual data of file from Data Block
    struct Inode *next;
};

typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

///////////////////////////////////////////////////////////////////////////////
//
//      Structure Name : FileTable
//      Description :    Hold the information about opened file
//
///////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef FileTable FILETABLE;
typedef FileTable* PFILETABLE;         // Pointer Points to IIT

///////////////////////////////////////////////////////////////////////////////
//
//      Structure Name : UAREA
//      Description :    Hold the information about process
//
///////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];          // Array of Pointer in UAREA
};

///////////////////////////////////////////////////////////////////////////////
//
//      Global variables or objects used in the project
//
///////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareaobj;

PINODE head = NULL;

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  InitialiseUAREA
//      Description :    It is used to initialise UAREA member
//      Author :         Ashwini Vishnu Kauthale
//      Data :           13/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName,"Myexe");

    int i = 0;

    for(i = 0; i < MAXOPENFILES; i++)
    {
        uareaobj.UFDT[i] = NULL;
    }
    printf("Ashwini CVSF : UAREA gets initialized succesfully\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  InitialiseSuperBlock
//      Description :    It is used to initialise Super bloch member
//      Author :         Ashwini Vishnu Kauthale
//      Data :           13/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("Ashwini CVSF : Super block gets initialized succesfully\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  CreateDILB
//      Description :    It is used to create Linked list of inodes
//      Author :         Ashwini Vishnu Kauthale
//      Data :           13/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    for(i = 1; i <= MAXINODE; i++)
    {
        newn = (PINODE)malloc(sizeof(INODE));

        strcpy(newn->FileName,"\0");
        newn->InodeNumber = i;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->FileType = 0;
        newn->ReferenceCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL)    // LL is empty
        {
            head = newn;
            temp = newn;
        }
        else                // LL contains at least 1 node
        {
            temp->next = newn;
            temp = temp->next;
        }
    }
    printf("Ashwini CVSF : DILD created succesfully\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  StartAuxillaryDataInitilisation
//      Description :    It is used to call all such function which are
//                       used to initialise auxillary data
//      Author :         Ashwini Vishnu Kauthale
//      Data :           13/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitilisation()
{
    strcpy(bootobj.Information,"Booting process of Ashwini CVFS is done");

    printf("%s\n",bootobj.Information);

    InitialiseSuperBlock();
    CreateDILB();
    InitialiseUAREA();

    printf("Ashwini CVSF : Auxillary data initialised succesfully\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  DisplayHelp
//      Description :    It is used to display page
//                       used to initialise auxillary data
//      Author :         Ashwini Vishnu Kauthale
//      Data :           14/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    int fd = 0,iRet = 0;
    char Buffer[100] = {'\0'};

    fd = open("CVFS.txt",O_RDWR);

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,iRet);
    }

    close(fd);
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  ManPageDisplay
//      Description :    It is used to display man page
//                       used to initialise auxillary data
//      Author :         Ashwini Vishnu Kauthale
//      Data :           14/01/2026
//
///////////////////////////////////////////////////////////////////////////////

void ManPageDisplay(char Name[])
{
    if(strcmp("ls",Name) == 0)
    {
        printf("About : It is used to list the names of all files\n");
        printf("Usage : ls\n");
    }
    else if(strcmp("man",Name) == 0)
    {
        printf("About : It is used to display manual page\n");
        printf("Usage : man command_name\n");
        printf("command_name : It is the name of command\n");
    }
    else if(strcmp("creat",Name) == 0)
    {
        printf("About : It is used to create new File if it is not exist.\n");
        printf("\nUsage : int creat(const char *pathname, mode_t mode);\n");
        printf("\nReturn Value : On Success return fd, on error return -1");
    }
    else if(strcmp("write",Name) == 0)
    {
        printf("About : write() writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor fd.\n");
        printf("\nUsage :ssize_t write(int fd, const void buf[count], size_t count); \n");
        printf("\nReturn Value : On Success number of bytes written is returned, on error -1 is returned\n");
    }
    else if(strcmp("read",Name) == 0)
    {
        printf("About : read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.\n");
        printf("\nUsage : ssize_t read( int fd, void buf[count], size_t count);\n");
        printf("\nReturn Value : On Success number of bytes read is returned, on error -1 is returned\n");
    }
    else if(strcmp("stat",Name) == 0)
    {
        printf("About : These functions return information about a file, in the buffer pointed to by statbuf.\n");
        printf("\nUsage : int stat(const char *restrict path,struct stat *restrict statbuf);\n");
        printf("\nReturn Value : On Success return 0, on Failure return -1");
    }
    else if(strcmp("unlink",Name) == 0)
    {
        printf("About : unlink() deletes a name from the filesystem.\n");
        printf("\nUsage : int unlink(const char *path);\n");
        printf("\nReturn Value : On Success return 0, on error return -1");
    }
    else if(strcmp("exit",Name) == 0)
    {
        printf("About : The exit() function causes normal process termination and the least significant byte of status is returne to the parent \n");
        printf("\nUsage : exit\n");
    }
    else if(strcmp("close",Name) == 0)
    {
        printf("About : close() closes a file descriptor, so that it no longer refers to any file and may be reused.\n");
        printf("\nUsage : int close(int fd);\n");
        printf("\nReturn Value : close() returns zero on success.  On error, -1 is returned, and errno is set to indicate the error.");
    }
    else if(strcmp("open",Name) == 0)
    {
        printf("About : It is used to terminate the shell\n");
        printf("\nUsage : int open(const char *path, int flags, .../* mode_t mode */ );\n");
        printf(" Return Value : On success, open(), return the new file descriptor (a nonnegative integer).  On error, -1 is returned and errno is set to indicate the error.\n");
    }
    else if(strcmp("lseek",Name) == 0)
    {
        printf("About : lseek() repositions the file offset of the open file description associated with the file descriptor fd to the argument offset according to the directive whence\n");
        printf("\nUsage : off_t lseek(int fd, off_t offset, int whence);\n");
        printf("\nReturn Value : Upon successful completion, lseek() returns the resulting offset location as measured in bytes from the beginning of the file.  On error, the value (off_t) -1 is returned and errno is set to indicate the error.");
    }
    else if(strcmp("chmod",Name) == 0)
    {
        printf("About : chmod changes the file mode bits of each given file according to model\n");
        printf("\nUsage : chmod [OPTION]\n");
    }
    else if(strcmp("rm",Name) == 0)
    {
        printf("About : rm removes each specified file.  By default, it does not remove directories\n");
        printf("\nUsage : rm [OPTION]\n");
    }
    else if(strcmp("cat",Name) == 0)
    {
        printf("About :   Concatenate FILE(s) to standard output.\n");
        printf("\nUsage : cat [OPTION]\n");
    }
    else if(strcmp("cd",Name) == 0)
    {
        printf("About : The cd utility shall change the working directory of the current shell execution environment\n");
        printf("\nUsage : cd [-L|-P] [directory]\n");
    }
    else if(strcmp("df",Name) == 0)
    {
        printf("About : df displays the amount of space available on the file system containing each file name argument.\n");
        printf("\nUsage : df [OPTION]... [FILE]...\n");
    }
    else if(strcmp("find",Name) == 0)
    {
        printf("About : find searches the directory tree rooted at each given starting-point by evaluating the given expression from left to right according to the rules of precedence until the outcome is known at which point find moves on to the next file name.  If no starting-point is specified, `.' is assumed. \n");
        printf("\nUsage : find   [-H] [-L] [-P] [-D debugopts] [-Olevel] [starting-point...][expression]\n");
    }
    else if(strcmp("grep",Name) == 0)
    {
        printf("About : grep searches for patterns in each FILE.\n");
        printf("\nUsage : grep [OPTION]... PATTERNS [FILE]...\n");
    }
    else if(strcmp("mkfs",Name) == 0)
    {
        printf("About : mkfs is used to build a Linux filesystem on a device, usually a hard disk partition\n");
        printf("\nUsage : mkfs [options]\n");
    }
    else if(strcmp("mkdir",Name) == 0)
    {
        printf("About : Create the DIRECTORY(ies), if they do not already exist.\n");
        printf("\nUsage : mkdir [OPTION]\n");
    }
    else if(strcmp("pwd",Name) == 0)
    {
        printf("About : Print the full filename of the current working directory.\n");
        printf("\nUsage : pwd [OPTION]\n");
    }
    else if(strcmp("touch",Name) == 0)
    {
        printf("About : Update the access and modification times of each FILE to the current time.\n");
        printf("\nUsage : touch [OPTION]\n");
    }
    else if(strcmp("uname",Name) == 0)
    {
        printf("About : Print certain system information.  With no OPTION, same as -s.\n");
        printf("\nUsage : uname [OPTION]\n");
    }
    else
    {
        printf("No manual entry for %s\n",Name);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  IsFileExist
//      Description :    It is used to check whether file is exist or not
//      Input :          It accept file name
//      Output:          It return true or false
//      Author :         Ashwini Vishnu Kauthale
//      Data :           16/01/2026
//
///////////////////////////////////////////////////////////////////////////////

bool IsFileExist(
                    char *name       // File name
                )
{
    PINODE temp = head;
    bool bFlag = false;

    while(temp != NULL)
    {
        if((strcmp(name,temp->FileName) == 0) && (temp->FileType == REGULARFILE))
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }


    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  CreateFile
//      Description :    It is used to create new regular file
//      Input :          It accept file name and permissions
//      Output:          It return file descriptor
//      Author :         Ashwini Vishnu Kauthale
//      Data :           16/01/2026
//
///////////////////////////////////////////////////////////////////////////////

int CreateFile(
                    char *name,          // Name of new file
                    int permission       // Permission for that file
                )
{
    PINODE temp = head;
    int i = 0;

    printf("Total number of Inodes remaning : %d\n",superobj.FreeInodes);

    // If name is missing
    if(name == NULL)
    {
        return ERR_INVALID_PARAMETER;
    }

    // If the permission value is wrong
    // permission -> 1 -> READ
    // permission -> 2 -> WRITE
    // permission -> 3 -> READ + WRITE
    if(permission < 1 || permission > 3)
    {
        return ERR_INVALID_PARAMETER;
    }

    // If inodes are full
    if(superobj.FreeInodes == 0)
    {
        return ERR_NO_INODES;
    }

    // If file is already present
    if(IsFileExist(name) == true)
    {
        return ERR_FILE_ALREADY_EXIST;
    }

    // Search empty Inode
    while(temp != NULL)
    {
        if(temp->FileType == 0)
        {
            break;
        }
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("There is no inode\n");
        return ERR_NO_INODES;
    }

    // Search for empty UFDT entry
    // Note : 0,1,2 are reserved
    for(i = 3; i < MAXOPENFILES; i++)
    {
        if(uareaobj.UFDT[i] == NULL)
        {
            break;
        }
    }

    // UFDT is full
    if(i == MAXOPENFILES)
    {
        return ERR_MAX_FILES_OPEN;
    }

    // Allocate memory for file table
    uareaobj.UFDT[i] = (PFILETABLE)malloc(sizeof(FileTable));

    // Initialize file table
    uareaobj.UFDT[i]->ReadOffset = 0;
    uareaobj.UFDT[i]->WriteOffset = 0;
    uareaobj.UFDT[i]->Mode = permission;

    // Connect file table with inode
    uareaobj.UFDT[i]->ptrinode = temp;

    // Initialize elements of Inode
    strcpy(uareaobj.UFDT[i]->ptrinode->FileName,name);
    uareaobj.UFDT[i]->ptrinode->FileSize = MAXFILESIZE;
    uareaobj.UFDT[i]->ptrinode->ActualFileSize = 0;
    uareaobj.UFDT[i]->ptrinode->FileType = REGULARFILE;
    uareaobj.UFDT[i]->ptrinode->ReferenceCount = 1;
    uareaobj.UFDT[i]->ptrinode->Permission = permission;

    // Allocate memory for files data
    uareaobj.UFDT[i]->ptrinode->Buffer = (char*)malloc(MAXFILESIZE);

    superobj.FreeInodes--;

    return i;          // File Descriptor
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  LsFile
//      Description :    It is used to list all files
//      Input :          Nothing
//      Output:          Nothing
//      Author :         Ashwini Vishnu Kauthale
//      Data :           16/01/2026
//
///////////////////////////////////////////////////////////////////////////////

// ls-l
void LsFile()
{
    PINODE temp = head;

    printf("-------------------------------------------------------------------------------\n");
    printf("-------------------Ashwini CVSF Files Information-------------------------\n");
    printf("-------------------------------------------------------------------------------\n");
    
    while(temp !=NULL)
    {
        if(temp->FileType != 0)
        {
            printf("%d\t%s\t%d\n",temp->InodeNumber,temp->FileName,temp->ActualFileSize);
        }
        temp = temp->next;
    }
    printf("-------------------------------------------------------------------------------\n");

}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  UnlinkFile
//      Description :    It is used to delete the file
//      Input :          file name
//      Output:          Nothing
//      Author :         Ashwini Vishnu Kauthale
//      Data :           22/01/2026
//
///////////////////////////////////////////////////////////////////////////////

int UnlinkFile(
                char *name
                )
{
    int i = 0;

    if(name == NULL)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(IsFileExist(name) == false)
    {
        return ERR_FILE_NOT_EXIST;
    }

    // Travel the UFDT

    for(i = 0; i < MAXOPENFILES; i++)
    {
        if(uareaobj.UFDT[i] != NULL)
        {
            if(strcmp(uareaobj.UFDT[i]->ptrinode->FileName,name) == 0)
            {
                // Delocate memory of Buffer
                free(uareaobj.UFDT[i]->ptrinode->Buffer);
                uareaobj.UFDT[i]->ptrinode->Buffer = NULL;

                // Recet all values of inode
                // Dont deallocate memory of inode
                uareaobj.UFDT[i]->ptrinode->FileSize = 0;
                uareaobj.UFDT[i]->ptrinode->ActualFileSize = 0;
                uareaobj.UFDT[i]->ptrinode->FileType = 0;
                uareaobj.UFDT[i]->ptrinode->ReferenceCount = 0;
                uareaobj.UFDT[i]->ptrinode->Permission = 0;

                memset(uareaobj.UFDT[i]->ptrinode->FileName,'\0',sizeof(uareaobj.UFDT[i]->ptrinode->FileName));

                // Deallocate memory of file table
                free(uareaobj.UFDT[i]);

                // set null to UFDT
                uareaobj.UFDT[i] = NULL;

                // Increment free inodes count

                superobj.FreeInodes++;

                break;                 // IMP
            }  // End of if
        }     // End of if
    }         // End of for

    return EXECUTE_SUCCESS;

}             // // End of function

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  WriteFile()
//      Description :    It is used to write the data into the file
//      Input :          file descriptor,
//                       Address of buffer which contains data,
//                       Size of data that we want to write
//      Output:          number of bytes succesfully written
//      Author :         Ashwini Vishnu Kauthale
//      Data :           22/01/2026
//
///////////////////////////////////////////////////////////////////////////////

int WriteFile(
                int fd,
                char *data,
                int size
            )
{
    printf("File Descriptor : %d\n",fd);
    printf("Data that we want to write : %s\n",data);
    printf("Data of byte that we want to write : %d\n",size);

    // Invalid fd
    if(fd < 0 || fd > MAXOPENFILES)
    {
        return ERR_INVALID_PARAMETER;
    }

    // fd points to null
    if(uareaobj.UFDT[fd] == NULL)
    {
        return ERR_FILE_NOT_EXIST;
    }

    // there is no permission to write
    if(uareaobj.UFDT[fd]->ptrinode->Permission < WRITE)
    {
        return ERR_PERMISSION_DENIDE;
    }

    // Insufficiant space

    if((MAXFILESIZE - uareaobj.UFDT[fd]->WriteOffset) < size)
    {
        return ERR_INSUFFICIENT_SPACE;
    }

    // Write the data into file
    strncpy(uareaobj.UFDT[fd]->ptrinode->Buffer + uareaobj.UFDT[fd]->WriteOffset,data,size);

    // Updata the write offset
    uareaobj.UFDT[fd]->WriteOffset = uareaobj.UFDT[fd]->WriteOffset + size;

    // Update the Actual file size

    uareaobj.UFDT[fd]->ptrinode->ActualFileSize = uareaobj.UFDT[fd]->ptrinode->ActualFileSize + size;

    return size;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Function Name :  ReadFile()
//      Description :    It is used to read the data into the file
//      Input :          file descriptor,
//                       Address of empty buffer,
//                       Size of data that we want to read
//      Output:          number of bytes succesfully read
//      Author :         Ashwini Vishnu Kauthale
//      Data :           22/01/2026
//
///////////////////////////////////////////////////////////////////////////////

int ReadFile(
                int fd,
                char *data,
                int size
            )
{
    // Invalid fd
    if(fd < 0 || fd > MAXOPENFILES)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(data == NULL)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(size <= 0)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(uareaobj.UFDT[fd] == NULL)
    {
        return ERR_FILE_NOT_EXIST;
    }

    // Filter for permission
    if(uareaobj.UFDT[fd]->ptrinode->Permission < READ)
    {
        return ERR_PERMISSION_DENIDE;
    }

    // Insufficiant data

    if((MAXFILESIZE - uareaobj.UFDT[fd]->ReadOffset) < size)
    {
        return ERR_INSUFFICIANT_DATA;
    }

    // Read the data

    strncpy(data,uareaobj.UFDT[fd]->ptrinode->Buffer + uareaobj.UFDT[fd]->ReadOffset,size);

    // Update the read offset
    uareaobj.UFDT[fd]->ReadOffset = uareaobj.UFDT[fd]->ReadOffset + size;

    return size;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Entry Point Function of the project
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    char str[80] = {'\0'};
    char Command[5][20] = {'\0'};
    char InputBuffer[MAXFILESIZE] = {'\0'};
    char *EmptyBuffer = NULL;
    int iCount = 0;
    int iRet = 0;

    StartAuxillaryDataInitilisation();

    printf("-------------------------------------------------------------------------------\n");
    printf("-------------------Ashwini CVSF started succesfully-------------------------\n");
    printf("-------------------------------------------------------------------------------\n");
    
    // Infinite listning shell
    while(1)
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\nAshwini CVSF : > ");
        fgets(str,sizeof(str),stdin);

        iCount = sscanf(str,"%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        fflush(stdin);

        if(iCount == 1)
        {
            // Ashwini CVSF : > exit
            if(strcmp("exit",Command[0]) == 0)
            {
                printf("Thank for using Ashwini CVFS\n");
                printf("Delocating all the allocated resources\n");

                break;
            }
            // Ashwini CVSF : > ls
            else if(strcmp("ls",Command[0]) == 0)
            {
                LsFile();
            }
            // Ashwini CVSF : > help
            else if(strcmp("help",Command[0]) == 0)
            {
                DisplayHelp();
            }
            // Ashwini CVSF : > clear
            else if(strcmp("clear",Command[0]) == 0)
            {
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
            }
        }// End of else if 1
        else if(iCount == 2)
        {
            // Ashwini CVSF : > man ls
            if(strcmp("man",Command[0]) == 0)
            {
                ManPageDisplay(Command[1]);
            }

            // Ashwini CVSF : > unlink Demo.txt
            else if(strcmp("unlink",Command[0]) == 0)
            {
                iRet = UnlinkFile(Command[1]);

                if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error : Invalid parameter\n");
                }

                if(iRet == ERR_FILE_NOT_EXIST)
                {
                    printf("Error : Unable to delete as there is no file\n");
                }

                if(iRet == EXECUTE_SUCCESS)
                {
                    printf("file gets succesfully deleted\n");
                }
            }
            // Ashwini CVFS : > write 2
            else if(strcmp("write",Command[0]) == 0)
            {
                printf("Enter the data that you want to write\n");
                fgets(InputBuffer,MAXFILESIZE,stdin);

                iRet = WriteFile(atoi(Command[1]),InputBuffer,strlen(InputBuffer) - 1);

                if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error : Invalid parameters\n");
                }
                else if(iRet == ERR_FILE_NOT_EXIST)
                {
                    printf("Error : There is no such file\n");
                }
                else if(iRet == ERR_PERMISSION_DENIDE)
                {
                    printf("Error : Unable to write as there is no permission\n");
                }
                else if(iRet == ERR_INSUFFICIENT_SPACE)
                {
                    printf("Error : Unable to write as there is no space\n");
                }
                else
                {
                    printf("%d bytes succesfully written\n",iRet);
                }
            }
            else
            {
                printf("There is no such command\n");
            }
        }// End of else if 2
        else if(iCount == 3)
        {
            // Ashwini CVSF : > creat Ganesh.txt 3
            if(strcmp("creat",Command[0]) == 0)
            {
                iRet = CreateFile(Command[1],atoi(Command[2]));

                if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error : Unable to create the file as parameters are invalid\n");
                    printf("Please refer man page\n");
                }

                if(iRet == ERR_NO_INODES)
                {
                    printf("Error : Unable to create the file as there is no inodes\n");
                }

                if(iRet == ERR_FILE_ALREADY_EXIST)
                {
                    printf("Error : Unable to create the file because file is already present\n");
                }

                if(iRet == ERR_MAX_FILES_OPEN)
                {
                    printf("Error : Unable to create the file\n");
                    printf("Max opened file limit reached\n");
                }

                printf("File gets succesfully created with FD %d\n",iRet);
            }
            // Ashwini CVFS : > read 3 10
            if(strcmp("read",Command[0]) == 0)
            {
                EmptyBuffer= (char *)malloc(sizeof(atoi(Command[2])));

                iRet = ReadFile(atoi(Command[1]),EmptyBuffer,atoi(Command[2]));

                if(iRet == ERR_INVALID_PARAMETER)
                {
                    printf("Error : Invalid parameter\n");
                }
                else if(iRet == ERR_FILE_NOT_EXIST)
                {
                    printf("Error : File not exist\n");
                }
                else if(iRet == ERR_PERMISSION_DENIDE)
                {
                    printf("Error : Permission Denide\n");
                }
                else if(iRet == ERR_INSUFFICIANT_DATA)
                {
                    printf("Error : Insufficiant data\n");
                }
                else
                {
                    printf("Read operation is succesfull\n");
                    printf("Data from file is : %s\n",EmptyBuffer);

                    free(EmptyBuffer);
                }
            }
            else
            {
                printf("There is no such command\n");
            }
        }// End of else if 3
        else if(iCount == 4)
        {
            
        } // End of else if 4
        else
        {
            printf("Command not found\n");
            printf("Please refer help option to get more information\n");
        } // End of else
    } // end of while
    return 0;
}