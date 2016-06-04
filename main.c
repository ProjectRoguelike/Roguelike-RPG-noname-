////////////////////////////////////////////////
// consoleColor.h
////////////////////////////////////////////////
#pragma once
 
 
enum ConsoleColor
{
    ConsoleColor_Black          = 0,
    ConsoleColor_DarkBlue       = 1,
    ConsoleColor_DarkGreen      = 2,
    ConsoleColor_DarkCyan       = 3,
    ConsoleColor_DarkRed        = 4,
    ConsoleColor_DarkMagenta    = 5,
    ConsoleColor_DarkYellow     = 6,
    ConsoleColor_Gray           = 7,
    ConsoleColor_DarkGray       = 8,
    ConsoleColor_Blue           = 9,
    ConsoleColor_Green          = 10,
    ConsoleColor_Cyan           = 11,
    ConsoleColor_Red            = 12,
    ConsoleColor_Magenta        = 13,
    ConsoleColor_Yellow         = 14,
    ConsoleColor_White          = 15
};
 
 
////////////////////////////////////////////////
// level.h
////////////////////////////////////////////////
#pragma once
 
 
/////////////////////////////////////
// Include
#include "consoleColor.h"
 
 
/////////////////////////////////////
// Constants
const int rowsCount = 15;
const int columnsCount = 35;
const int heartHeal = 150;
 
const unsigned char fogOfWarRenderSymbol = 176;
ConsoleColor fogOfWarRenderColor = ConsoleColor_DarkGray;
 
const unsigned char CellSymbol_Empty    = ' ';
const unsigned char CellSymbol_Wall     = '#';
const unsigned char CellSymbol_Hero     = 'h';
const unsigned char CellSymbol_Exit     = 'e';
const unsigned char CellSymbol_Orc      = 'o';
const unsigned char CellSymbol_Skeleton = 's';
const unsigned char CellSymbol_Stick    = '1';
const unsigned char CellSymbol_Club     = '2';
const unsigned char CellSymbol_Spear    = '3';
const unsigned char CellSymbol_Saber    = '4';
const unsigned char CellSymbol_Heart    = '+';
 
const unsigned char levelData0[rowsCount][columnsCount + 1] =   {
                                                                    "###################################",
                                                                    "#   #+##      o           s       #",
                                                                    "# # o  #o############## ######### #",
                                                                    "# ###### #   #+#3  s  # ##s##   # #",
                                                                    "#  s       # # ###### # #s4   #s# #",
                                                                    "###### # ### #      # # ##s##   # #",
                                                                    "##  o# # # # #### # #   ##### # # #",
                                                                    "#+ #   # # o    # ##+######+#   # #",
                                                                    "######## # ####         #  s# # #s#",
                                                                    "#  2#    #      ####### # # #   # #",
                                                                    "# ### #### ######   o   # #   #   #",
                                                                    "#  o       #      ####### #########",
                                                                    "############ ######   #1# # s #   #",
                                                                    "#h                  #   #   #s  # #",
                                                                    "#################################e#",
                                                                };
 
 
unsigned char GetRenderCellSymbol( unsigned char cellSymbol )
{
    switch( cellSymbol )
    {
        case CellSymbol_Empty:          return ' ';
        case CellSymbol_Wall:           return 177;
        case CellSymbol_Hero:           return 2;
        case CellSymbol_Orc:            return 2;
        case CellSymbol_Skeleton:       return 2;
        case CellSymbol_Stick:          return 47;
        case CellSymbol_Club:           return 33;
        case CellSymbol_Spear:          return 24;
        case CellSymbol_Saber:          return 108;
        case CellSymbol_Exit:           return 178;
        case CellSymbol_Heart:          return 3;
    }
 
    return '?';
}
 
