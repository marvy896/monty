#include "monty.h"

/**
 * array_len - calculates the array of a token.
 * Return: Lenght of the token.
 */
unsigned int array_len(void)
{
	unsigned int token_len = 0;

	while (globalvar.token2[token_len])
		token_len++;
	return (token_len);
}
/**
 * tokerr - makes the last element of instructions as error code.
 * @error_status: type int where the error is saved as srt.
 */
void tokerr(int error_status)
{
    int token_len = array_len();
    
    char *exit_str = get_int(error_status);
    if (!exit_str)
    {
        stderr_malloc();
        return;
    }
    
    char *new_token = malloc(sizeof(char) * (token_len + 2));
    if (!new_token)
    {
        stderr_malloc();
        return;
    }
    
    for (int i = 0; i < token_len; i++)
    {
        new_token[i] = globalvar.token2[i];
    }
    
    free(globalvar.token2);
    globalvar.token2 = new_token;
}

