# Unix-File-Sorter-C-Program-to-Sort-Files-by-Creation-Date
A C program designed for Unix systems to sort files in the current directory by creation date using system calls and file metadata.

## Problem Statement
Develop a script to organize files in ascending order based on their creation date and time.

## Solution
Shell script verifies input, checks directory permissions, retrieves and sorts file list, displays details, and handles errors.

## Features
- Verify input directory path
- Check directory existence and permissions
- Retrieve and prepare file list with metadata
- Sort files by creation time
- Display sorted file information with name, size, and timestamp
- Handle errors and edge cases gracefully
  
### System Calls -
The Unix File Sorter script leverages system calls to efficiently interact with the operating system and manage files. System calls are used to verify input, check directory permissions, retrieve file metadata, and perform sorting operations, enhancing the script's performance and reliability.

#### Commands to run 
- use a linux environment
- go to the directory where you want sort the files.
- compile it with the command -> cc filename.c (here file_sorter.c)
- when compiled with no errors, run using -> ./a.out