ConsoleColor GetRenderCellSymbolColor( unsigned char cellSymbol )
{
    switch( cellSymbol )
    {
        case CellSymbol_Empty:          return ConsoleColor_Black;
        case CellSymbol_Wall:           return ConsoleColor_White;
        case CellSymbol_Hero:           return ConsoleColor_Yellow;
        case CellSymbol_Orc:            return ConsoleColor_Green;
        case CellSymbol_Skeleton:       return ConsoleColor_White;
        case CellSymbol_Stick:          return ConsoleColor_DarkYellow;
        case CellSymbol_Club:           return ConsoleColor_DarkRed;
        case CellSymbol_Spear:          return ConsoleColor_DarkCyan;
        case CellSymbol_Saber:          return ConsoleColor_Cyan;
        case CellSymbol_Exit:           return ConsoleColor_DarkRed;
        case CellSymbol_Heart:          return ConsoleColor_Red;
    }
 
    return ConsoleColor_Gray;
}
 
////////////////////////////////////////////////
// weaponType.h
////////////////////////////////////////////////
#pragma once
 
/////////////////////////////////////
// Include
#include "level.h"
 
 
enum WeaponType
{
    WeaponType_None,
    WeaponType_Fist,
    WeaponType_Stick,
    WeaponType_Club,
    WeaponType_Spear,
    WeaponType_Saber
};
 
 
const char* WeaponName_None         = "None";
const char* WeaponName_Fist         = "Fist";
const char* WeaponName_Stick        = "Stick";
const char* WeaponName_Club         = "Club";
const char* WeaponName_Spear        = "Spear";
const char* WeaponName_Saber        = "Saber";
 
 
const char* GetWeaponName( WeaponType weaponType )
{
    switch( weaponType )
    {
        case WeaponType_Fist:           return WeaponName_Fist;
        case WeaponType_Stick:          return WeaponName_Stick;
        case WeaponType_Club:           return WeaponName_Club;
        case WeaponType_Spear:          return WeaponName_Spear;
        case WeaponType_Saber:          return WeaponName_Saber;
    }
   
    return WeaponName_None;
}
 
int GetWeaponDamage( WeaponType weaponType )
{
    switch( weaponType )
    {
        case WeaponType_Fist:           return 2;
        case WeaponType_Stick:          return 16;
        case WeaponType_Club:           return 24;
        case WeaponType_Spear:          return 32;
        case WeaponType_Saber:          return 40;
    }
   
    return 0;
}
 
WeaponType GetWeaponTypeFromCell( unsigned char cellSymbol )
{
    switch( cellSymbol )
    {
        case CellSymbol_Stick:          return WeaponType_Stick;
        case CellSymbol_Club:           return WeaponType_Club;
        case CellSymbol_Spear:          return WeaponType_Spear;
        case CellSymbol_Saber:          return WeaponType_Saber;
    }
 
    return WeaponType_None;
}
 
 
////////////////////////////////////////////////
// unitType.h
////////////////////////////////////////////////
#pragma once
 
/////////////////////////////////////
// Include
#include "level.h"
#include "weaponType.h"
 
 
enum UnitType
{
    UnitType_None,
    UnitType_Hero,
    UnitType_Orc,
    UnitType_Skeleton
};
 
const char* UnitName_None           = "None";
const char* UnitName_Hero           = "Hero";
const char* UnitName_Orc            = "Orc";
const char* UnitName_Skeleton       = "Skeleton";
 
 
const char* GetUnitName( UnitType unitType )
{
    switch( unitType )
    {
        case UnitType_Hero:     return UnitName_Hero;
        case UnitType_Orc:      return UnitName_Orc;
        case UnitType_Skeleton: return UnitName_Skeleton;
    }
   
    return UnitName_None;
}
 
WeaponType GetUnitDefaultWeapon( UnitType unitType )
{
    switch( unitType )
    {
        case UnitType_Hero:             return WeaponType_Fist;
        case UnitType_Orc:              return WeaponType_Club;
        case UnitType_Skeleton:         return WeaponType_Saber;
    }
   
    return WeaponType_None;
}
 
