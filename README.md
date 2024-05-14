# Implementation of get_next_line Function

## Purpose

The `get_next_line` function is designed to read a line from a file descriptor, character by character, until a newline character `\n` is encountered or the end of file (EOF) is reached. It's particularly useful when reading input from a file or any other input stream, where you want to process the data line by line.

## Architecture

#### Function Signature
`int get_next_line(int fd, char **line);`


### Parameters

- `fd`: File descriptor from which to read the input.
- `line`: Pointer to a character pointer where the line read will be stored.

### Return Value

- `1`: A line has been read successfully.
- `0`: End of file has been reached.
- `-1`: An error occurred.

### Algorithm Overview

1. **Initialization**: Allocate memory for the buffer to hold the read characters and initialize a static variable to keep track of the current position within the buffer.

2. **Reading from File Descriptor**: Read a chunk of characters from the file descriptor into the buffer. If the end of file is reached, return `0`.

3. **Processing the Buffer**:
    - If the newline character `\n` is found in the buffer, copy the characters up to the newline character into the line pointer and return `1`.
    - If the newline character is not found and the end of file is not reached, concatenate the buffer content with the current content of the line pointer and continue reading.

4. **Memory Management**:
    - Free the buffer memory after each iteration.
    - Return `-1` if an error occurs during memory allocation or reading.

### Architecture Details

- **Static Variables**:
    - A static variable is used to store the buffer between function calls, allowing the function to remember the state of the buffer between reads.
  
- **Buffer Management**:
    - The buffer is dynamically allocated using `malloc`, allowing it to be resized as needed to accommodate varying line lengths.

- **Line Pointer**:
    - The line pointer passed to the function is dynamically allocated or reallocated to store the characters read from the file descriptor.

- **Error Handling**:
    - Errors are handled by returning `-1`, indicating an error condition, and freeing any allocated memory before returning.

- **EOF Handling**:
    - When the end of file is reached, the function returns `0`, indicating that there are no more lines to read.

- **Usage**:
    - The function is called in a loop until it returns `0` or `-1`, indicating the end of file or an error, respectively.

### Conclusion

The `get_next_line` function provides a flexible and efficient way to read input from file descriptors line by line, making it a fundamental component of many file processing applications. Its modular architecture and dynamic memory management allow it to handle various input scenarios while maintaining performance and reliability.
