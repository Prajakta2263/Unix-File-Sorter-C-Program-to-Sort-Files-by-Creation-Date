#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
  // Get the current directory.
  char *current_directory = getcwd(NULL, 0);

  // Create a struct to store the file information.
  struct file_info {
    char *filename;
    struct stat file_stat;
  };

  // Create an array to store the file information.
  struct file_info *files = malloc(sizeof(struct file_info) * 100);
  int num_files = 0;

  // Iterate through the files in the current directory.
  DIR *dir = opendir(current_directory);
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Get the file name.
    char *filename = entry->d_name;

    // Get the file status.
    stat(filename, &files[num_files].file_stat);

    // Add the file information to the array.
    files[num_files].filename = filename;
    num_files++;
  }

  // Close the directory.
  closedir(dir);

  // Sort the files in the array by the creation date.
  for (int i = 0; i < num_files; i++) {
    for (int j = i + 1; j < num_files; j++) {
      if (files[i].file_stat.st_ctime < files[j].file_stat.st_ctime) {
        struct file_info temp = files[i];
        files[i] = files[j];
        files[j] = temp;
      }
    }
  }

  // Print the sorted files.
  for (int i = 0; i < num_files; i++) {
    printf("%s\n", files[i].filename);
  }

  // Free the memory allocated for the file information array.
  free(files);

  // Set the current_directory pointer to NULL.
  current_directory = NULL;

  // Allocate memory for the string.
  char *strdup_ptr = malloc(strlen(current_directory) + 1);

  // Copy the string to the allocated memory.
  strcpy(strdup_ptr, current_directory);

  // Free the string that was allocated on the stack.
  free(current_directory);

  // Free the string that was allocated on the heap.
  free(strdup_ptr);

  return 0;
}
