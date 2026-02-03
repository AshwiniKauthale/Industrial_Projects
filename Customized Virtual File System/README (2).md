

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

