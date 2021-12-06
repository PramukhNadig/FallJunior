#include "PlaylistNode.h"
#include <string.h>
#include <stdio.h>

//thisNode = head node

void SetPlaylistNode(PlaylistNode* thisNode, char idInit[], char songNameInit[], char artistNameInit[], int songLengthInit){
    strncpy(thisNode->uniqueID, idInit, 50);
    strncpy(thisNode->songName, songNameInit, 50);
    strncpy(thisNode->artistName, artistNameInit, 50);
    thisNode->songLength = songLengthInit;
    thisNode->nextNodePtr = NULL;
    return;
}

void PrintPlaylistNode(PlaylistNode* thisNode){
    printf("Unique ID: %s\nSong Name: %s\nArtist Name: %s\nSong Length (in seconds): %d", thisNode->uniqueID, thisNode->songName, thisNode->artistName, thisNode->songLength);
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode){
    return thisNode->nextNodePtr;
}


