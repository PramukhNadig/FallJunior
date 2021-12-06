#include <string.h>
#include "PlaylistNode.h"
#include <stdio.h>
#include <stdlib.h>

int numberOfNodes = 0;
PlaylistNode* headNode;
void PrintMenu(char* name)
{
    printf("%s PLAYLIST MENU\na - Add song\nr - Remove song\no - Output full playlist\nq - Quit\n\n", name);
}

PlaylistNode* ExecuteMenu(char option, char playlistTitle[], PlaylistNode* headNode)
{

    switch (option)
    {
    case 'a': ;
        char uniqueID[50] = "";
        char songName[50] = "";
        char artistName[50] = "";
        int songLength = 0;
        PlaylistNode *currNode = headNode;

        printf("Enter song's unique ID:\n");
        scanf("%s", uniqueID);

        printf("Enter song's name:\n");
        fgets(songName, 50, stdin);
        songName[strlen(songName) - 1] = '\0'; // clear NULL
        printf("Enter artist's name:\n");
        fgets(artistName, 50, stdin);
        artistName[strlen(artistName) - 1] = '\0';

        printf("Enter song's length (in seconds):\n");
        scanf("%d", &songLength);
        printf("\n");
        if(headNode == NULL){
        SetPlaylistNode(headNode, uniqueID, songName, artistName, songLength);
        }else{
            while(currNode != NULL){
                currNode = currNode->nextNodePtr;
            }
            SetPlaylistNode(currNode, uniqueID, songName, artistName, songLength);
        }
    case 'r':
        
        break;

    case 'o':
        printf("%s - OUTPUT FULL PLAYLIST\n", playlistTitle);
        if(headNode == NULL){
            printf("Playlist is empty\n\n");
        }else{
            PlaylistNode* currNode = headNode;
            while(currNode != NULL){
                PrintPlaylistNode(currNode);
                currNode = currNode->nextNodePtr;
            }
        }
        break;
    }

    return headNode;
}


int main(void)
{
    char menuOp = ' ';
    char playlistTitle[50] = "";
    // Prompt user for playlist title
    printf("Enter playlist's title:\n");
    fgets(playlistTitle, 50, stdin);
    printf("\n");

    // Eliminate end-of-line char
    playlistTitle[strlen(playlistTitle) - 1] = '\0';

    // Output play list menu options
    PrintMenu(playlistTitle);

    while (menuOp != 'q')
    {
        printf("Choose an option:\n");
        scanf(" %c", &menuOp);
        if (menuOp == 'a' || menuOp == 'r' || menuOp == 'o')
        {
            headNode = ExecuteMenu(menuOp, playlistTitle, headNode);
            PrintMenu(playlistTitle);
        }
    }

    return 0;
}