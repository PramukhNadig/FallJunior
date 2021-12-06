#ifndef PLAYLISTNODE_H_   /* Include guard */
#define PLAYLISTNODE_H_
typedef struct PlaylistNode{
    char uniqueID[50];
    char songName[50];
    char artistName[50];
    int songLength;
    struct PlaylistNode* nextNodePtr;
}PlaylistNode;

void SetPlaylistNode(PlaylistNode* thisNode, char idInit[], char songNameInit[], char artistNameInit[], int songLengthInit);
void PrintPlaylistNode(PlaylistNode* node);
PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode);

#endif 