int GetUnitDefaultHealth( UnitType unitType )
{
    switch( unitType )
    {
        case UnitType_Hero:         return 400;
        case UnitType_Orc:          return 60;
        case UnitType_Skeleton:     return 80;
    }
   
    return 0;
}
 
UnitType GetUnitTypeFromCell( unsigned char cellSymbol )
{
    switch( cellSymbol )
    {
        case CellSymbol_Hero:               return UnitType_Hero;
        case CellSymbol_Orc:                return UnitType_Orc;
        case CellSymbol_Skeleton:           return UnitType_Skeleton;
    }
 
    return UnitType_None;
}
 
////////////////////////////////////////////////
// unitData.h
////////////////////////////////////////////////
#pragma once
 
/////////////////////////////////////
// Include
#include "unitType.h"
#include "weaponType.h"
 
 
struct UnitData
{
    UnitType type;
    int row;
    int column;
    int health;
    WeaponType weapon;
};
 
 
////////////////////////////////////////////////
// main.cpp
////////////////////////////////////////////////
/////////////////////////////////////
// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>
 
#include "consoleColor.h"
#include "level.h"
#include "weaponType.h"
#include "unitType.h"
#include "unitData.h"
 
 
/////////////////////////////////////
// Constants
const int maxUnitsCount = 35;
 
 
/////////////////////////////////////
// Logics variables
HANDLE consoleHandle = 0;
bool isGameActive = true;
 
unsigned char levelData[rowsCount][columnsCount];
bool fogOfWar[rowsCount][columnsCount];
 
UnitData unitsData[maxUnitsCount];
int unitsCount = 0;
int heroIndex = 0;
 
char tempBuffer[128];
char statusMessage[128];
 
 
/////////////////////////////////////
// Functions
void SetupSystem()
{
    statusMessage[0] = 0;
 
    srand( time( 0 ) );
 
    consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
 
    // Hide console cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
 
void RevealFogOfWar( int row, int column )
{
    for( int r = row - 1; r <= row + 1; r++ )
    {
        for( int c = column - 1; c <= column + 1; c++ )
        {
            fogOfWar[r][c] = false;
        }
    }
}
 
void Initialize()
{
    unitsCount = 0;
 
    // Load level
    for( int r = 0; r < rowsCount; r++ )
    {
        for( int c = 0; c < columnsCount; c++ )
        {
            fogOfWar[r][c] = true;
 
 
            unsigned char cellSymbol = levelData0[r][c];
 
            levelData[r][c] = cellSymbol;
 
            switch( cellSymbol )
            {
                case CellSymbol_Hero:
                    heroIndex = unitsCount;
 
                case CellSymbol_Orc:
                case CellSymbol_Skeleton:
                {
                    UnitType unitType = GetUnitTypeFromCell( cellSymbol );
                    unitsData[unitsCount].type = unitType;
                    unitsData[unitsCount].row = r;
                    unitsData[unitsCount].column = c;
                    unitsData[unitsCount].weapon = GetUnitDefaultWeapon( unitType );
                    unitsData[unitsCount].health = GetUnitDefaultHealth( unitType );
                    unitsCount++;
 
                    break;
                }
            }
        }
    }
 
    // Reveal fog of war
    RevealFogOfWar( unitsData[heroIndex].row, unitsData[heroIndex].column );
}
 
void Render()
{
    // Move console cursor to (0,0)
    COORD cursorCoord;
    cursorCoord.X = 0;
    cursorCoord.Y = 0;
    SetConsoleCursorPosition( consoleHandle, cursorCoord );
 
 
    // Draw game title
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_Green );
    printf("\n\tDUNGEONS AND ORCS");
 
 
    // Draw hero HP
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_Red );
    printf("\n\n\tHP: ");
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_White );
    printf("%i", unitsData[heroIndex].health);
 
 
    // Draw hero weapon
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_Cyan );
    printf("     Weapon: ");
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_White );
    printf("%s", GetWeaponName( unitsData[heroIndex].weapon ) );
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_Gray );
    printf(" (Dmg: %i)               ", GetWeaponDamage( unitsData[heroIndex].weapon ) );
 
 
    // Draw level
    printf("\n\n\t");
    for( int r = 0; r < rowsCount; r++ )
    {
        for( int c = 0; c < columnsCount; c++ )
        {
            if( fogOfWar[r][c] == false )
            {
                unsigned char cellSymbol = levelData[r][c];
 
                unsigned char renderCellSymbol = GetRenderCellSymbol( cellSymbol );
                ConsoleColor cellColor = GetRenderCellSymbolColor( cellSymbol );
 
                SetConsoleTextAttribute( consoleHandle, cellColor );
                printf("%c", renderCellSymbol );
            }
            else
            {
                SetConsoleTextAttribute( consoleHandle, fogOfWarRenderColor );
                printf("%c", fogOfWarRenderSymbol );
            }
        }
        printf("\n\t");
    }
 
 
    // Fill status message with spaces
    while( strlen( statusMessage ) < 160 )
    {
        strcat(statusMessage, " ");
    }
    SetConsoleTextAttribute( consoleHandle, ConsoleColor_Yellow );
    printf("\n\n\t%s", statusMessage);
 
    // Clear status message
    statusMessage[0] = 0;
}
 
