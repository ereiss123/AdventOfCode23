/**
 * @brief Reads a file and returns its contents as a string.
 * @param filename The name of the file to read.
 * @return The contents of the file as a string.
*/
char* read_file(char* filename);

/**
 * @brief Finds the next colon in a string.
 * @param str The string to search.
 * @return A pointer to the next colon in the string.
*/
char* find_colon(char* str);

/**
 * @brief Finds the next  bar ('|') in a string.
 * @param str The string to search.
 * @return A pointer to the next bar in the string.
*/
char* find_line(char* str);

/**
 * @brief Finds the next newline in a string.
 * @param str The string to search.
 * @return A pointer to the next newline in the string.
*/
char* find_newline(char* str);
