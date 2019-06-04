#ifndef GUARD_LOAD_SAVE_H
#define GUARD_LOAD_SAVE_H

#include "global.h"
#include "task.h"

#define SAVE_AGE_INVALID 0
#define SAVE_AGE_SAME 1
#define SAVE_AGE_NEW_GAME 2
#define SAVE_AGE_NEWER 3
#define SAVE_AGE_OLDER 4

#define SAVE_COMPATIBLE 0
#define SAVE_INCOMPATIBLE 1
#define SAVE_COMPATIBLE_CONV 2

#define SAVE_VERSION_INVALID 0
#define SAVE_VERSION_ALPHA1 1

extern struct SaveBlock1 gSaveblock1;
extern struct SaveBlock2 gSaveblock2;
extern struct PokemonStorage gPokemonStorage;

extern bool32 gFlashMemoryPresent;
extern struct SaveBlock1 *gSaveBlock1Ptr;
extern struct SaveBlock2 *gSaveBlock2Ptr;
extern struct PokemonStorage *gPokemonStoragePtr;

struct SaveCompatibility {
    u8 compatibility;
    TaskFunc convFunc;
};

extern const struct SaveCompatibility gSaveCompatibility[];

extern const u8* const gVersionStringsTable[];

void CheckForFlashMemory(void);
void ClearSav2(void);
void ClearSav1(void);
void SetSaveBlocksPointers(u16 offset);
void MoveSaveBlocks_ResetHeap(void);
u32 UseContinueGameWarp(void);
void ClearContinueGameWarpStatus(void);
void SetContinueGameWarpStatus(void);
void SetContinueGameWarpStatusToDynamicWarp(void);
void ClearContinueGameWarpStatus2(void);
void SavePlayerParty(void);
void LoadPlayerParty(void);
void SaveObjectEvents(void);
void LoadObjectEvents(void);
void SaveSerializedGame(void);
void LoadSerializedGame(void);
void LoadPlayerBag(void);
void SavePlayerBag(void);
void ApplyNewEncryptionKeyToHword(u16 *hWord, u32 newKey);
void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey);
u8 CheckSaveAge(void);
u8 CheckSaveCompatibility(void);

//Tasks
void Task_SaveConversionTemplate(u8 taskId);

#endif // GUARD_LOAD_SAVE_H