void MoveUnitTo( UnitData* pointerToUnitData, int row, int column )
{
    // Ignore dead units
    if( pointerToUnitData->health <= 0 )
    {
        return;
    }
 
    unsigned char unitSymbol = levelData[pointerToUnitData->row][pointerToUnitData->column];
    unsigned char destinationCellSymbol = levelData[row][column];
    bool canMoveToCell = false;
 
    // All units actions
    switch( destinationCellSymbol )
    {
        // Empty cell
        case CellSymbol_Empty:
        {
            canMoveToCell = true;
            break;
        }
 
        // Units cells
        case CellSymbol_Hero:
        case CellSymbol_Orc:
        case CellSymbol_Skeleton:
        {
            UnitType destinationUnitType = GetUnitTypeFromCell( destinationCellSymbol );
 
            // If destination unit have other type
            if( pointerToUnitData->type != destinationUnitType )
            {
                // Find enemy unit struct
                for( int u = 0; u < unitsCount; u++ )
                {
                    // Ignore dead units
                    if( unitsData[u].health <= 0 )
                        continue;
 
                    if( unitsData[u].row == row && unitsData[u].column == column )
                    {
                        // Calculate weapon damage
                        int damage = GetWeaponDamage( pointerToUnitData->weapon );
 
                        // Deal damage
                        unitsData[u].health = unitsData[u].health - damage;
 
                        // Add to status message
                        sprintf(tempBuffer, " %s dealt %i damage to %s.", GetUnitName( pointerToUnitData->type ), damage, GetUnitName( destinationUnitType ) );
                        strcat(statusMessage, tempBuffer);
 
                        // If enemy unit die
                        if( unitsData[u].health <= 0.0f )
                        {
                            levelData[row][column] = CellSymbol_Empty;
 
                            // Add to status message
                            sprintf(tempBuffer, " %s died.", GetUnitName( destinationUnitType ), damage, GetUnitName( destinationUnitType ) );
                            strcat(statusMessage, tempBuffer);
                        }
 
                        break;
                    }
                }
            }
 
            break;
        }
    }
 
    // Only hero actions
    if( pointerToUnitData->type == UnitType_Hero )
    {
        switch( destinationCellSymbol )
        {
            // Weapon Cell
            case CellSymbol_Stick:
            case CellSymbol_Club:
            case CellSymbol_Spear:
            case CellSymbol_Saber:
            {
                canMoveToCell = true;
 
                WeaponType weaponType = GetWeaponTypeFromCell( destinationCellSymbol );
                if( unitsData[heroIndex].weapon < weaponType )
                {
                    unitsData[heroIndex].weapon = weaponType;
                }
 
                // Add to status message
                sprintf(tempBuffer, " %s found %s.", GetUnitName( pointerToUnitData->type ), GetWeaponName( weaponType ) );
                strcat(statusMessage, tempBuffer);
 
                break;
            }
 
            // Heart
            case CellSymbol_Heart:
            {
                canMoveToCell = true;
                unitsData[heroIndex].health += heartHeal;
                break;
            }
 
            // Exit cell
            case CellSymbol_Exit:
            {
                isGameActive = false;
                break;
            }
        }
    }
 
    if( canMoveToCell )
    {
        // Remove unit symbol from previous position
        levelData[pointerToUnitData->row][pointerToUnitData->column] = CellSymbol_Empty;
 
        // Set new hero position
        pointerToUnitData->row = row;
        pointerToUnitData->column = column;
 
        // Set hero symbol to new position
        levelData[pointerToUnitData->row][pointerToUnitData->column] = unitSymbol;
 
 
        // Reveal fog of war
        if( pointerToUnitData->type == UnitType_Hero )
        {
            RevealFogOfWar( row, column );
        }
    }
}
 
