#include "shell.h"
/**
* saveCommandHistory - Saves the command history to a specified file.
* @historyHead: Pointer to the head of the command history list.
* @filePath: Path to the file where command history will be saved.
*
* Return: 1 on success, -1 on failure.
*/
int saveCommandHistory(CommandHistory *historyHead, const char *filePath)
{
FILE *file = fopen(filePath, "w");
CommandHistory *currentCommand = historyHead;
if (!file) {
return -1;
}
while (currentCommand != NULL) {
fprintf(file, "%s\n", currentCommand->command);
currentCommand = currentCommand->next;
}
fclose(file);
return 1;
}
/**
* loadCommandHistory - Loads the command history from a specified file.
* @historyHead: Double pointer to the head of the command history list.
* @filePath: Path to the file from which to load the command history.
*
* Return: The number of commands loaded on success, -1 on failure.
*/
int loadCommandHistory(CommandHistory **historyHead, const char *filePath)
{
FILE *file = fopen(filePath, "r");
char commandBuffer[MAX_COMMAND_LENGTH];
int commandsLoaded = 0;
if (!file) {
return -1;
}
while (fgets(commandBuffer, sizeof(commandBuffer), file) != NULL) {
// Remove trailing newline character
commandBuffer[strcspn(commandBuffer, "\n")] = '\0';
addCommandToHistory(commandBuffer, historyHead);
commandsLoaded++;
}
fclose(file);
return commandsLoaded;
}
/**
* addCommandToHistory - Adds a new command to the history list.
* @command: The command to add.
* @historyHead: Double pointer to the head of the command history list.
*
* Return: 1 on success, 0 on failure.
*/
int addCommandToHistory(const char *command, CommandHistory **historyHead)
{
CommandHistory *newNode = malloc(sizeof(CommandHistory));
if (!newNode) {
return 0;
}
newNode->command = strdup(command);
newNode->next = NULL;
if (*historyHead == NULL) {
*historyHead = newNode;
} else {
CommandHistory *current = *historyHead;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
}
return 1;
}
/**
* freeCommandHistory - Frees the memory allocated for the command history list.
* @historyHead: Pointer to the head of the command history list.
*
* Return: void.
*/
void freeCommandHistory(CommandHistory *historyHead)
{
CommandHistory *current = historyHead;
while (current != NULL) {
CommandHistory *temp = current;
current = current->next;
free(temp->command);
free(temp);
}
}