void UpdateAI()
{
    // Pass all units
    for( int u = 0; u < unitsCount; u++ )
    {
        // Ignore hero
        if( u == heroIndex )
            continue;
 
        // Ignore dead units
        if( unitsData[u].health <= 0 )
            continue;
 
        // Distance to hero
        int distanceToHeroR =  abs(unitsData[heroIndex].row - unitsData[u].row);
        int distanceToHeroC = abs(unitsData[heroIndex].column - unitsData[u].column);
 
        // If hero nearby
        if( (distanceToHeroR + distanceToHeroC) == 1 )
        {
            // Attack hero
            MoveUnitTo( &unitsData[u], unitsData[heroIndex].row, unitsData[heroIndex].column );
        }
        else
        {
            // Random move
            switch( rand() % 4 )
            {
            case 0:
                MoveUnitTo( &unitsData[u], unitsData[u].row - 1, unitsData[u].column );
                break;
 
            case 1:
                MoveUnitTo( &unitsData[u], unitsData[u].row + 1, unitsData[u].column );
                break;
 
            case 2:
                MoveUnitTo( &unitsData[u], unitsData[u].row, unitsData[u].column - 1 );
                break;
 
            case 3:
                MoveUnitTo( &unitsData[u], unitsData[u].row, unitsData[u].column + 1 );
                break;
            }
 
        }
    }
}
 
void Update()
{
    unsigned char inputChar = _getch();
    inputChar = tolower( inputChar );
 
    switch( inputChar )
    {
        // Up
        case 'w':
            MoveUnitTo( &unitsData[heroIndex], unitsData[heroIndex].row - 1, unitsData[heroIndex].column );
            break;
 
        // Down
        case 's':
            MoveUnitTo( &unitsData[heroIndex], unitsData[heroIndex].row + 1, unitsData[heroIndex].column );
            break;
 
        // Left
        case 'a':
            MoveUnitTo( &unitsData[heroIndex], unitsData[heroIndex].row, unitsData[heroIndex].column - 1 );
            break;
 
        // Right
        case 'd':
            MoveUnitTo( &unitsData[heroIndex], unitsData[heroIndex].row, unitsData[heroIndex].column + 1 );
            break;
 
        // Restart level
        case 'r':
            Initialize();   
            break;
    }
 
 
    // AI turn
    UpdateAI();
 
 
    // Hero death
    if( unitsData[heroIndex].health <= 0 )
    {
        isGameActive = false;
    }
    else
    {
        // Health regeneration
        if( unitsData[heroIndex].health < GetUnitDefaultHealth( UnitType_Hero ) )
        {
            unitsData[heroIndex].health++;
        }
    }
 
}
 
void Shutdown()
{
    system("cls");
    printf("\n\tGame over...");
    _getch();
}
 
int main()
{
    SetupSystem();
    Initialize();
 
    do
    {
        Render();
        Update();
    }
    while( isGameActive );
 
    Shutdown();
 
    return 0;
}
